#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection {
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();  // Function to create the connection
    void closeconnect();   // Function to close the connection
};

#endif // CONNECTION_H
