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

    m_arduino_connected = false;
    m_beat_buzzer_mode = false;
    m_btb_winner = NO_BOUTON;
    m_play_long_fragment = true;
    m_allow_simultaneous_audio = true;

    ui->status_bar->addPermanentWidget(m_audio_status);
    ui->status_bar->addPermanentWidget(m_arduino_status);

    //connect to arduino interface
    QObject::connect(&m_arduino, SIGNAL(arduino_signal(short)), this, SLOT(arduino_signal(short)));

    //connect to unlock buzzer button
    QObject::connect(ui->btn_unlock_buzzers, SIGNAL(clicked()), this, SLOT(unlock_buzzers()));

    //connect to mode radiobuttons
    QObject::connect(ui->rb_buzzer_beater, SIGNAL(toggled(bool)), this, SLOT(mode_toggled(bool)));
    QObject::connect(ui->rb_free_buzzer, SIGNAL(toggled(bool)), this, SLOT(mode_toggled(bool)));

    m_arduino.connect();
    m_arduino.start();
    m_arduino.set_button_state(ALL_BOUTONS, BUTTON_STATE_ON);
}

MainWindow::~MainWindow()
{
    m_arduino.exit();
    delete ui;
}

void MainWindow::unlock_buzzers()
{
    if(!m_beat_buzzer_mode) return;

    m_btb_winner = NO_BOUTON;
    m_arduino.set_button_state(ALL_BOUTONS, BUTTON_STATE_ON);
    ui->lbl_press_info->setText("n/a");
}

void MainWindow::mode_toggled(bool b)
{
    if(ui->rb_buzzer_beater->isChecked() && !m_beat_buzzer_mode)
    {
        m_beat_buzzer_mode = true;
        unlock_buzzers();
    }
    else if((!ui->rb_buzzer_beater->isChecked()) && m_beat_buzzer_mode)
    {
        m_beat_buzzer_mode = false;
        m_arduino.set_button_state(ALL_BOUTONS, 1000);
    }
}

void MainWindow::arduino_signal(short i)
{
    if(!m_arduino_connected && i == ARDUINO_STATUS_OK)
    {
        m_arduino_status->setText("Arduino: Ok!");
        m_arduino_connected = true;
        return;
    } 
    else if(i == ARDUINO_STATUS_DISC)
    {
       m_arduino_connected = false;
       m_arduino_status->setText("Arduino: n/a");
       return;
    }

    if(m_beat_buzzer_mode && m_btb_winner == NO_BOUTON)
    {
        m_btb_winner = i;
        ui->lbl_press_info->setText(bouton_by_name(i));

        //play audio

        m_arduino.set_button_state(i, BUTTON_STATE_ON);
        m_arduino.set_button_state(~i, BUTTON_STATE_OFF);
    }
    else if(!m_beat_buzzer_mode)
    {
        ui->lbl_press_info->setText(bouton_by_name(i));
        //play audio
    }
}
