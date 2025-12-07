#ifndef ARDUINO1_H
#define ARDUINO1_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino1 : public QObject
{
    Q_OBJECT

public:
    explicit Arduino1(QObject *parent = nullptr);
    bool connectArduino();                     // Connexion COM4
    void sendToArduino(const QString &data);   // Envoi OK#/NOK#

signals:
    void codeReceived(QString code);           // Code reçu depuis Arduino
    void arduinoConnected();
    void arduinoDisconnected();

private slots:
    void readSerialData();                    // Lecture du port série

private:
    QSerialPort *serial;
    QString buffer;
};

#endif // ARDUINO1_H
