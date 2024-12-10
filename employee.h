#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

class Employee
{
private:
    int id;
    QString nom;
    QString prenom;
    QString login;
    QString password;
    QString telephone;
    QString poste;
    QString disponibilite;
    QString heureTravail;

public:

    Employee();
    Employee(int id, QString n, QString p, QString login, QString password, QString tel, QString poste, QString disponibilite, QString heureTravail);

    // Getters
    int getID() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getLogin() const;
    QString getPassword() const;
    QString getTelephone() const;
    QString getPoste() const;
    QString getDisponibilite() const;
    QString getHeureTravail() const;


    void setID(int id);
    void setNom(const QString &n);
    void setPrenom(const QString &p);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    void setTelephone(const QString &tel);
    void setPoste(const QString &poste);
    void setDisponibilite(const QString &disponibilite);
    void setHeureTravail(const QString &heureTravail);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier();
    bool exporterPDF(const QString &nomFichier, QAbstractItemModel *model);
    QSqlQueryModel* trierParID(bool asc);
    //QHash<QString, int> statistiquesDisponibilite();
    QMap<QString, int> statistiquesDisponibilite();
    int calculerScore() const;
    static Employee trouverMeilleurEmployeeParAnnee(int annee, QSqlQueryModel* model);
    bool chercherParID(int id);



};

#endif // EMPLOYEE_H
