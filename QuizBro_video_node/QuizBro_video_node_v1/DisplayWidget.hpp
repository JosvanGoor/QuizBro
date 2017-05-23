#ifndef QUIZBRO_VIDEO_NODE_DISPLAYWIDGET_HPP
#define QUIZBRO_VIDEO_NODE_DISPLAYWIDGET_HPP

#include <QLabel>
#include <QThread>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QResizeEvent>

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    DisplayWidget(QWidget *parent = 0);

    void display_image(QString file);
    void display_video(QString file);

protected:
    virtual void resizeEvent(QResizeEvent *event);

protected:
    QLabel *m_image_display;
    QMediaPlayer *m_media_player;
    QVideoWidget *m_video_widget;
};

#endif