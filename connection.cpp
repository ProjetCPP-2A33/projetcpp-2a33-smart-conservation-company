
#include <QSqlError>
#include <QDebug>

#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source2a33"); // Verify the database name
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



void Connection ::closeconnect()
{
    db.close();
}


