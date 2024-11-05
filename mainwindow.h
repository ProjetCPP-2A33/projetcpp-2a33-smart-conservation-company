#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"
#include<QVector>
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
    void on_pushButton_336_clicked();  // Supprimer une commande

private:
    Ui::MainWindow *ui;
    Commande Ctemp;  // Instance temporaire de Commande
      // Méthode pour afficher les commandes
};

#endif // MAINWINDOW_H

