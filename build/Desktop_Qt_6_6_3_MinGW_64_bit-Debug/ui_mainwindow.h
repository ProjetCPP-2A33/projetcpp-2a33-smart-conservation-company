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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_21;
    QFrame *frame_209;
    QPushButton *pushButton_332;
    QLabel *label_765;
    QPushButton *pushButton_339;
    QLabel *label_766;
    QPushButton *historique;
    QLabel *label_767;
    QLabel *label_768;
    QLabel *label_769;
    QPushButton *pushButton_336;
    QLabel *label_770;
    QPushButton *pdf;
    QLabel *label_771;
    QPushButton *calculerReduction;
    QLineEdit *supp;
    QPushButton *statistique;
    QLineEdit *ide;
    QFrame *frame_205;
    QPushButton *pushButton_331;
    QFrame *frame_206;
    QVBoxLayout *verticalLayout_47;
    QLabel *label_759;
    QLabel *label_760;
    QLabel *label_761;
    QLabel *label_762;
    QLabel *label_763;
    QFrame *frame_207;
    QLineEdit *idInput;
    QLineEdit *fideliteInput;
    QLineEdit *etatInput;
    QLineEdit *prixInput;
    QLineEdit *dateInput;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_13;
    QFrame *frame_21;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_9;
    QPushButton *pushButton_14;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_9;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_12;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_19;
    QFrame *frame_22;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_18;
    QLabel *label_19;
    QTableView *tableView;
    QFrame *frame_208;
    QHBoxLayout *horizontalLayout_46;
    QLineEdit *lineEdit_272;
    QLabel *label_764;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *rechercher;
    QWidget *tab_22;
    QLabel *label_989;
    QLabel *label_990;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *tab;
    QTableView *tableView_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1433, 735);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1391, 671));
        tab_21 = new QWidget();
        tab_21->setObjectName("tab_21");
        frame_209 = new QFrame(tab_21);
        frame_209->setObjectName("frame_209");
        frame_209->setGeometry(QRect(200, 540, 1181, 80));
        frame_209->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_209->setFrameShape(QFrame::Shape::StyledPanel);
        frame_209->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_332 = new QPushButton(frame_209);
        pushButton_332->setObjectName("pushButton_332");
        pushButton_332->setGeometry(QRect(80, 30, 93, 28));
        label_765 = new QLabel(frame_209);
        label_765->setObjectName("label_765");
        label_765->setGeometry(QRect(20, 20, 51, 47));
        label_765->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_765->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/edit.svg")));
        pushButton_339 = new QPushButton(frame_209);
        pushButton_339->setObjectName("pushButton_339");
        pushButton_339->setGeometry(QRect(240, 30, 93, 28));
        label_766 = new QLabel(frame_209);
        label_766->setObjectName("label_766");
        label_766->setGeometry(QRect(180, 20, 51, 47));
        label_766->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_766->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/layers.svg")));
        historique = new QPushButton(frame_209);
        historique->setObjectName("historique");
        historique->setGeometry(QRect(400, 30, 93, 28));
        label_767 = new QLabel(frame_209);
        label_767->setObjectName("label_767");
        label_767->setGeometry(QRect(340, 20, 51, 47));
        label_767->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_767->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/fast-forward.svg")));
        label_768 = new QLabel(frame_209);
        label_768->setObjectName("label_768");
        label_768->setGeometry(QRect(500, 20, 51, 47));
        label_768->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_768->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/trending-up.svg")));
        label_769 = new QLabel(frame_209);
        label_769->setObjectName("label_769");
        label_769->setGeometry(QRect(820, 20, 51, 47));
        label_769->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_769->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/trash-2.svg")));
        pushButton_336 = new QPushButton(frame_209);
        pushButton_336->setObjectName("pushButton_336");
        pushButton_336->setGeometry(QRect(880, 30, 93, 28));
        label_770 = new QLabel(frame_209);
        label_770->setObjectName("label_770");
        label_770->setGeometry(QRect(980, 20, 51, 47));
        label_770->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_770->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/file-plus.svg")));
        pdf = new QPushButton(frame_209);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(1040, 30, 93, 28));
        label_771 = new QLabel(frame_209);
        label_771->setObjectName("label_771");
        label_771->setGeometry(QRect(660, 20, 51, 47));
        label_771->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));
        label_771->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/corner-right-down.svg")));
        calculerReduction = new QPushButton(frame_209);
        calculerReduction->setObjectName("calculerReduction");
        calculerReduction->setGeometry(QRect(720, 30, 93, 28));
        supp = new QLineEdit(frame_209);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(870, 0, 113, 26));
        statistique = new QPushButton(frame_209);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(560, 30, 93, 28));
        ide = new QLineEdit(frame_209);
        ide->setObjectName("ide");
        ide->setGeometry(QRect(710, 0, 113, 26));
        frame_205 = new QFrame(tab_21);
        frame_205->setObjectName("frame_205");
        frame_205->setGeometry(QRect(200, 0, 341, 541));
        frame_205->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_205->setFrameShape(QFrame::Shape::StyledPanel);
        frame_205->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_331 = new QPushButton(frame_205);
        pushButton_331->setObjectName("pushButton_331");
        pushButton_331->setGeometry(QRect(30, 10, 281, 61));
        pushButton_331->setAutoFillBackground(false);
        pushButton_331->setStyleSheet(QString::fromUtf8("\n"
"                                                           \n"
"\n"
"                                                           \n"
"QPushButton {\n"
"    background-color: rgb(50, 120, 90); /* Darker green */\n"
"    color: black;\n"
"    \n"
"    font-size: 20px;\n"
"    text-decoration: underline;  /* Underlined text */\n"
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
        pushButton_331->setCheckable(true);
        frame_206 = new QFrame(frame_205);
        frame_206->setObjectName("frame_206");
        frame_206->setGeometry(QRect(10, 80, 151, 431));
        frame_206->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_206->setFrameShape(QFrame::Shape::StyledPanel);
        frame_206->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_47 = new QVBoxLayout(frame_206);
        verticalLayout_47->setObjectName("verticalLayout_47");
        label_759 = new QLabel(frame_206);
        label_759->setObjectName("label_759");
        label_759->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);"));

        verticalLayout_47->addWidget(label_759);

        label_760 = new QLabel(frame_206);
        label_760->setObjectName("label_760");
        label_760->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);\n"
