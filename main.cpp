#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

#include <QDebug>
#include <QSqldatabase>
#include <QSqlerror>

/*int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createConnection();
    MainWindow w;

    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    w.show();

    return a.exec();
}*/

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);  // Création de l'application Qt

    Connection c;                 // Instance de la classe Connection
    bool test = c.createConnection();  // Tentative de création de la connexion à la base de données
    MainWindow w;                // Instance de la fenêtre principale

    if (test) {                  // Si la connexion est réussie
        w.show();                // Afficher la fenêtre principale
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {                       // Si la connexion échoue
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        return 1;              // Quitter l'application si la connexion échoue
    }

    return a.exec();            // Exécuter l'application Qt
}

