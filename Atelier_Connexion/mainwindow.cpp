#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug> // Ajout de qDebug

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Affiche les clients dans le QTableView au démarrage
    ui->tableView_clients->setModel(client.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Ajouter button clicked"; // Message de débogage

    // Récupérer les informations du client à partir des champs de saisie
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString date_inscription = ui->lineEdit_dateInscription->text();

    // Créer un objet Client et ajouter à la base de données
    Client nouveauClient(id, nom, prenom, telephone, adresse, date_inscription);
    bool test = nouveauClient.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Le client a été ajouté avec succès."), QMessageBox::Ok);
        // Rafraîchir l'affichage dans le QTableView
        ui->tableView_clients->setModel(nouveauClient.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout du client a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    qDebug() << "Supprimer button clicked"; // Message de débogage

    // Récupérer l'ID du client à partir du champ de saisie
    int id = ui->lineEdit_ID->text().toInt();
    bool test = client.supprimer(id);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);
        // Rafraîchir l'affichage dans le QTableView
        ui->tableView_clients->setModel(client.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}

/*
 * #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug> // Ajout de qDebug

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Affiche les clients dans le QTableView au démarrage
    ui->tableView_clients->setModel(client.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Bouton ajouter cliqué"; // Message de débogage

    // Récupérer les informations du client à partir des champs de saisie
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString date_inscription = ui->lineEdit_dateInscription->text();

    // Créer un objet Client et ajouter à la base de données
    Client nouveauClient(id, nom, prenom, telephone, adresse, date_inscription);
    bool test = nouveauClient.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Le client a été ajouté avec succès."), QMessageBox::Ok);
        // Rafraîchir l'affichage dans le QTableView
        ui->tableView_clients->setModel(nouveauClient.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout du client a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    qDebug() << "Bouton supprimer cliqué"; // Message de débogage

    // Récupérer l'ID du client à partir du champ de saisie
    int id = ui->lineEdit_ID->text().toInt();
    bool test = client.supprimer(id);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);
        // Rafraîchir l'affichage dans le QTableView
        ui->tableView_clients->setModel(client.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}
*/
