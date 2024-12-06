#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
//******************************
class Client {
public:
    Client();
    Client(int id, QString nom, QString prenom, QString telephone, QString adresse, QString date_inscription);

    // Getters
    int getID() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getTelephone() const;
    QString getAdresse() const;
    QString getDateInscription() const;

    // Setters
    void setID(int id);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setTelephone(const QString &telephone);
    void setAdresse(const QString &adresse);
    void setDateInscription(const QString &date_inscription);

    // Functionalities
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficherTriParNom();
    QSqlQueryModel* afficherRepartitionGeographique();
    QSqlQueryModel*  afficherRepartitionGeographique2();

private:
    int id_client;               // ID du client
    QString nom;                 // Nom du client
    QString prenom;              // Prénom du client
    QString telephone;           // Téléphone du client
    QString adresse;             // Adresse du client
    QString date_inscription;    // Date d'inscription du client
};

#endif // CLIENT_H