""));

        verticalLayout_47->addWidget(label_760);

        label_761 = new QLabel(frame_206);
        label_761->setObjectName("label_761");
        label_761->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);"));

        verticalLayout_47->addWidget(label_761);

        label_762 = new QLabel(frame_206);
        label_762->setObjectName("label_762");
        label_762->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);"));

        verticalLayout_47->addWidget(label_762);

        label_763 = new QLabel(frame_206);
        label_763->setObjectName("label_763");
        label_763->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 168, 79);"));

        verticalLayout_47->addWidget(label_763);

        frame_207 = new QFrame(frame_205);
        frame_207->setObjectName("frame_207");
        frame_207->setGeometry(QRect(170, 80, 161, 431));
        frame_207->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_207->setFrameShape(QFrame::Shape::StyledPanel);
        frame_207->setFrameShadow(QFrame::Shadow::Raised);
        idInput = new QLineEdit(frame_207);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(10, 40, 141, 41));
        idInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        fideliteInput = new QLineEdit(frame_207);
        fideliteInput->setObjectName("fideliteInput");
        fideliteInput->setGeometry(QRect(10, 370, 141, 41));
        fideliteInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        etatInput = new QLineEdit(frame_207);
        etatInput->setObjectName("etatInput");
        etatInput->setGeometry(QRect(10, 200, 141, 41));
        etatInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        prixInput = new QLineEdit(frame_207);
        prixInput->setObjectName("prixInput");
        prixInput->setGeometry(QRect(10, 290, 141, 41));
        prixInput->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        dateInput = new QLineEdit(frame_207);
        dateInput->setObjectName("dateInput");
        dateInput->setGeometry(QRect(0, 120, 151, 41));
        dateInput->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */"));
        frame_4 = new QFrame(tab_21);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 0, 201, 631));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_4);
        verticalLayout_13->setObjectName("verticalLayout_13");
        frame_21 = new QFrame(frame_4);
        frame_21->setObjectName("frame_21");
        frame_21->setFrameShape(QFrame::Shape::StyledPanel);
        frame_21->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_21);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(-1, -1, -1, 16);
        pushButton_7 = new QPushButton(frame_21);
        pushButton_7->setObjectName("pushButton_7");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/BleuIcons/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setCheckable(true);
        pushButton_7->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        pushButton_8 = new QPushButton(frame_21);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/BleuIcons/users.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setCheckable(true);
        pushButton_8->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_9);

        pushButton_14 = new QPushButton(frame_21);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/BleuIcons/lock.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon2);
        pushButton_14->setCheckable(true);
        pushButton_14->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_14);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        pushButton_9 = new QPushButton(frame_21);
        pushButton_9->setObjectName("pushButton_9");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/BleuIcons/shopping-cart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);
        pushButton_9->setCheckable(true);
        pushButton_9->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_9);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_10);

        pushButton_13 = new QPushButton(frame_21);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/BleuIcons/truck.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setCheckable(true);
        pushButton_13->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_13);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        pushButton_12 = new QPushButton(frame_21);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/BleuIcons/inbox.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon5);
        pushButton_12->setCheckable(true);
        pushButton_12->setAutoExclusive(true);

        verticalLayout_7->addWidget(pushButton_12);


        verticalLayout_13->addWidget(frame_21);

        pushButton_30 = new QPushButton(frame_4);
        pushButton_30->setObjectName("pushButton_30");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/newPrefix/settings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_30->setIcon(icon6);
        pushButton_30->setCheckable(true);
        pushButton_30->setAutoExclusive(true);

        verticalLayout_13->addWidget(pushButton_30);

        pushButton_31 = new QPushButton(frame_4);
        pushButton_31->setObjectName("pushButton_31");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/newPrefix/log-out.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_31->setIcon(icon7);
        pushButton_31->setCheckable(true);
        pushButton_31->setAutoExclusive(true);

        verticalLayout_13->addWidget(pushButton_31);

        frame_6 = new QFrame(tab_21);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(540, 0, 841, 541));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_6);
        verticalLayout_12->setObjectName("verticalLayout_12");
        frame_19 = new QFrame(frame_6);
        frame_19->setObjectName("frame_19");
        frame_19->setFrameShape(QFrame::Shape::StyledPanel);
        frame_19->setFrameShadow(QFrame::Shadow::Raised);
        frame_22 = new QFrame(frame_19);
        frame_22->setObjectName("frame_22");
        frame_22->setGeometry(QRect(0, 0, 141, 51));
        frame_22->setFrameShape(QFrame::Shape::StyledPanel);
        frame_22->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_22);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_11 = new QLabel(frame_22);
        label_11->setObjectName("label_11");
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/align-justify.svg")));

        horizontalLayout_8->addWidget(label_11);

        label_12 = new QLabel(frame_22);
        label_12->setObjectName("label_12");

        horizontalLayout_8->addWidget(label_12);

        label_18 = new QLabel(frame_19);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(1000, 10, 131, 61));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/BleuIcons/user.svg")));
        label_19 = new QLabel(frame_19);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(1060, 20, 51, 41));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/user.svg")));
        tableView = new QTableView(frame_19);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(100, 110, 541, 381));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
