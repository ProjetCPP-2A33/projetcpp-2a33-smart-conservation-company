/*#include "gestionemp.h"
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
    ui->tabclient->setCurrentIndex(0);

    // Disable Tab 2 initially
    ui->tabclient->setTabEnabled(1, false);

    // Connect the welcome button signal to the slot
    connect(ui->buttonWelcome, &QPushButton::clicked, this, &MainWindow::on_buttonWelcome_clicked);

    // Connect the backup button signal to the slot
    connect(ui->buttonBackup, &QPushButton::clicked, this, &MainWindow::on_buttonBackup_clicked);
    connect(ui->pushButton_suivant, &QPushButton::clicked, this, &MainWindow::on_pushButton_suivant_clicked);
    ui->tabclient->setTabEnabled(2, false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_suivant_clicked() {
    // Enable and switch to Tab 3
    ui->tabclient->setTabEnabled(2, true);
    ui->tabclient->setCurrentIndex(2);
*/
//--------------------
//pour le pdf
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

//recheche
#include <QSqlError>
//statistique
#include <QtCharts>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
// statistiques
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QGraphicsScene>
#include <QPieSeries>
#include <QPieSlice>
#include <QRandomGenerator>
//sms
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <QRegularExpression>
//tsawer
#include <QPixmap>
//bar chart
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
//excel
#include <QAxObject>
#include<Client.h>
//--------------------
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
#include "arduino.h"
#include <QSerialPortInfo>

//----------------------gestion produit-------------------------------

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
//----------- include pour gestion equipement
#include "equipement.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QSqlRecord>
#include <QPainter>
#include <QPageSize>
#include <QSqlError>
#include <QVariant>
#include <QFileDialog>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QPen>

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setVisible(false);
    arduino = new Arduino(this);
    if (!arduino->connectToArduino()) {
        QMessageBox::critical(this, tr("Erreur de connexion"), tr("Impossible de se connecter à l'Arduino."));
    }

    connect(arduino, &Arduino::dataReceived, this, &MainWindow::handleArduinoData);

    // Set Tab 1 (Login) as the current tab
    ui->tabclient->setCurrentIndex(0);

    // Disable Tab 2 and Tab 3 initially
    ui->tabclient->setTabEnabled(1, false);
    ui->tabclient->setTabEnabled(2, false);
     // Connect the welcome button signal to the slot
    connect(ui->buttonWelcome, &QPushButton::clicked, this, &MainWindow::on_buttonWelcome_clicked);

    // Connect the backup button signal to the slot
    connect(ui->buttonBackup, &QPushButton::clicked, this, &MainWindow::on_buttonBackup_clicked);

    // Connect 'pushButton_suivant' to the slot 'on_pushButton_suivant_clicked'
    connect(ui->pushButton_suivant, &QPushButton::clicked, this, &MainWindow::on_pushButton_suivant_clicked);

    // Connect verify button to the slot
    connect(ui->verifyButton, &QPushButton::clicked, this, &MainWindow::on_verifyButton_clicked);
    // Connect 'forgot your password2' button to the slot 'on_buttonForgotPassword2_clicked'
    connect(ui->yourPasswordButton, &QPushButton::clicked, this, &MainWindow::on_buttonForgotPassword2_clicked);
    // Connect 'fermer' button to the slot 'on_buttonFermer_clicked'
    connect(ui->pushButton_fermer, &QPushButton::clicked, this, &MainWindow::on_pushButton_fermer_clicked);
    connect(ui->yourPasswordButton, &QPushButton::clicked, this, &MainWindow::on_yourPasswordButton_clicked);
     connect(ui->tableView_employee, &QTableView::clicked, this, &MainWindow::on_tableView_employee_clicked);
    //***************************************************************
    //CLIENT
    ui->tabclient->setTabEnabled(ui->tabclient->indexOf(ui->tab_4), false);
    connect(ui->pushButton_client, &QPushButton::clicked, this, &MainWindow::showClientTab);
    connect(ui->pushButton_client, &QPushButton::clicked, this, &MainWindow::on_pushButton_client_clicked);
    ui->stackedWidget2->hide();
    ui->stackedWidget_stat->hide();
    ui->stackedWidget_statbar->hide();
    ui->stackedWidget_3->setVisible(false);

    // Affiche les clients dans le QTableView
    ui->tableView_clients->setModel(client.afficher());

    //pour le boutton pdf
    connect(ui->pushButton_pdf2, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf2_clicked);

    //rapport
    // Connecter pushButton_alerte pour afficher le QStackedWidget lors du clic
    connect(ui->pushButton_rapport, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget2->show();
    });
    ui->pushButton_closeStackedWidget_stat->setVisible(true);

    connect(ui->pushButton_closeStackedWidget, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget2->hide();
    });
    //reccherche
    connect(ui->bouton_rechercher, &QPushButton::clicked, this, &MainWindow::rechercherClientParID);
    //--------------------
    // Connexions pour les boutons de statistique et de fermeture
    connect(ui->pushButton_stat, &QPushButton::clicked, this, &MainWindow::genererStatistiquesParDate);
    connect(ui->pushButton_closeStackedWidget_stat, &QPushButton::clicked, this, &MainWindow::fermerStackedWidgetStat);
    //sms
    connect(ui->pushButton_sms, &QPushButton::clicked, this, [this]() {
        QString telephone = ui->lineEdit_telephone->text();
        QString message = "bienvenue parmi nous dans notre smart conservation company";
        envoyerSMS(telephone, message);
    });

    //bouton statistiques géographiques
    connect(ui->pushButton_statbar_2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_statbar->setVisible(true); // Affiche le stackedWidget_statbar
        //appel de la méthode pour générer les statistiques géographiques
        genererStatistiquesParAdresse();
    });

    // Connecter le bouton "pushButton_closeStackedWidgetbar" pour fermer le stackedWidget_statbar
    connect(ui->pushButton_closeStackedWidgetbar, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_statbar->setVisible(false); // Cache le stackedWidget_statbar
    });


    // excel
    connect(ui->pushButton_excel, &QPushButton::clicked, this, &MainWindow::on_pushButton_excel_clicked);

    //releve
    // Connexion pour afficher stackedWidget_3 lors du clic sur pushButton_releve
    /*
    connect(ui->pushButton_releve_2 , &QPushButton::clicked, this, [this]() {
        ui->stackedWidget_3->setVisible(true);
        generateActivityReport(); // Appel de la fonction pour générer et afficher le relevé d'activité
    });
    //fermer lors du clic sur pushButton_closeStackedWidgetreleve
    connect(ui->pushButton_closeStackedWidgetreleve, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget_3->setVisible(false);
    });*/

    //-------------------------------------------------------------------------------------------
    connect(ui->pushButton_pdfrapportgeo_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdfrapportgeo_2_clicked);
    //***********************************************************

    //--------------------gestion produit---------------------------------------------------------


    produits p;
    connect(ui->bouttonrecherche, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);



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

    //-------------------------------gestion commande------------------------------------

    chargerCommandes();
    connect(ui->tableViewCommande, SIGNAL(entered(QModelIndex)), this, SLOT(on_tableView_hoveredRow(QModelIndex)));

    QSqlQueryModel *modell = qobject_cast<QSqlQueryModel *>(ui->tableViewCommande->model());
    if (model) {
        qDebug() << model->rowCount() << "lignes dans le modèle.";
    }

    if (!arduino->connectToArduino()) {
        qDebug() << "Erreur : Impossible de connecter à Arduino.";
    } else {
        qDebug() << "Arduino connecté avec succès.";
    }

    // Ajouter les connexions spécifiques à votre projet
    setupConnections();
}
//------------------------------
//menu equipement

void MainWindow::on_bouttonacceuil_4_clicked()
{
    showTab();
}
void MainWindow::on_buttongererClient_5_clicked()
{
    int tabIndex = ui->tabclient->indexOf(ui->tab_4);

    if (tabIndex != -1) {
        // Activer l'onglet
        ui->tabclient->setTabEnabled(tabIndex, true);

        // Basculer vers l'onglet
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_4 activé et sélectionné.";
    } else {
        qDebug() << "Tab_4 introuvable ou index incorrect.";
    }
}
void MainWindow::on_bouttonprod5_clicked()
{
    showGestionProduitTab();
}
void MainWindow::on_btemp5_clicked()
{
    showTab2();
}
void MainWindow::on_bouttoncom5_clicked()
{
    showGestionCommandeTab();
}



//menu commande

//buttongererequipements4 buttongererProduit_4 buttoncll4 buttonemp4 bouttonacceuil_4

void MainWindow::on_homeeee_clicked()
{
    showTab();
}
void MainWindow::on_buttongererProduitcom_clicked()
{
    showGestionProduitTab();
}
/*
void MainWindow::bouttonacceuilcom_clicked()
{
    showTab();
}*/
//------------------------------
void MainWindow::on_buttongererequipements4_clicked()
{
    showTab5();
}

void MainWindow::on_buttonemp4_clicked()
{
    showTab2();
}

void MainWindow::on_buttoncll4_clicked()
{
    int tabIndex = ui->tabclient->indexOf(ui->tab_4);

    if (tabIndex != -1) {
        // Activer l'onglet
        ui->tabclient->setTabEnabled(tabIndex, true);

        // Basculer vers l'onglet
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_4 activé et sélectionné.";
    } else {
        qDebug() << "Tab_4 introuvable ou index incorrect.";
    }
}



//menu produit
void MainWindow::on_bouttonacceuil3_clicked()
{
    showTab();
}
//------------------------------
void MainWindow::on_bequip3_clicked()
{
    showTab5();
}

void MainWindow::on_bcomm3_clicked()
{
    showGestionCommandeTab();
}

void MainWindow::on_bemp3_clicked()
{
    showTab2();
}

void MainWindow::on_bcl3_clicked()
{
    int tabIndex = ui->tabclient->indexOf(ui->tab_4);

    if (tabIndex != -1) {
        // Activer l'onglet
        ui->tabclient->setTabEnabled(tabIndex, true);

        // Basculer vers l'onglet
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_4 activé et sélectionné.";
    } else {
        qDebug() << "Tab_4 introuvable ou index incorrect.";
    }
}
//MENU DU CLIENT
//bouttonemp2    bprod2  bouttequip2 boucomm2  bouttonacceuil2
void MainWindow::on_bouttonacceuil2_clicked()
{
    showTab();
}
//------------------------------
void MainWindow::on_bouttequip2_clicked()
{
    showTab5();
}

void MainWindow::on_boucomm2_clicked()
{
    showGestionCommandeTab();
}

