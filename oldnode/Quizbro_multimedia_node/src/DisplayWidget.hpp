#ifndef DISPLAYWIDGET_HPP
#define DISPLAYWIDGET_HPP

#include <QUrl>
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QMediaPlayer>
#include <QResizeEvent>
#include <QEasingCurve>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

#define TRANSFER_DURATION_MS 3500

enum DisplayMode
{
    IMAGE,
    VIDEO
};

class DisplayWidget : public QWidget
{
    Q_OBJECT

    public:
        DisplayWidget(QWidget *parent = nullptr);
        ~DisplayWidget();

    public slots:
        void display_image(const QString &file);
        void display_video(const QString &file);
    
    private slots:
        void hide_inactive_layers();
        //void video_playing(float f); //video progress, this manages the loop.

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;

    private:
        QSize m_window_size;

        QLabel *m_image_primary;
        QLabel *m_image_secondary;

        bool m_video_changed;

        QMediaPlayer *m_player_primary;
        QMediaPlaylist *m_playlist_primary;
        QVideoWidget *m_video_primary;

        QMediaPlayer *m_player_secondary;
        QMediaPlaylist *m_playlist_secondary;
        QVideoWidget *m_video_secondary;

        DisplayMode m_display_mode;
};

#endif