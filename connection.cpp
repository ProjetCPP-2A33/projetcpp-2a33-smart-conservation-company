#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
    // The constructor initializes the object without opening the database
}

bool Connection::createconnect()
{
    bool test = false;
    db = QSqlDatabase::addDatabase("QODBC"); // Use QODBC as the driver
    db.setDatabaseName("departementEmployee"); // Use the ODBC data source name
    db.setUserName("omar0"); // Username
    db.setPassword("omar"); // Password

    // Check if the database opens successfully
    if (db.open()) {
        test = true;
        qDebug() << "Database connection opened successfully.";
    } else {
        qDebug() << "Error opening database connection:" << db.lastError().text();
    }

    return test;
}

void Connection::closeconnect()
{
    db.close(); // Close the database connection
}
