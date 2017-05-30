#include "Arduino.hpp"

Arduino::Arduino(QObject *parent)
    : QThread(parent)
{
}

int Arduino::status()
{
    return ARDUINO_STATUS_ERROR;
}

bool Arduino::connect()
{   
    if(m_serial.isOpen()) return;

    m_serial.setPortName("ttyAMC0");
    m_serial.open(QIODevice::ReadWrite);
    m_serial.setBaudRate(9600);
    m_serial.setDataBits(QSerialPort::Data8);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setControlFlow(QSerialPort::NoFlowControl);
}

void Arduino::set_button_state(int button, int state)
{
    //send die datatje jwz
}

void Arduino::run()
{
    short data;

    while(m_serial.isOpen())
    {
        m_serial.readData(data, sizeof(short));
        arduino_signal(data);
    }
}