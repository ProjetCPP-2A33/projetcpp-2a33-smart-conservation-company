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

signals:
    void dataReceived(QString data);

private slots:
    void readSerialData();

private:
    QSerialPort *serial;
};

#endif // ARDUINO_H
