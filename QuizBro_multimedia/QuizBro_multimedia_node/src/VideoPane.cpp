#include "VideoPane.hpp"

VideoPane::VideoPane(QWidget *parent)
    : QWidget(parent)
{
    m_display_primary = new QVideoWidget(this);
    m_display_primary->setObjectName(QStringLiteral("m_video_primary"));
    
    m_display_secondary = new QVideoWidget(this);
    m_display_secondary->setObjectName(QStringLiteral("m_video_secondary"));
    m_display_secondary->hide();

    m_playlist_primary = new QMediaPlaylist;
    m_playlist_primary->setObjectName(QStringLiteral("m_playlist_primary"));
    m_playlist_primary->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    m_playlist_secondary = new QMediaPlaylist;
    m_playlist_secondary->setObjectName(QStringLiteral("m_playlist_secondary"));
    m_playlist_secondary->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    m_player_primary = new QMediaPlayer;
    m_player_primary->setObjectName(QStringLiteral("m_player_primary"));
    m_player_primary->setVideoOutput(m_display_primary);
    m_player_primary->setPlaylist(m_playlist_primary);
    m_player_primary->setMuted(true);

    m_player_secondary = new QMediaPlayer;
    m_player_secondary->setObjectName(QStringLiteral("m_player_secondary"));
    m_player_secondary->setVideoOutput(m_display_secondary);
    m_player_secondary->setPlaylist(m_playlist_secondary);
    m_player_secondary->setMuted(true);
}

VideoPane::~VideoPane()
{
    delete m_player_primary;
    delete m_player_secondary;
    delete m_playlist_primary;
    delete m_playlist_secondary;
    delete m_display_primary;
    delete m_display_secondary;
}

void VideoPane::display_video(const QString &file)
{
    m_playlist_primary->clear();
    m_playlist_primary->addMedia(QUrl(file));
    m_playlist_primary->setCurrentIndex(0);

    m_player_primary->play();
}

void VideoPane::hide_inactive_layer()
{

}

void VideoPane::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();

    m_display_primary->setGeometry(0, 0, size.width(), size.height());
    m_display_secondary->setGeometry(0, 0, size.width(), size.height());
}