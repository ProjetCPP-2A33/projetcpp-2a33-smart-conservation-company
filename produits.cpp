#include "produits.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtSql>
#include <QMessageBox>

produits::produits(const QString& nomproduit, const QDate& dateExpiration, int quantiteDisponible, int humidite, int temperature, const QDate& dateDebut, const QDate& dateAjout, int etat)
    : nomproduit(nomproduit), dateExpiration(dateExpiration), quantiteDisponible(quantiteDisponible), humidite(humidite), temperature(temperature), dateDebut(dateDebut), dateAjout(dateAjout), etat(etat)
{
}

produits::produits() {}

QSqlQueryModel* produits::afficherProduits() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Produits");
    if (model->lastError().isValid()) {
        qDebug() << "Erreur requête:" << model->lastError().text();
    } else {
        qDebug() << model->rowCount() << " enregistrements trouvés";
    }

    return model;
}

bool produits::supprimerProduits(int idproduit) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Produits WHERE idproduit = :idproduit");
    query.bindValue(":idproduit", idproduit);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID:" << query.lastError().text();
        return false;
    }

    query.next();
    int nbr = query.value(0).toInt();

    if (nbr == 0) {
        QMessageBox::critical(nullptr, "Suppression", "ID introuvable");
        return false;
    }

    QSqlQuery querySupprimer;
    querySupprimer.prepare("DELETE FROM Produits WHERE idproduit = :idproduit");
    querySupprimer.bindValue(":idproduit", idproduit);

    if (!querySupprimer.exec()) {
        qDebug() << "Erreur lors de la suppression:" << querySupprimer.lastError().text();
        return false;
    }
    return true;
}

//modifier produit
bool produits::modifierProduits(int idproduit, const QString& nomproduit, const QDate& dateExpiration, int quantiteDisponible, int humidite, int temperature, const QDate& dateDebut, const QDate& dateAjout) {
    QSqlQuery query;
    query.prepare("UPDATE Produits SET nomproduit = :nomproduit, dateExpiration = :dateExpiration, quantiteDisponible = :quantiteDisponible, "
                  "humidite = :humidite, temperature = :temperature, dateDebut = :dateDebut, dateAjout = :dateAjout WHERE idproduit = :idproduit");

    query.bindValue(":idproduit", idproduit);
    query.bindValue(":nomproduit", nomproduit);
    query.bindValue(":dateExpiration", dateExpiration);
    query.bindValue(":quantiteDisponible", quantiteDisponible);
    query.bindValue(":humidite", humidite);
    query.bindValue(":temperature", temperature);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateAjout", dateAjout);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour";
        return false;
    }

    return true;
}

// Ajouter produit
bool produits::ajouterProduit(produits p) {
    QSqlQuery query;
    query.prepare("INSERT INTO Produits (nomproduit, dateExpiration, quantiteDisponible, humidite, temperature, dateDebut, dateAjout, etat) "
                  "VALUES (:nomproduit, :dateExpiration, :quantiteDisponible, :humidite, :temperature, :dateDebut, :dateAjout, :etat)");

    query.bindValue(":nomproduit", p.nomproduit);
    query.bindValue(":dateExpiration", p.dateExpiration);
    query.bindValue(":quantiteDisponible", p.quantiteDisponible);
    query.bindValue(":humidite", p.humidite);
    query.bindValue(":temperature", p.temperature);
    query.bindValue(":dateDebut", p.dateDebut);
    query.bindValue(":dateAjout", p.dateAjout);
    query.bindValue(":etat", p.etat);


    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
        return false;
    }
    return true;
}

// trier produit
QSqlQueryModel* produits::trierProduits(int index)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (index == 1) {
        query.prepare("SELECT * FROM Produits ORDER BY nomproduit ASC");
    } else  {
        query.prepare("SELECT * FROM Produits");
    }

    if (query.exec()) {
        model->setQuery(std::move(query));
    } else {
        qDebug() << "Erreur lors de la requête de tri:" << query.lastError().text();
    }

    return model;
}
// recherche par nom produit

QSqlQueryModel* produits::rechercheparnomproduit(const QString& nomproduit) {
    QSqlQuery query;
    query.prepare("SELECT * FROM produits WHERE nomproduit LIKE :nomproduit");
    query.bindValue(":nomproduit", "%" + nomproduit + "%");

    if (!query.exec()) {
        qDebug() << "erreur requete" << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query)); // Utilisez std::move pour éviter la copie

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans le modèle:" << model->lastError().text();
    } else {
        qDebug() << model->rowCount() << " résultats success.";
    }

    return model;
}

