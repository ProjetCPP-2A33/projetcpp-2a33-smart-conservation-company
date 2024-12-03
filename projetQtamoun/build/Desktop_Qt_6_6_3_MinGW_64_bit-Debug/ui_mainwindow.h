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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *header;
    QVBoxLayout *verticalLayout_3;
    QPushButton *bouttonacceuil;
    QSpacerItem *verticalSpacer;
    QPushButton *buttongererProduit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttongererClient;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_4;
    QStackedWidget *stackedwidgetmainbody;
    QWidget *pageacceuil;
    QLabel *label;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QWidget *pagegererproduits;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidgetgererproduit;
    QWidget *pageafficherproduits;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *clerecherche;
    QPushButton *bouttonrecherche;
    QPushButton *bouttonnotification;
    QComboBox *menutri;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *stackedWidgetmodifierajout;
    QWidget *formajout;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushButton_6;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_29;
    QLabel *label_24;
    QLabel *label_28;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_25;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *inputnomproduit_2;
    QDateEdit *inputdateexpiration_2;
    QLineEdit *inputquantitedisponible_2;
    QLineEdit *inputhumidite_2;
    QLineEdit *inputtemperature_2;
    QDateEdit *inputdatedebut_2;
    QWidget *formmodifier;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *inputidproduitmodif;
    QLineEdit *inputnomproduit_3;
    QDateEdit *inputdateexpiration_3;
    QLineEdit *inputquantitedisponible_3;
    QLineEdit *inputhumidite_3;
    QLineEdit *inputtemperature_3;
    QDateEdit *inputdatedebut_3;
    QTableView *tableauproduits;
    QWidget *pagestatistiques;
    QLabel *label_22;
    QWidget *pagehistorique;
    QGridLayout *gridLayout;
    QTextEdit *textHistorique;
    QWidget *page;
    QPushButton *pushButton_7;
    QPushButton *sendButton;
    QLineEdit *messageInput;
    QTextEdit *outputText;
    QFrame *frameoperationsproduits;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bouttonajouterproduit;
    QPushButton *bouttonpdffile;
    QPushButton *bouttonstatistiques;
    QPushButton *bouttonhistorique;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1545, 641);
        MainWindow->setMinimumSize(QSize(1028, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        header = new QFrame(centralwidget);
        header->setObjectName("header");
        header->setMinimumSize(QSize(0, 0));
        header->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        header->setFrameShape(QFrame::Shape::StyledPanel);
        header->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(header);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(11, -1, -1, -1);
        bouttonacceuil = new QPushButton(header);
        bouttonacceuil->setObjectName("bouttonacceuil");
        bouttonacceuil->setMinimumSize(QSize(0, 40));
        bouttonacceuil->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));

        verticalLayout_3->addWidget(bouttonacceuil);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        buttongererProduit = new QPushButton(header);
        buttongererProduit->setObjectName("buttongererProduit");
        buttongererProduit->setMinimumSize(QSize(0, 40));
        buttongererProduit->setCursor(QCursor(Qt::PointingHandCursor));
        buttongererProduit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        buttongererProduit->setAutoExclusive(true);

        verticalLayout_3->addWidget(buttongererProduit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        buttongererClient = new QPushButton(header);
        buttongererClient->setObjectName("buttongererClient");
        buttongererClient->setMinimumSize(QSize(0, 35));
        buttongererClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        buttongererClient->setAutoExclusive(true);

        verticalLayout_3->addWidget(buttongererClient);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        pushButton_2 = new QPushButton(header);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_2->setAutoExclusive(true);

        verticalLayout_3->addWidget(pushButton_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        pushButton = new QPushButton(header);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton->setAutoExclusive(true);

        verticalLayout_3->addWidget(pushButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        pushButton_3 = new QPushButton(header);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(pushButton_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        pushButton_4 = new QPushButton(header);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_4->setAutoExclusive(true);

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout->addWidget(header);

        stackedwidgetmainbody = new QStackedWidget(centralwidget);
        stackedwidgetmainbody->setObjectName("stackedwidgetmainbody");
        pageacceuil = new QWidget();
        pageacceuil->setObjectName("pageacceuil");
        label = new QLabel(pageacceuil);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 20, 721, 511));
        label->setStyleSheet(QString::fromUtf8("border: 1 solid blue;\n"
"border-radius:25px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_4 = new QFrame(pageacceuil);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(199, 276, 750, 101));
        frame_4->setMinimumSize(QSize(750, 0));
        frame_4->setMaximumSize(QSize(900, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8(""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedwidgetmainbody->addWidget(pageacceuil);
        pagegererproduits = new QWidget();
        pagegererproduits->setObjectName("pagegererproduits");
        verticalLayout_2 = new QVBoxLayout(pagegererproduits);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidgetgererproduit = new QStackedWidget(pagegererproduits);
        stackedWidgetgererproduit->setObjectName("stackedWidgetgererproduit");
        stackedWidgetgererproduit->setMaximumSize(QSize(16777215, 16777215));
        stackedWidgetgererproduit->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */"));
        pageafficherproduits = new QWidget();
        pageafficherproduits->setObjectName("pageafficherproduits");
        verticalLayout_5 = new QVBoxLayout(pageafficherproduits);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(pageafficherproduits);
        frame_5->setObjectName("frame_5");
        frame_5->setMinimumSize(QSize(0, 50));
        frame_5->setMaximumSize(QSize(16777215, 70));
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_2 = new QFrame(frame_5);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(800, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8("border:1 solid lightgray;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        clerecherche = new QLineEdit(frame_2);
        clerecherche->setObjectName("clerecherche");
        clerecherche->setMinimumSize(QSize(600, 30));
        clerecherche->setMaximumSize(QSize(600, 30));
        clerecherche->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(clerecherche);

        bouttonrecherche = new QPushButton(frame_2);
        bouttonrecherche->setObjectName("bouttonrecherche");
        bouttonrecherche->setMinimumSize(QSize(0, 30));
        bouttonrecherche->setMaximumSize(QSize(100, 16777215));
        bouttonrecherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}QPushButton:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));

        horizontalLayout_6->addWidget(bouttonrecherche);


        horizontalLayout_4->addWidget(frame_2);

        bouttonnotification = new QPushButton(frame_5);
        bouttonnotification->setObjectName("bouttonnotification");
        bouttonnotification->setMinimumSize(QSize(0, 50));
        bouttonnotification->setMaximumSize(QSize(150, 16777215));
        bouttonnotification->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(bouttonnotification);

        menutri = new QComboBox(frame_5);
        menutri->addItem(QString());
        menutri->addItem(QString());
        menutri->addItem(QString());
        menutri->setObjectName("menutri");
        menutri->setMinimumSize(QSize(100, 0));
        menutri->setMaximumSize(QSize(120, 16777215));
        menutri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #E8F5E9; /* Vert tr\303\250s clair */\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    padding: 5px;\n"
"    border: 1px solid #81C784;\n"
"    border-radius: 4px;\n"
"}\n"
"QComboBox:focus {\n"
"    border: 1px solid #4CAF50; /* Bordure plus fonc\303\251e lorsqu'on clique */\n"
"    background-color: #F1F8E9;\n"
"}"));

        horizontalLayout_4->addWidget(menutri);


        verticalLayout_5->addWidget(frame_5);

        frame_7 = new QFrame(pageafficherproduits);
        frame_7->setObjectName("frame_7");
        frame_7->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
"}\n"
""));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        stackedWidgetmodifierajout = new QStackedWidget(frame_7);
        stackedWidgetmodifierajout->setObjectName("stackedWidgetmodifierajout");
        stackedWidgetmodifierajout->setMaximumSize(QSize(350, 16777215));
        stackedWidgetmodifierajout->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
"}"));
        formajout = new QWidget();
        formajout->setObjectName("formajout");
        formajout->setStyleSheet(QString::fromUtf8("border:none;\n"
"    background-image: url(\":/images/bg.jpeg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover; /* Optionnel */"));
        verticalLayout_9 = new QVBoxLayout(formajout);
        verticalLayout_9->setObjectName("verticalLayout_9");
        frame_6 = new QFrame(formajout);
        frame_6->setObjectName("frame_6");
        frame_6->setMinimumSize(QSize(0, 0));
        frame_6->setMaximumSize(QSize(400, 16777215));
        frame_6->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_6);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(frame_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(0, 50));
        pushButton_6->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setBold(true);
        font.setUnderline(true);
        pushButton_6->setFont(font);
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"    opacity: 0.85; /* Augmentation de l'opacit\303\251 */\n"
"    transform: scale(1.05); /* Agrandissement l\303\251ger */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Ombre pour donner de la profondeur */\n"
"}\n"
""
                        "\n"
