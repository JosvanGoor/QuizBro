#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QFrame>
#include <QDebug>
#include <QMainWindow>
#include <QSoundEffect>

#include "Arduino.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void arduino_signal(short i); //rgby -> red, green, blue, yellow.

private:
    Ui::MainWindow *ui;

    Arduino m_arduino;

    //statusbar labels
    QLabel *m_audio_status;
    QLabel *m_arduino_status;

    bool m_beat_buzzer_mode;
    bool m_play_long_fragment;
    bool m_allow_simultaneous_audio;

    QSoundEffect m_red_audio_long;
    QSoundEffect m_red_audio_short;
    QSoundEffect m_blue_audio_long;
    QSoundEffect m_blue_audio_short;
    QSoundEffect m_green_audio_long;
    QSoundEffect m_green_audio_short;
    QSoundEffect m_yellow_audio_long;
    QSoundEffect m_yellow_audio_short;
};

#endif // MAINWINDOW_H
