
#include "client.h"
#include <QDebug>
#include <QSqlError>

// Default Constructor
Client::Client() {}

// Parameterized Constructor
Client::Client(int id, QString nom, QString prenom, QString telephone, QString adresse, QString date_inscription)
    : id_client(id), nom(nom), prenom(prenom), telephone(telephone), adresse(adresse), date_inscription(date_inscription) {}

// Getters
int Client::getID() const { return id_client; }
QString Client::getNom() const { return nom; }
QString Client::getPrenom() const { return prenom; }
QString Client::getTelephone() const { return telephone; }
QString Client::getAdresse() const { return adresse; }
QString Client::getDateInscription() const { return date_inscription; }

// Setters
void Client::setID(int id) { id_client = id; }
void Client::setNom(const QString &nom) { this->nom = nom; }
void Client::setPrenom(const QString &prenom) { this->prenom = prenom; }
void Client::setTelephone(const QString &telephone) { this->telephone = telephone; }
void Client::setAdresse(const QString &adresse) { this->adresse = adresse; }
void Client::setDateInscription(const QString &date_inscription) { this->date_inscription = date_inscription; }
//----------------------------


QSqlQueryModel* Client::afficherRepartitionGeographique2()
{
    QSqlQuery query;
    query.prepare("SELECT adresse, COUNT(*) AS nombre_clients FROM CLIENT GROUP BY adresse ORDER BY nombre_clients DESC");

    if (query.exec()) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        return model;
    } else {
        qDebug() << "Erreur de requête : " << query.lastError();
        return nullptr;
    }
}

//-----------------------------------------------------------
// Method to AJOUTER a client
bool Client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (IDCLIENT, NOMCLIENT, PRÉNOMCLIENT, TÉLÉPHONECLIENT, ADRESSE, DATEINSCRI) "
                  "VALUES (:id, :nom, :prenom, :telephone, :adresse, :dateInscri)");
    query.bindValue(":id", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":dateInscri", date_inscription);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du client :" << query.lastError().text();
        return false;
    }
    qDebug() << "Client added successfully to database.";
    return true;
}
//-----------------------------------------------------------
// Method AFFICHER clients
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT IDCLIENT, NOMCLIENT, PRÉNOMCLIENT, TÉLÉPHONECLIENT, ADRESSE, DATEINSCRI FROM CLIENT");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des clients:" << model->lastError().text();
    } else {
        qDebug() << "Données clients récupérées avec succès";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date d'inscription"));
    return model;
}

//-----------------------------------------------------------


// Method to SUPPRIMER a client
bool Client::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du client :" << query.lastError().text();
        return false;
    }
    qDebug() << "Client deleted successfully from database.";
    return true;
}
//modifier
//-----------------UPDATE-------------------------------
bool Client::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOMCLIENT = :nom, PRÉNOMCLIENT = :prenom, TÉLÉPHONECLIENT = :telephone, ADRESSE = :adresse, DATEINSCRI = :dateInscri "
                  "WHERE IDCLIENT = :id");
    query.bindValue(":id", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":dateInscri", date_inscription);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du client :" << query.lastError().text();
        return false;
    }
    qDebug() << "Client modified successfully in database.";
    return true;
}
//-------------Tri---------------------
QSqlQueryModel* Client::afficherTriParNom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT IDCLIENT, NOMCLIENT, PRÉNOMCLIENT, TÉLÉPHONECLIENT, ADRESSE, DATEINSCRI FROM CLIENT ORDER BY NOMCLIENT ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage trié des clients:" << model->lastError().text();
    } else {
        qDebug() << "Données clients récupérées et triées par nom avec succès";
    }

    return model;
}
//  rapport des adresse geographique des clients
QSqlQueryModel* Client::afficherRepartitionGeographique() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécution d'une requête SQL pour obtenir le nombre de clients par ville (ou adresse)
    model->setQuery("SELECT ADRESSE, COUNT(*) AS NombreClients "
                    "FROM CLIENT "
                    "GROUP BY ADRESSE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage de la répartition géographique:" << model->lastError().text();
    } else {
        qDebug() << "Répartition géographique récupérée avec succès";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de Clients"));
    return model;
}




