#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.createconnect();

    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("base donnée fermé"),
                              QObject::tr("echec connexion.\n"
                                          "clickez pour quitter"), QMessageBox::Cancel);
        return -1;
    }

    MainWindow w;//instanciation de lobjet appel constructeur appel de methode afficher
    w.show();
  /*  QMessageBox::information(nullptr, QObject::tr("connexion a la base donnée confirmé"),
                             QObject::tr("connecté.\n"
                                         "clicker pour quitter."), QMessageBox::Cancel);*/
    return a.exec();
}
