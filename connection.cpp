
#include <QSqlError>
#include <QDebug>

#include "connection.h"

Connection::Connection()
{

}
/*
bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_Projet2A33"); // Verify the database name
    db.setUserName("emna");                  // Verify the username
    db.setPassword("emna2004");              // Verify the password

    if (db.open()) {
        test = true;
        qDebug() << "Database connection successful";
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
    }
    return test;
}
*/
bool Connection::createconnect() {
    bool test = false;
    qDebug() << "Starting database connection attempt...";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug() << "Database driver set: QODBC";

    db.setDatabaseName("departementEmployee");  // Vérifier le nom de la base
    db.setUserName("omar0");                    // Vérifier le nom d'utilisateur
    db.setPassword("omar");                // Vérifier le mot de passe

    qDebug() << "Trying to open the database...";
    if (db.open()) {
        test = true;
        qDebug() << "Database connection successful";
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
        qDebug() << "Driver available: " << QSqlDatabase::isDriverAvailable("QODBC");
    }
    return test;
}




void Connection ::closeconnect()
{
    db.close();
}


