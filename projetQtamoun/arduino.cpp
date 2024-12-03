#include "Arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

Arduino::Arduino()
{
    serial = new QSerialPort;
    arduino_is_available = false;
}

int Arduino::connect_arduino()
{

    // cas reel
    /*foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                                                                                    == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();
            } } }
    qDebug() << "arduino_port_name est :" << arduino_port_name;
    if(arduino_is_available){
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }*/


    // simulation sur le port com3

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Found port:" << serialPortInfo.portName();
        if (serialPortInfo.portName() == "COM3") {
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

void Arduino::setPortName(const QString &portName)
{
    arduino_port_name = portName;
    serial->setPortName(portName);
}
QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}


