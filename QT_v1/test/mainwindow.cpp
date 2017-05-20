#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_blink_speed = 1000;
    m_red_score = m_blue_score = m_green_score = m_yellow_score = 0;

    m_beat_buzzer_mode = false;
    m_play_long_fragment = true;
    m_allow_simultaneous_audio = true;

    /*  
        Link signals and slots.
    */
    //blinkspeed silder link.
    QObject::connect(ui->sld_blinkspeed, SIGNAL(valueChanged(int)), this, SLOT(blinkspeed_slider_changed(int)));
    //mute check link
    QObject::connect(ui->chb_mute, SIGNAL(stateChanged(int)), this, SLOT(toggle_mute(int)));

    //score change links / set audio (red)
    QObject::connect(ui->btn_red_m1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_m5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_m10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_p10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_p5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_p1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_red_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_red_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    //score change links / set audio (blue)
    QObject::connect(ui->btn_blue_m1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_m5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_m10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_p10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_p5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_p1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_blue_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_blue_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    //score change links / set audio (green)
    QObject::connect(ui->btn_green_m1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_m5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_m10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_p10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_p5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_p1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_green_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_green_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    //score change links / set audio (yellow)
    QObject::connect(ui->btn_yellow_m1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_m5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_m10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_p10, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_p5, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_p1, SIGNAL(clicked()), this, SLOT(score_change()));
    QObject::connect(ui->btn_yellow_set_long_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
    QObject::connect(ui->btn_yellow_set_short_audio, SIGNAL(clicked()), this, SLOT(set_audio()));
}

/*
    Personally defined slots.
*/
void MainWindow::blinkspeed_slider_changed(int val)
{
    char buf[16];
    sprintf(buf, "%.1f sec.", val/1000.0);
    ui->lbl_blinkspeed->setText(QString(buf));
    m_blink_speed = val;
}

//scoreboard buttons
void MainWindow::score_change()
{
    QObject *sender = QObject::sender();

    int delta = 0;
    if(sender->objectName().contains(QString("m10"))) delta = -10;
    else if(sender->objectName().contains(QString("m5"))) delta = -5;
    else if(sender->objectName().contains(QString("m1"))) delta = -1;
    else if(sender->objectName().contains(QString("p10"))) delta = 10;
    else if(sender->objectName().contains(QString("p5"))) delta = 5;
    else if(sender->objectName().contains(QString("p1"))) delta = 1;


    char buf[16];
    if(sender->objectName().contains(QString("red")))
    {
        m_red_score += delta;
        sprintf(buf, "Score: %d", m_red_score);
        ui->lbl_red_score->setText(QString(buf));
    }
    else if(sender->objectName().contains(QString("blue")))
    {
        m_blue_score += delta;
        sprintf(buf, "Score: %d", m_blue_score);
        ui->lbl_blue_score->setText(QString(buf));
    }
    else if(sender->objectName().contains(QString("green")))
    {
        m_green_score += delta;
        sprintf(buf, "Score: %d", m_green_score);
        ui->lbl_green_score->setText(QString(buf));
    }
    else if(sender->objectName().contains(QString("yellow")))
    {
        m_yellow_score += delta;
        sprintf(buf, "Score: %d", m_yellow_score);
        ui->lbl_yellow_score->setText(QString(buf));
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
        m_red_audio_long.setMuted(false);
        m_red_audio_short.setMuted(false);
        m_blue_audio_long.setMuted(false);
        m_blue_audio_short.setMuted(false);
        m_green_audio_long.setMuted(false);
        m_green_audio_short.setMuted(false);
        m_yellow_audio_long.setMuted(false);
        m_yellow_audio_short.setMuted(false);
        std::cout << "Audio muted..."  << std::endl;
    } 
    else 
    {
        m_red_audio_long.setMuted(true);
        m_red_audio_short.setMuted(true);
        m_blue_audio_long.setMuted(true);
        m_blue_audio_short.setMuted(true);
        m_green_audio_long.setMuted(true);
        m_green_audio_short.setMuted(true);
        m_yellow_audio_long.setMuted(true);
        m_yellow_audio_short.setMuted(true);
        std::cout << "Audio unmuted..."  << std::endl;
    }
}

/*
    End of handwritten code.
*/

MainWindow::~MainWindow()
{
    delete ui;
}
