#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QFileDialog>
#include <QSqlQueryModel>
#include <QPageSize>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QPen>
#include <QGraphicsView>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "equipement.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_ajouter_clicked(); // Gère le clic sur le bouton "Ajouter"

    void on_pushButton_supprimer_clicked(bool checked);
    void on_modifier_clicked();
    void on_valider_modif_clicked();
    void on_trier_clicked();
    //void on_pushButton_exporter_pdf_clicked();
    void on_exporterPDF_clicked();
    void on_pushButtonPrevoir_clicked();
    void on_pushButtonPlanifier_clicked();
    bool exporterPDF(const QString &nomFichier, QAbstractItemModel *model);
    void on_pushButtonRecherche_clicked();
    void on_pushButton_stats_clicked(); // Slot pour afficher les statistiques


    void genererStatistiquesParEtat();
    void on_pushButton_stat_clicked();
    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
    void on_Button_Arduino_clicked();
private:
    void updateEtatCycle(QMap<QString, int> statistiques); // Méthode pour mettre à jour le graphique


private:
    Ui::MainWindow *ui;
    QSqlQueryModel* model; // Modèle pour le QTableView
    int idActuel;
    Arduino arduino;


};

#endif // MAINWINDOW_H
