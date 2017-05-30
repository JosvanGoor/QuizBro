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
    if(m_serial.isOpen()) return true;

    m_serial.setPortName(SERIAL_HANDLE);
    if(!m_serial.open(QIODevice::ReadWrite))
    {
        qDebug() << "Failed to connect to port " << SERIAL_HANDLE;
        qDebug() << "\tReason: " << m_serial.error();
        arduino_signal(ARDUINO_STATUS_ERROR);
        return false;
    }

    m_serial.setBaudRate(9600);
    m_serial.setDataBits(QSerialPort::Data8);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Succesfully connected to port " << SERIAL_HANDLE;
    arduino_signal(ARDUINO_STATUS_OK);
    return true;
}

void Arduino::set_button_state(int button, int state)
{
    //send die datatje jwz
}

void Arduino::run()
{

    short msg;
    while(true)
    {   
        //dit gaat akelig fout, maar weetje.... er is verbinding woeii!
        int r = m_serial.read((char*)&msg, sizeof(short));
        
        if(r > 0)
        {
            qDebug() << "Read from arduino: " << msg;
            arduino_signal(msg);
        }
    }

}
