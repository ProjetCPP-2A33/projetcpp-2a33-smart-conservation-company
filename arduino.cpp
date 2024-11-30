#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
}

bool Arduino::connectToArduino()
{
    qDebug() << "Recherche d'Arduino sur les ports série disponibles...";

    // Parcourir tous les ports série disponibles
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port détecté :";
        qDebug() << "  Nom du port     :" << info.portName();
        qDebug() << "  Description     :" << info.description();
        qDebug() << "  Fabricant       :" << info.manufacturer();

        // Identifier si le port correspond à un Arduino ou clone
        if (info.description().contains("Arduino", Qt::CaseInsensitive) ||
            info.manufacturer().contains("Arduino", Qt::CaseInsensitive) ||
            info.description().contains("CH340", Qt::CaseInsensitive) ||
            info.manufacturer().contains("wch.cn", Qt::CaseInsensitive)) {

            // Configurer le port série
            serial->setPort(info);
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);    // 8 bits de données
            serial->setParity(QSerialPort::NoParity);   // Pas de parité
            serial->setStopBits(QSerialPort::OneStop);  // 1 bit de stop
            serial->setFlowControl(QSerialPort::NoFlowControl); // Pas de contrôle de flux
            serial->setPortName("COM3");
            // Tenter d'ouvrir le port
            if (serial->open(QIODevice::ReadWrite)) {
                // Connecter le signal de réception des données
                connect(serial, &QSerialPort::readyRead, this, &Arduino::readSerialData);

                qDebug() << "Connecté à l'Arduino sur le port" << info.portName();
                return true;
            } else {
                qDebug() << "Erreur : Impossible d'ouvrir le port" << info.portName()
                << "Raison :" << serial->errorString();
            }
        }
    }

    // Aucun port correspondant trouvé
    qDebug() << "Erreur : Aucun Arduino détecté parmi les ports série disponibles.";
    return false;
}

void Arduino::disconnectFromArduino()
{
    if (serial->isOpen()) {
        serial->close();
    }
}

void Arduino::readSerialData()
{
    if (serial->canReadLine()) {
        QString data = serial->readLine().trimmed();
        emit dataReceived(data);
    }
}
