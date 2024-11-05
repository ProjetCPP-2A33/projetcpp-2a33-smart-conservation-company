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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *ajouter;
    QGroupBox *groupBox;
    QLineEdit *idInput;
    QLineEdit *dateInput;
    QLineEdit *etatInput;
    QLineEdit *fideliteInput;
    QPushButton *pushButton_331;
    QLineEdit *prixInput;
    QWidget *liste;
    QTableView *tableView;
    QWidget *supprimer;
    QGroupBox *groupBox_2;
    QLineEdit *supp;
    QPushButton *pushButton_336;
    QWidget *tab_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1388, 817);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 741, 521));
        ajouter = new QWidget();
        ajouter->setObjectName("ajouter");
        groupBox = new QGroupBox(ajouter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 29, 641, 371));
        idInput = new QLineEdit(groupBox);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(210, 60, 113, 26));
        dateInput = new QLineEdit(groupBox);
        dateInput->setObjectName("dateInput");
        dateInput->setGeometry(QRect(210, 120, 113, 26));
        etatInput = new QLineEdit(groupBox);
        etatInput->setObjectName("etatInput");
        etatInput->setGeometry(QRect(210, 180, 113, 26));
        fideliteInput = new QLineEdit(groupBox);
        fideliteInput->setObjectName("fideliteInput");
        fideliteInput->setGeometry(QRect(210, 280, 113, 26));
        pushButton_331 = new QPushButton(groupBox);
        pushButton_331->setObjectName("pushButton_331");
        pushButton_331->setGeometry(QRect(220, 330, 93, 29));
        prixInput = new QLineEdit(groupBox);
        prixInput->setObjectName("prixInput");
        prixInput->setGeometry(QRect(210, 230, 113, 26));
        tabWidget->addTab(ajouter, QString());
        liste = new QWidget();
        liste->setObjectName("liste");
        tableView = new QTableView(liste);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 70, 711, 371));
        tabWidget->addTab(liste, QString());
        supprimer = new QWidget();
        supprimer->setObjectName("supprimer");
        groupBox_2 = new QGroupBox(supprimer);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(39, 69, 571, 311));
        supp = new QLineEdit(groupBox_2);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(200, 200, 113, 26));
        pushButton_336 = new QPushButton(groupBox_2);
        pushButton_336->setObjectName("pushButton_336");
        pushButton_336->setGeometry(QRect(200, 258, 121, 41));
        tabWidget->addTab(supprimer, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1388, 26));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_331->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ajouter), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(liste), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        supp->setText(QString());
        pushButton_336->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(supprimer), QCoreApplication::translate("MainWindow", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
