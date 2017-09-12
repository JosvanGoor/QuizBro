#ifndef QUIZBRO_ARDUINO_HPP
#define QUIZBRO_ARDUINO_HPP

#include <QDebug>
#include <QThread>
#include <QIODevice>
#include <QSerialPort>

#define SERIAL_HANDLE "/dev/ttyACM0"
//#define SERIAL_HANDLE "COM3"

enum ArduinoSignal
{
    NO_BOUTON               =   0b0000000000000000,
    RED_BOUTON              =   0b0000000000000001,
    GREEN_BOUTON            =   0b0000000000000010,
    BLUE_BOUTON             =   0b0000000000000100,
    YELLOW_BOUTON           =   0b0000000000001000,
    WHITE_BOUTON            =   0b0000000000010000,
    EXT1_BOUTON             =   0b0000000000100000,
    EXT2_BOUTON             =   0b0000000001000000,
    EXT3_BOUTON             =   0b0000000010000000,
    ALL_BOUTONS             =   0b0000000011111111,

    ARDUINO_MODE_BTB        =   0b0100000000000000,
    ARDUINO_MODE_FREE       =   0b0010000000000000,
    ARDUINO_MODE_UNLOCK     =   0b0001000000000000,

    ARDUINO_STATUS_DISC     =   0b0000100000000000,
    ARDUINO_STATUS_ERROR    =   0b0000010000000000,
    ARDUINO_STATUS_OK       =   0b0000001000000000,

    BUTTON_STATE_OFF        =   0,
    BUTTON_STATE_ON         =   -1,
    BUTTON_STATE_ON_PUSH    =   -2,
    BUTTON_STATE_OFF_PUSH   =   -3
};

/*
*/

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
