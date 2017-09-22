#ifndef VIDEOPANE_HPP
#define VIDEOPANE_HPP

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QResizeEvent>
#include <QString>
#include <QVideoWidget>
#include <QWidget>

#define FADE_TIME_MS 3500

class VideoPane : public QWidget
{
    Q_OBJECT

    public:
        VideoPane(QWidget *parent = nullptr);
        ~VideoPane();

    public slots:
        void display_video(const QString &file);
        void hide_inactive_layer();

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;

    private:
        QString m_current_video;

        QMediaPlayer *m_player_primary;
        QMediaPlaylist *m_playlist_primary;
        QVideoWidget *m_display_primary;

        QMediaPlayer *m_player_secondary;
        QMediaPlaylist *m_playlist_secondary;
        QVideoWidget *m_display_secondary;
};

#endif