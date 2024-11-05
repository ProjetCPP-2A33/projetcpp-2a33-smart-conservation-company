#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Initialiser la connexion à la base de données
    Connection connection;
    bool isConnected = connection.createconnect();

    // Vérification de la connexion
    if (!isConnected) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Failed to connect to the database. "
                                          "The application will now close."));
        return -1; // Arrêter le programme si la connexion échoue
    }

    MainWindow mainWindow;
    mainWindow.show(); // Afficher la fenêtre principale si la connexion réussit

    return app.exec(); // Exécuter l'application Qt
}

/*
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();//etablir la connection
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
*/