"                                                           \n"
"\n"
"/*                                                  \n"
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
"/*"));

        verticalLayout_8->addWidget(pushButton_6);

        frame_10 = new QFrame(frame_6);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_8 = new QFrame(frame_10);
        frame_8->setObjectName("frame_8");
        frame_8->setStyleSheet(QString::fromUtf8("QFrame QLabel {\n"
"background-color: rgb(28, 168, 79);\n"
"\n"
"}"));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_8);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_29 = new QLabel(frame_8);
        label_29->setObjectName("label_29");
        label_29->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_29);

        label_24 = new QLabel(frame_8);
        label_24->setObjectName("label_24");
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_24);

        label_28 = new QLabel(frame_8);
        label_28->setObjectName("label_28");
        label_28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_28->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_28);

        label_26 = new QLabel(frame_8);
        label_26->setObjectName("label_26");
        label_26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_26);

        label_27 = new QLabel(frame_8);
        label_27->setObjectName("label_27");
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_27->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_27);

        label_25 = new QLabel(frame_8);
        label_25->setObjectName("label_25");
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_25);


        horizontalLayout_2->addWidget(frame_8);

        frame_3 = new QFrame(frame_10);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        inputnomproduit_2 = new QLineEdit(frame_3);
        inputnomproduit_2->setObjectName("inputnomproduit_2");
        inputnomproduit_2->setMinimumSize(QSize(100, 30));
        inputnomproduit_2->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_7->addWidget(inputnomproduit_2);

        inputdateexpiration_2 = new QDateEdit(frame_3);
        inputdateexpiration_2->setObjectName("inputdateexpiration_2");
        inputdateexpiration_2->setMinimumSize(QSize(0, 30));

        verticalLayout_7->addWidget(inputdateexpiration_2);

        inputquantitedisponible_2 = new QLineEdit(frame_3);
        inputquantitedisponible_2->setObjectName("inputquantitedisponible_2");
        inputquantitedisponible_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_7->addWidget(inputquantitedisponible_2);

        inputhumidite_2 = new QLineEdit(frame_3);
        inputhumidite_2->setObjectName("inputhumidite_2");
        inputhumidite_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_7->addWidget(inputhumidite_2);

        inputtemperature_2 = new QLineEdit(frame_3);
        inputtemperature_2->setObjectName("inputtemperature_2");
        inputtemperature_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_7->addWidget(inputtemperature_2);

        inputdatedebut_2 = new QDateEdit(frame_3);
        inputdatedebut_2->setObjectName("inputdatedebut_2");

        verticalLayout_7->addWidget(inputdatedebut_2);


        horizontalLayout_2->addWidget(frame_3);


        verticalLayout_8->addWidget(frame_10);


        verticalLayout_9->addWidget(frame_6);

        stackedWidgetmodifierajout->addWidget(formajout);
        formmodifier = new QWidget();
        formmodifier->setObjectName("formmodifier");
        formmodifier->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(formmodifier);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_5 = new QPushButton(formmodifier);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(0, 50));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"    opacity: 0.85; /* Augmentation de l'opacit\303\251 */\n"
