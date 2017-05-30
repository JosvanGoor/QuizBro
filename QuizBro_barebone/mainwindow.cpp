#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_audio_status = new QLabel("AudioNode: n/a");
    m_audio_status->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_arduino_status = new QLabel("Arduino: n/a");
    m_arduino_status->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    m_beat_buzzer_mode = false;
    m_play_long_fragment = true;
    m_allow_simultaneous_audio = true;

    ui->status_bar->addPermanentWidget(m_audio_status);
    ui->status_bar->addPermanentWidget(m_arduino_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}
