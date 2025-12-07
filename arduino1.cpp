#include "arduino1.h"
#include <QDebug>

Arduino1::Arduino1(QObject *parent)
    : QObject(parent), serial(new QSerialPort(this))
{}

bool Arduino1::connectArduino()
{
    serial->setPortName("COM3");                 // ⚡ Arduino sur COM4
    serial->setBaudRate(QSerialPort::Baud9600);

    if (serial->open(QIODevice::ReadWrite)) {

        connect(serial, &QSerialPort::readyRead,
                this, &Arduino1::readSerialData);

        qDebug() << "Arduino connecté sur COM4";
        emit arduinoConnected();
        return true;
    }

    qDebug() << "Erreur : impossible d’ouvrir COM4";
    emit arduinoDisconnected();
    return false;
}

void Arduino1::readSerialData()
{
    buffer += serial->readAll();

    if (buffer.endsWith('#')) {          // Fin de transmission
        buffer.chop(1);                  // enlever le '#'
        emit codeReceived(buffer);
        buffer.clear();
    }
}

void Arduino1::sendToArduino(const QString &data)
{
    if (serial->isOpen()) {
        serial->write(data.toUtf8());    // Exemple : "OK#" ou "NOK#"
    }
}
