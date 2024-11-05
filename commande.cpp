#include "commande.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Commande::Commande(int id, QDate dateCommande, QString etatCommande, float prix, int pointFidelite)
    : id(id), dateCommande(dateCommande), etatCommande(etatCommande), prix(prix), pointFidelite(pointFidelite) {}



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
// commande.cpp
bool Commande::ajouter() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur : La base de données n'est pas ouverte.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO commandes (dateCommande, etatCommande, prix, pointFidelite) VALUES (:dateCommande, :etatCommande, :prix, :pointFidelite)");
    query.bindValue(":dateCommande", dateCommande);
    query.bindValue(":etatCommande", etatCommande);
    query.bindValue(":prix", prix);
    query.bindValue(":pointFidelite", pointFidelite);

    qDebug() << "Tentative d'ajout avec :"
             << "dateCommande:" << dateCommande
             << "etatCommande:" << etatCommande
             << "prix:" << prix
             << "pointFidelite:" << pointFidelite;

    if (!query.exec()) {
        qDebug() << "Erreur d'ajout : " << query.lastError().text(); // Vérifie le message d'erreur
        return false;
    }

    qDebug() << "Ajout réussi.";
    return true;
}


bool Commande::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM commandes WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur : " << query.lastError().text();
        return false;
    }
    qDebug() << "Suppression réussie : " << id;

    return true;
}
