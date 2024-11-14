#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_331_clicked();  // Ajouter une commande
    void on_pushButton_336_clicked();
    void on_pushButton_332_clicked();    // Supprimer une commande
    void onTableViewClicked(const QModelIndex &index) ;
    void setupConnections();
    void on_pushButton_339_clicked();
    void on_pdf_clicked();
    void on_statistique_clicked();
    void on_rechercher_clicked();
    void on_calculerReduction_clicked();
    void on_historique_clicked();





private:
    Ui::MainWindow *ui;
    Commande Ctemp;



};

#endif // MAINWINDOW_H
