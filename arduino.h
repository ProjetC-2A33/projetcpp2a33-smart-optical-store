#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>

class Arduino : public QObject
{
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);

    bool connectArduino();
    void sendToArduino(const QString &data);

signals:
    void rfidOk();      // Arduino a envoyé "1"
    void rfidError();   // Arduino a envoyé "0"

private slots:
    void readSerial();

private:
    QSerialPort *serial;
};

#endif // ARDUINO_H
