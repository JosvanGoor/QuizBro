#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSoundEffect>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/*
    Personally defined slots, to receive actions from buttons etc.
*/
private slots:
    //Slider changes
    void blinkspeed_slider_changed(int val);
    //scoreboard buttons
    void score_change();
    //Audio settings
    void set_audio();
    void toggle_mute(int state);

private:
    Ui::MainWindow *ui;

    int m_blink_speed;

    int m_red_score;
    int m_blue_score;
    int m_green_score;
    int m_yellow_score;

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
