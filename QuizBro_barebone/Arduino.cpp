#include "Arduino.hpp"



Arduino::Arduino(QObject *parent)
    : QThread(parent)
{
    m_serial.setTextModeEnabled(true);
    QObject::connect(&m_serial, SIGNAL(readyRead()), this, SLOT(input_posted()));
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

    m_serial.setBaudRate(QSerialPort::Baud57600);
    m_serial.setDataBits(QSerialPort::Data8);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setFlowControl(QSerialPort::NoFlowControl);

    QThread::sleep(2.5); //wait for the interface to settle.
    qDebug() << "Succesfully connected to port " << SERIAL_HANDLE;
    arduino_signal(ARDUINO_STATUS_OK);
    return true;
}

void Arduino::run()
{
    exec();
    m_serial.close();
}

void Arduino::set_button_state(short button, short state)
{
    QByteArray buf = QByteArray::number(button).append(" ").append(QByteArray::number(state));
    qDebug() << __PRETTY_FUNCTION__ << " sending \"" << buf << "\"";
    m_serial.write(buf);
}

void Arduino::input_posted()
{
    qDebug() << __PRETTY_FUNCTION__;
    while(m_serial.canReadLine())
    {
        qDebug() << "Entered while";
        QByteArray bar = m_serial.readLine();
        qDebug() << __PRETTY_FUNCTION__ <<"Arduino sent: " << bar;
        arduino_signal((short)bar.trimmed().toInt());
    }
}


QString bouton_by_name(short as)
{
    QString str;
    if(as & RED_BOUTON) str += "Red ";
    if(as & BLUE_BOUTON) str += "Blue ";
    if(as & GREEN_BOUTON) str += "Green ";
    if(as & YELLOW_BOUTON) str += "Yellow ";
    return str;
}