"    transform: scale(1.05); /* Agrandissement l\303\251ger */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Ombre pour donner de la profondeur */\n"
"}\n"
""
                        "\n"
"                                                           \n"
"\n"
"/*                                                  \n"
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
"/*"));

        verticalLayout->addWidget(pushButton_5);

        frame = new QFrame(formmodifier);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border:none;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        frame_9 = new QFrame(frame);
        frame_9->setObjectName("frame_9");
        frame_9->setStyleSheet(QString::fromUtf8("QFrame QLabel {\n"
"background-color: rgb(28, 168, 79);\n"
"\n"
"}\n"
""));
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_9);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_2 = new QLabel(frame_9);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_2);

        label_30 = new QLabel(frame_9);
        label_30->setObjectName("label_30");
        label_30->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_30);

        label_31 = new QLabel(frame_9);
        label_31->setObjectName("label_31");
        label_31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_31->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_31);

        label_32 = new QLabel(frame_9);
        label_32->setObjectName("label_32");
        label_32->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_32->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_32);

        label_33 = new QLabel(frame_9);
        label_33->setObjectName("label_33");
        label_33->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_33->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_33);

        label_34 = new QLabel(frame_9);
        label_34->setObjectName("label_34");
        label_34->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_34);

        label_35 = new QLabel(frame_9);
        label_35->setObjectName("label_35");
        label_35->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(28, 168, 79); /* Couleur de fond */\n"
