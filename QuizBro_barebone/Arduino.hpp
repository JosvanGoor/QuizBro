#ifndef QUIZBRO_ARDUINO_HPP
#define QUIZBRO_ARDUINO_HPP

#include <QDebug>
#include <QThread>
#include <QIODevice>
#include <QSerialPort>

#define SERIAL_HANDLE "/dev/ttyACM0"

enum ArduinoSignal
{
    NO_EVENT                =   0b0000000000000000,
    NO_BOUTON               =   0b0000000000000000,
    RED_BOUTON              =   0b0000000000000001,
    GREEN_BOUTON            =   0b0000000000000010,
    BLUE_BOUTON             =   0b0000000000000100,
    YELLOW_BOUTON           =   0b0000000000001000,
    ALL_BOUTONS             =   0b0000000000001111,

    ARDUINO_STATUS_DISC     =   0b0100000000000000,
    ARDUINO_STATUS_ERROR    =   0b0000000000000000,
    ARDUINO_STATUS_OK       =   0b0000000000000001,

    ARDUINO_MODE_BTB        =   0b0000000000000010,
    ARDUINO_MODE_FREE       =   0b0000000000000100,
    ARDUINO_MODE_UNLOCK     =   0b0000000000001000,

    BUTTON_STATE_OFF        =   0,
    BUTTON_STATE_ON         =   -1,
    BUTTON_STATE_ON_PUSH    =   -2,
    BUTTON_STATE_OFF_PUSH   =   -3
};

class Arduino : public QThread
{
    Q_OBJECT

    public:
        Arduino(QObject *parent = 0);

        int status();
        bool connect(); //todo: disconnect
        void set_button_state(short button, short state);

        virtual void run() override;

    protected slots:
        void input_posted(); //channelReadyRead

    signals:
        void arduino_signal(short signal);

    private:
        QSerialPort m_serial;
};

QString bouton_by_name(short as);

#endif
