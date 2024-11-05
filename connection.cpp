#include "Connection.h"
Connection::Connection()
{}



bool Connection::createConnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source2A33");
    db.setUserName("mariem");//inserer nom de l'utilisateur
    db.setPassword("oracle");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
