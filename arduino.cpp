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
            serial->setPortName("COM7");
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

void Arduino::readSerialData() {
    while (serial->canReadLine()) {
        QByteArray data = serial->readLine().trimmed();
        GlobalData = data;
       // qDebug()  << GlobalData;
        emit dataReceived(data); // Signal pour transmettre les données au reste de l'application
    }
}
QString Arduino::getGlobalData()
{
    return GlobalData;
}
int Arduino::connect_arduino()
{

    // simulation sur le port com3

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Found port:" << serialPortInfo.portName();
        if (serialPortInfo.portName() == "COM7") {
            serial->setPortName(serialPortInfo.portName());

            if (serial->open(QSerialPort::ReadWrite)) {
                qDebug() << "Connected to" << serialPortInfo.portName();
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                arduino_is_available = true;
                return 0; // Success
            } else {
                qDebug() << "Failed to open" << serialPortInfo.portName();
            }
        }
    }
    return -1;



}
void Arduino::setPortName(const QString &portName)
{
    arduino_port_name = portName;
    serial->setPortName(portName);
}
QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}
int Arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "ferme connection serial";
        arduino_is_available = false;
        return 0;
    }
    return -1;
}
QByteArray Arduino::read_from_arduino()
{
    if (serial && serial->isOpen()) {
        QByteArray data = serial->readAll();
        return data;
    }

    qDebug() << "Serial port ferme ou invalide";
    return QByteArray();
}

int Arduino::write_to_arduino(QByteArray data)
{
    if (serial->isOpen()) {
        if (serial->isWritable()) {
            qDebug() << "donné ecrit a arduino:" << data;
            serial->write(data);
            if (serial->waitForBytesWritten(100)) {
                return 0;
            } else {
                qDebug() << "temps mort ";
            }
        } else {
            qDebug() << "port serie introuvable pr ecriture";
        }
    } else {
        qDebug() << "Serial port fermé";
    }
    return -1;
}

void Arduino::sendToArduino(const QString &data) {
    if (serial->isOpen()) {
        serial->write(data.toUtf8());
    } else {
        qDebug() << "Port série non ouvert.";
    }
}
QSerialPort* Arduino::getserial() {
    return serial;  // Retourne le pointeur vers l'objet QSerialPort
}
