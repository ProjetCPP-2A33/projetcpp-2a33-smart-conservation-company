#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QPen>
#include <QMap>
#include <QSqlError>
#include <QDebug>


class Equipement {
private:
    int id_equip;                // ID de l'équipement (entier)
    QString nom_equip;           // Nom de l'équipement
    QString type;                // Type d'équipement
    QString date_maintenance;    // Date de maintenance
    QString etat;                // État de l'équipement

public:
    Equipement();
    Equipement(int id, QString nom, QString type, QString date, QString etat);

    bool ajouter(); // Ajouter un équipement dans la base
    static QSqlQueryModel* afficher(); // Afficher tous les équipements
    static bool supprimer(int id);
    bool modifier(int id, QString nom, QString type, QString date, QString etat); // Modifier un équipement
    static QSqlQueryModel* trierParNom();
    static QString prevoirUsure(int id_equip);
    QString planifierMaintenance(int id);
    QString rechercherParId(int id);
    QMap<QString, int> getEtatStatistics(); // Récupère les statistiques des états*/


};

#endif // EQUIPEMENT_H
