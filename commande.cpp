 #include "commande.h"
#include "qpdfwriter.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPainter>
#include <QFont>
#include <QPdfWriter>
#include <QMessageBox>
#include <QMap>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDateTime>
#include <QStandardItem>
#include <QTableView>
#include <QFile>
#include <QTextStream>


Commande::Commande(int id, QString dateCommande, QString etatCommande, float prix, int pointFidelite)
    : id(id), dateCommande(dateCommande), etatCommande(etatCommande), prix(prix), pointFidelite(pointFidelite) {

}

QSqlQueryModel* Commande::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateCommande"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etatCommande"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("pointFidelite"));
    return model;
}

bool Commande::ajouter() {
    if (id <= 0) {
        qDebug() << "Erreur : L'ID de la commande doit être un entier positif.";
        return false;
    }

    QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy");
    if (!date.isValid()) {
        qDebug() << "Erreur : La date de commande est invalide ou mal formatée.";
        return false;
    }

    QString formattedDate = date.toString("dd/MM/yyyy");

    QStringList etatsValides = {"en preparation", "traite", "reçu"};
    if (!etatsValides.contains(etatCommande)) {
        qDebug() << "Erreur : L'état de la commande est invalide.";
        return false;
    }

    if (prix <= 0) {
        qDebug() << "Erreur : Le prix de la commande doit être un nombre positif.";
        return false;
    }

    if (pointFidelite < 0) {
        qDebug() << "Erreur : Les points de fidélité doivent être un nombre positif ou égal à zéro.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO commandes (id, dateCommande, etatCommande, prix, pointFidelite) "
                  "VALUES (:id, :dateCommande, :etatCommande, :prix, :pointFidelite)");

    query.bindValue(":id", id);
    query.bindValue(":dateCommande", formattedDate);  // Ensure correct format
    query.bindValue(":etatCommande", etatCommande);
    query.bindValue(":prix", prix);
    query.bindValue(":pointFidelite", pointFidelite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "Commande ajoutée avec succès.";


addToHistory("Ajout d'une commande", id);

    return true;
}






bool Commande::idExiste(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID : " << query.lastError().text();
        return false;
    }

    query.next();
    return query.value(0).toInt() > 0;
}


bool Commande::modifier() {
    QSqlQuery query;
    QStringList setClauses;

    // Modifier la date uniquement si elle a été changée
    if (!dateCommande.isEmpty()) {
        QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy");
        if (!date.isValid()) {
            qDebug() << "Erreur : La date de commande est invalide ou mal formatée.";
            return false;
        }
        setClauses << "dateCommande = :dateCommande";  // Ajouter la clause de mise à jour pour la date
    }

    // Modifier l'état uniquement si il a été modifié
    if (!etatCommande.isEmpty()) {
        setClauses << "etatCommande = :etatCommande";  // Ajouter la clause de mise à jour pour l'état
    }

    // Modifier le prix uniquement si il a été modifié (prix > 0)
    if (prix > 0) {
        setClauses << "prix = :prix";  // Ajouter la clause de mise à jour pour le prix
    }

    // Modifier les points de fidélité uniquement s'ils sont modifiés
    if (pointFidelite >= 0) {
        setClauses << "pointFidelite = :pointFidelite";  // Ajouter la clause de mise à jour pour les points
    }

    // Si aucun champ n'a été modifié, retourner false
    if (setClauses.isEmpty()) {
        qDebug() << "Aucune modification à apporter.";
        return false;
    }

    // Construire la requête SQL avec les champs modifiés
    query.prepare("UPDATE commandes SET " + setClauses.join(", ") + " WHERE id = :id");

    // Lier les valeurs modifiées
    query.bindValue(":id", id);
    if (!dateCommande.isEmpty()) {
        QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy");
        query.bindValue(":dateCommande", date.toString("yyyy-MM-dd"));
    }
    if (!etatCommande.isEmpty()) {
        query.bindValue(":etatCommande", etatCommande);
    }
    if (prix > 0) {
        query.bindValue(":prix", prix);
    }
    if (pointFidelite >= 0) {
        query.bindValue(":pointFidelite", pointFidelite);
    }

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "Commande modifiée avec succès.";
    addToHistory("Modification d'une commande", id);

    return true;
}



bool Commande::supprimer(int id) {
    QSqlQuery query;

    // Vérifier si l'ID existe dans la base de données
    query.prepare("SELECT COUNT(*) FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'existence de l'ID:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) {
        // Si l'ID n'existe pas dans la base de données
        qDebug() << "Aucun enregistrement trouvé avec l'ID:" << id;
        return false;
    }

    // Préparation de la requête SQL pour supprimer la commande
    query.prepare("DELETE FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    // Exécution de la requête de suppression
    if (!query.exec()) {
        // Si la requête échoue, afficher l'erreur
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }

    // Si la requête réussit, afficher un message de succès
    qDebug() << "Suppression réussie pour l'ID:" << id;
    addToHistory("Suppression d'une commande", id);
    return true;
}
QSqlQueryModel* Commande::trierParDate() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM commandes ORDER BY dateCommande ASC";

    // Requête pour trier par dateCommande en convertissant le format en date

    qDebug() << "Exécution de la requête : " << queryStr;

    model->setQuery(queryStr);

    // Vérifiez si la requête s'est exécutée correctement
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'exécution de la requête de tri par date : " << model->lastError().databaseText();
        qDebug() << "Détail de l'erreur : " << model->lastError().driverText();

        delete model;
        return nullptr;
    }




    return model;
}


