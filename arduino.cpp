#include "arduino.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
}

bool Arduino::connectArduino()
{
    serial->setPortName("COM3");  // Adapter selon ton PC
    serial->setBaudRate(QSerialPort::Baud9600);

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Erreur d'ouverture Arduino.";
        return false;
    }

    connect(serial, &QSerialPort::readyRead, this, &Arduino::readSerial);
    return true;
}

void Arduino::readSerial()
{
    QString data = QString::fromUtf8(serial->readAll()).trimmed();

    if (data == "1") emit rfidOk();
    if (data == "0") emit rfidError();
}

void Arduino::sendToArduino(const QString &data)
{
    serial->write(data.toUtf8());
}
