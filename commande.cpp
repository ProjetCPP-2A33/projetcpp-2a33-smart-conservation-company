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
    QSqlQueryModel* model = new QSqlQueryModel();// pointeur model pour acceder a tableView
    model->setQuery("SELECT * FROM commandes");// remplir requette sql
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));// definir titre d'une colone dans tableView
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
        qDebug() << "Erreur : La date est invalide.";
        return false;
    }


    QString formattedDate = date.toString("dd/MM/yyyy");


    QStringList etatsValides = {"en preparation", "traite", "recu"};
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

    // Exécution de la requête d'ajout dans la base de données
    QSqlQuery query;
    query.prepare("INSERT INTO commandes (id, dateCommande, etatCommande, prix, pointFidelite) "
                  "VALUES (:id, :dateCommande, :etatCommande, :prix, :pointFidelite)");

    query.bindValue(":id", id);
    query.bindValue(":dateCommande", formattedDate);
    query.bindValue(":etatCommande", etatCommande);
    query.bindValue(":prix", prix);
    query.bindValue(":pointFidelite", pointFidelite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "Commande ajoutée avec succès.";
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


    if (!dateCommande.isEmpty()) {
        QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy");
        if (!date.isValid()) {
            qDebug() << "Erreur : La date de commande est invalide ou mal formatée.";
            return false;
        }
        setClauses << "dateCommande = :dateCommande";  // Ajouter la clause de mise à jour pour la date
    }


    if (!etatCommande.isEmpty()) {
        setClauses << "etatCommande = :etatCommande";  // Ajouter la clause de mise à jour pour l'état
    }


    if (prix > 0) {
        setClauses << "prix = :prix";  // Ajouter la clause de mise à jour pour le prix
    }


    if (pointFidelite >= 0) {
        setClauses << "pointFidelite = :pointFidelite";  // Ajouter la clause de mise à jour pour les points
    }


    if (setClauses.isEmpty()) {
        qDebug() << "Aucune modification à apporter.";
        return false;
    }


    query.prepare("UPDATE commandes SET " + setClauses.join(", ") + " WHERE id = :id");


    query.bindValue(":id", id);
    if (!dateCommande.isEmpty()) {
        QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy");
        query.bindValue(":dateCommande", date.toString("dd/MM/yyyy"));
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


    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la commande :" << query.lastError().text();
        return false;
    }

    qDebug() << "Commande modifiée avec succès.";


    return true;
}






bool Commande::supprimer(int id) {
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM commandes WHERE id = :id");
    query.bindValue(":id", id);//valeur reél

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'existence de l'ID:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count == 0) {

        qDebug() << "Aucun enregistrement trouvé avec l'ID:" << id;
        return false;
    }


    query.prepare("DELETE FROM commandes WHERE id = :id");
    query.bindValue(":id", id);


    if (!query.exec()) {
        // Si la requête échoue, afficher l'erreur
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }


    qDebug() << "Suppression réussie pour l'ID:" << id;
    // addToHistory("Suppression d'une commande", id);
    return true;
}


QSqlQueryModel* Commande::trierParDate() {
    QSqlQueryModel* model = new QSqlQueryModel();// excution requette sql et afficher resultat sur tableView

    // Requête SQL modifiée pour Oracle
    QString queryStr = "SELECT * FROM commandes "
                       "WHERE TO_DATE(dateCommande, 'DD/MM/YYYY') IS NOT NULL "
                       "ORDER BY TO_DATE(dateCommande, 'DD/MM/YYYY') ASC";

    qDebug() << "Exécution de la requête : " << queryStr;// affichage requette pour le debogage verifie shnuw excetué o shnuw le

    model->setQuery(queryStr);// exution sql et stockage(pour model dima stocker et recuperer) donné

    // Vérification si la requête s'est exécutée correctement
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << model->lastError().databaseText();
        qDebug() << "Détail de l'erreur : " << model->lastError().driverText();

        delete model;
        return nullptr;
    }
    //addToHistory("Tri des commandes effectué par date", 0);

    return model;
}










void Commande::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)// esm fich et model fih donne tab comm
{
    QPdfWriter pdfWriter(nomFichier);// fich win besh nhot contenu
    QPainter painter(&pdfWriter);// text forme sur pdf


    painter.setPen(Qt::black);// couleur
    painter.setFont(QFont("Arial", 20));//police

    // Titre
    painter.drawText(2500, 1100, "Liste des Commandes");

    // Coordonnées et dimensions des cellules
    int startX = 200;
    int startY = 1800;
    int cellWidth = 1800;
    int cellHeight = 600;



    QStringList headers = {"id ", "datec", "etatc", "prix", "pointfid"};// nom colonne
    painter.setFont(QFont("Arial", 10, QFont::Bold));// besh tektebhom id .. en gras
    for (int col = 0; col < headers.size(); ++col) {// parcout chaque colonne
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);// win bedhabet besh tektebhom
    }


    int rowCount = model->rowCount();// nbre ligne
    painter.setFont(QFont("Arial", 10));// police de ligne cordonné
    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::green : Qt::white;// parcout setar abyedh o lekhyr akhedhyr

        for (int col = 0; col < headers.size(); ++col) {// chaque cologne mt3 lignz
            QString data = model->data(model->index(row, col)).toString();// acceder yehezeha  puis convertir de forme  text
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);// position taille

            painter.fillRect(cellRect, bgColor);// arriere plan
            painter.drawText(cellRect, Qt::AlignCenter, data);// text f centre cellule
            painter.drawRect(cellRect);//contour de cellule
        }
    }

    QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé.");
}

QMap<QString, int> Commande::getStatistiquesParEtat() {
    QMap<QString, int> statistiques;
    QSqlQuery query;//préparer et exécuter des requêtes SQL
    query.prepare("SELECT etatCommande, COUNT(*) FROM commandes GROUP BY etatCommande");

    if (query.exec()) {// execution nejhet nodekhel lel bloc
        while (query.next()) {// 2eme ligne
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();//recupere ihawelha string
            statistiques.insert(etat, count);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
    }

    return statistiques;// retourne Qmap
}




float Commande::getPrix() const {// pour reduction necessair
    return this->prix;
}




bool Commande::calculerReductionAvecUpdate(int id) {
    if (id <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez entrer un ID valide !");
        return false;
    }

    if (!idExiste(id)) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID de la commande n'existe pas !");
        return false;
    }

    QSqlQuery query;


    query.prepare("SELECT prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        float prix = query.value(0).toFloat();
        int pointsFidelite = static_cast<int>(prix / 20); // Calcul des points fidélité 1pt sur 20


        float prixApresReduction = prix;
        if (pointsFidelite >= 10) {
            prixApresReduction = prix * 0.9; // Appliquer 10% de réduction
        }


        QSqlQuery updateQuery;//nouv requette pour update
        updateQuery.prepare("UPDATE commandes SET pointFidelite = :pointsFidelite, prix = :prixApresReduction WHERE id = :id");
        updateQuery.bindValue(":pointsFidelite", pointsFidelite);
        updateQuery.bindValue(":prixApresReduction", prixApresReduction);
        updateQuery.bindValue(":id", id);//yorbet les nouvelle val bel requette

        if (updateQuery.exec()) {

            QString action = QString("Réduction de 10%% appliquée. Ancien prix: %1, Nouveau prix: %2, Points fidélité: %3")
                                 .arg(prix)
                                 .arg(prixApresReduction)
                                 .arg(pointsFidelite);


            return true;
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Impossible de récupérer les détails de la commande !");
    }
    return false;
}










