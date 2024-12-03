#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent), serial(new QSerialPort(this)) {
    baudRate = 9600; // Vitesse de communication
    portName = "";   // Nom du port Arduino (à détecter automatiquement)
}

Arduino::~Arduino() {
    if (serial->isOpen()) {
        serial->close();
    }
}
bool Arduino::connectToArduino() {
    // Spécifiez manuellement le port
    portName = "COM3";  // Remplacez "COM3" par le port correct

    serial->setPortName(portName);//associe le nom au serial
    serial->setBaudRate(baudRate);//definit vitesse du port serie
    serial->setDataBits(QSerialPort::Data8);//la taille des données envoyées à 8 bits par caractère.
    serial->setParity(QSerialPort::NoParity);//vérification d'erreur sur les données
    serial->setStopBits(QSerialPort::OneStop);//d'arrêt
    serial->setFlowControl(QSerialPort::NoFlowControl);// désactive la gestion du débit des données

    // Essayer d'ouvrir le port série
    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Impossible d'ouvrir le port série. Erreur : " << serial->errorString();
        return false;
    } else {
        qDebug() << "Port série ouvert avec succès.";
        return true;
    }
}


void Arduino::sendToArduino(const QString &data) {
    if (serial->isOpen()) {
        serial->write(data.toUtf8());// écrit les données sous forme de chaîne UTF-8
    } else {
        qDebug() << "Port série non ouvert.";
    }
}

QString Arduino::readFromArduino() {
    if (serial->isOpen() && serial->waitForReadyRead(1000)) {// les donnes pret a lire delait d'attente 1 s
        return QString(serial->readAll());
    }
    return "";
}
void Arduino::listAvailablePorts() {
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {// parcourt liste des port
        qDebug() << "Port disponible : " << port.portName();// chaque port disponible on peut l'acceder a son nom
    }
}

