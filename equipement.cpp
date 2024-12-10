#include "equipement.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QSqlRecord>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QPen>



Equipement::Equipement() {}

Equipement::Equipement(int id, QString nom, QString type, QString date, QString etat)
    : id_equip(id), nom_equip(nom), type(type), date_maintenance(date), etat(etat) {}

// Ajouter un équipement dans la base
bool Equipement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO equipement (ID_EQUIP, NOM_EQUIP, TYPE, DATE_MAINTENANCE, ETAT) "
                  "VALUES (:id, :nom, :type, :date, :etat)");
    query.bindValue(":id", id_equip);
    query.bindValue(":nom", nom_equip);
    query.bindValue(":type", type);
    query.bindValue(":date", date_maintenance);
    query.bindValue(":etat", etat);

    return query.exec(); // Retourne true si l'insertion réussit, sinon false
}

// Afficher tous les équipements
QSqlQueryModel* Equipement::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM equipement");
    return model;
}

// Ajoutez cette méthode à la classe Equipement
bool Equipement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id);
    return query.exec();  // Retourne true si la suppression réussit, sinon false
}
bool Equipement::modifier(int id, QString nom, QString type, QString date, QString etat) {
    QSqlQuery query;
    query.prepare("UPDATE equipement SET NOM_EQUIP = :nom, TYPE = :type, DATE_MAINTENANCE = :date, ETAT = :etat WHERE ID_EQUIP = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":etat", etat);
    query.bindValue(":id", id);

    return query.exec(); // Retourne true si la requête a réussi
}

QSqlQueryModel* Equipement::trierParNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM equipement ORDER BY NOM_EQUIP ASC"); // ASC pour ordre croissant
    return model;
}


QString Equipement::prevoirUsure(int id_equip) {
    // Vérifier la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return "Erreur : La base de données n'est pas ouverte.";
    }

    // Requête pour récupérer les données de l'équipement
    QSqlQuery query;
    query.prepare("SELECT DATE_MAINTENANCE, ETAT FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id_equip);

    if (!query.exec() || !query.next()) {
        return "Erreur : Impossible de récupérer les données pour l'équipement avec ID " + QString::number(id_equip);
    }

    // Récupération des données
    QString dateMaintenance = query.value("DATE_MAINTENANCE").toString();
    QString etat = query.value("ETAT").toString();

    // Calcul des jours depuis la dernière maintenance
    QDate dateDerniereMaintenance = QDate::fromString(dateMaintenance, "yyyy-MM-dd");
    if (!dateDerniereMaintenance.isValid()) {
        return "Erreur : Date de maintenance invalide.";
    }
    int joursDepuisMaintenance = dateDerniereMaintenance.daysTo(QDate::currentDate());

    // Calcul du score d'usure basé sur des pondérations
    double scoreUsure = 0;

    // Pondération pour les jours depuis maintenance
    if (joursDepuisMaintenance > 365) {
        scoreUsure += 50; // Plus d'un an
    } else if (joursDepuisMaintenance > 180) {
        scoreUsure += 30; // Plus de 6 mois
    } else {
        scoreUsure += 10; // Maintenance récente
    }

    // Pondération pour l'état
    if (etat == "bon etat") {
        scoreUsure += 10;
    } else if (etat == "etat moyen") {
        scoreUsure += 30;
    } else if (etat == "etat mauvais") {
        scoreUsure += 50;
    }

    // Format du résultat
    QString resultat = QString(
                           "Prévision d'usure pour l'équipement %1 :\n\n"
                           "- Jours depuis dernière maintenance : %2\n"
                           "- État actuel : %3\n"
                           "- Score d'usure prévu : %4/100"
                           ).arg(id_equip).arg(joursDepuisMaintenance).arg(etat).arg(scoreUsure);

    return resultat;
}

QString Equipement::planifierMaintenance(int id) {
    // Requête pour obtenir l'état de l'équipement
    QSqlQuery query;
    query.prepare("SELECT ETAT FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        return "Erreur lors de l'exécution de la requête: " + query.lastError().text();
    }

    if (query.next()) {
        QString etat = query.value(0).toString().trimmed();  // Récupérer et nettoyer l'état

        // Planification en fonction de l'état
        if (etat == "bon etat") {
            return "La prochaine maintenance sera dans 6 mois.";
        } else if (etat == "etat moyen") {
            return "La prochaine maintenance sera dans 3 mois.";
        } else if (etat == "etat mauvais") {
            return "La prochaine maintenance sera dans 1 mois.";
        } else {
            return "État de l'équipement inconnu.";
        }
    }

    return "Équipement non trouvé.";
}

QString Equipement::rechercherParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString resultat = "ID: " + query.value("ID_EQUIP").toString() +
                           "\nNom: " + query.value("NOM_EQUIP").toString() +
                           "\nType: " + query.value("TYPE").toString() +
                           "\nDate Maintenance: " + query.value("DATE_MAINTENANCE").toString() +
                           "\nÉtat: " + query.value("ETAT").toString();
        return resultat;
    } else {
        return "Équipement introuvable.";
    }
}

QMap<QString, int> Equipement::getEtatStatistics()
{
    QMap<QString, int> statistiques;
    QSqlQuery query;

    // Requête SQL pour regrouper les équipements par état
    query.prepare("SELECT ETAT, COUNT(*) FROM equipement GROUP BY ETAT");

    if (query.exec()) {
        while (query.next()) {
            QString etat = query.value(0).toString(); // Extrait l'état
            int count = query.value(1).toInt();       // Extrait le nombre
            statistiques.insert(etat, count);         // Ajoute au QMap
        }
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
    }

    return statistiques; // Retourne les statistiques
}





