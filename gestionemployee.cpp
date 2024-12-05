
#include "gestionemployee.h"
#include "ui_gestionemployee.h"  // Assurez-vous que cette inclusion est présente
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
#include <QSerialPortInfo>

GestionEmployee::GestionEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionEmployee),
    arduino(new Arduino(this))
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(true);
ui->stackedWidget_2->setVisible(false);
    // Connexion à l'Arduino
    if (!arduino->connectToArduino()) {
        QMessageBox::critical(this, tr("Erreur de connexion"), tr("Impossible de se connecter à l'Arduino."));
    }

    connect(arduino, &Arduino::dataReceived, this, &GestionEmployee::handleArduinoData);

    // Définir la page Home comme page actuelle
    ui->stackedWidget->setCurrentWidget(ui->pageHome);

    // Connecter les boutons à leurs slots
    connect(ui->buttonHome, &QPushButton::clicked, this, &GestionEmployee::on_buttonHome_clicked);
    connect(ui->buttonEmployee, &QPushButton::clicked, this, &GestionEmployee::on_buttonEmployee_clicked);
    connect(ui->buttonWelcome, &QPushButton::clicked, this, &GestionEmployee::on_buttonWelcome_clicked);
    connect(ui->buttonBackup, &QPushButton::clicked, this, &GestionEmployee::on_buttonBackup_clicked);
    connect(ui->pushButton_suivant, &QPushButton::clicked, this, &GestionEmployee::on_pushButton_suivant_clicked);
    connect(ui->verifyButton, &QPushButton::clicked, this, &GestionEmployee::on_verifyButton_clicked);
    connect(ui->yourPasswordButton, &QPushButton::clicked, this, &GestionEmployee::on_buttonForgotPassword2_clicked);
    connect(ui->pushButton_fermer, &QPushButton::clicked, this, &GestionEmployee::on_pushButton_fermer_clicked);
    connect(ui->yourPasswordButton, &QPushButton::clicked, this, &GestionEmployee::on_yourPasswordButton_clicked);
    connect(ui->tableView_employee, &QTableView::clicked, this, &GestionEmployee::on_tableView_employee_clicked);
    connect(ui->buttonClient, &QPushButton::clicked, this, &GestionEmployee::on_buttonClient_clicked);
    connect(ui->buttonProduct, &QPushButton::clicked, this, &GestionEmployee::on_buttonProduct_clicked);
    connect(ui->buttonOrder, &QPushButton::clicked, this, &GestionEmployee::on_buttonOrder_clicked);
    connect(ui->buttonEquipment, &QPushButton::clicked, this, &GestionEmployee::on_buttonEquipment_clicked);
   // connect(ui->pushButton_pdf, &QPushButton::clicked, this, &GestionEmployee::on_pushButton_pdf_clicked);

}

GestionEmployee::~GestionEmployee()
{
    arduino->disconnectFromArduino();
    delete ui;
}

void GestionEmployee::handleArduinoData(QString data)
{
    QString currentText = ui->lineEditID->text();
    currentText += data; // Ajouter le nouveau chiffre à ceux déjà présents
    ui->lineEditID->setText(currentText);
}

void GestionEmployee::on_pushButton_suivant_clicked() {
    // Enable and switch to Tab 3
    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setCurrentIndex(2);
}

void GestionEmployee::on_buttonForgotPassword2_clicked() {
    // Afficher le QStackedWidget
    ui->stackedWidget_2->setVisible(true);
}

void GestionEmployee::on_pushButton_fermer_clicked() {
    // Cacher le QStackedWidget
    ui->stackedWidget_2->setVisible(false);
}

void GestionEmployee::on_verifyButton_clicked()
{
    QString id = ui->lineEditID->text();

    // Requête pour vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE ID = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            ui->label_id_status->setText("L'ID existe.");
        } else {
            ui->label_id_status->setText("L'ID n'existe pas.");
        }
    } else {
        QMessageBox::critical(this, tr("Erreur de requête"), tr("Erreur lors de l'exécution de la requête."));
    }
}

