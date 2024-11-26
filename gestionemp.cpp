#include "gestionemp.h"
#include "ui_gestionemp.h"
#include "user.h"
#include <QMessageBox>
#include <QDebug>
#include "employee.h"
#include "connection.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDialog>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set Tab 1 (Login) as the current tab
    ui->tabWidget->setCurrentIndex(0);

    // Disable Tab 2 initially
    ui->tabWidget->setTabEnabled(1, false);

    // Connect the welcome button signal to the slot
    connect(ui->buttonWelcome, &QPushButton::clicked, this, &MainWindow::on_buttonWelcome_clicked);

    // Connect the backup button signal to the slot
    connect(ui->buttonBackup, &QPushButton::clicked, this, &MainWindow::on_buttonBackup_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    User user(username, password);

    if (user.authenticate()) {
        // Enable and switch to Tab 2
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setCurrentIndex(1);

        // Disable Tab 1
        ui->tabWidget->setTabEnabled(0, false);

        // Create a connection object and check the connection
        Connection connection;
        if (!connection.createconnect()) {
            QMessageBox::critical(this, tr("Database Connection Error"),
                                  tr("Failed to connect to the database.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
            return;
        }

        // Display employees in the QTableView at startup
        ui->tableView_employee->setModel(emp.afficher());

    } else {
        QMessageBox::critical(this, tr("Login Failed"),
                              tr("Invalid username or password."),
                              QMessageBox::Ok);
    }
}
void MainWindow::on_buttonForgotPassword_clicked()
{
    QString passwords;

    for (const User &user : User::userList) {
        passwords += "Username: " + user.getUsername() + ", Password: " + user.getPassword() + "\n";
    }

    QMessageBox::information(this, tr("Passwords List"), passwords);
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Ajouter button clicked";

    // Check if the database is open before executing the query
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        QMessageBox::critical(this, tr("Database Error"),
                              tr("The database connection is not open.\nPlease check your connection settings."),
                              QMessageBox::Ok);
        return;
    }

    // Retrieve employee information from input fields
    QString idStr = ui->lineEdit_ID->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString poste = ui->lineEdit_poste->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString heureTravail = ui->lineEdit_heureTravail->text();

    // Validate ID
    QRegularExpression idRegex("^[0-9]{1,5}$");
    QRegularExpressionValidator idValidator(idRegex);
    int idPos = 0;
    if (idValidator.validate(idStr, idPos) != QValidator::Acceptable) {
        QMessageBox::warning(this, tr("Invalid ID"), tr("The ID must be numeric and at most 5 digits long."));
        return;
    }

    int id = idStr.toInt();

    // Validate Login
    QRegularExpression loginRegex("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    QRegularExpressionValidator loginValidator(loginRegex);
    int loginPos = 0;
    if (loginValidator.validate(login, loginPos) != QValidator::Acceptable) {
        QMessageBox::warning(this, tr("Invalid Login"), tr("The login must contain '@' and '.' characters and be in a valid format."));
        return;
    }

    qDebug() << "ID:" << id << "Nom:" << nom << "Prenom:" << prenom << "Login:" << login << "Password:" << password
             << "Telephone:" << telephone << "Poste:" << poste << "Disponibilite:" << disponibilite << "HeureTravail:" << heureTravail;

    // Create an Employee object and add to the database
    Employee nouveauEmployee(id, nom, prenom, login, password, telephone, poste, disponibilite, heureTravail);
    bool test = nouveauEmployee.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("L'employé a été ajouté avec succès."), QMessageBox::Ok);

        // Call backup function
        backupToFile(nouveauEmployee);

        // Refresh the display in the QTableView
        ui->tableView_employee->setModel(nouveauEmployee.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout de l'employé a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::backupToFile(const Employee& employee) {
    QFile file("backup.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "ID: " << employee.getID() << "\n";
        out << "Nom: " << employee.getNom() << "\n";
        out << "Prénom: " << employee.getPrenom() << "\n";
        out << "Login: " << employee.getLogin() << "\n";
        out << "Mot de passe: " << employee.getPassword() << "\n";
        out << "Téléphone: " << employee.getTelephone() << "\n";
        out << "Poste: " << employee.getPoste() << "\n";
        out << "Disponibilité: " << employee.getDisponibilite() << "\n";
        out << "Heures de travail: " << employee.getHeureTravail() << "\n";
        out << "----------------------------------------\n";
        file.close();
        qDebug() << "Sauvegarde réussie dans backup.txt";
    } else {
        qDebug() << "Erreur lors de l'ouverture du fichier de sauvegarde";
    }
}

void MainWindow::on_buttonBackup_clicked()
{
    QString filename = "backup.txt";
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(filename))) {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de l'ouverture du fichier de sauvegarde."));
    }
}

//--------------------------------------------------------------------------------------------------------

void MainWindow::on_pushButton_supprimer_clicked()
{
    qDebug() << "Supprimer button clicked";


    int id = ui->lineEdit_ID->text().toInt();
    bool test = emp.supprimer(id);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);

        ui->tableView_employee->setModel(emp.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked() {
    qDebug() << "Modifier button clicked";


    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString poste = ui->lineEdit_poste->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString heureTravail = ui->lineEdit_heureTravail->text();


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

    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        Employee emp;


        QSqlQueryModel *model = emp.afficher();


        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun employé à exporter.");
            delete model; // Libération de la mémoire
            return;
        }


        bool exportSuccess = emp.exporterPDF(nomFichier, model);


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



void MainWindow::on_pushButton_stats_clicked(){

    Employee emp;


    QMap<QString, int> statistiques = emp.statistiquesDisponibilite();

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }


    QPieSeries *series = new QPieSeries();
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(it.value()), it.value());


        if (series->slices().size() % 2 == 0) {
            slice->setBrush(QColor(173, 216, 230));
        } else {
            slice->setBrush(QColor(152, 251, 152));
        }


        slice->setLabelVisible(true);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des employés par disponibilité");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QFont titleFont;
    titleFont.setPixelSize(20);
    titleFont.setBold(true);
    titleFont.setItalic(false);
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(QColor(152, 251, 152)));

    // Customize the labels
    QFont labelFont;
    labelFont.setPixelSize(16); // Label size
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelFont(labelFont);
        slice->setLabelBrush(QBrush(QColor(152, 251, 152))); // Label color (pastel green)
    }


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QLayoutItem *item;
    while ((item = ui->verticalLayout_4->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }


    ui->verticalLayout_4->addWidget(chartView);



    qDebug() << "Statistiques mises à jour et graphique actualisé.";
}