"    border: 2px solid #1C8A4F; /* Bordure assortie */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    color: white; /* Texte en blanc */\n"
"    font-size: 14px; /* Taille de police */\n"
"    padding: 5px; /* Espacement interne */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: rgb(20, 140, 60); /* Couleur de fond change lorsque l'on survole le label */\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #0D6E3F; /* Bordure qui change en cas de focus (utile pour les QLabel avec interaction) */\n"
"}\n"
"\n"
""));
        label_35->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_35);


        horizontalLayout_7->addWidget(frame_9);

        frame_12 = new QFrame(frame);
        frame_12->setObjectName("frame_12");
        frame_12->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */"));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_12);
        verticalLayout_11->setObjectName("verticalLayout_11");
        inputidproduitmodif = new QLineEdit(frame_12);
        inputidproduitmodif->setObjectName("inputidproduitmodif");
        inputidproduitmodif->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputidproduitmodif);

        inputnomproduit_3 = new QLineEdit(frame_12);
        inputnomproduit_3->setObjectName("inputnomproduit_3");
        inputnomproduit_3->setMinimumSize(QSize(100, 30));
        inputnomproduit_3->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_11->addWidget(inputnomproduit_3);

        inputdateexpiration_3 = new QDateEdit(frame_12);
        inputdateexpiration_3->setObjectName("inputdateexpiration_3");
        inputdateexpiration_3->setMinimumSize(QSize(0, 30));
        inputdateexpiration_3->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputdateexpiration_3);

        inputquantitedisponible_3 = new QLineEdit(frame_12);
        inputquantitedisponible_3->setObjectName("inputquantitedisponible_3");
        inputquantitedisponible_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputquantitedisponible_3);

        inputhumidite_3 = new QLineEdit(frame_12);
        inputhumidite_3->setObjectName("inputhumidite_3");
        inputhumidite_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputhumidite_3);

        inputtemperature_3 = new QLineEdit(frame_12);
        inputtemperature_3->setObjectName("inputtemperature_3");
        inputtemperature_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputtemperature_3);

        inputdatedebut_3 = new QDateEdit(frame_12);
        inputdatedebut_3->setObjectName("inputdatedebut_3");
        inputdatedebut_3->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border-radius: 15px;\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_11->addWidget(inputdatedebut_3);


        horizontalLayout_7->addWidget(frame_12);


        verticalLayout->addWidget(frame);

        stackedWidgetmodifierajout->addWidget(formmodifier);

        horizontalLayout_5->addWidget(stackedWidgetmodifierajout);

        tableauproduits = new QTableView(frame_7);
        tableauproduits->setObjectName("tableauproduits");
        tableauproduits->setMinimumSize(QSize(0, 0));
        tableauproduits->setMaximumSize(QSize(16777215, 16777215));
        tableauproduits->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: rgb(20, 5, 104); /* Header background color */\n"
