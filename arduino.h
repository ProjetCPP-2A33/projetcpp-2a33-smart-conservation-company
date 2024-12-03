
#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>// classe les objets Qt.
#include <QtSerialPort/QSerialPort>//communication en serie avec arduino
#include <QtSerialPort/QSerialPortInfo>//rcupérer des informations sur les ports série disponibles.

class Arduino : public QObject {
    Q_OBJECT// pour utiliserfonctionnaliter qt

public:
    explicit Arduino(QObject *parent = nullptr);  // Constructeur
    ~Arduino();  // Destructeur

    bool connectToArduino();             // Connexion à Arduino
    void sendToArduino(const QString &); // Envoi de données
    QString readFromArduino();//lire donner envoyer par arduino
void listAvailablePorts();        // Lecture des port available

private:
    QSerialPort *serial; // Objet pour gérer le port série
    QString portName;    // Nom du port Arduino
    int baudRate;        // Vitesse de communication
};

#endif // ARDUINO_H
