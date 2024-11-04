#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection {
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnect();
};

#endif // CONNECTION_H


/*#include "connection.h"

Connection::Connection() {
    // Initialiser la base de données
    db = QSqlDatabase::addDatabase("QSQLITE"); // Par exemple pour SQLite
    db.setDatabaseName("chemin/vers/ta/base_de_donnees.db"); // Remplace par le chemin de ta base de données
}

bool Connection::createconnect() {
    if (db.open()) {
        qDebug() << "Connexion réussie!";
        return true;
    } else {
        qDebug() << "Erreur de connexion :" << db.lastError().text();
        return false;
    }
}

void Connection::closeconnect() {
    db.close();
}
*/
