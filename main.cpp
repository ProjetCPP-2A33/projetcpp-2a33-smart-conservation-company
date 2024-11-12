#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create the Qt application
    MainWindow w;               // Instance of the main window
    Connection c;               // Instance of the Connection class

    // Attempt to connect to the database
    bool test = c.createconnect();
    if (test) {
        // If the connection is successful, show the main window
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        // If the connection fails, show an error message
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        return 1; // Exit the application if the connection fails
    }

    return a.exec(); // Execute the Qt application
}
