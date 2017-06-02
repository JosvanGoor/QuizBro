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
    QObject::connect(ui->rb_play_long, SIGNAL(toggled(bool)), this, SLOT(mode_toggled(bool)));
    QObject::connect(ui->rb_play_short, SIGNAL(toggled(bool)), this, SLOT(mode_toggled(bool)));

    //connect audiobuttons
    QObject::connect(ui->btn_red_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_red_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_blue_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_blue_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_green_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_green_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_yellow_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_yellow_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    
    //connect checkboxxes
    QObject::connect(ui->chb_mute, SIGNAL(stateChanged(int)), this, SLOT(toggle_mute(int)));
    QObject::connect(ui->chb_simultaneous, SIGNAL(stateChanged(int)), this, SLOT(toggle_simultaneous(int)));

    m_arduino.connect();
    m_arduino.start();
    m_arduino.set_button_state(ALL_BOUTONS, 1000);
}

MainWindow::~MainWindow()
{
    m_arduino.exit();
    delete ui;
}

bool MainWindow::any_playing()
{
    if(m_red_audio_long.isPlaying() || m_red_audio_short.isPlaying())
        return true;
    if(m_blue_audio_long.isPlaying() || m_blue_audio_short.isPlaying())
        return true;
    if(m_green_audio_long.isPlaying() || m_green_audio_short.isPlaying())
        return true;
    if(m_yellow_audio_long.isPlaying() || m_yellow_audio_short.isPlaying())
        return true;
    return false;
}

void MainWindow::play(short i)
{
    if(!m_allow_simultaneous_audio && any_playing()) return;

    if(m_play_long_fragment)
    {
        if((i & RED_BOUTON) && !m_red_audio_long.isPlaying()) m_red_audio_long.play();
        if((i & BLUE_BOUTON) && !m_blue_audio_long.isPlaying()) m_blue_audio_long.play();
        if((i & GREEN_BOUTON) && !m_green_audio_long.isPlaying()) m_green_audio_long.play();
        if((i & YELLOW_BOUTON) && !m_yellow_audio_long.isPlaying()) m_yellow_audio_long.play();
    }
    else
    {
        if((i & RED_BOUTON) && !m_red_audio_short.isPlaying()) m_red_audio_short.play();
        if((i & BLUE_BOUTON) && !m_blue_audio_short.isPlaying()) m_blue_audio_short.play();
        if((i & GREEN_BOUTON) && !m_green_audio_short.isPlaying()) m_green_audio_short.play();
        if((i & YELLOW_BOUTON) && !m_yellow_audio_short.isPlaying()) m_yellow_audio_short.play();
    }
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
    Q_UNUSED(b);
    
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

    if(ui->rb_play_long->isChecked())
    {
        m_play_long_fragment = true;
    }
    else
    {
        m_play_long_fragment = false;
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

        play(i);

        m_arduino.set_button_state(i, BUTTON_STATE_ON);
        m_arduino.set_button_state(~i, BUTTON_STATE_OFF);
    }
    else if(!m_beat_buzzer_mode)
    {
        ui->lbl_press_info->setText(bouton_by_name(i));
        play(i);
    }
}

void MainWindow::set_audio()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select audio file", QDir::homePath(), "Uncompressed Audio (*.wav)");
    if(filename == "") return;

    QObject *sender = QObject::sender();
    QUrl file_url = QUrl::fromLocalFile(filename);
    QString label = file_url.fileName();

    if(sender->objectName().contains(QString("red")))
    {
        if(sender->objectName().contains(QString("short")))
        {
            m_red_audio_short.setSource(file_url);
            label.prepend("Short audio: ");
            ui->lbl_red_short_audio->setText(label);

            m_red_audio_short.play();
        }
        else if(sender->objectName().contains(QString("long")))
        {
            m_red_audio_long.setSource(file_url);
            label.prepend("Long audio: ");
            ui->lbl_red_long_audio->setText(label);
        }
    }
    else if(sender->objectName().contains(QString("blue")))
    {
        if(sender->objectName().contains(QString("short")))
        {
            m_blue_audio_short.setSource(file_url);
            label.prepend("Short audio: ");
            ui->lbl_blue_short_audio->setText(label);
        }
        else if(sender->objectName().contains(QString("long")))
        {
            m_blue_audio_long.setSource(file_url);
            label.prepend("Long audio: ");
            ui->lbl_blue_long_audio->setText(label);
        }
    }
    else if(sender->objectName().contains(QString("green")))
    {
        if(sender->objectName().contains(QString("short")))
        {
            m_green_audio_short.setSource(file_url);
            label.prepend("Short audio: ");
            ui->lbl_green_short_audio->setText(label);
        }
        else if(sender->objectName().contains(QString("long")))
        {
            m_green_audio_long.setSource(file_url);
            label.prepend("Long audio: ");
            ui->lbl_green_long_audio->setText(label);
        }
    }
    else if(sender->objectName().contains(QString("yellow")))
    {
        if(sender->objectName().contains(QString("short")))
        {
            m_yellow_audio_short.setSource(file_url);
            label.prepend("Short audio: ");
            ui->lbl_yellow_short_audio->setText(label);
        }
        else if(sender->objectName().contains(QString("long")))
        {
            m_yellow_audio_long.setSource(file_url);
            label.prepend("Long audio: ");
            ui->lbl_yellow_long_audio->setText(label);
        }
    }
}

void MainWindow::toggle_mute(int state)
{
    if(state == Qt::Checked)
    {
        m_red_audio_long.setMuted(true);
        m_red_audio_short.setMuted(true);
        m_blue_audio_long.setMuted(true);
        m_blue_audio_short.setMuted(true);
        m_green_audio_long.setMuted(true);
        m_green_audio_short.setMuted(true);
        m_yellow_audio_long.setMuted(true);
        m_yellow_audio_short.setMuted(true);
        qDebug() << "Audio muted...";
    } 
    else 
    {
        m_red_audio_long.setMuted(false);
        m_red_audio_short.setMuted(false);
        m_blue_audio_long.setMuted(false);
        m_blue_audio_short.setMuted(false);
        m_green_audio_long.setMuted(false);
        m_green_audio_short.setMuted(false);
        m_yellow_audio_long.setMuted(false);
        m_yellow_audio_short.setMuted(false);
        qDebug() << "Audio unmuted...";
    }
}

void MainWindow::toggle_simultaneous(int state)
{
    if(state == Qt::Checked)
        m_allow_simultaneous_audio = true;
    else
        m_allow_simultaneous_audio = false;
}