"}"));
        frame_208 = new QFrame(frame_19);
        frame_208->setObjectName("frame_208");
        frame_208->setGeometry(QRect(0, 50, 631, 51));
        frame_208->setStyleSheet(QString::fromUtf8("background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));
        frame_208->setFrameShape(QFrame::Shape::StyledPanel);
        frame_208->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_46 = new QHBoxLayout(frame_208);
        horizontalLayout_46->setObjectName("horizontalLayout_46");
        lineEdit_272 = new QLineEdit(frame_208);
        lineEdit_272->setObjectName("lineEdit_272");
        lineEdit_272->setStyleSheet(QString::fromUtf8("\n"
"background-color: #edf7e6;         /* Light green inside background */\n"
"border: 2px solid rgb(68, 150, 109); /* Green border */\n"
"border-radius: 15px;                /* Rounded corners with 15px radius */\n"
""));

        horizontalLayout_46->addWidget(lineEdit_272);

        label_764 = new QLabel(frame_208);
        label_764->setObjectName("label_764");
        label_764->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/search.svg")));

        horizontalLayout_46->addWidget(label_764);

        label_20 = new QLabel(frame_19);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(720, 0, 91, 41));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/BleuIcons/user.svg")));
        label_21 = new QLabel(frame_19);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(740, 0, 51, 41));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/user.svg")));
        rechercher = new QPushButton(frame_19);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(660, 60, 151, 29));
        rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(50, 120, 90); /* Darker green */\n"