void GestionEmployee::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    User user(username, password);

    if (user.authenticate()) {
        // Créer un objet de connexion et vérifier la connexion
        Connection connection;
        if (!connection.createconnect()) {
            QMessageBox::critical(this, tr("Database Connection Error"),
                                  tr("Failed to connect to the database.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
            return;
        }

        // Afficher la page appropriée en fonction du type d'utilisateur
        if (username == "admin") {
            ui->stackedWidget->setCurrentWidget(ui->pageEmployee);
            ui->tableView_employee->setModel(emp.afficher());
        } else if (username == "client") {
            ui->stackedWidget->setCurrentWidget(ui->pageClient);
            // Afficher les données clients dans le QTableView ou autre
        } else if (username == "produit") {
            ui->stackedWidget->setCurrentWidget(ui->pageProduit);
            // Afficher les données des produits dans le QTableView ou autre
        } else if (username == "commande") {
            ui->stackedWidget->setCurrentWidget(ui->pageCommande);
            // Afficher les données des commandes dans le QTableView ou autre
        } else if (username == "equipement") {
            ui->stackedWidget->setCurrentWidget(ui->pageEquipement);
            // Afficher les données des équipements dans le QTableView ou autre
        }

    } else {
        QMessageBox::critical(this, tr("Login Failed"),
                              tr("Invalid username or password."),
                              QMessageBox::Ok);
    }
}

void GestionEmployee::on_yourPasswordButton_clicked()
{
    QString username = ui->lineEditUsername_2->text();
    for (const User &user : User::userList) {
        if (user.getUsername() == username) {
            QMessageBox::information(this, tr("Your Password"), tr("Le mot de passe pour %1 est: %2").arg(username).arg(user.getPassword()));
            return;
        }
    }
    QMessageBox::warning(this, tr("Your Password"), tr("Utilisateur non trouvé."));
}

void GestionEmployee::on_buttonHome_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->pageHome);
}

void GestionEmployee::on_buttonEmployee_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->pageEmployee);
}




//----------------------------------------------------------------------------------------------------------------------------------------------------

void GestionEmployee::on_pushButton_ajouter_clicked()
{
    qDebug() << "Ajouter button clicked";

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, tr("Database Error"),
                              tr("The database connection is not open.\nPlease check your connection settings."),
                              QMessageBox::Ok);
        return;
    }

    QString idStr = ui->lineEdit_ID->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString poste = ui->lineEdit_poste->text();
    QString disponibilite = ui->lineEdit_disponibilite->text();
    QString heureTravail = ui->lineEdit_heureTravail->text();

    QRegularExpression idRegex("^[0-9]{1,5}$");
    QRegularExpressionValidator idValidator(idRegex);
    int idPos = 0;
    if (idValidator.validate(idStr, idPos) != QValidator::Acceptable) {
        QMessageBox::warning(this, tr("Invalid ID"), tr("The ID must be numeric and at most 5 digits long."));
        return;
    }

    int id = idStr.toInt();

    QRegularExpression loginRegex("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    QRegularExpressionValidator loginValidator(loginRegex);
    int loginPos = 0;
    if (loginValidator.validate(login, loginPos) != QValidator::Acceptable) {
        QMessageBox::warning(this, tr("Invalid Login"),
                             tr("The login must contain '@' and '.' characters and be in a valid format."));
        return;
    }

    qDebug() << "ID:" << id << "Nom:" << nom << "Prenom:" << prenom << "Login:" << login
             << "Password:" << password << "Telephone:" << telephone << "Poste:" << poste
             << "Disponibilite:" << disponibilite << "HeureTravail:" << heureTravail;

    Employee nouveauEmployee(id, nom, prenom, login, password, telephone, poste, disponibilite, heureTravail);
    bool test = nouveauEmployee.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("L'employé a été ajouté avec succès."), QMessageBox::Ok);
        backupToFile(nouveauEmployee);
        ui->tableView_employee->setModel(nouveauEmployee.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout de l'employé a échoué."), QMessageBox::Cancel);
    }
}

