/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *ajouter;
    QPushButton *pushButton_supprimer;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_modif_etat;
    QLabel *label_9;
    QLineEdit *lineEdit_modif_date;
    QLabel *label_10;
    QLineEdit *lineEdit_modif_type;
    QLabel *label_12;
    QLineEdit *lineEdit_modif_nom;
    QLabel *label_13;
    QPushButton *modifier;
    QPushButton *valider_modif;
    QPushButton *trier;
    QPushButton *exporterPDF;
    QPushButton *pushButton_statistiques;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QLineEdit *lineEdit_date;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_etat;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_nom;
    QLabel *label_7;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLineEdit *lineEditPrevoir;
    QPushButton *pushButtonPrevoir;
    QPushButton *pushButtonPlanifier;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLineEdit *lineEditPlanifier;
    QGroupBox *groupBox_5;
    QLabel *label_3;
    QLineEdit *lineEdit_recherche;
    QPushButton *pushButtonRecherche;
    QMenuBar *menuBar;
    QMenu *menuGestion_des_quipements;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1422, 646);
        MainWindow->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgb(200, 255, 200); /* Fond plus clair */\n"
"    border: 2px solid #1C8A4F;\n"
"    border-radius: 10px;\n"
"    color: black;\n"
"    font-size: 14px;\n"
"    font-family: \"Helvetica Neue\", Arial, sans-serif; /* Police claire Helvetica Neue */\n"
"    font-weight: bold; /* Applique le texte en gras */\n"
"    selection-background-color: rgb(28, 168, 79); /* Fond de s\303\251lection */\n"
"    selection-color: white;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    font-family: \"Segoe UI\", Tahoma, sans-serif; /* Police claire Segoe UI pour les cellules */\n"
"    font-weight: bold; /* Applique le texte en gras pour les cellules */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: rgb(28, 168, 79);\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgb(150, 200, 150);\n"
"    color: black;\n"
"    font-weight: bold; /* En-t\303\252tes en gras */\n"
"    font-family: \"Helvetica "
                        "Neue\", Arial, sans-serif; /* Police claire pour les en-t\303\252tes */\n"
"    border: 1px solid #1C8A4F;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: rgb(200, 255, 200);\n"
"}\n"
"QPushButton {\n"
"    background-color: rgb(50, 120, 90); /* Couleur verte fonc\303\251e */\n"
"    /*color: black;*/\n"
"   /* color: #1f472e;*/\n"
"color:black;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"     \n"
"    font-weight: bold; /* texte en gras */\n"
"    font-size: 20px;\n"
"    text-decoration: underline;  /* Texte soulign\303\251 */\n"
"    line-height: 1.5;\n"
"\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.65;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"    transition: background-color 0.3s ease, opacity 0.3s ease, transform 0.3s ease; /* Transition pour effet plus fluide */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(70, 140, 110); /* Couleur de fond l\303\251g\303\250rement plus claire au survol */\n"
"    op"
                        "acity: 0.85; /* Augmentation de l'opacit\303\251 */\n"