"    color: white;                      /* Header text color */\n"
"                      /* Remove border */\n"
"\n"
" }\n"
"QTableView {\n"
"\n"
"    border: none;                     /* Remove border around table itself */\n"
"}\n"
"QHeaderView::section:first {\n"
"    border-top-left-radius: 25px; /* Round top-left corner */\n"
"}\n"
"\n"
"QHeaderView::section:last {\n"
"    border-top-right-radius: 25px; /* Round top-right corner */\n"
"}"));
        tableauproduits->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tableauproduits);


        verticalLayout_5->addWidget(frame_7);

        stackedWidgetgererproduit->addWidget(pageafficherproduits);
        pagestatistiques = new QWidget();
        pagestatistiques->setObjectName("pagestatistiques");
        label_22 = new QLabel(pagestatistiques);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(510, 160, 111, 121));
        stackedWidgetgererproduit->addWidget(pagestatistiques);
        pagehistorique = new QWidget();
        pagehistorique->setObjectName("pagehistorique");
        gridLayout = new QGridLayout(pagehistorique);
        gridLayout->setObjectName("gridLayout");
        textHistorique = new QTextEdit(pagehistorique);
        textHistorique->setObjectName("textHistorique");
        textHistorique->setReadOnly(true);

        gridLayout->addWidget(textHistorique, 0, 0, 1, 1);

        stackedWidgetgererproduit->addWidget(pagehistorique);
        page = new QWidget();
        page->setObjectName("page");
        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(590, 160, 271, 29));
        sendButton = new QPushButton(page);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(590, 210, 271, 29));
        messageInput = new QLineEdit(page);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(350, 160, 113, 26));
        outputText = new QTextEdit(page);
        outputText->setObjectName("outputText");
        outputText->setGeometry(QRect(340, 220, 211, 81));
        stackedWidgetgererproduit->addWidget(page);

        verticalLayout_2->addWidget(stackedWidgetgererproduit);

        frameoperationsproduits = new QFrame(pagegererproduits);
        frameoperationsproduits->setObjectName("frameoperationsproduits");
        frameoperationsproduits->setMinimumSize(QSize(0, 50));
        frameoperationsproduits->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */"));
        frameoperationsproduits->setFrameShape(QFrame::Shape::StyledPanel);
        frameoperationsproduits->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameoperationsproduits);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        bouttonajouterproduit = new QPushButton(frameoperationsproduits);
        bouttonajouterproduit->setObjectName("bouttonajouterproduit");
        bouttonajouterproduit->setMinimumSize(QSize(120, 0));
        bouttonajouterproduit->setMaximumSize(QSize(120, 80));
        bouttonajouterproduit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_3->addWidget(bouttonajouterproduit);

        bouttonpdffile = new QPushButton(frameoperationsproduits);
        bouttonpdffile->setObjectName("bouttonpdffile");
        bouttonpdffile->setMinimumSize(QSize(120, 0));
        bouttonpdffile->setMaximumSize(QSize(120, 80));
        bouttonpdffile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_3->addWidget(bouttonpdffile);

        bouttonstatistiques = new QPushButton(frameoperationsproduits);
        bouttonstatistiques->setObjectName("bouttonstatistiques");
        bouttonstatistiques->setMinimumSize(QSize(120, 0));
        bouttonstatistiques->setMaximumSize(QSize(120, 80));
        bouttonstatistiques->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_3->addWidget(bouttonstatistiques);

        bouttonhistorique = new QPushButton(frameoperationsproduits);
        bouttonhistorique->setObjectName("bouttonhistorique");
        bouttonhistorique->setMinimumSize(QSize(120, 0));
        bouttonhistorique->setMaximumSize(QSize(120, 80));
        bouttonhistorique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #b8e0c7;\n"
"    color: #1f472e;\n"
"    font-family: \"Roboto\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: bold; /* texte en gras */\n"
"    border-radius: 5px; /* coins arrondis */\n"
"    transition: background-color 0.3s ease, border 0.3s ease, transform 0.3s ease; /* ajoute une transition pour l'agrandissement */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A0D6B4;\n"
"    border: 1px solid #4CAF50;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"    transform: scale(1.05); /* agrandit le bouton de 5% */\n"
"}\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout_3->addWidget(bouttonhistorique);


        verticalLayout_2->addWidget(frameoperationsproduits);

        stackedwidgetmainbody->addWidget(pagegererproduits);

        horizontalLayout->addWidget(stackedwidgetmainbody);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedwidgetmainbody->setCurrentIndex(1);
        stackedWidgetgererproduit->setCurrentIndex(0);
        stackedWidgetmodifierajout->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bouttonacceuil->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        buttongererProduit->setText(QCoreApplication::translate("MainWindow", "G\303\251rer Produit", nullptr));
        buttongererClient->setText(QCoreApplication::translate("MainWindow", "G\303\251rer Client", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "G\303\251rer employ\303\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "G\303\251rer commandes", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "G\303\251rer \303\251quipements", nullptr));
        pushButton_4->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Nom de l'Application", nullptr));
        bouttonrecherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        bouttonnotification->setText(QCoreApplication::translate("MainWindow", "Notifications", nullptr));
        menutri->setItemText(0, QCoreApplication::translate("MainWindow", "tri", nullptr));
        menutri->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));
        menutri->setItemText(2, QString());

        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Ajouter le Produit", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Date Expiration", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 Disponible", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Date D\303\251but", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Modifier un Produit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID Produit", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Date Expiration", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 Dispo", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Date D\303\251but", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "STATISTIQUES", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "connectButton", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "sendButton", nullptr));
        bouttonajouterproduit->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        bouttonpdffile->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        bouttonstatistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        bouttonhistorique->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