void GestionEmployee::backupToFile(const Employee& employee) {
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

void GestionEmployee::on_buttonBackup_clicked()
{
    QString filename = "backup.txt";
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(filename))) {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de l'ouverture du fichier de sauvegarde."));
    }
}

void GestionEmployee::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    Employee emp;

    bool test = emp.supprimer(id);
    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);
        ui->tableView_employee->setModel(emp.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}





void GestionEmployee::on_pushButton_modifier_clicked()
{
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
/*
void GestionEmployee::on_pb_pdf_clicked()
{
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        Employee emp;
        QSqlQueryModel *model = emp.afficher();

        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun employé à exporter.");
            delete model;
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
*/
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>

void GestionEmployee::on_pushButton_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le PDF"), "", tr("PDF Files (*.pdf);;All Files ()"));
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);

    int y = 100; // Position verticale de départ
    int page = 1; // Numéro de la page

    // Titre
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(100, y, tr("Liste des Employés"));

    // Date (déplacée légèrement à gauche)
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");
    painter.setFont(QFont("Arial", 12));
    painter.drawText(pdfWriter.width() - 500, y, tr("Date : ") + currentDate);

    // Ligne sous le titre
    y += 50;
    painter.drawLine(100, y, pdfWriter.width() - 100, y);

    y += 50; // Espace après le titre

    // En-têtes avec fond coloré
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setBrush(Qt::lightGray);

    // Colonnes
    painter.drawRect(100, y, 300, 240); // ID
    painter.drawText(110, y + 140, tr("ID"));

    painter.drawRect(400, y, 300, 240); // Nom
    painter.drawText(410, y + 140, tr("Nom"));

    painter.drawRect(700, y, 300, 240); // Prénom
    painter.drawText(710, y + 140, tr("Prénom"));

    painter.drawRect(1000, y, 300, 240); // Login
    painter.drawText(1010, y + 140, tr("Login"));

    painter.drawRect(1300, y, 300, 240); // Téléphone
    painter.drawText(1310, y + 140, tr("Téléphone"));

    painter.drawRect(1600, y, 300, 240); // Poste
    painter.drawText(1610, y + 140, tr("Poste"));

    painter.drawRect(1900, y, 300, 240); // Disponibilité
    painter.drawText(1910, y + 140, tr("Disponibilité"));

    painter.drawRect(2200, y, 300, 240); // Heure de Travail
    painter.drawText(2210, y + 140, tr("Heure de Travail"));

    y += 240; // Ligne suivante

    // Remplissage des lignes du tableau
    painter.setFont(QFont("Arial", 10));
    painter.setBrush(Qt::NoBrush); // Pas de fond pour les cellules
    QSqlQuery query("SELECT IDEMPLOYE, NOMEMPLOYE, PRENOMEMPLOYE, LOGIN, TELEPHONEEMPLOYE, POSTEEMPLOYE, DISPONIBILITE, HEUREDETRAVAIL FROM EMPLOYE");
    while (query.next()) {
        if (y > pdfWriter.height() - 200) { // Vérification si la page est pleine
            painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));
            pdfWriter.newPage();
            y = 100; // Réinitialisation de la position
            page++;
        }

        // ID
        painter.drawRect(100, y, 300, 240);
        painter.drawText(110, y + 140, query.value("IDEMPLOYE").toString());

        // Nom
        painter.drawRect(400, y, 300, 240);
        painter.drawText(410, y + 140, query.value("NOMEMPLOYE").toString());

        // Prénom
        painter.drawRect(700, y, 300, 240);
        painter.drawText(710, y + 140, query.value("PRENOMEMPLOYE").toString());

        // Login
        painter.drawRect(1000, y, 300, 240);
        painter.drawText(1010, y + 140, query.value("LOGIN").toString());

        // Téléphone
        painter.drawRect(1300, y, 300, 240);
        painter.drawText(1310, y + 140, query.value("TELEPHONEEMPLOYE").toString());

        // Poste
        painter.drawRect(1600, y, 300, 240);
        painter.drawText(1610, y + 140, query.value("POSTEEMPLOYE").toString());

        // Disponibilité
        painter.drawRect(1900, y, 300, 240);
        painter.drawText(1910, y + 140, query.value("DISPONIBILITE").toString());

        // Heure de Travail
        painter.drawRect(2200, y, 300, 240);
        painter.drawText(2210, y + 140, query.value("HEUREDETRAVAIL").toString());

        y += 240; // Ligne suivante
    }

    // Ajouter le numéro de page
    painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));

    painter.end();
    QMessageBox::information(this, tr("PDF généré"), tr("Le fichier PDF a été généré avec succès."));
}




