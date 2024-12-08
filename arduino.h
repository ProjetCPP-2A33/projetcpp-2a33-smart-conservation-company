#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>

class Arduino : public QObject
{
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
    bool connectToArduino();
    void disconnectFromArduino();
    int connect_arduino();
    //-----gestion produit---------------------
    void setPortName(const QString &portName);
    QSerialPort* getserial();
    QString getarduino_port_name();
    int close_arduino();
    int write_to_arduino(QByteArray data);
    QByteArray read_from_arduino();

signals:
    void dataReceived(QString data);

private slots:
    void readSerialData();

private:
    QSerialPort *serial;

    //-------gestion produit--------------------------

    bool arduino_is_available;
    QString arduino_port_name;
    QByteArray data;  // contenant les données lues à partir d'Arduino
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
};

#endif // ARDUINO_H
