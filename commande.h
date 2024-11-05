#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Commande {
private:
    int id;
    QDate dateCommande;
    QString etatCommande;
    float prix;
    int pointFidelite;

public:
    Commande() {}
    Commande(int id, QDate dateCommande, QString etatCommande, float prix, int pointFidelite);

    // Getters
    int getId() const;
    QDate getDateCommande() const;
    QString getEtatCommande() const;
    float getPrix() const;
    int getPointFidelite() const;

    // Setters
    void setId(int id);
    void setDateCommande(QDate dateCommande);
    void setEtatCommande(QString etatCommande);
    void setPrix(float prix);
    void setPointFidelite(int pointFidelite);

    bool ajouter();
    QSqlQueryModel* afficher(); // Déclaration
    bool supprimer(int id);
};

#endif // COMMANDE_H