void Commande::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)
{
    QPdfWriter pdfWriter(nomFichier);
    QPainter painter(&pdfWriter);

    // Paramètres PDF
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));

    // Titre
    painter.drawText(2500, 1100, "Liste des Commandes");

    // Coordonnées et dimensions des cellules
    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;

    // En-têtes du tableau
    QStringList headers = {"id ", "datec", "etatc", "prix", "pointfid"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }

    // Données des commandes
    int rowCount = model->rowCount();
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);
            painter.drawText(cellRect, Qt::AlignCenter, data);
            painter.drawRect(cellRect);
        }
    }

    QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé.");
}

QMap<QString, int> Commande::getStatistiquesParEtat() {
    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT etatCommande, COUNT(*) FROM commandes GROUP BY etatCommande");

    if (query.exec()) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques.insert(etat, count);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
    }

    return statistiques;
}
// commande.cpp


float Commande::getPrix() const {
    return this->prix;
}

/*bool Commande::calculerReductionAvecUpdate(int id) {
    QSqlQuery query;

    // Récupérer les détails de la commande par ID
    query.prepare("SELECT prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        float prix = query.value(0).toFloat();
        int pointsFidelite = static_cast<int>(prix / 20); // Calcul des points fidélité

        // Calcul du prix après réduction si nécessaire
        float prixApresReduction = prix;
        if (pointsFidelite >= 10) {
            prixApresReduction = prix * 0.9; // Appliquer 10% de réduction
        }

        // Mettre à jour les valeurs dans la base de données
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE commandes SET pointFidelite = :pointsFidelite, prix = :prixApresReduction WHERE id = :id");
        updateQuery.bindValue(":pointsFidelite", pointsFidelite);
        updateQuery.bindValue(":prixApresReduction", prixApresReduction);
        updateQuery.bindValue(":id", id);

        return updateQuery.exec(); // Retourne true si la mise à jour a réussi
    }
}*/
bool Commande::calculerReductionAvecUpdate(int id) {
    QSqlQuery query;

    // Récupérer les détails de la commande par ID
    query.prepare("SELECT prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        float prix = query.value(0).toFloat();
        int pointsFidelite = static_cast<int>(prix / 20); // Calcul des points fidélité

        // Calcul du prix après réduction si nécessaire
        float prixApresReduction = prix;
        if (pointsFidelite >= 10) {
            prixApresReduction = prix * 0.9; // Appliquer 10% de réduction
        }

        // Mettre à jour les valeurs dans la base de données
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE commandes SET pointFidelite = :pointsFidelite, prix = :prixApresReduction WHERE id = :id");
        updateQuery.bindValue(":pointsFidelite", pointsFidelite);
        updateQuery.bindValue(":prixApresReduction", prixApresReduction);
        updateQuery.bindValue(":id", id);

        if (updateQuery.exec()) {
            // Ajouter l'action à l'historique après la mise à jour réussie
            QString action = QString("Réduction de 10%% appliquée. Ancien prix: %1, Nouveau prix: %2, Points fidélité: %3")
                                 .arg(prix)
                                 .arg(prixApresReduction)
                                 .arg(pointsFidelite);
            addToHistory(action, id); // Enregistrer l'action dans l'historique

            return true; // Retourne true si la mise à jour et l'ajout à l'historique ont réussi
        }
    }
    return false; // Retourne false si la mise à jour échoue
}










void Commande::writeHistoryToFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier d'historique.";
        return;
    }

    QTextStream out(&file);
    for (const QString &entry : historyList) {
        out << entry << "\n";
    }

    file.close();
    qDebug() << "Historique écrit dans le fichier : " << fileName;
}

void Commande::addToHistory(const QString &action, int idCommande) {
    // Chemin du fichier d'historique
    QString filePath = "C:/Users/MSI/Documents/crud/historique.txt";

    // Ouvrir le fichier en mode ajout
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier d'historique.";
        return;
    }

    // Créer un flux texte
    QTextStream out(&file);

    // Obtenir la date et l'heure actuelles
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Ajouter l'entrée avec la date, l'action, et l'ID (si disponible)
    QString entry = currentDateTime.toString("yyyy-MM-dd hh:mm:ss") + " - " + action;
    if (idCommande != 0) {
        entry += " pour l'ID " + QString::number(idCommande);
    }
    out << entry << "\n";

    // Fermer le fichier
    file.close();

    qDebug() << "Action ajoutée à l'historique : " << entry;
}


void Commande::afficherHistorique() {
    // Chemin du fichier d'historique
    QString filePath = "C:/Users/MSI/Documents/crud/historique.txt";

    // Ouvrir le fichier en lecture seule
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
        return;
    }

    // Lire tout le contenu du fichier
    QTextStream in(&file);
    QString historique = in.readAll();

    // Fermer le fichier
    file.close();

    // Afficher le contenu dans une boîte de dialogue
    QMessageBox::information(nullptr, "Historique", historique.isEmpty() ? "Aucun historique disponible." : historique);
}
