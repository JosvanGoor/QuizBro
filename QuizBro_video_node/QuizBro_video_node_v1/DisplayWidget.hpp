#ifndef QUIZBRO_VIDEO_NODE_DISPLAYWIDGET_HPP
#define QUIZBRO_VIDEO_NODE_DISPLAYWIDGET_HPP

#include <QDir>
#include <QLabel>
#include <QTimer>
#include <QThread>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QResizeEvent>
#include <QMediaPlaylist>

#include <algorithm>

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    DisplayWidget(QWidget *parent = 0);
    ~DisplayWidget();

    void set_muted(bool muted);

    //EXPIRIMENTAL
    void stop_slideshow();
    void enable_slideshow(int interval, QString filelist, bool random_order = false);

public slots:
    void display_image(QString file);
    void display_video(QString file);

protected:
    virtual void resizeEvent(QResizeEvent *event);

private slots:
    void next_slide(); //used with the slideshow function.
    void media_player_state_change(QMediaPlayer::State state); //currently unused.

protected:
    //used for slideshow func
    int m_slideshow_index;
    bool m_random_order;
    QList<QString> *m_slideshow_files;
    QTimer *m_slideshow_timer;

    QLabel *m_image_display;
    QMediaPlayer *m_media_player;
    QMediaPlaylist *m_media_playlist;
    QVideoWidget *m_video_widget;
};

#endif