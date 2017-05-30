#ifndef QUIZBRO_ARDUINO_HPP
#define QUIZBRO_ARDUINO_HPP

#include <QThread>
#include <QIODevice>
#include <QSerialPort>

enum ArduinoSignal
{
    NO_EVENT                =   0b0000000000000000,
    RED_BOUTON              =   0b0000000000000001,
    GREEN_BOUTON            =   0b0000000000000010,
    BLUE_BOUTON             =   0b0000000000000100,
    YELLOW_BOUTON           =   0b0000000000001000,
    ALL_BOUTONS             =   0b0000000000010000,

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
        void set_button_state(int button, int state);

        virtual void run() override;

    signals:
        void arduino_signal(short signal);

    private:
        QSerialPort m_serial;
};

#endif