"    color: black;\n"
"    \n"
"    font-size: 20px;\n"
"    text-decoration: underline;  /* Underlined text */\n"
"    line-height: 1.5;\n"
"\n"
"    width: 200px;\n"
"    height: 40px;\n"
"    opacity: 0.65;\n"
"    text-align: center;\n"
"    \n"
"    border-style: solid;\n"
"}"));

        verticalLayout_12->addWidget(frame_19);

        tabWidget->addTab(tab_21, QString());
        tab_22 = new QWidget();
        tab_22->setObjectName("tab_22");
        label_989 = new QLabel(tab_22);
        label_989->setObjectName("label_989");
        label_989->setGeometry(QRect(20, 100, 641, 441));
        label_989->setPixmap(QPixmap(QString::fromUtf8("../../../Capture_d_\303\251cran_2024-10-07_212351-removebg-preview.png")));
        label_989->setScaledContents(true);
        label_990 = new QLabel(tab_22);
        label_990->setObjectName("label_990");
        label_990->setGeometry(QRect(770, 200, 351, 211));
        label_990->setPixmap(QPixmap(QString::fromUtf8("../../../3956310.png")));
        label_990->setScaledContents(true);
        verticalLayoutWidget_2 = new QWidget(tab_22);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(40, 10, 1331, 651));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_22, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tableView_2 = new QTableView(tab);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(5, 1, 1401, 541));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1433, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_332->setText(QCoreApplication::translate("MainWindow", "Modifer", nullptr));
        label_765->setText(QString());
        pushButton_339->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        label_766->setText(QString());
        historique->setText(QCoreApplication::translate("MainWindow", "historique ", nullptr));
        label_767->setText(QString());
        label_768->setText(QString());
        label_769->setText(QString());
        pushButton_336->setText(QCoreApplication::translate("MainWindow", "Suppression", nullptr));
        label_770->setText(QString());
        pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_771->setText(QString());
        calculerReduction->setText(QCoreApplication::translate("MainWindow", "R\303\251duction", nullptr));
        supp->setText(QString());
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pushButton_331->setText(QCoreApplication::translate("MainWindow", " Ajouter une commande", nullptr));
        label_759->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_760->setText(QCoreApplication::translate("MainWindow", "dateCommande", nullptr));
        label_761->setText(QCoreApplication::translate("MainWindow", "etatCommande", nullptr));
        label_762->setText(QCoreApplication::translate("MainWindow", "prix", nullptr));
        label_763->setText(QCoreApplication::translate("MainWindow", "pointFidelite", nullptr));
        idInput->setText(QString());
        fideliteInput->setText(QString());
        etatInput->setText(QString());
        prixInput->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Gestion Employ\303\251s", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Gestion des cliens", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "gestion des produits", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Gestion  commandes", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Gestion  \303\251quipements", nullptr));
        pushButton_30->setText(QString());
        pushButton_31->setText(QString());
        label_11->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "DashBoard", nullptr));
        label_18->setText(QString());
        label_19->setText(QString());
        lineEdit_272->setText(QString());
        lineEdit_272->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Here....", nullptr));
        label_764->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        rechercher->setText(QCoreApplication::translate("MainWindow", "recherche ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_21), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label_989->setText(QString());
        label_990->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_22), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
