#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include "delegatedeuxbouttons.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttongererProduit_clicked();
    void on_buttongererClient_clicked();
    void on_bouttonajouterproduit_clicked();
    void on_bouttonacceuil_clicked();
    void on_bouttonafficherproduits_clicked();
    void on_bouttonmodifierproduit_clicked();
    void on_bouttonstatistiques_clicked();
    void afficherstatistiquesproduits();
    void on_bouttonconfirmerajout_clicked();
    void on_pushButton_6_clicked();
    void on_menutri_currentIndexChanged(int index);
    void on_bouttonconfirmersupprimerproduit_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void onModifierClicked(int ligne);
    void onSupprimerClicked(int ligne);
    void on_bouttonpdffile_clicked();
    void historique(const QString &typeevenement, const QString &nomproduit, const QString &extrainfo);
    void on_bouttonhistorique_clicked();
    void loadHistoriqueFile();
    void on_bouttonnotification_clicked();
    void verifierproduitexpire();
    void on_bouttonrecherche_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QChartView *chartView = nullptr;

    delegateDeuxBouttons *delegate;
};

#endif // MAINWINDOW_H