void MainWindow::on_bprod2_clicked()
{
    showGestionProduitTab();
}
void MainWindow::showTab2()
{
    // Récupérer l'index de tab_2
    int tabIndex = ui->tabclient->indexOf(ui->tab_2);

    if (tabIndex != -1) {
        // Activer et afficher l'onglet tab_2
        ui->tabclient->setTabEnabled(tabIndex, true);
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_2 activé et sélectionné.";
    } else {
        qDebug() << "Tab_2 introuvable dans le QTabWidget.";
    }
}

void MainWindow::on_bouttonemp2_clicked()
{
    // Appeler showTab2() pour centraliser la logique
    showTab2();
}


//-----------------------------

//MENU DE LEMPLOYEE
void MainWindow::showTab()
{
    // Récupérer l'index de tab
    int tabIndex = ui->tabclient->indexOf(ui->tab);  // Replace 'tab' with your actual tab name

    if (tabIndex != -1) {
        // Activer et afficher l'onglet
        ui->tabclient->setTabEnabled(tabIndex, true);
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab activé et sélectionné.";
    } else {
        qDebug() << "Tab introuvable dans le QTabWidget.";
    }
}

void MainWindow::on_pushButton_h1_clicked()
{
    // Appeler showTab() pour centraliser la logique
    showTab();
}
//------------------------------
void MainWindow::on_buttonequip_clicked()
{
    // Appeler showTab5() pour centraliser la logique
    showTab5();
}
void MainWindow::showTab5()
{
    // Récupérer l'index de tab_5
    int tabIndex = ui->tabclient->indexOf(ui->tab_5);

    if (tabIndex != -1) {
        // Activer et afficher l'onglet tab_5
        ui->tabclient->setTabEnabled(tabIndex, true);
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_5 activé et sélectionné.";
    } else {
        qDebug() << "Tab_5 introuvable dans le QTabWidget.";
    }
}
//---------------------------------
void MainWindow::showGestionCommandeTab()
{
    // Récupérer l'index de gestion_commande
    int tabIndex = ui->tabclient->indexOf(ui->gestion_commade);

    if (tabIndex != -1) {
        // Activer et afficher l'onglet gestion_commande
        ui->tabclient->setTabEnabled(tabIndex, true);
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Gestion Commande activé et sélectionné.";
    } else {
        qDebug() << "Gestion Commande introuvable dans le QTabWidget.";
    }
}

void MainWindow::on_pushButton_cmd_clicked()
{
    // Appeler showGestionCommandeTab() pour centraliser la logique
    showGestionCommandeTab();
}
void MainWindow::showGestionProduitTab()
{
    // Récupérer l'index de gestion_produit
    int tabIndex = ui->tabclient->indexOf(ui->gestion_produit);

    if (tabIndex != -1) {
        // Activer et afficher l'onglet gestion_produit
        ui->tabclient->setTabEnabled(tabIndex, true);
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Gestion Produit activé et sélectionné.";
    } else {
        qDebug() << "Gestion Produit introuvable dans le QTabWidget.";
    }
}
void MainWindow::on_pushButton_prod_clicked()
{
    // Appeler showGestionProduitTab() pour centraliser la logique
    showGestionProduitTab();
}


//-----------------------------
void MainWindow::showClientTab()
{
    // Récupérer l'index de tab_4
    int tabIndex = ui->tabclient->indexOf(ui->tab_4);

    if (tabIndex != -1) {
        // Activer tab_4
        ui->tabclient->setTabEnabled(tabIndex, true);

        // Basculer vers tab_4
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_4 activé et sélectionné.";
    } else {
        qDebug() << "Tab_4 introuvable dans le QTabWidget.";
    }
}
void MainWindow::on_pushButton_client_clicked()
{
    int tabIndex = ui->tabclient->indexOf(ui->tab_4);

    if (tabIndex != -1) {
        // Activer l'onglet
        ui->tabclient->setTabEnabled(tabIndex, true);

        // Basculer vers l'onglet
        ui->tabclient->setCurrentIndex(tabIndex);

        qDebug() << "Tab_4 activé et sélectionné.";
    } else {
        qDebug() << "Tab_4 introuvable ou index incorrect.";
    }
}

//------------------------------------------------------------------------------------------------
//sms
void MainWindow::envoyerSMS(const QString &telephone, const QString &message) {
    // Vos informations Twilio
    QString accountSid = "ACa0fb540f9b24f62daeb044a92226642f";
    QString authToken = "9c779977f1b980c91136b5b627a0023f";
    QString fromNumber = "+12029296365";  // Numéro Twilio

    // Vérification que le numéro du destinataire est valide
    if (telephone.isEmpty() || telephone == fromNumber) {
        qDebug() << "Erreur : Le numéro du destinataire est vide ou identique à l'expéditeur.";
        return;
    }

    // Préparation du numéro de téléphone
    QString trimmedPhoneNumber = telephone.trimmed();

    // Si le numéro ne commence pas par '+', ajoutez le préfixe international par défaut
    if (!trimmedPhoneNumber.startsWith("+")) {
        QString defaultCountryCode = "+216";  // Changez selon votre pays
        trimmedPhoneNumber = defaultCountryCode + trimmedPhoneNumber;
    }

    // Vérifiez si le numéro est valide en format E.164
    QRegularExpression phonePattern("^\\+\\d{1,15}$");

    // Debugging output
    qDebug() << "Vérification du numéro de téléphone après ajout du préfixe: " << trimmedPhoneNumber;

    if (!phonePattern.match(trimmedPhoneNumber).hasMatch()) {
        qDebug() << "Erreur : Numéro de téléphone invalide.";
        return;
    }

    // URL de l'API Twilio
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json";

    // Paramètres de la requête
    QUrlQuery params;
    params.addQueryItem("To", trimmedPhoneNumber);      // Numéro du destinataire
    params.addQueryItem("From", fromNumber);           // Numéro Twilio
    params.addQueryItem("Body", message);              // Contenu du SMS

    // Création de la requête HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Authentification
    QByteArray authData = accountSid.toUtf8() + ":" + authToken.toUtf8();
    QString authHeader = "Basic " + authData.toBase64();
    request.setRawHeader("Authorization", authHeader.toUtf8());

    // Envoi de la requête
    QNetworkReply *reply = manager->post(request, params.query().toUtf8());

    // Connexion à la réponse
    connect(manager, &QNetworkAccessManager::finished, this, [manager, reply](QNetworkReply *response) {
        if (response->error() == QNetworkReply::NoError) {
            qDebug() << "SMS envoyé avec succès!";
        } else {
            qDebug() << "Erreur d'envoi de SMS:" << response->errorString();
            qDebug() << "Réponse : " << response->readAll();
        }
        reply->deleteLater();
        manager->deleteLater();
    });
}






//***********************************************************************************************************



//---------EFFACER--------------------------------------------------------
void MainWindow::clearFields()
{
    ui->lineEdit_ID2->clear();
    ui->lineEdit_nom_2->clear();
    ui->lineEdit_prenom_2->clear();
    ui->lineEdit_telephone_2->clear();
    ui->lineEdit_adresse_2->clear();
    ui->dateEdit_dateInscription->clear();
}
//*SUPLEMMENTAIRE/
//clic au tableview met les info dans les lineedit
void MainWindow::on_tableView_clients_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->lineEdit_ID2->setText(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 0)).toString());
    ui->lineEdit_nom_2->setText(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 1)).toString());
    ui->lineEdit_prenom_2->setText(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 2)).toString());
    ui->lineEdit_telephone_2->setText(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 3)).toString());
    ui->lineEdit_adresse_2->setText(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 4)).toString());
    ui->dateEdit_dateInscription->setDate(QDate::fromString(ui->tableView_clients->model()->data(ui->tableView_clients->model()->index(row, 5)).toString(), "yyyy-MM-dd"));
}

//---------EFFACER--------------------------------------------------------
void MainWindow::on_pushButton_effacer_clicked()
{
    ui->lineEdit_ID2->clear();
    ui->lineEdit_nom_2->clear();
    ui->lineEdit_prenom_2->clear();
    ui->lineEdit_telephone_2->clear();
    ui->lineEdit_adresse_2->clear();
    //ui->dateEdit_dateInscription_2->clear();
}

//---------AJOUT--------------------------------------------------------
void MainWindow::on_pushButton_ajouter2_clicked()
{
    int id = ui->lineEdit_ID2->text().toInt();  //lineEdit_ID2
    QString nom = ui->lineEdit_nom_2->text();   //lineEdit_nom_2
    QString prenom = ui->lineEdit_prenom_2->text(); //lineEdit_prenom_2
    QString telephone = ui->lineEdit_telephone_2->text();//lineEdit_telephone_2
    QString adresse = ui->lineEdit_adresse_2->text();//lineEdit_adresse_2
    QString date_inscription = ui->dateEdit_dateInscription->text();//dateEdit_dateInscription_2
    // Vérifier les champs vides
    if (nom.isEmpty() || prenom.isEmpty() || telephone.isEmpty() || adresse.isEmpty() || date_inscription.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Tous les champs doivent être remplis."));
        return;
    }
    // Vérifier le format du numéro de téléphone
    if (telephone.length() < 8 || !telephone.toInt()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le numéro de téléphone doit contenir au moins 8 chiffres et être numérique."));
        return;
    }
    // Vérifier si l'ID existe déjà (comme avant)
    QSqlQuery query;
    query.prepare("SELECT IDCLIENT FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Cet ID existe déjà."));
        clearFields(); // Efface les champs de saisie
        return;
    }
    // Ajout du client si toutes les validations sont passées
    Client nouveauClient(id, nom, prenom, telephone, adresse, date_inscription);
    bool test = nouveauClient.ajouter();
    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Le client a été ajouté avec succès."));
        ui->tableView_clients->setModel(nouveauClient.afficher());
        clearFields(); // Effacer les champs après ajout réussi
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("L'ajout du client a échoué."));
    }
}


//---------SUPPRIMER--------------------------------------------------------
void MainWindow::on_pushButton_supprimer_2_clicked()
{
    qDebug() << "Supprimer button clicked"; // Message de débogage

    // Récupérer l'ID du client à partir du champ de saisie
    int id = ui->lineEdit_ID2->text().toInt();
    bool test = client.supprimer(id);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."), QMessageBox::Ok);
        // Rafraîchir l'affichage dans le QTableView
        ui->tableView_clients->setModel(client.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression."), QMessageBox::Cancel);
    }
}
//---------MODIFIER--------------------------------------------
void MainWindow::on_pushButton_modifier_2_clicked()
{
    int id = ui->lineEdit_ID2->text().toInt();
    QString nom = ui->lineEdit_nom_2->text();
    QString prenom = ui->lineEdit_prenom_2->text();
    QString telephone = ui->lineEdit_telephone_2->text();
    QString adresse = ui->lineEdit_adresse_2->text();
    QString date_inscription = ui->dateEdit_dateInscription->text();
    // Validation des champs
    if (nom.isEmpty() || prenom.isEmpty() || telephone.isEmpty() || adresse.isEmpty() || date_inscription.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Tous les champs doivent être remplis."));
        return;
    }
    if (telephone.length() < 8 || !telephone.toInt()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le numéro de téléphone doit contenir au moins 8 chiffres et être numérique."));
        return;
    }
    // Vérifier si le client existe pour la modification
    QSqlQuery query;
    query.prepare("SELECT IDCLIENT FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Ce client n'existe pas."));
        return;
    }

    Client clientToUpdate(id, nom, prenom, telephone, adresse, date_inscription);
    bool test = clientToUpdate.modifier();
    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Le client a été modifié avec succès."));
        ui->tableView_clients->setModel(clientToUpdate.afficher());
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La modification du client a échoué."));
    }
}
//LES METIERS
//------------TRI-----------------------------------------------------------------------------