"    transform: scale(1.05); /* Agrandissement l\303\251ger */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Ombre pour donner de la profondeur */\n"
"}\n"
"\n"
"                                                           \n"
"                                               \n"
"QPushButton {\n"
"    background-color: rgb(50, 120, 90); \n"
"    color: black;\n"
"    \n"
"    font-size: 20px;\n"
"    text-decoration: underline;   \n"
"    line-height: 1.5;\n"
"\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.65;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(660, 30, 541, 281));
        ajouter = new QPushButton(centralWidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(20, 60, 111, 29));
        pushButton_supprimer = new QPushButton(centralWidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(20, 110, 111, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(160, 300, 301, 261));
        lineEdit_modif_etat = new QLineEdit(groupBox);
        lineEdit_modif_etat->setObjectName("lineEdit_modif_etat");
        lineEdit_modif_etat->setGeometry(QRect(160, 210, 113, 28));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 100, 121, 20));
        lineEdit_modif_date = new QLineEdit(groupBox);
        lineEdit_modif_date->setObjectName("lineEdit_modif_date");
        lineEdit_modif_date->setGeometry(QRect(160, 150, 113, 28));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 210, 121, 20));
        lineEdit_modif_type = new QLineEdit(groupBox);
        lineEdit_modif_type->setObjectName("lineEdit_modif_type");
        lineEdit_modif_type->setGeometry(QRect(160, 100, 113, 28));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 150, 151, 20));
        lineEdit_modif_nom = new QLineEdit(groupBox);
        lineEdit_modif_nom->setObjectName("lineEdit_modif_nom");
        lineEdit_modif_nom->setGeometry(QRect(160, 50, 113, 28));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 50, 121, 20));
        modifier = new QPushButton(centralWidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(20, 390, 121, 31));
        valider_modif = new QPushButton(centralWidget);
        valider_modif->setObjectName("valider_modif");
        valider_modif->setGeometry(QRect(20, 450, 121, 31));
        trier = new QPushButton(centralWidget);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(30, 210, 83, 29));
        exporterPDF = new QPushButton(centralWidget);
        exporterPDF->setObjectName("exporterPDF");
        exporterPDF->setGeometry(QRect(30, 260, 83, 29));
        pushButton_statistiques = new QPushButton(centralWidget);
        pushButton_statistiques->setObjectName("pushButton_statistiques");
        pushButton_statistiques->setGeometry(QRect(10, 160, 141, 29));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(160, 30, 311, 251));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 30, 111, 20));
        lineEdit_date = new QLineEdit(groupBox_2);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setGeometry(QRect(170, 170, 113, 28));
        lineEdit_type = new QLineEdit(groupBox_2);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(170, 120, 113, 28));
        lineEdit_id = new QLineEdit(groupBox_2);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(170, 30, 113, 28));
        lineEdit_etat = new QLineEdit(groupBox_2);
        lineEdit_etat->setObjectName("lineEdit_etat");
        lineEdit_etat->setGeometry(QRect(170, 210, 113, 28));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 70, 121, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 170, 151, 20));
        lineEdit_nom = new QLineEdit(groupBox_2);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(170, 70, 113, 28));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 210, 121, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 121, 20));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(500, 380, 281, 81));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 141, 20));
        lineEditPrevoir = new QLineEdit(groupBox_3);
        lineEditPrevoir->setObjectName("lineEditPrevoir");
        lineEditPrevoir->setGeometry(QRect(150, 40, 113, 28));
        pushButtonPrevoir = new QPushButton(centralWidget);
        pushButtonPrevoir->setObjectName("pushButtonPrevoir");
        pushButtonPrevoir->setGeometry(QRect(550, 470, 151, 29));
        pushButtonPlanifier = new QPushButton(centralWidget);
        pushButtonPlanifier->setObjectName("pushButtonPlanifier");
        pushButtonPlanifier->setGeometry(QRect(840, 470, 231, 29));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(810, 380, 281, 81));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 141, 20));
        lineEditPlanifier = new QLineEdit(groupBox_4);
        lineEditPlanifier->setObjectName("lineEditPlanifier");
        lineEditPlanifier->setGeometry(QRect(150, 40, 113, 28));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(1120, 380, 281, 81));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 40, 141, 20));
        lineEdit_recherche = new QLineEdit(groupBox_5);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(150, 40, 113, 28));
        pushButtonRecherche = new QPushButton(centralWidget);
        pushButtonRecherche->setObjectName("pushButtonRecherche");
        pushButtonRecherche->setGeometry(QRect(1190, 470, 121, 29));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1422, 25));
        menuGestion_des_quipements = new QMenu(menuBar);
        menuGestion_des_quipements->setObjectName("menuGestion_des_quipements");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGestion_des_quipements->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Type \303\251quipement", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Etat \303\251quipement", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Date de maintenance", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Nom \303\251quipement", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        valider_modif->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        trier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        exporterPDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "Statestiques", nullptr));
        groupBox_2->setTitle(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "ID \303\251quipement", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nom \303\251quipement", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Date de maintenance", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Etat \303\251quipement", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Type \303\251quipement", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Prevision d'usure", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID pour pr\303\251vision", nullptr));
        pushButtonPrevoir->setText(QCoreApplication::translate("MainWindow", "Pr\303\251voir Usure", nullptr));
        pushButtonPlanifier->setText(QCoreApplication::translate("MainWindow", "Planifier Maintenance", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Planification", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID pour planifier", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ID pour chercher", nullptr));
        pushButtonRecherche->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        menuGestion_des_quipements->setTitle(QCoreApplication::translate("MainWindow", "Gestion des \303\251quipements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