void GestionEmployee::on_pushButton_trier_clicked()
{
    qDebug() << "Trier button clicked";

    bool ascending = true; // Changer à `false` pour trier par ordre décroissant
    ui->tableView_employee->setModel(emp.trierParID(ascending));
}

void GestionEmployee::on_pushButton_11_clicked()
{
    int id = ui->lineEdit_recherche->text().toInt();
    Employee emp;

    if (emp.chercherParID(id)) {
        QMessageBox::information(this, "Search Result", "Employee with ID " + QString::number(id) + " exists.");
    } else {
        QMessageBox::information(this, "Search Result", "Employee with ID " + QString::number(id) + " does not exist.");
    }
}

void  GestionEmployee::on_pushButton_stats_clicked(){

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
    while ((item = ui->verticalLayout_11->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }


    ui->verticalLayout_11->addWidget(chartView);



    qDebug() << "Statistiques mises à jour et graphique actualisé.";
}

void GestionEmployee::on_tableView_employee_clicked(const QModelIndex &index)
{
    int row = index.row();
    QAbstractItemModel *model = ui->tableView_employee->model();

    ui->lineEdit_ID->setText(model->data(model->index(row, 0)).toString());
    ui->lineEdit_nom->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_prenom->setText(model->data(model->index(row, 2)).toString());
    ui->lineEdit_login->setText(model->data(model->index(row, 3)).toString());
    ui->lineEdit_password->setText(model->data(model->index(row, 4)).toString());
    ui->lineEdit_telephone->setText(model->data(model->index(row, 5)).toString());
    ui->lineEdit_poste->setText(model->data(model->index(row, 6)).toString());
    ui->lineEdit_disponibilite->setText(model->data(model->index(row, 7)).toString());
   ui->lineEdit_heureTravail->setDate(QDate::fromString(model->data(model->index(row, 8)).toString(), "yyyy-MM-dd"));
}
void GestionEmployee::on_buttonClient_clicked() {
    // Afficher la page des clients
    ui->stackedWidget->setCurrentWidget(ui->pageClient);
    qDebug() << "Page de gestion des client affichée.";
}
void GestionEmployee::on_buttonProduct_clicked() {
    // Afficher la page des produits
    ui->stackedWidget->setCurrentWidget(ui->pageProduit);
    qDebug() << "Page de gestion des produits affichée.";
}
void GestionEmployee::on_buttonOrder_clicked() {
    // Afficher la page des commandes
    ui->stackedWidget->setCurrentWidget(ui->pageCommande);
    qDebug() << "Page de gestion des commandes affichée.";
}
void GestionEmployee::on_buttonEquipment_clicked() {
    // Afficher la page des équipements
    ui->stackedWidget->setCurrentWidget(ui->pageEquipement);
    qDebug() << "Page de gestion des équipements affichée.";
}

