#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "employee.h"
#include "connection.h"
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


#include <QDialog>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a connection object and check the connection
    Connection connection;
    if (!connection.createconnect()) {
        QMessageBox::critical(this, tr("Database Connection Error"),
                              tr("Failed to connect to the database.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        qApp->exit(-1); // Exit the application if the connection fails
    }

    // Display employees in the QTableView at startup
    ui->tableView_employee->setModel(emp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Ajouter button clicked"; // Debug message

    // Check if the database is open before executing the query
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        QMessageBox::critical(this, tr("Database Error"),
                              tr("The database connection is not open.\nPlease check your connection settings."),
                              QMessageBox::Ok);
        return;
    }

    // Retrieve employee information from input fields
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString poste = ui->lineEdit_poste->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString heureTravail = ui->lineEdit_heureTravail->text();

    qDebug() << "ID:" << id << "Nom:" << nom << "Prenom:" << prenom << "Login:" << login << "Password:" << password
             << "Telephone:" << telephone << "Poste:" << poste << "Disponibilite:" << disponibilite << "HeureTravail:" << heureTravail;

    // Create an Employee object and add to the database
    Employee nouveauEmployee(id, nom, prenom, login, password, telephone, poste, disponibilite, heureTravail);
    bool test = nouveauEmployee.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("L'employé a été ajouté avec succès."), QMessageBox::Ok);
        // Refresh the display in the QTableView
        ui->tableView_employee->setModel(nouveauEmployee.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout de l'employé a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    qDebug() << "Supprimer button clicked"; // Debug message
/*
    // Check if the database is open before executing the query
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        QMessageBox::critical(this, tr("Database Error"),
                              tr("The database connection is not open.\nPlease check your connection settings."),
                              QMessageBox::Ok);
        return;
    }
*/
    // Retrieve the employee ID from the input field
    int id = ui->lineEdit_ID->text().toInt();
    bool test = emp.supprimer(id);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);
        // Refresh the display in the QTableView
        ui->tableView_employee->setModel(emp.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked() {
    qDebug() << "Modifier button clicked"; // Debug message
/*
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        QMessageBox::critical(this, tr("Database Error"),
                              tr("The database connection is not open.\nPlease check your connection settings."),
                              QMessageBox::Ok);
        return;
    }
*/
    // Retrieve employee information from input fields
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString poste = ui->lineEdit_poste->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString heureTravail = ui->lineEdit_heureTravail->text();

    // Create an Employee object with new data and modify in database
    Employee emp(id, nom, prenom, login, password, telephone, poste, disponibilite, heureTravail);
    bool test = emp.modifier();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("L'employé a été modifié avec succès."), QMessageBox::Ok);
        ui->tableView_employee->setModel(emp.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La modification de l'employé a échoué."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pb_pdf_clicked()
{
    // Ouvrir une boîte de dialogue pour sélectionner le chemin de sauvegarde du PDF
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        Employee emp;

        // Récupérer les données d'employé
        QSqlQueryModel *model = emp.afficher();

        // Vérifier si les données existent
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun employé à exporter.");
            delete model; // Libération de la mémoire
            return;
        }

        // Exporter vers PDF
        bool exportSuccess = emp.exporterPDF(nomFichier, model);

        // Libération de mémoire
        delete model;

        if (exportSuccess) {
            QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
        } else {
            QMessageBox::critical(this, "Erreur d'exportation", "L'exportation vers PDF a échoué.");
        }
    }
}


void MainWindow::on_pushButton_trier_clicked()
{
    qDebug() << "Trier button clicked"; // Debug message

    // Sort the employees by ID
    bool ascending = true; // Set to false if you want to sort in descending order
    ui->tableView_employee->setModel(emp.trierParID(ascending));
}


void MainWindow::on_pushButton_stats_clicked() {
    // Create an instance of Employee (or use an existing instance if you have one)
    Employee emp;

    // Get the availability statistics
    QHash<QString, int> stats = emp.statistiquesDisponibilite();

    // Format the statistics to display in a message box
    QString message = QString("Disponible: %1\nNon Disponible: %2")
                          .arg(stats["Disponible"])
                          .arg(stats["Non Disponible"]);

    // Display the statistics in a message box
    QMessageBox::information(this, "Statistiques de Disponibilité", message);
}



void MainWindow::on_pushButton_10_clicked()
{
    int id = ui->lineEdit_recherche->text().toInt();
    Employee emp;

    if (emp.chercherParID(id)) {
        QMessageBox::information(this, "Search Result", "Employee with ID " + QString::number(id) + " exists.");
    } else {
        QMessageBox::information(this, "Search Result", "Employee with ID " + QString::number(id) + " does not exist.");
    }
}



