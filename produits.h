#ifndef PRODUITS_H
#define PRODUITS_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QList>
#include <QDate>

class produits
{
private:
    QString nomproduit;
    QDate dateExpiration;
    int quantiteDisponible;
    int humidite;
    int temperature;
    QDate dateDebut;
    QDate dateAjout;
    int etat=0;
public:
    produits();
    produits(const QString& nomproduit, const QDate& dateExpiration, int quantiteDisponible, int humidite, int temperature, const QDate& dateDebut, const QDate& dateAjout = QDate::currentDate(), int etat=0);

    QString getNomProduit() const { return nomproduit; }
    QDate getDateExpiration() const { return dateExpiration; }
    int getQuantiteDisponible() const { return quantiteDisponible; }
    int getHumidite() const { return humidite; }
    int getTemperature() const { return temperature; }
    QDate getDateDebut() const { return dateDebut; }
    QDate getDateAjout() const { return dateAjout; }
    int getEtat() const { return etat; }

    void setNomProduit(const QString& p) { nomproduit = p; }
    void setDateExpiration(const QDate& dexp) { dateExpiration = dexp; }
    void setQuantiteDisponible(int qtd) { quantiteDisponible = qtd; }
    void setHumidite(int h) { humidite = h; }
    void setTemperature(int tp) { temperature = tp; }
    void setDateDebut(const QDate& dd) { dateDebut = dd; }
    void setDateAjout(const QDate& da) { dateAjout = da; }
    void setEtat(const int& et) { etat = et; }

    bool ajouterProduit(produits p);
    QSqlQueryModel* afficherProduits();
    bool supprimerProduits(int idproduit);
    bool modifierProduits(int idproduit, const QString& nomproduit, const QDate& dateExpiration, int quantiteDisponible, int humidite, int temperature, const QDate& dateDebut,const QDate& dateAjout);
    QList<produits> retrouverListProduits();
    QSqlQueryModel* trierProduits(int index);
    QSqlQueryModel* rechercheparnomproduit(const QString& nomproduit);
};

#endif