void MainWindow::on_pushButton_tri_nom_clicked()
{
    ui->tableView_clients->setModel(client.afficherTriParNom());
    QMessageBox::information(this, tr("Tri par Nom"), tr("Les clients ont été triés par nom."), QMessageBox::Ok);
}

//-------------PDF---------------------------------------------------------------------------

void MainWindow::on_pushButton_pdf2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le PDF"), "", tr("PDF Files (*.pdf);;All Files (*)"));
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
    painter.drawText(100, y, tr("Liste des Clients"));

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

    painter.drawRect(1000, y, 300, 240); // Téléphone
    painter.drawText(1010, y + 140, tr("Téléphone"));

    painter.drawRect(1300, y, 300, 240); // Adresse
    painter.drawText(1310, y + 140, tr("Adresse"));

    painter.drawRect(1600, y, 500, 240); // Date d'inscription (colonne élargie)
    painter.drawText(1610, y + 140, tr("Date d'inscription"));

    y += 240; // Ligne suivante

    // Remplissage des lignes du tableau
    painter.setFont(QFont("Arial", 10));
    painter.setBrush(Qt::NoBrush); // Pas de fond pour les cellules
    QSqlQuery query("SELECT IDCLIENT, NOMCLIENT, PRÉNOMCLIENT, TÉLÉPHONECLIENT, ADRESSE, DATEINSCRI FROM CLIENT");
    while (query.next()) {
        if (y > pdfWriter.height() - 200) { // Vérification si la page est pleine
            painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));
            pdfWriter.newPage();
            y = 100; // Réinitialisation de la position
            page++;
        }

        // ID
        painter.drawRect(100, y, 300, 240);
        painter.drawText(110, y + 140, query.value("IDCLIENT").toString());

        // Nom
        painter.drawRect(400, y, 300, 240);
        painter.drawText(410, y + 140, query.value("NOMCLIENT").toString());

        // Prénom
        painter.drawRect(700, y, 300, 240);
        painter.drawText(710, y + 140, query.value("PRÉNOMCLIENT").toString());

        // Téléphone
        painter.drawRect(1000, y, 300, 240);
        painter.drawText(1010, y + 140, query.value("TÉLÉPHONECLIENT").toString());

        // Adresse
        painter.drawRect(1300, y, 300, 240);
        painter.drawText(1310, y + 140, query.value("ADRESSE").toString());

        // Date d'inscription (alignée à gauche)
        painter.drawRect(1600, y, 500, 240);
        painter.drawText(1610, y + 140, query.value("DATEINSCRI").toString());

        y += 240; // Ligne suivante
    }

    // Ajouter le numéro de page
    painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));

    painter.end();
    QMessageBox::information(this, tr("PDF généré"), tr("Le fichier PDF a été généré avec succès."));
}
// statistique de date d inscription
//pie chart
void MainWindow::genererStatistiquesParDate()
{
    QSqlQuery query;
    query.prepare("SELECT DATEINSCRI, COUNT(*) AS nombre_clients FROM CLIENT GROUP BY DATEINSCRI ORDER BY DATEINSCRI DESC");

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL : " << query.lastError();
        QMessageBox::critical(this, "Erreur", "La requête SQL a échoué. Vérifiez votre base de données.");
        return;
    }

    if (!query.next()) {
        QMessageBox::information(this, "Aucune donnée", "Aucune donnée à afficher pour les statistiques.");
        return;
    }

    // Créer une série pour le diagramme en secteurs
    QPieSeries *series = new QPieSeries();
    do {
        QString dateInscription = query.value("DATEINSCRI").toString();
        int nombreClients = query.value("nombre_clients").toInt();

        QPieSlice *slice = series->append(dateInscription + ": " + QString::number(nombreClients), nombreClients);
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setBrush(QColor::fromHsv(rand() % 256, 200, 255));
    } while (query.next());

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques d'inscription des clients");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer une vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un bouton "Fermer"
    QPushButton *closeButton = new QPushButton("Fermer");

    // Appliquer le style CSS au bouton "Fermer"
    closeButton->setStyleSheet(
        "QPushButton {"
        "background-color: #b8e0c7;"
        "color: #1f472e;"
        "font-family: 'Roboto', sans-serif;"
        "font-size: 14px;"
        "font-weight: bold;"
        "border-radius: 5px;"
        "transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease;"
        "}"
        "QPushButton:hover {"
        "background-color: #A0D6B4;"
        "border: 1px solid #4CAF50;"
        "box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"
        "transform: scale(1.05);"
        "}"
        );

    // Connecter le bouton "Fermer" pour masquer le QStackedWidget
    connect(closeButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget_stat->hide();
    });

    // Créer une nouvelle page pour le QStackedWidget
    QWidget *statPage = new QWidget();
    QVBoxLayout *pageLayout = new QVBoxLayout(statPage);

    // Ajouter le graphique et le bouton "Fermer" à la page
    pageLayout->addWidget(chartView);
    pageLayout->addWidget(closeButton);

    // Supprimer les anciennes pages du QStackedWidget
    while (ui->stackedWidget_stat->count() > 0) {
        QWidget *widgetToRemove = ui->stackedWidget_stat->widget(0);
        ui->stackedWidget_stat->removeWidget(widgetToRemove);
        widgetToRemove->deleteLater();
    }

    // Ajouter la nouvelle page au QStackedWidget
    ui->stackedWidget_stat->addWidget(statPage);

    // Afficher la nouvelle page
    ui->stackedWidget_stat->setCurrentWidget(statPage);
    ui->stackedWidget_stat->show();
}
// Fonction pour masquer le QStackedWidget
//--------------------------------------------------------------------
void MainWindow::fermerStackedWidgetStat()
{
    ui->stackedWidget_stat->hide();
}

void MainWindow::on_pushButton_stat_clicked()
{
    qDebug() << "Bouton 'Statistiques' cliqué !";
    genererStatistiquesParDate(); // Générer les statistiques
}

void MainWindow::on_pushButton_closeStackedWidget_stat_clicked()
{
    qDebug() << "Bouton 'Fermer' cliqué !";
    fermerStackedWidgetStat(); // Masquer le QStackedWidget
}



//----------RECHERCHE PAR ID-------------------------------------------------------------------------------------
void MainWindow::rechercherClientParID()
{
    QString id = ui->lineEdit_search->text();
    QSqlQuery query;

    query.prepare("SELECT * FROM CLIENT WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString nom = query.value("NOMCLIENT").toString();
            QString prenom = query.value("PRÉNOMCLIENT").toString();
            QString telephone = query.value("TÉLÉPHONECLIENT").toString();
            QString adresse = query.value("ADRESSE").toString();
            QString dateInscription = query.value("DATEINSCRI").toString();

            ui->lineEdit_nom_2->setText(nom);
            ui->lineEdit_prenom_2->setText(prenom);
            ui->lineEdit_telephone_2->setText(telephone);
            ui->lineEdit_adresse_2->setText(adresse);
            ui->dateEdit_dateInscription->setDate(QDate::fromString(dateInscription, "yyyy-MM-dd"));

        } else {
            QMessageBox::information(this, tr("Recherche"), tr("Aucun client trouvé avec cet ID."));
        }
    } else {
        QMessageBox::warning(this, tr("Erreur"), tr("Échec de la recherche dans la base de données : ") + query.lastError().text());
    }
}
//generer rapport par adresse avec tableau et stat bares
//*****************************************
void MainWindow::generateActivityReport() {
    QString period = "Mois"; // Exemple : peut être changé en "Trimestre"
    QString reportTitle = QString("Relevé d'activité pour le %1").arg(period);
    ui->label_report->setText(reportTitle);

    ui->tableWidget_report->clearContents();
    ui->tableWidget_report->setRowCount(0);
    QStringList headers = {"Type de Statistique", "Valeur"};
    ui->tableWidget_report->setColumnCount(headers.size());
    ui->tableWidget_report->setHorizontalHeaderLabels(headers);

    // Nombre de nouveaux clients
    QString startDate = (period == "Mois") ? QDate::currentDate().addMonths(-1).toString("yyyy-MM-dd")
                                           : QDate::currentDate().addMonths(-3).toString("yyyy-MM-dd");

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM clients WHERE date_inscription >= :startDate");
    query.bindValue(":startDate", startDate);

    int newClients = 0;
    if (query.exec() && query.next()) {
        newClients = query.value(0).toInt();
    } else {
        qDebug() << "Erreur lors de la récupération des nouveaux clients:" << query.lastError().text();
    }

    // Ajout au tableau
    addRowToTable("Nombre de nouveaux clients", QString::number(newClients));

    // Répartition géographique
    QSqlQueryModel *regionModel = client.afficherRepartitionGeographique();
    if (regionModel) {
        while (regionModel->canFetchMore()) {
            regionModel->fetchMore();
        }

        for (int i = 0; i < regionModel->rowCount(); ++i) {
            QString region = regionModel->data(regionModel->index(i, 0)).toString();
            int clientCount = regionModel->data(regionModel->index(i, 1)).toInt();
            addRowToTable("Clients dans " + region, QString::number(clientCount));
        }

        // Configuration du graphique
        setupChart(regionModel);
    } else {
        qDebug() << "Erreur : impossible de charger les données géographiques.";
    }
}

void MainWindow::addRowToTable(const QString &label, const QString &value) {
    int row = ui->tableWidget_report->rowCount();
    ui->tableWidget_report->insertRow(row);
    ui->tableWidget_report->setItem(row, 0, new QTableWidgetItem(label));
    ui->tableWidget_report->setItem(row, 1, new QTableWidgetItem(value));
}

void MainWindow::setupChart(QSqlQueryModel *regionModel) {
    QBarSet *set = new QBarSet("Nombre de clients");
    QStringList categories;

    int maxClientCount = 0;
    for (int i = 0; i < regionModel->rowCount(); ++i) {
        QString region = regionModel->data(regionModel->index(i, 0)).toString();
        int clientCount = regionModel->data(regionModel->index(i, 1)).toInt();
        *set << clientCount;
        categories << region;

        if (clientCount > maxClientCount) {
            maxClientCount = clientCount;
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique des clients");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxClientCount + 5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    axisX->setLabelsColor(QColor("#4CAF50"));
    axisY->setLabelsColor(QColor("#4CAF50"));

    QLinearGradient gradient(0, 0, 1, 1);
    gradient.setColorAt(0, QColor(129, 199, 132));
    gradient.setColorAt(1, QColor(67, 160, 71));
    set->setBrush(gradient);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chartView_report);
    chartView->resize(ui->chartView_report->size());
    chartView->show();
}
//***********************************************



//les statistique par adresse

void MainWindow::genererStatistiquesParAdresse()
{
    QSqlQuery query;
    query.prepare("SELECT adresse, COUNT(*) AS nombre_clients FROM CLIENT GROUP BY adresse ORDER BY nombre_clients DESC");

    if (!query.exec()) {
        qDebug() << "Erreur dans la requête SQL : " << query.lastError();
        return;
    }
    QStringList categories; // Liste des adresses (pour l'axe X)
    QBarSet *barSet = new QBarSet("Clients"); // Un seul QBarSet pour toutes les adresses
    // Générer des couleurs harmonieuses
    QList<QColor> couleurs;
    for (int i = 0; i < 10; i++) {
        couleurs << QColor::fromHsv(rand() % 256, 200 + rand() % 56, 180 + rand() % 75);
    }
    int index = 0;
    while (query.next()) {
        QString adresse = query.value("adresse").toString();
        int nombreClients = query.value("nombre_clients").toInt();

        *barSet << nombreClients; // Ajouter le nombre de clients dans le QBarSet
        categories << adresse;   // Ajouter l'adresse à la liste des catégories
        index++;
    }

    if (categories.isEmpty()) {
        qDebug() << "Aucune donnée trouvée pour les statistiques géographiques.";
        return;
    }

    // Créer une série de barres
    QBarSeries *series = new QBarSeries();
    series->append(barSet); // Ajouter le QBarSet contenant les données

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique des clients");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Axe X : Ajouter les catégories (adresses)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisX->setLabelsAngle(45); // Incliner les étiquettes
    axisX->setLabelsFont(QFont("Arial", 10));

    // Axe Y : Nombre de clients
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de clients");
    axisY->setTickCount(10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    axisY->setLabelsFont(QFont("Arial", 10));

    // Ajuster les marges
    chart->setMargins(QMargins(10, 10, 10, 10));

    // Vue pour le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Nettoyer les anciens widgets
    QLayout *layout = ui->graphicsView_statistiques_2->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->graphicsView_statistiques_2);
        ui->graphicsView_statistiques_2->setLayout(layout);
    }

    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    layout->addWidget(chartView);

    // Mise à jour de la vue
    ui->graphicsView_statistiques_2->update();
    ui->stackedWidget_statbar->setVisible(true);
}
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_rapport_clicked()
{
    // Charger le modèle de répartition géographique des clients
    ui->tableView_rapport->setModel(client.afficherRepartitionGeographique());
    // Afficher le QStackedWidget
    ui->stackedWidget2->show();
}

//***supplementaires

//------EXCEL------------------------------------
void MainWindow::on_pushButton_excel_clicked() {

    QAxObject *excel = new QAxObject("Excel.Application", this);
    excel->setProperty("Visible", true);

    //new workbook
    QAxObject *workbooks = excel->querySubObject("Workbooks");
    QAxObject *workbook = workbooks->querySubObject("Add");

    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
    worksheet->setProperty("Name", "Liste des Clients");

    //les titres
    worksheet->querySubObject("Cells(int, int)", 1, 1)->setProperty("Value", "ID");
    worksheet->querySubObject("Cells(int, int)", 1, 2)->setProperty("Value", "Nom");
    worksheet->querySubObject("Cells(int, int)", 1, 3)->setProperty("Value", "Prénom");
    worksheet->querySubObject("Cells(int, int)", 1, 4)->setProperty("Value", "Téléphone");
    worksheet->querySubObject("Cells(int, int)", 1, 5)->setProperty("Value", "Adresse");
    worksheet->querySubObject("Cells(int, int)", 1, 6)->setProperty("Value", "Date d'inscription");

    // on prend les clients de la base de donnees
    QSqlQuery query("SELECT IDCLIENT, NOMCLIENT, PRÉNOMCLIENT, TÉLÉPHONECLIENT, ADRESSE, DATEINSCRI FROM CLIENT");
    int row = 2;
    while (query.next()) {
        worksheet->querySubObject("Cells(int, int)", row, 1)->setProperty("Value", query.value(0).toInt());
        worksheet->querySubObject("Cells(int, int)", row, 2)->setProperty("Value", query.value(1).toString());
        worksheet->querySubObject("Cells(int, int)", row, 3)->setProperty("Value", query.value(2).toString());
        worksheet->querySubObject("Cells(int, int)", row, 4)->setProperty("Value", query.value(3).toString());
        worksheet->querySubObject("Cells(int, int)", row, 5)->setProperty("Value", query.value(4).toString());
        worksheet->querySubObject("Cells(int, int)", row, 6)->setProperty("Value", query.value(5).toString());
        row++;
    }

    //remplir les colonnes
    QAxObject *columns = worksheet->querySubObject("Columns");
    columns->dynamicCall("AutoFit()");

    // Save file dialog for exporting
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Excel File"), "", tr("Excel Files (*.xlsx)"));
    if (!filePath.isEmpty()) {
        workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filePath));
        QMessageBox::information(this, tr("Export Successful"), tr("Client list has been exported successfully!"));
    } else {
        QMessageBox::warning(this, tr("Export Canceled"), tr("Export was canceled by the user."));
    }

    // Clean up and release resources
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete excel;
}
//-------------------------------------------------------------------
//PDF pour les statistique rapport geo

void MainWindow::on_pushButton_pdfrapportgeo_2_clicked() {
    QSqlQueryModel *model = client.afficherRepartitionGeographique();
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à afficher.");
        return;
    }

    // Création du graphique à barres
    QBarSeries *series = new QBarSeries();
    QStringList categories;
    int maxValue = 0;

    for (int i = 0; i < model->rowCount(); ++i) {
        QString region = model->data(model->index(i, 0)).toString();
        int count = model->data(model->index(i, 1)).toInt();

        QBarSet *set = new QBarSet(region);
        *set << count;
        series->append(set);
        categories << region;

        maxValue = qMax(maxValue, count);
    }

    // Agrandir les barres et ajouter un espace
    series->setBarWidth(0.6); // Largeur des barres
    series->setLabelsVisible(true); // Afficher les valeurs sur les barres

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique des clients");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Axe X : Ajouter correctement les catégories (pays/régions)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories); // Ajouter toutes les catégories
    axisX->setLabelsAngle(-25); // Inclinaison légère des labels
    axisX->setTitleText("Régions");

    // Espacement entre les barres
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Axe Y : Plage des valeurs
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de clients");
    axisY->setRange(0, maxValue + 5); // Légère marge en haut
    axisY->setTickCount(5); // Nombre de divisions de l'axe Y
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Personnalisation des polices
    QFont axisFont("Arial", 10, QFont::Bold);
    QFont titleFont("Arial", 12, QFont::Bold);
    axisX->setLabelsFont(axisFont);
    axisY->setLabelsFont(axisFont);
    chart->setTitleFont(titleFont);

    // Configuration de la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configuration des marges et dimensions du graphique
    chart->setMargins(QMargins(5, 5, 5, 5)); // Marges ajustées
    chart->resize(600, 300);

    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);

    // Génération du fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le rapport", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4)); // Taille de page A4
    writer.setResolution(300);

    QPainter pdfPainter(&writer);
    if (pdfPainter.isActive()) {
        int pdfWidth = writer.width();
        int pdfHeight = writer.height();

        // Calcul de la taille du pixmap pour l'adapter à la taille du PDF
        int pixmapWidth = pdfWidth - 100; // Largeur ajustée pour le PDF
        int pixmapHeight = pdfHeight - 150; // Hauteur ajustée pour le PDF

        QPixmap pixmap(pixmapWidth, pixmapHeight);
        pixmap.fill(Qt::white);
        QPainter pixmapPainter(&pixmap);
        chartView.render(&pixmapPainter);
        pixmapPainter.end();

        // Dessiner le pixmap dans le fichier PDF
        QRect targetRect(50, 50, pixmap.width(), pixmap.height());
        pdfPainter.drawPixmap(targetRect, pixmap);

        // Ajouter une description en bas du graphique
        pdfPainter.setPen(Qt::black);
        pdfPainter.setFont(QFont("Arial", 12));
        QRect textRect(50, pdfHeight - 100, pdfWidth - 100, 50);
        pdfPainter.drawText(textRect, Qt::AlignCenter, "Rapport géographique des clients avec leurs répartitions.");

        QMessageBox::information(this, "Succès", "Rapport PDF généré avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le PDF.");
    }
    pdfPainter.end();
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//*******************************************************************************************************************************************************************************************************************
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_buttonForgotPassword2_clicked() {
    // Afficher le QStackedWidget
    ui->stackedWidget->setVisible(true);
}

void MainWindow::on_pushButton_fermer_clicked() {
    // Cacher le QStackedWidget
    ui->stackedWidget->setVisible(false);
}


void MainWindow::on_pushButton_suivant_clicked() {
    // Enable and switch to Tab 3
    ui->tabclient->setTabEnabled(2, true);
    ui->tabclient->setCurrentIndex(2);


}

void MainWindow::handleArduinoData(QString data)
{
    ui->lineEditID->setText(data); // Afficher l'ID reçu dans le QLineEdit
}
void MainWindow::on_verifyButton_clicked() {
    QString id = ui->lineEditID->text(); // Lire l'ID de commande

    // Vérifier si l'ID est vide
    if (id.trimmed().isEmpty()) { // Supprimer les espaces inutiles avant vérification
        qDebug() << "ID de commande vide.";
        QMessageBox::warning(this, "Erreur", "L'ID de commande est vide. Veuillez entrer un ID valide.");
        return;
    }

    // Requête pour vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT etatCommande FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            // L'ID existe, récupérer l'état de la commande
            QString etatCommande = query.value(0).toString();
            qDebug() << "ID trouvé. État envoyé à Arduino :" << etatCommande;

            // Afficher un message box avec l'ID et l'état
            QMessageBox::information(this, "Vérification ID",
                                     "L'ID de commande existe.\nID : " + id + "\nÉtat de la commande : " + etatCommande);

            // Vérifier si Arduino est prêt avant l'envoi
            if (arduino && !etatCommande.isEmpty()) {
                static QString dernierEtatEnvoye = ""; // Variable statique pour suivre le dernier état envoyé
                if (etatCommande != dernierEtatEnvoye) {
                    arduino->sendToArduino(etatCommande); // Envoyer uniquement si l'état est différent du dernier envoyé
                    dernierEtatEnvoye = etatCommande;    // Mettre à jour l'état envoyé
                } else {
                    qDebug() << "État déjà envoyé, aucun nouvel envoi nécessaire.";
                }
            } else {
                qDebug() << "Erreur : Instance Arduino non initialisée ou état vide.";
                QMessageBox::critical(this, "Erreur", "La connexion à l'Arduino n'est pas initialisée.");
            }
        } else {
            // L'ID n'existe pas
            qDebug() << "Commande introuvable.";
            QMessageBox::information(this, "Vérification ID", "L'ID n'existe pas. Veuillez vérifier l'ID.");
        }
    } else {
        // Erreur lors de l'exécution de la requête
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur de requête", "Une erreur s'est produite lors de l'exécution de la requête.");
    }
}

/*void MainWindow::on_verifyButton_clicked()
{
    QString id = ui->lineEditID->text();

    // Requête pour vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE IDCOMMANDES = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            QMessageBox::information(this, tr("Vérification ID"), tr("L'ID existe."));
        } else {
            QMessageBox::information(this, tr("Vérification ID"), tr("L'ID n'existe pas."));
        }
    } else {
        QMessageBox::critical(this, tr("Erreur de requête"), tr("Erreur lors de l'exécution de la requête."));
    }
}*/

MainWindow::~MainWindow()
{
    arduino->disconnectFromArduino();
    //-----gestion produit----------

    arduino->close_arduino();
    delete arduino;

    delete ui;
}
/*
void MainWindow::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    User user(username, password);

    if (user.authenticate()) {
        // Enable and switch to Tab 2
        ui->tabclient->setTabEnabled(1, true);
        ui->tabclient->setCurrentIndex(1);

        // Disable Tab 1
        ui->tabclient->setTabEnabled(0, false);

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
}*/
/*void MainWindow::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();



    qDebug() << "Trying to authenticate user:" << username;

    User user(username, password);

    if (user.authenticate()) {
        qDebug() << "User authenticated successfully.";

        // Create a connection object and check the connection
        Connection connection;
        if (!connection.createconnect()) {
            qDebug() << "Failed to connect to the database.";
            QMessageBox::critical(this, tr("Database Connection Error"),
                                  tr("Failed to connect to the database.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
            return;
        }

        qDebug() << "Database connection established.";

        if (username == "client") {
            int tabIndex = ui->tabclient->indexOf(ui->tab_4);

                if (tabIndex != -1) {
                    // Activer l'onglet
                    ui->tabclient->setTabEnabled(tabIndex, true);

                    // Basculer vers l'onglet
                    ui->tabclient->setCurrentIndex(tabIndex);

                    qDebug() << "Tab_4 activé et sélectionné.";
                } else {
                    qDebug() << "Tab_4 introuvable ou index incorrect.";
                }
                 }
                if (username == "commande") {
                    int tabIndex = ui->tabclient->indexOf(ui->gestion_commade);

                       if (tabIndex != -1) {
                       ui->tabclient->setTabEnabled(4, true);
                       ui->tabclient->setCurrentIndex(4);

                       ui->tabclient->setTabEnabled(0, false);
                       ui->tabclient->setTabEnabled(1, false);
                       ui->tabclient->setTabEnabled(2, false);
                       ui->tabclient->setTabEnabled(3, false);
                       ui->tabclient->setTabEnabled(5, false);
                       ui->tableViewCommande->setModel(Ctemp.afficher()); // Charger les données dans le `tableViewCommande`

                        //  qDebug() << "gestion_produit activé et sélectionné.";

                       }
         }
                if (username == "produit") {
                    int tabIndex = ui->tabclient->indexOf(ui->gestion_produit);

                    if (tabIndex != -1) {
                        ui->tabclient->setTabEnabled(3, true);
                        ui->tabclient->setCurrentIndex(3);

                        ui->tabclient->setTabEnabled(0, false);
                        ui->tabclient->setTabEnabled(1, false);
                        ui->tabclient->setTabEnabled(2, false);
                        ui->tabclient->setTabEnabled(4, false);
                        ui->tabclient->setTabEnabled(5, false);
                        produits p;
                        QSqlQueryModel *model = p.afficherProduits();
                        ui->tableauproduits->setModel(model);
                        ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
                        ui->tableauproduits->setModel(p.afficherProduits());
                        chartView = nullptr;

                        delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
                        ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
                        connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
                        connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);

                        //  qDebug() << "gestion_produit activé et sélectionné.";

                    }
                }
                else {
            // Enable and switch to Tab 2 for other users
            ui->tabclient->setTabEnabled(1, true);
            ui->tabclient->setCurrentIndex(1);

            // Disable Tab 1
            ui->tabclient->setTabEnabled(0, false);

            // Display employees in the QTableView at startup for non-client users
            ui->tableView_employee->setModel(emp.afficher());
            ui->tableViewCommande->setModel(Ctemp.afficher()); // Charger les données dans le `tableViewCommande`
            produits p;
            QSqlQueryModel *model = p.afficherProduits();
            ui->tableauproduits->setModel(model);
            ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
            ui->tableauproduits->setModel(p.afficherProduits());
            chartView = nullptr;

            delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
            ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
            connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
            connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);
        }

    } else {
        qDebug() << "Authentication failed.";
        QMessageBox::critical(this, tr("Login Failed"),
                              tr("Invalid username or password."),
                              QMessageBox::Ok);
    }

}
*/
/*
void MainWindow::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    qDebug() << "Trying to authenticate user:" << username;

    User user(username, password);

    if (user.authenticate()) {
        qDebug() << "User authenticated successfully.";

        // Create a connection object and check the connection
        Connection connection;
        if (!connection.createconnect()) {
            qDebug() << "Failed to connect to the database.";
            QMessageBox::critical(this, tr("Database Connection Error"),
                                  tr("Failed to connect to the database.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
            return;
        }

        qDebug() << "Database connection established.";

        if (username == "client") {
            int tabIndex = ui->tabclient->indexOf(ui->tab_4);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                qDebug() << "Tab_4 activé et sélectionné pour le client.";
            } else {
                qDebug() << "Tab_4 introuvable ou index incorrect.";
            }
        } else if (username == "commande") {
            int tabIndex = ui->tabclient->indexOf(ui->gestion_commade);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                // Charger les données dans le tableViewCommande
                ui->tableViewCommande->setModel(Ctemp.afficher());

                qDebug() << "Gestion des commandes activée et sélectionnée.";
            } else {
                qDebug() << "Gestion des commandes introuvable ou index incorrect.";
            }
        } else if (username == "produit") {
            int tabIndex = ui->tabclient->indexOf(ui->gestion_produit);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                // Charger les données dans le tableauproduits
                produits p;
                QSqlQueryModel *model = p.afficherProduits();
                ui->tableauproduits->setModel(model);
                ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
                ui->tableauproduits->setModel(p.afficherProduits());
                chartView = nullptr;

                delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
                ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
                connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
                connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);

                qDebug() << "Gestion des produits activée et sélectionnée.";
            } else {
                qDebug() << "Gestion des produits introuvable ou index incorrect.";
            }
        } else {
            // Enable and switch to Tab 2 for other users
            ui->tabclient->setTabEnabled(1, true);
            ui->tabclient->setCurrentIndex(1);

            // Disable Tab 1
            ui->tabclient->setTabEnabled(0, false);

            // Display employees in the QTableView at startup for non-client users
            ui->tableView_employee->setModel(emp.afficher());
            ui->tableViewCommande->setModel(Ctemp.afficher()); // Charger les données dans le tableViewCommande
            produits p;
            QSqlQueryModel *model = p.afficherProduits();
            ui->tableauproduits->setModel(model);
            ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
            ui->tableauproduits->setModel(p.afficherProduits());
            chartView = nullptr;

            delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
            ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
            connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
            connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);
        }

    } else {
        qDebug() << "Authentication failed.";
        QMessageBox::critical(this, tr("Login Failed"),
                              tr("Invalid username or password."),
                              QMessageBox::Ok);
    }
}
*/
void MainWindow::on_buttonWelcome_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    qDebug() << "Trying to authenticate user:" << username;

    User user(username, password);

    if (user.authenticate()) {
        qDebug() << "User authenticated successfully.";

        // Create a connection object and check the connection
        Connection connection;
        if (!connection.createconnect()) {
            qDebug() << "Failed to connect to the database.";
            QMessageBox::critical(this, tr("Database Connection Error"),
                                  tr("Failed to connect to the database.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
            return;
        }

        qDebug() << "Database connection established.";

        if (username == "client") {
            int tabIndex = ui->tabclient->indexOf(ui->tab_4);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                qDebug() << "Tab_4 activé et sélectionné pour le client.";
            } else {
                qDebug() << "Tab_4 introuvable ou index incorrect.";
            }
        } else if (username == "commande") {
            int tabIndex = ui->tabclient->indexOf(ui->gestion_commade);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                // Charger les données dans le tableViewCommande
                ui->tableViewCommande->setModel(Ctemp.afficher());

                qDebug() << "Gestion des commandes activée et sélectionnée.";
            } else {
                qDebug() << "Gestion des commandes introuvable ou index incorrect.";
            }
        } else if (username == "produit") {
            int tabIndex = ui->tabclient->indexOf(ui->gestion_produit);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                // Charger les données dans le tableauproduits
                produits p;

                 QSqlQueryModel *model = p.afficherProduits();
                ui->tableauproduits->setModel(model);
                ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
                ui->tableauproduits->setModel(p.afficherProduits());
                chartView = nullptr;

                delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
                ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
                connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
                connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);

                qDebug() << "Gestion des produits activée et sélectionnée.";
            } else {
                qDebug() << "Gestion des produits introuvable ou index incorrect.";
            }
        } else if (username == "equipement") {
            int tabIndex = ui->tabclient->indexOf(ui->tab_5);

            if (tabIndex != -1) {
                // Activer l'onglet
                ui->tabclient->setTabEnabled(tabIndex, true);

                // Basculer vers l'onglet
                ui->tabclient->setCurrentIndex(tabIndex);

                // Désactiver tous les autres onglets
                for (int i = 0; i < ui->tabclient->count(); ++i) {
                    if (i != tabIndex) {
                        ui->tabclient->setTabEnabled(i, false);
                    }
                }

                qDebug() << "Tab_5 activé et sélectionné pour l'équipement.";
            } else {
                qDebug() << "Tab_5 introuvable ou index incorrect.";
            }
        } else {
            // Enable and switch to Tab 2 for other users
            ui->tabclient->setTabEnabled(1, true);
            ui->tabclient->setCurrentIndex(1);

            // Disable Tab 1
            ui->tabclient->setTabEnabled(0, false);

            // Display employees in the QTableView at startup for non-client users
            ui->tableView_employee->setModel(emp.afficher());
            ui->tableViewCommande->setModel(Ctemp.afficher()); // Charger les données dans le tableViewCommande
            produits p;
            QSqlQueryModel *model = p.afficherProduits();
            ui->tableauproduits->setModel(model);
            ui->tableauproduits->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
            ui->tableauproduits->setModel(p.afficherProduits());
            chartView = nullptr;


            delegateDeuxBouttons *delegate = new delegateDeuxBouttons(this);
            ui->tableauproduits->setItemDelegateForColumn(model->columnCount() - 1, delegate);
            connect(delegate, &delegateDeuxBouttons::modifierClicked, this, &MainWindow::onModifierClicked);
            connect(delegate, &delegateDeuxBouttons::supprimerClicked, this, &MainWindow::onSupprimerClicked);
        }

    } else {
        qDebug() << "Authentication failed.";
        QMessageBox::critical(this, tr("Login Failed"),
                              tr("Invalid username or password."),
                              QMessageBox::Ok);
    }
}


void MainWindow::on_yourPasswordButton_clicked()
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
void MainWindow::on_tableView_employee_clicked(const QModelIndex &index)
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

//-----------------------------Gestion Produit----------------------------------------------------

void MainWindow::onMessageReceived(const QByteArray &data)
{
    ui->outputText->append("donnée: " + data);
    qDebug()  << data;
}
void MainWindow::readSerialData()
{
    QByteArray data = arduino->read_from_arduino();
    qDebug()  << data;

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



void MainWindow::on_modifierProduit_clicked() {
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
//ajout

void MainWindow::on_ajouterProduit_clicked(){
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
    // Sélection du fichier de sauvegarde
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le PDF"), "", tr("PDF Files (*.pdf);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    // Création de l'écrivain PDF
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);  // Résolution de l'impression
    pdfWriter.setPageMargins(QMarginsF(15, 15, 15, 15)); // Marges de la page
    QPainter painter(&pdfWriter);

    // Initialisation de la position verticale
    int y = 100;
    int page = 1;

    // Titre principal
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(100, y, tr("Liste des Produits"));

    // Date actuelle
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");
    painter.setFont(QFont("Arial", 12));
    painter.drawText(pdfWriter.width() - 500, y, tr("Date : ") + currentDate);

    // Ligne sous le titre
    y += 50;
    painter.drawLine(100, y, pdfWriter.width() - 100, y);

    y += 50; // Espace après le titre

    // Largeur de colonne
    int colWidth = (pdfWriter.width() - 200) / 7; // Calcul dynamique

    // Fonction pour dessiner les en-têtes
    auto drawHeaders = [&]() {
        QStringList headers = { "IDP", "NomP", "DateExp", "Quantité", "Humidité", "Temp", "DateAjout" };
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.setBrush(Qt::lightGray);

        for (int i = 0; i < headers.size(); ++i) {
            painter.drawRect(100 + i * colWidth, y, colWidth, 40);
            painter.drawText(110 + i * colWidth, y + 30, headers[i]);
        }
        y += 50; // Ligne suivante
    };

    drawHeaders(); // Dessiner les en-têtes de la première page

    // Remplissage des lignes du tableau
    painter.setFont(QFont("Arial", 10));
    painter.setBrush(Qt::NoBrush); // Pas de fond pour les cellules
    QSqlQuery query("SELECT idproduit, nomproduit, dateExpiration, quantiteDisponible, humidite, temperature, dateAjout FROM Produits");
    while (query.next()) {
        if (y > pdfWriter.height() - 200) { // Vérification si la page est pleine
            painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));
            pdfWriter.newPage();
            y = 100; // Réinitialisation de la position
            page++;
            drawHeaders(); // Répéter les en-têtes
        }

        // Dessiner les colonnes
        QStringList data = {
            query.value("idproduit").toString(),
            query.value("nomproduit").toString(),
            query.value("dateExpiration").toDate().toString("dd/MM/yyyy"),
            query.value("quantiteDisponible").toString(),
            query.value("humidite").toString(),
            query.value("temperature").toString(),
            query.value("dateAjout").toDate().toString("dd/MM/yyyy")
        };

        for (int i = 0; i < data.size(); ++i) {
            painter.drawRect(100 + i * colWidth, y, colWidth, 40);
            painter.drawText(110 + i * colWidth, y + 30, data[i]);
        }
        y += 50; // Ligne suivante
    }

    // Ajouter le numéro de page à la fin
    painter.drawText(pdfWriter.width() - 200, pdfWriter.height() - 50, tr("Page ") + QString::number(page));

    painter.end();
    QMessageBox::information(this, tr("PDF généré"), tr("Le fichier PDF a été généré avec succès."));
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
    QString temperature = model->data(temperatureIndex).toString();

    // Afficher la température récupérée
    QMessageBox::information(this, "Température trouvée", QString("La température du produit %1 est %2°C").arg(productName).arg(temperature));


    QString data=arduino->getGlobalData().trimmed();
    int dataI =data.toInt();
    qDebug() <<data;
    qDebug() <<temperature;

    // Contrôler le ventilateur en fonction de la température
    if (temperature < data) {
        sendToArduino(*arduino, "g"); // Allumer le ventilateur
        QMessageBox::information(this, "Ventilateur activé", "Température élevée. Le ventilateur a été activé.");
    } else {
        sendToArduino(*arduino, "s"); // Éteindre le ventilateur
        QMessageBox::information(this, "Ventilateur désactivé", "Température normale. Le ventilateur a été éteint.");
    }



    // Nettoyage
    delete model;
}



//---------------------------------gestion commande------------------------------------------------

void MainWindow::on_tableViewCommande_clicked(const QModelIndex &index) {
    if (!index.isValid())
        return;

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->tableViewCommande->model());
    if (model) {
        int row = index.row();

        // Extraire les données de la ligne sélectionnée
        QString id = model->data(model->index(row, 0)).toString();
        QString dateCommande = model->data(model->index(row, 1)).toString();
        QString etatCommande = model->data(model->index(row, 2)).toString();
        QString prix = model->data(model->index(row, 3)).toString();
        QString pointFidelite = model->data(model->index(row, 4)).toString();

        // Déboguer les valeurs extraites
        qDebug() << "Ligne sélectionnée:" << row;
        qDebug() << "ID : " << id;
        qDebug() << "Date : " << dateCommande;
        qDebug() << "État : " << etatCommande;
        qDebug() << "Prix : " << prix;
        qDebug() << "Points fidélité : " << pointFidelite;

        // Remplir les QLineEdits avec les valeurs extraites
        ui->idInputC->setText(id);
        ui->dateInputC->setText(dateCommande);
        ui->etatInputC->setText(etatCommande);
        ui->prixInputC->setText(prix);
        ui->fideliteInputC->setText(pointFidelite);
    }
}


void MainWindow::setupConnections() {
    connect(ui->tableViewCommande, &QTableView::clicked, this, &MainWindow::on_tableViewCommande_clicked);
}


void MainWindow::on_ajouterCommande_clicked() {

    int id = ui->idInputC->text().toInt();
    QString dateCommandeStr = ui->dateInputC->text(); // La date est maintenant juste une chaîne de caractères.
    QString etatCommande = ui->etatInputC->text();
    float prix = ui->prixInputC->text().toFloat();  // Assurer que le prix est bien un float.
    int pointFidelite = ui->fideliteInputC->text().toInt();


    if (ui->idInputC->text().isEmpty() && ui->dateInputC->text().isEmpty() &&
        ui->etatInputC->text().isEmpty() && ui->prixInputC->text().isEmpty() &&
        ui->fideliteInputC->text().isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Veuillez remplir au moins le champ ID."));
        return;
    }


    if (id <= 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID doit être un entier positif et différent de zéro."));
        return;
    }


    if (prix <= 20.0f) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("Le prix doit être supérieur à 20."));
        return;
    }


    Commande c(id, dateCommandeStr, etatCommande, prix, pointFidelite);
    bool test = c.ajouter();


    if (test) {
        ui->tableViewCommande->setModel(Ctemp.afficher());
        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("L'ajout a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}





void MainWindow::on_ModifierCommande_clicked() {
    int id = ui->idInputC->text().toInt();
    QString dateCommande = ui->dateInputC->text();
    QString etatCommande = ui->etatInputC->text();
    float prix = ui->prixInputC->text().toFloat();
    int pointFidelite = ui->fideliteInputC->text().toInt();


    if (id <= 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID de la commande doit être valide."));
        return;
    }

    Commande cmdToUpdate(id, dateCommande, etatCommande, prix, pointFidelite);
    bool exists = cmdToUpdate.idExiste(id);
    if (!exists) {
        QMessageBox::warning(this, tr("Erreur"), tr("Cette commande n'existe pas."));
        return;
    }


    bool test = cmdToUpdate.modifier();
    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("La commande a été modifiée avec succès."));
        ui->tableViewCommande->setModel(cmdToUpdate.afficher());

    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La modification de la commande a échoué."));
    }
}





void MainWindow::on_SupprimerCommande_clicked() {
    int id = ui->suppCommande->text().toInt();


    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }


    bool test = Ctemp.supprimer(id);

    if (test) {

        QSqlQueryModel* model = Ctemp.afficher();
        if (model) {// model valide
            ui->tableViewCommande->setModel(model);// affichage tableView bel mise a
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Suppression effectuée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

        } else {
            QMessageBox::critical(this, QObject::tr("Erreur"),
                                  QObject::tr("Échec du rafraîchissement de la table.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("La suppression a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pdfCommande_clicked()
{
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");//dialog yekhtar win ihot fich ***nomfich chemin
    if (!nomFichier.isEmpty()) {
        Commande commande;


        QSqlQueryModel *model = commande.afficher();


        commande.exporterPDF(nomFichier, model);



        delete model;

        QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
    }
}

void MainWindow::on_TrierCommande_clicked() {

    QSqlQueryModel* model = Ctemp.trierParDate();
    if (model) {

        ui->tableViewCommande->setModel(model);

        ui->tableViewCommande->setModel(model);

        // ui->tabWidget->setCurrentWidget(ui->tableView);


        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Tri effectué par date du plus proche au plus loin.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("Le tri a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}






void MainWindow::on_statistiqueCommande_clicked() {

    ui->stackedWidgetCommande->setCurrentIndex(0);
    Commande commande;
    QMap<QString, int> statistiques = commande.getStatistiquesParEtat();//ihezehom ml fonction commande ihotehom fl map

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }


    QPieSeries *series = new QPieSeries();//dsign cerculaire
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(it.value()), it.value());// ajouter chaque etat comme une tranche


        if (series->slices().size() % 2 == 0) {
            slice->setBrush(QColor(173, 216, 230)); // Gris clair
        } else {
            slice->setBrush(QColor(152, 251, 152)); // Vert pastel
        }


        slice->setLabelVisible(true);
    }


    QChart *chart = new QChart();// objet pour graphique
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QFont titleFont;
    titleFont.setPixelSize(20);
    titleFont.setBold(true);
    titleFont.setItalic(false);
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(QColor(152, 251, 152)));


    QFont labelFont;
    labelFont.setPixelSize(16);
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelFont(labelFont);
        slice->setLabelBrush(QBrush(QColor(152, 251, 152)));
    }


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QLayoutItem *item;
    while ((item = ui->verticalLayoutCommande->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }


    ui->verticalLayoutCommande->addWidget(chartView);





    qDebug() << "Statistiques mises à jour et graphique actualisé.";
}






void MainWindow::on_rechercherCommande_2_clicked()
{
    QString id = ui->rechercherCommande->text().trimmed(); // Récupère l'ID entré par l'utilisateur
    QSqlQuery query; // Préparer et exécuter des requêtes SQL


    query.prepare("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id); // Remplacement de ":id" par la valeur réelle de id

    if (query.exec()) {
        if (query.next()) {

            QString dateCommande = query.value("dateCommande").toString();
            QString etatCommande = query.value("etatCommande").toString();
            float prix = query.value("prix").toFloat();
            int pointFidelite = query.value("pointFidelite").toInt();



            QStandardItemModel *model = new QStandardItemModel(this);
            model->setColumnCount(5); // Nombre de colonnes
            model->setHorizontalHeaderLabels({"ID", "Date Commande", "État", "Prix", "Points de Fidélité"});


            QList<QStandardItem *> row;
            row.append(new QStandardItem(id));
            row.append(new QStandardItem(dateCommande));
            row.append(new QStandardItem(etatCommande));
            row.append(new QStandardItem(QString::number(prix, 'f', 2)));
            row.append(new QStandardItem(QString::number(pointFidelite)));

            model->appendRow(row);
            ui->tableViewCommande->setModel(model);

            // Afficher un message de succès
            QMessageBox::information(this, tr("Recherche"), tr("Commande trouvée avec succès."));


            chargerCommandes();
        } else {

            QMessageBox::information(this, tr("Recherche"), tr("Aucune commande trouvée avec cet ID."));


            chargerCommandes();
        }
    } else {

        QMessageBox::warning(this, tr("Erreur"), tr("Échec de la recherche dans la base de données : ") + query.lastError().text());


        chargerCommandes();
    }
}







void MainWindow::on_calculerReductionCommande_clicked() {

    QString idText = ui->idReduction->text();


    if (idText.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID !");
        return;
    }


    bool conversionOk;
    int id = idText.toInt(&conversionOk);


    if (!conversionOk || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return; // Arrêter l'exécution si la conversion échoue
    }

    Commande commande;


    if (commande.calculerReductionAvecUpdate(id)) {
        QMessageBox::information(this, "Succès", "Réduction appliquée avec succès.");


        QSqlQueryModel *model = new QSqlQueryModel();//afficher sur tableView
        QSqlQuery query;//préparer et exécuter des requêtes SQL
        query.exec("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes");
        model->setQuery(std::move(query));//trnsfere le model
        ui->tableViewCommande->setModel(model);//associé model au tableView
        ui->tableViewCommande->resizeColumnsToContents();//ajustertaimlle de colone
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'application de la réduction.");
    }
}


void MainWindow::on_effacerCommande_clicked()
{
    ui->idInputC->clear();
    ui->dateInputC->clear();
    ui->etatInputC->clear();
    ui->prixInputC->clear();
    ui->fideliteInputC->clear();

}
void MainWindow::on_calendrierCommande_clicked() {



    afficherCalendrier();
}

void MainWindow::afficherCalendrier() {

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Calendrier");
    dialog->resize(400, 450);


    QCalendarWidget *calendrier = new QCalendarWidget(dialog);
    calendrier->setGridVisible(true);
    calendrier->setGeometry(10, 10, 380, 300);


    mettreEnEvidenceDates(calendrier);


    QPushButton *btnFermer = new QPushButton("Fermer", dialog);
    btnFermer->setGeometry(150, 350, 100, 30);//position et taille


    connect(btnFermer, &QPushButton::clicked, this, [=]() {

        dialog->accept();
    });


    connect(calendrier, &QCalendarWidget::clicked, this, [=](const QDate &date) {
        qDebug() << "Date sélectionnée dans le calendrier:" << date.toString("dd/MM/yyyy");

    });

    // Afficher le dialogue
    dialog->exec();


    dialog->deleteLater();
}



void MainWindow::mettreEnEvidenceDates(QCalendarWidget *calendrier) {

    QTextCharFormat formatPreparation;
    formatPreparation.setBackground(Qt::yellow);

    QTextCharFormat formatTraite;
    formatTraite.setBackground(Qt::green);

    QTextCharFormat formatRecu;
    formatRecu.setBackground(Qt::red);


    QSqlQuery query("SELECT DISTINCT dateCommande, etatCommande FROM commandes");
    while (query.next()) {
        QString dateCommande = query.value(0).toString();
        QString etatCommande = query.value(1).toString();
        QDate date = QDate::fromString(dateCommande, "dd/MM/yyyy"); // Convertir la date au bon format

        if (date.isValid()) {
            qDebug() << "Date avec commande trouvée:" << date.toString("yyyy-MM-dd") << ", État:" << etatCommande;


            if (etatCommande == "en preparation") {
                calendrier->setDateTextFormat(date, formatPreparation);
            } else if (etatCommande == "traite") {
                calendrier->setDateTextFormat(date, formatTraite);
            } else if (etatCommande == "recu") {
                calendrier->setDateTextFormat(date, formatRecu);
            }
        } else {
            qDebug() << "Date invalide:" << dateCommande;
        }
    }
}





void MainWindow::chargerCommandes()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);


    model->setQuery("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Commande"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("État Commande"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Points de Fidélité"));


    ui->tableViewCommande->setModel(model);
}
void MainWindow::on_RetourCommande_clicked()
{
    ui->stackedWidgetCommande->setCurrentIndex(1);
}

//---------------------------------gestion equipement------------------------------------------------

void MainWindow::genererStatistiquesParEtat()
{
    QSqlQuery query;
    query.prepare("SELECT ETAT, COUNT(*) AS nombre_equipements FROM EQUIPEMENT GROUP BY ETAT");

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL : " << query.lastError();
        QMessageBox::critical(this, "Erreur", "La requête SQL a échoué. Vérifiez votre base de données.");
        return;
    }

    if (!query.next()) {
        QMessageBox::information(this, "Aucune donnée", "Aucune donnée à afficher pour les statistiques.");
        return;
    }

    // Créer une série pour le diagramme en secteurs
    QPieSeries *series = new QPieSeries();
    do {
        QString etat = query.value("ETAT").toString();
        int nombreEquipements = query.value("nombre_equipements").toInt();

        // Générer une couleur aléatoire pour chaque tranche
        QColor randomColor(rand() % 256, rand() % 256, rand() % 256);

        QPieSlice *slice = series->append(etat + ": " + QString::number(nombreEquipements), nombreEquipements);
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setBrush(randomColor);  // Appliquer la couleur aléatoire
    } while (query.next());

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des équipements par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer une vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un bouton "Fermer"
    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet(
        "QPushButton {"
        "background-color: #f0f0f0;"
        "font-size: 14px;"
        "padding: 5px 10px;"
        "}"
        );

    connect(closeButton, &QPushButton::clicked, this, [this]() {
        ui->equip_stackedWidget->hide();
    });

    // Créer une nouvelle page pour le QStackedWidget
    QWidget *statPage = new QWidget();
    QVBoxLayout *pageLayout = new QVBoxLayout(statPage);
    pageLayout->addWidget(chartView);
    pageLayout->addWidget(closeButton);

    // Supprimer les anciennes pages du QStackedWidget
    while (ui->equip_stackedWidget->count() > 0) {
        QWidget *widgetToRemove = ui->equip_stackedWidget->widget(0);
        ui->equip_stackedWidget->removeWidget(widgetToRemove);
        widgetToRemove->deleteLater();
    }

    // Ajouter la nouvelle page au QStackedWidget
    ui->equip_stackedWidget->addWidget(statPage);

    // Afficher la nouvelle page
    ui->equip_stackedWidget->setCurrentWidget(statPage);
    ui->equip_stackedWidget->show();
}
// Connecter cette fonction au bouton "pushButton_stat"
void MainWindow::on_equip_stat_clicked()
{
    genererStatistiquesParEtat();
}

// Bouton Ajouter
void MainWindow::on_ajouter_equip_clicked() {
    // Récupérer les valeurs des QLineEdit
    int id = ui->equipement_id->text().toInt(); // Convertir en entier
    QString nom = ui->equipement_nom->text();
    QString type = ui->equipement_type->text();
    QString date = ui->equipement_date->text();
    QString etat = ui->equipement_etat->text();

    // Créer un objet Equipement et ajouter à la base
    Equipement equip(id, nom, type, date, etat);
    if (equip.ajouter()) {
        QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");

        // Mettre à jour le QTableView
        model = Equipement::afficher();
        ui->equipement_tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter l'équipement.");
    }
}
// Implémentation de la fonction de suppression


void MainWindow::on_equip_supprimer_clicked(bool checked)
{
    // Afficher un QInputDialog pour demander l'ID de l'équipement à supprimer
    bool ok;
    int id = QInputDialog::getInt(this, "Supprimer un équipement", "Entrez l'ID de l'équipement à supprimer :",
                                  0, 0, 100000, 1, &ok);  // Plage d'ID : 0 à 100000

    if (ok) {  // Si l'utilisateur clique sur OK
        // Appeler la méthode supprimer de la classe Equipement avec l'ID saisi
        if (Equipement::supprimer(id)) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès.");

            // Mettre à jour le QTableView pour afficher les équipements restants
            model = Equipement::afficher();
            ui->equipement_tableView->setModel(model);
        } else {
            QMessageBox::critical(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        }
    } else {
        // Si l'utilisateur annule la saisie, rien ne se passe
        QMessageBox::information(this, "Annulation", "Suppression annulée.");
    }
}
void MainWindow::on_equip_modifier_clicked() {
    // Demander l'ID de l'équipement à modifier
    bool ok;
    int id = QInputDialog::getInt(this, "Modifier un équipement", "Entrez l'ID de l'équipement à modifier :",
                                  0, 0, 100000, 1, &ok);

    if (ok) {
        // Charger les informations actuelles
        QSqlQuery query;
        query.prepare("SELECT NOM_EQUIP, TYPE, DATE_MAINTENANCE, ETAT FROM equipement WHERE ID_EQUIP = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            // Stocker l'ID actuel
            idActuel = id;

            // Afficher les données dans les QLineEdit
            ui->lineEdit_modif_nom->setText(query.value(0).toString());
            ui->lineEdit_modif_type->setText(query.value(1).toString());
            ui->lineEdit_modif_date->setText(query.value(2).toString());
            ui->lineEdit_modif_etat->setText(query.value(3).toString());

            // Activer les champs et le bouton "Valider"
            ui->lineEdit_modif_nom->setEnabled(true);
            ui->lineEdit_modif_type->setEnabled(true);
            ui->lineEdit_modif_date->setEnabled(true);
            ui->lineEdit_modif_etat->setEnabled(true);
            ui->equip_valider->setEnabled(true);
        } else {
            QMessageBox::critical(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        }
    } else {
        QMessageBox::information(this, "Annulation", "Modification annulée.");
    }
}
void MainWindow::on_equip_valider_clicked() {
    if (idActuel == -1) {
        QMessageBox::warning(this, "Erreur", "Aucun équipement sélectionné pour modification.");
        return;
    }

    // Récupérer les nouvelles données des QLineEdit
    QString nom = ui->lineEdit_modif_nom->text();
    QString type = ui->lineEdit_modif_type->text();
    QString date = ui->lineEdit_modif_date->text();
    QString etat = ui->lineEdit_modif_etat->text();

    // Vérifier que les champs ne sont pas vides
    if (nom.isEmpty() || type.isEmpty() || date.isEmpty() || etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Mettre à jour les données dans la base
    QSqlQuery query;
    query.prepare("UPDATE equipement SET NOM_EQUIP = :nom, TYPE = :type, DATE_MAINTENANCE = :date, ETAT = :etat WHERE ID_EQUIP = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":etat", etat);
    query.bindValue(":id", idActuel);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Équipement modifié avec succès.");

        // Réinitialiser les champs
        ui->lineEdit_modif_nom->clear();
        ui->lineEdit_modif_type->clear();
        ui->lineEdit_modif_date->clear();
        ui->lineEdit_modif_etat->clear();
        ui->lineEdit_modif_nom->setEnabled(false);
        ui->lineEdit_modif_type->setEnabled(false);
        ui->lineEdit_modif_date->setEnabled(false);
        ui->lineEdit_modif_etat->setEnabled(false);
        ui->equip_valider->setEnabled(false);

        // Réinitialiser l'ID actuel
        idActuel = -1;

        // Mettre à jour la vue
        model = Equipement::afficher();
        ui->equipement_tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de modifier l'équipement.");
    }
}

void MainWindow::on_equip_trier_clicked() {
    // Récupérer les données triées et les afficher dans le QTableView
    model = Equipement::trierParNom();
    ui->equipement_tableView->setModel(model);

    QMessageBox::information(this, "Tri effectué", "Les équipements ont été triés par nom (A-Z).");
}

void MainWindow::on_equip_PDF_clicked() {
    // Ouvrir une boîte de dialogue pour sélectionner le chemin de sauvegarde du PDF
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        // Initialiser un modèle pour récupérer les données de la table `equipement`
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT ID_EQUIP, NOM_EQUIP, TYPE, DATE_MAINTENANCE, ETAT FROM equipement");

        // Vérifier si la table contient des données
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun équipement à exporter.");
            delete model; // Libération de la mémoire
            return;
        }

        // Appeler la fonction pour exporter vers PDF
        bool exportSuccess = exporterPDF(nomFichier, model);

        // Libération de mémoire
        delete model;

        // Afficher un message en fonction du succès ou de l'échec
        if (exportSuccess) {
            QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
        } else {
            QMessageBox::critical(this, "Erreur d'exportation", "L'exportation vers PDF a échoué.");
        }
    }
}

bool MainWindow::exporterPDF(const QString &nomFichier, QAbstractItemModel *model) {
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        qDebug() << "Erreur lors de l'initialisation du QPainter pour le PDF.";
        return false;
    }

    // Titre du PDF
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(2000, 1100, "Liste des Équipements");

    // Coordonnées et dimensions des cellules du tableau
    int startX = 200;          // Position X de départ
    int startY = 1800;         // Position Y de départ
    int cellWidth = 1500;      // Largeur des cellules
    int cellHeight = 450;      // Hauteur des cellules

    // En-têtes des colonnes
    QStringList headers = {"ID Equip", "Nom Equip", "Type", "Date Maintenance", "État"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    // Dessiner les en-têtes
    for (int col = 0; col < headers.size(); ++col) {
        QRect headerRect(startX + col * cellWidth, startY, cellWidth, cellHeight);
        painter.drawRect(headerRect); // Dessiner les bordures
        painter.drawText(headerRect, Qt::AlignCenter, headers[col]); // Écrire le texte
    }

    // Données de la table `equipement`
    painter.setFont(QFont("Arial", 10));
    int rowCount = model->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white; // Couleur alternée pour les lignes

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);         // Remplir la cellule avec une couleur de fond
            painter.drawText(cellRect, Qt::AlignCenter, data); // Écrire les données
            painter.drawRect(cellRect);                 // Dessiner les bordures de la cellule
        }
    }

    painter.end();
    return true; // Exportation réussie
}



void MainWindow::on_equip_Prevoir_clicked() {
    // Récupérer l'ID depuis le champ `lineEditPrevoir`
    bool conversionOk;
    int idEquipement = ui->equipement_Prevoir->text().toInt(&conversionOk);

    if (!conversionOk || idEquipement <= 0) {
        QMessageBox::warning(this, "Entrée invalide", "Veuillez entrer un ID valide pour l'équipement.");
        return;
    }

    // Appeler la fonction de prévision
    QString resultat = Equipement::prevoirUsure(idEquipement);

    // Afficher le résultat
    if (resultat.startsWith("Erreur")) {
        QMessageBox::critical(this, "Erreur", resultat);
    } else {
        QMessageBox::information(this, "Prévision d'usure", resultat);
    }
}

void MainWindow::on_equip_Planifier_clicked() {
    bool ok;
    int id_equip = ui->equipement_Planifier->text().toInt(&ok);  // Convertir l'ID de l'équipement en entier

    if (!ok || id_equip <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement valide.");
        return;
    }

    Equipement equipement;
    QString resultat = equipement.planifierMaintenance(id_equip);  // Appel de la méthode pour planifier la maintenance

    // Affichage du résultat dans un message box
    QMessageBox::information(this, "Planification de la maintenance", resultat);
}

void MainWindow::on_equip_Recherche_clicked() {
    // Récupérer l'ID depuis lineEdit
    QString idText = ui->equipement_recherche->text();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID.");
        return;
    }

    int id = idText.toInt();

    // Appeler la fonction de recherche
    Equipement equipement;
    QString resultat = equipement.rechercherParId(id);

    // Afficher le résultat dans un QMessageBox
    QMessageBox::information(this, "Résultat de la recherche", resultat);
}

void MainWindow::updateEtatCycle(QMap<QString, int> statistiques)
{
    int total = 0;
    for (auto count : statistiques.values()) {
        total += count; // Calcul du total des équipements
    }

    if (total == 0) {
        qDebug() << "Aucun équipement trouvé pour les statistiques.";
        return;
    }

    // Accéder à la scène actuelle
    QGraphicsScene *scene = ui->graphicsView->scene();
    if (!scene) {
        scene = new QGraphicsScene();
        ui->graphicsView->setScene(scene);
    } else {
        scene->clear();
    }

    int radius = 100;  // Rayon du cercle
    int centerX = 150; // Centre X
    int centerY = 150; // Centre Y

    qreal startAngle = 90; // Angle de départ

    // Générer les arcs pour chaque état
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QString etat = it.key();
        int count = it.value();

        qreal angleSpan = 360.0 * count / total; // Portion de l'angle

        QPainterPath path;
        path.moveTo(centerX, centerY);
        path.arcTo(centerX - radius, centerY - radius, 2 * radius, 2 * radius, startAngle, -angleSpan);

        QGraphicsPathItem *arc = scene->addPath(path, QPen(Qt::black), QBrush(Qt::blue));
        if (etat == "bon état") arc->setBrush(Qt::green);
        else if (etat == "état moyen") arc->setBrush(Qt::yellow);
        else if (etat == "état mauvais") arc->setBrush(Qt::red);

        // Ajouter le pourcentage
        QString percentageText = QString::number((count * 100.0) / total, 'f', 1) + "%";
        QGraphicsTextItem *text = new QGraphicsTextItem(etat + ": " + percentageText);
        text->setFont(QFont("Arial", 10, QFont::Bold));
        text->setDefaultTextColor(Qt::black);
        text->setPos(centerX + radius * qCos(qDegreesToRadians(startAngle - angleSpan / 2)) - text->boundingRect().width() / 2,
                     centerY - radius * qSin(qDegreesToRadians(startAngle - angleSpan / 2)) - text->boundingRect().height() / 2);
        scene->addItem(text);

        startAngle -= angleSpan; // Ajuster l'angle de départ pour le prochain segment
    }

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_vende_clicked()
{
    Equipement equipement;
    QMap<QString, int> statistiques = equipement.getEtatStatistics();

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }

    updateEtatCycle(statistiques); // Mettre à jour le graphique
}


void MainWindow::on_equip_arduino_clicked()
{
    // Récupérer l'ID de l'équipement depuis l'interface utilisateur
    QString id_equipement = ui->equipement_Arduino->text();

    // Vérifier si l'ID est vide
    if (id_equipement.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement.");
        return;
    }

    // Récupérer l'état de l'équipement depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT ETAT FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id_equipement);

    // Vérifier si la requête a réussi et s'il y a un résultat
    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();

        QByteArray command;

        // En fonction de l'état de l'équipement, définir la commande à envoyer à l'Arduino
        if (etat == "bon etat") {
            command = "buzzer_on\n"; // Commande pour activer le buzzer une fois
        } else if (etat == "etat moyen") {
            // Envoyer deux commandes pour deux bips
            command = "buzzer_on\nbuzzer_on\n";
        } else if (etat == "etat mauvais") {
            // Envoyer trois commandes pour trois bips
            command = "buzzer_on\nbuzzer_on\nbuzzer_on\n";
        } else {
            QMessageBox::information(this, "État inconnu", "L'état de l'équipement n'est pas reconnu.");
            return;
        }

        // Vérifier si Arduino est connecté et envoyer la commande
        if (arduino->getserial()->isOpen()) {
            arduino->write_to_arduino(command);
        } else {
            QMessageBox::warning(this, "Erreur de connexion", "Impossible de se connecter à l'Arduino.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Équipement non trouvé.");
    }
}


void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}







