#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include<QTableWidgetItem>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ctemp.afficher()); // Assure-toi que Ctemp est une instance de Commande
}




MainWindow::~MainWindow() {
    delete ui;
}


// mainwindow.cpp
void MainWindow::on_pushButton_331_clicked() {
    int id = ui->idInput->text().toInt();
    QString dateText = ui->dateInput->text();
    QDate dateCommande = QDate::fromString(dateText, "yyyy-MM-dd");
    QString etatCommande = ui->etatInput->text();
    float prix = ui->prixInput->text().toFloat();
    int pointFidelite = ui->fideliteInput->text().toInt();

    Commande c(id, dateCommande, etatCommande, prix, pointFidelite);
    bool test = c.ajouter();

    if (test) {
        ui->tableView->setModel(Ctemp.afficher());
        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("L'ajout a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}




void MainWindow::on_pushButton_336_clicked() {

        int id = ui->supp->text().toInt(); // Assurez-vous de récupérer l'ID à supprimer

        Commande c; // Créer un objet Commande
        bool test = c.supprimer(id); // Appeler la méthode supprimer

        // Vérification du résultat et affichage du message
        if (test) {
            ui->tableView->setModel(Ctemp.afficher()); // Rafraîchir la table
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Suppression effectuée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(this, QObject::tr("Erreur"),
                                  QObject::tr("La suppression a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }


