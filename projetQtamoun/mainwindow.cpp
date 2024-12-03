#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "produits.h"
#include <QSqlQuery>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QDebug>
#include "delegatedeuxbouttons.h"
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QMessageBox>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "arduino.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    arduino(new Arduino())

{
    ui->setupUi(this);


    produits p;
    QSqlQueryModel *model = p.afficherProduits();
    ui->tableauproduits->setModel(model);
    ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    chartView = nullptr;

    delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
    ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);

    connect(ui->bouttonrecherche, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);


    connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
    connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);

    loadHistoriqueFile();
    ui->bouttonnotification->setIcon(QIcon("C:/Users/user/Desktop/projetQtEmna/images/notification.png"));
    verifierproduitexpire();
    // for test puposes
    arduino->setPortName("COM3"); // Set the correct port
    if (arduino->connect_arduino() == 0) {
        qDebug() << "Successfully opened port COM3";
    } else {
        qDebug() << "Failed to connect to Arduino.";
        return;
    }

    /* int ret=arduino->connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< arduino->getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<arduino->getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }*/
}

MainWindow::~MainWindow()
{
    arduino->close_arduino();
    delete ui;
    delete arduino;
}
void MainWindow::onMessageReceived(const QByteArray &data)
{
    ui->outputText->append("donnée: " + data);
    qDebug() << "Données reçues d'Arduino:" << data;
}
void MainWindow::readSerialData()
{
    QByteArray data = arduino->read_from_arduino();
    qDebug() << "Données reçues d'Arduino :" << data;

    if (!data.isEmpty()) {
        ui->label->setText(data);
    }
}
void MainWindow::loadHistoriqueFile()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/historique.txt";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    ui->textHistorique->setPlainText(content);
}
void MainWindow::on_buttongererProduit_clicked()
{
    produits p;
    ui->stackedwidgetmainbody->setCurrentWidget(ui->pagegererproduits);
    ui->stackedWidgetgererproduit->setCurrentWidget(ui->pageafficherproduits);
    ui->tableauproduits->setModel(p.afficherProduits());
}
void MainWindow::afficherstatistiquesproduits() {
    QStringList categories;
    QVector<int> nbrproduits(31, 0);

    QSqlQuery query;
    query.prepare("SELECT EXTRACT(DAY FROM dateajout) AS jour, COUNT(*) AS nombre_produits "
                  "FROM Produits "
                  "WHERE EXTRACT(MONTH FROM dateajout) = EXTRACT(MONTH FROM SYSDATE) "
                  "AND EXTRACT(YEAR FROM dateajout) = EXTRACT(YEAR FROM SYSDATE) "
                  "GROUP BY EXTRACT(DAY FROM dateajout) "
                  "ORDER BY jour");

    if (query.exec()) {
        while (query.next()) {
            int jour = query.value(0).toInt();
            int nombre = query.value(1).toInt();
            nbrproduits[jour - 1] = nombre;
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des statistiques.");
        return;
    }

    if (chartView) {
        delete chartView;
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Produits Ajoutés");
    for (int count : nbrproduits) {
        *set << count;
    }
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);

    QString moisActuel = QDate::currentDate().toString("MMMM");

    chart->setTitle("Produits Ajoutés par Jour - " + moisActuel);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    for (int i = 1; i <= 31; ++i) {
        categories << QString::number(i);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    int maxValue = *std::max_element(nbrproduits.begin(), nbrproduits.end()) + 1;

    axisY->setRange(0, maxValue);
    axisY->setTickCount(maxValue);
    axisY->setMinorTickCount(0);

    int interval = maxValue / 10 + 1;
    axisY->setTickInterval(interval);

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if (!ui->pagestatistiques->layout()) {
        ui->pagestatistiques->setLayout(new QVBoxLayout());
    }
    ui->pagestatistiques->layout()->addWidget(chartView);
}






void MainWindow::on_bouttonstatistiques_clicked()
{
    ui->stackedWidgetgererproduit->setCurrentWidget(ui->pagestatistiques);
    afficherstatistiquesproduits();

}

void MainWindow::on_bouttonajouterproduit_clicked()
{
    ui->stackedWidgetgererproduit->setCurrentWidget(ui->pageafficherproduits);
    ui->stackedWidgetmodifierajout->setCurrentWidget(ui->formajout);




}

void MainWindow::on_bouttonacceuil_clicked()
{
    ui->stackedwidgetmainbody->setCurrentWidget(ui->pageacceuil);
}

void MainWindow::on_bouttonafficherproduits_clicked()
{
    ui->stackedWidgetgererproduit->setCurrentWidget(ui->pageafficherproduits);
}

void MainWindow::on_bouttonmodifierproduit_clicked()
{
}

void MainWindow::on_bouttonconfirmerajout_clicked()
{
    QString nomProduit = ui->inputnomproduit_2->text();
    QDate dateExpiration = ui->inputdateexpiration_2->date();
    int quantiteDisponible = ui->inputquantitedisponible_2->text().toInt();
    int humidite = ui->inputhumidite_2->text().toInt();
    QDate dateDebut = ui->inputdatedebut_2->date();
    int temperature = ui->inputtemperature_2->text().toInt();

    // Validation des champs
    if (nomProduit.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Nom du produit est requis.");
        return;
    }

    if (!dateExpiration.isValid() || dateExpiration <= dateDebut) {
        QMessageBox::warning(this, "Erreur", "Date d'expiration invalide.");
        return;
    }

    // Création et ajout du produit
    produits produitToAdd(nomProduit, dateExpiration, quantiteDisponible, humidite, temperature, dateDebut);
    if (produitToAdd.ajouterProduit(produitToAdd)) {
        //QMessageBox::information(this, "Succès", "Produit ajouté avec succès!");

        // Check if temperature exceeds 30 degrees

        // Send command to turn ON the fan
        int resultat=arduino->write_to_arduino("g");
        qDebug() << "Sent command to turn ON the fan.";
        if (resultat == 0) {
            qDebug() << "Sent command to turn ON the fan.";
        }
        else {
            qDebug() << "not Sent command to turn ON the fan.";
        }
        // Mettre à jour le tableau des produits
        ui->tableauproduits->setModel(produits().afficherProduits());

        // Historique
        historique("Ajout", nomProduit, "Quantité: " + QString::number(quantiteDisponible));

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}
// tri
void MainWindow::on_menutri_currentIndexChanged(int index)
{
    produits p;
    QSqlQueryModel* model = p.trierProduits(index);
    ui->tableauproduits->setModel(model);
    historique("Tri", "Produits", "Critère: " + QString::number(index));

}

// confirmer la suppression
void MainWindow::on_bouttonconfirmersupprimerproduit_clicked()
{

}



void MainWindow::on_pushButton_5_clicked() {
    bool quantiteOk, humiditeOk, temperatureOk;
    int idproduit = ui->inputidproduitmodif->text().toInt();
    QString nomProduit = ui->inputnomproduit_3->text();
    QDate dateExpiration = ui->inputdateexpiration_3->date();
    int quantiteDisponible = ui->inputquantitedisponible_3->text().toInt(&quantiteOk);
    int humidite = ui->inputhumidite_3->text().toInt(&humiditeOk);
    QDate dateDebut = ui->inputdatedebut_3->date();
    int temperature = ui->inputtemperature_3->text().toInt(&temperatureOk);

    if (nomProduit.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Nom du produit est requis");
        return;
    }

    // Validate the dates
    if (dateExpiration <= dateDebut) {
        QMessageBox::warning(this, "Erreur", "La date d'expiration doit être après la date de début.");
        return;
    }
    if (!dateDebut.isValid()) {
        QMessageBox::warning(this, "Erreur", "Date début invalide.");
        return;
    }

    // Validate integer inputs
    if (!quantiteOk) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un entier.");
        return;
    }
    if (!humiditeOk) {
        QMessageBox::warning(this, "Erreur", "L'humidité doit être un entier.");
        return;
    }
    if (!temperatureOk) {
        QMessageBox::warning(this, "Erreur", "La température doit être un entier.");
        return;
    }

    QDate dateajout = QDate::currentDate();

    produits p;
    if (!p.modifierProduits(idproduit, nomProduit, dateExpiration, quantiteDisponible, humidite, temperature, dateDebut, dateajout)) {
        QMessageBox::warning(this, "Erreur", "La mise à jour du produit a échoué.");
    } else {
        QMessageBox::information(this, "Succès", "Le produit a été modifié avec succès.");
        historique("Modification", nomProduit,"");

        ui->tableauproduits->setModel(p.afficherProduits());
        ui->inputidproduitmodif->clear();
        ui->inputnomproduit_3->clear();
        ui->inputdateexpiration_3->setDate(QDate::currentDate());

        ui->inputquantitedisponible_3->clear();
        ui->inputhumidite_3->clear();
        ui->inputdatedebut_3->setDate(QDate::currentDate());
        ui->inputtemperature_3->clear();


    }
}

// Afficher produit a modifier change rq a supprime
void MainWindow::on_pushButton_7_clicked()
{

}
void MainWindow::on_buttongererClient_clicked(){}
void MainWindow::on_pushButton_6_clicked(){
    bool quantiteOk, humiditeOk, temperatureOk;
    int etat=0;
    QString nomProduit = ui->inputnomproduit_2->text();
    QDate dateExpiration = ui->inputdateexpiration_2->date();
    int quantiteDisponible = ui->inputquantitedisponible_2->text().toInt(&quantiteOk);
    int humidite = ui->inputhumidite_2->text().toInt(&humiditeOk);
    QDate dateDebut = ui->inputdatedebut_2->date();
    int temperature = ui->inputtemperature_2->text().toInt(&temperatureOk);
    // controle saisie str
    if (nomProduit.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Nom du produit est requis");
        return;
    }
    // controle saisie des dates
    if (!dateExpiration.isValid() || dateExpiration <= dateDebut) {
        QMessageBox::warning(this, "Erreur", "Date d'expiration requise");
        return;
    }
    if (!dateDebut.isValid() ||dateExpiration<=dateDebut ) {
        QMessageBox::warning(this, "Erreur", "Date debut requise");
        return;
    }

    // controler de saisie des valeurs int
    if (!quantiteOk) {
        QMessageBox::warning(this, "Erreur", "La quantite doit être un entier");
        return;
    }
    if (!humiditeOk) {
        QMessageBox::warning(this, "Erreur", "L'humidite doit être un entier");
        return;
    }
    if (!temperatureOk) {
        QMessageBox::warning(this, "Erreur", "La temperature doit être un entier");
        return;
    }
    QDate dateAjout = QDate::currentDate();

    if(temperature>30){
        etat=1;
        produits produitToAdd(nomProduit, dateExpiration, quantiteDisponible, humidite, temperature, dateDebut,dateAjout,etat);
        int resultat=arduino->write_to_arduino("g");
        qDebug() << "Sent command to turn ON the fan.";
        produitToAdd.ajouterProduit(produitToAdd);
        if (resultat == 0) {
            qDebug() << "Sent command to turn ON the fan.";
        }
        else {
            qDebug() << "not Sent command to turn ON the fan.";
        }
        ui->tableauproduits->setModel(produits().afficherProduits());
        historique("Ajout+Etat", nomProduit,"");

    }

    else if (temperature<=30) {
        produits produitToAdd(nomProduit, dateExpiration, quantiteDisponible, humidite, temperature, dateDebut,dateAjout,etat);
        int resultat=arduino->write_to_arduino("s");
        qDebug() << "Sent command to turn OFF the fan.";
        produitToAdd.ajouterProduit(produitToAdd);
        if (resultat == 0) {
            qDebug() << "Sent command to turn OFF the fan.";
        }
        else {
            qDebug() << "not Sent command to turn OFF the fan.";
        }
        ui->tableauproduits->setModel(produits().afficherProduits());
        historique("Ajout", nomProduit,"");
    }

    ui->inputnomproduit_2->clear();
    ui->inputdateexpiration_2->clear();
    ui->inputquantitedisponible_2->clear();
    ui->inputhumidite_2->clear();
    ui->inputdatedebut_2->clear();
    ui->inputtemperature_2->clear();

}

void MainWindow::onModifierClicked(int ligne)
{
    ui->stackedWidgetmodifierajout->setCurrentWidget(ui->formmodifier);

    qDebug() << "Modifier a la ligne:" << ligne;

    int productId = ui->tableauproduits->model()->index(ligne, 0).data().toInt();
    ui->inputidproduitmodif->setText(QString::number(productId));
    qDebug() << "Modifier product id:" << productId;

    QString nomProduit = ui->tableauproduits->model()->index(ligne, 1).data().toString();
    ui->inputnomproduit_3->setText(nomProduit);

    QDate dateExpiration = ui->tableauproduits->model()->index(ligne, 2).data().toDate();
    ui->inputdateexpiration_3->setDate(dateExpiration);
    qDebug() << "Modifier dateExpiration:" << dateExpiration;

    int humidite = ui->tableauproduits->model()->index(ligne, 3).data().toInt();
    ui->inputhumidite_3->setText(QString::number(humidite));

    int quantiteDisponible = ui->tableauproduits->model()->index(ligne, 4).data().toInt();
    ui->inputquantitedisponible_3->setText(QString::number(quantiteDisponible));

    QDate dateDebut = ui->tableauproduits->model()->index(ligne, 6).data().toDate();
    ui->inputdatedebut_3->setDate(dateDebut);

    QString temperature = ui->tableauproduits->model()->index(ligne, 5).data().toString();
    ui->inputtemperature_3->setText(temperature);

    qDebug() << "input temperature:" << temperature;

}

void MainWindow::onSupprimerClicked(int ligne)
{

    qDebug() << "Supprimer boutton a la ligne " << ligne;


    int productId = ui->tableauproduits->model()->index(ligne, 0).data().toInt();

    qDebug() << "Supprimer boutton a la ligne du id produit " << productId;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce produit?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        produits p;
        if (p.supprimerProduits(productId)) {
            QMessageBox::information(this, "Succès", "Produit supprimé avec succès.");
            ui->tableauproduits->setModel(produits().afficherProduits());

        } else {
            QMessageBox::warning(this, "Erreur", "Échec de suppression.");
        }
    }
}

int nbrproduits(const QString& req) {
    QSqlQuery query;
    query.exec(req);
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

void MainWindow::on_bouttonpdffile_clicked()
{
    QString dateAct = QDate::currentDate().toString("dd/MM/yyyy");

    int nbrproduitsajoutes = nbrproduits("SELECT COUNT(*) FROM Produits WHERE dateajout <= CURDATE()");

    int nbrproduitsexp = nbrproduits("SELECT COUNT(*) FROM Produits WHERE TRUNC(dateExpiration) < TRUNC(SYSDATE)");

    QString html =
        "<div align=right>"
        + dateAct +
        "</div>"
        "<h1 align=center>STOCK PRODUITS</h1>"
        "<p align=justify>"
        "Nombre de produits ajoutés: " + QString::number(nbrproduitsajoutes) + "<br>"
                                                "Nombre de produits expirés : " + QString::number(nbrproduitsexp) + "<br>"
                                            "</p>";

    QTextDocument document;
    document.setHtml(html);

    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf);;All Files (*)");

    if (!filePath.isEmpty()) {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);
        printer.setPageMargins(QMarginsF(15, 15, 15, 15));
        printer.setPageSize(QPageSize::A4);

        document.print(&printer);

        QMessageBox::information(this, "PDF", "PDF rapport génére avec success!");
    } else {
        QMessageBox::warning(this, "PDF", "pas de ficher selection ");
    }
}

void MainWindow::historique(const QString &action, const QString &nomProduit, const QString &details) {
    QString filePath = QCoreApplication::applicationDirPath() + "/historique.txt";

    QFile file(filePath);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "fichier historique vide");
        return;
    }

    QTextStream out(&file);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    out << timestamp << " - Action: " << action << " - Produit: " << nomProduit << " - " << details << "\n";
    file.close();
}


void MainWindow::on_bouttonhistorique_clicked() {
    ui->stackedWidgetgererproduit->setCurrentWidget(ui->pagehistorique);

    QString filePath = QCoreApplication::applicationDirPath() + "/historique.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur","fichier historique vide");
        return;
    }

    QTextStream in(&file);
    QString historiqueContent = in.readAll();
    file.close();

    ui->textHistorique->setPlainText(historiqueContent);
}


void MainWindow::verifierproduitexpire() {
    QSqlQuery req;
    req.prepare("SELECT COUNT(*) FROM Produits WHERE dateExpiration < CURRENT_DATE");
    req.exec();

    if (req.next()) {
        int expiredCount = req.value(0).toInt();
        if (expiredCount > 0) {
            ui->bouttonnotification->setStyleSheet("background-color: red;border:none;");
        }
    }
}
void MainWindow::on_bouttonnotification_clicked()
{
    ui->bouttonnotification->setStyleSheet("");

    QSqlQuery query;
    query.prepare("SELECT nomproduit , dateexpiration FROM produits WHERE TO_DATE(dateExpiration, 'DD-MM-YY') < SYSDATE;");
    if (query.exec()) {
        QString produitsexpries;
        while (query.next()) {
            QString nomProduit = query.value(0).toString();
            QDate dateexpiration = query.value(1).toDate();
            produitsexpries += "Produit: " + nomProduit + " | Date d'expiration: " + dateexpiration.toString() + "\n";
        }

        if (!produitsexpries.isEmpty()) {
            QMessageBox::information(this, "Produits Expires", produitsexpries);
        } else {
            QMessageBox::information(this, "Aucun produit expire", "pas de produits expires.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "erreur produits expires.");
    }
}


void MainWindow::on_bouttonrecherche_clicked() {
    produits p;
    QString cle = ui->clerecherche->text();
    qDebug() << "cle:" << cle;

    QSqlQueryModel* model = p.rechercheparnomproduit(cle);

    if (model) {
        ui->tableauproduits->setModel(model);
    } else {
        qDebug() << "pas de model";
    }
}


void MainWindow::sendToArduino(Arduino &arduino, const QString &message) {
    QByteArray data = message.toUtf8();
    if (arduino.write_to_arduino(data) != -1) {
        qDebug() << "Message sent to Arduino: " << message;
    } else {
        qDebug() << "Failed to send message to Arduino!";
    }
}

void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageInput->text();  // Get message from the input field
}
void MainWindow::onReceiveData(const QByteArray &data) {
    qDebug() << "Received from Arduino:" << data;
    ui->outputText->append(data);  // Append received data to QTextEdit
}

void MainWindow::on_searchButton_clicked() {
    QString productName = ui->clerecherche->text(); // Récupérer le nom du produit

    if (productName.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom de produit.");
        return;
    }

    // Appeler la méthode rechercheparnomproduit pour récupérer les données
    QSqlQueryModel* model = produits().rechercheparnomproduit(productName);

    if (model == nullptr || model->rowCount() == 0) { // Vérifiez si le produit existe
        QMessageBox::warning(this, "Erreur", "Produit non trouvé.");
        return;
    }

    // Supposons que la colonne "temperature" est à l'index 4 dans le résultat de la requête
    QModelIndex temperatureIndex = model->index(0, 5);
    int temperature = model->data(temperatureIndex).toInt();

    // Afficher la température récupérée
    QMessageBox::information(this, "Température trouvée", QString("La température du produit %1 est %2°C").arg(productName).arg(temperature));

    // Contrôler le ventilateur en fonction de la température
    if (temperature > 30) {
        sendToArduino(*arduino, "g"); // Allumer le ventilateur
        QMessageBox::information(this, "Ventilateur activé", "Température élevée. Le ventilateur a été activé.");
    } else {
        sendToArduino(*arduino, "s"); // Éteindre le ventilateur
        QMessageBox::information(this, "Ventilateur désactivé", "Température normale. Le ventilateur a été éteint.");
    }

    // Nettoyage
    delete model;
}

