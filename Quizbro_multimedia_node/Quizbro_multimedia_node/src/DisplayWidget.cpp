#include "DisplayWidget.hpp"

#include <QDebug>

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)
{
    //init image hosts
    m_image_primary = new QLabel("", this);
    m_image_primary->setObjectName(QStringLiteral("m_image_primary"));
    m_image_primary->setGeometry(0, 0, 10, 10);
    m_image_primary->setPixmap(QPixmap(":/resources/logo.png"));

    m_image_secondary = new QLabel("", this);
    m_image_secondary->setObjectName(QStringLiteral("m_image_secondary"));
    m_image_secondary->setGeometry(0, 0, 10, 10);
    m_image_secondary->hide();

    //init video hosts
    m_video_primary = new QVideoWidget(this);
    m_video_primary->setObjectName("m_video_primary");
    m_video_primary->setGeometry(0, 0, 0, 0);
    m_video_primary->hide();

    m_video_secondary = new QVideoWidget(this);
    m_video_secondary->setObjectName("m_video_secondary");
    m_video_secondary->setGeometry(0, 0, 0, 0);
    m_video_secondary->hide();

    m_playlist_primary = new QMediaPlaylist;
    m_playlist_primary->setObjectName("m_playlist_primary");
    m_playlist_primary->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    m_playlist_secondary = new QMediaPlaylist;
    m_playlist_secondary->setObjectName("m_playlist_secondary");
    m_playlist_secondary->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    m_player_primary = new QMediaPlayer;
    m_player_primary->setObjectName("m_player_primary");
    m_player_primary->setVideoOutput(m_video_primary);
    m_player_primary->setPlaylist(m_playlist_primary);
    m_player_primary->setMuted(true);

    m_player_secondary = new QMediaPlayer;
    m_player_secondary->setObjectName("m_player_secondary");
    m_player_secondary->setVideoOutput(m_video_secondary);
    m_player_secondary->setPlaylist(m_playlist_secondary);
    m_player_secondary->setMuted(true);

    //initial state setup
    m_video_changed = false;
    m_display_mode = IMAGE;
}

DisplayWidget::~DisplayWidget()
{
    //delete all the things
    delete m_player_primary;
    delete m_player_secondary;
    delete m_playlist_primary;
    delete m_playlist_secondary;
    delete m_video_primary;
    delete m_video_secondary;

    delete m_image_primary;
    delete m_image_secondary;
}

void DisplayWidget::display_image(const QString &file)
{
    QPixmap image(file);
    if(image.isNull())
    {
        qDebug() << "QPixmap is null";
        return;
    }
    
    if(m_display_mode == IMAGE)
    {
        m_image_secondary->setPixmap(image.scaled(m_window_size.width(), m_window_size.height()));
        if(m_image_secondary->graphicsEffect())
            m_image_secondary->graphicsEffect()->setEnabled(false);
        m_image_primary->raise();
        m_image_secondary->show();

        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        m_image_primary->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
        a->setDuration(TRANSFER_DURATION_MS);
        a->setStartValue(1.0);
        a->setEndValue(0.0);
        a->setEasingCurve(QEasingCurve::OutBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(hide_inactive_layers()));

        //swap pointers
        QLabel *tmp = m_image_primary;
        m_image_primary = m_image_secondary;
        m_image_secondary = tmp;
    }
    else if(m_display_mode == VIDEO)
    {
        m_display_mode = IMAGE;

        m_image_primary->setPixmap(image.scaled(m_window_size.width(), m_window_size.height()));
        if(m_image_primary->graphicsEffect())
            m_image_primary->graphicsEffect()->setEnabled(false);
        
        m_video_primary->raise();
        m_image_primary->show();
        
        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        m_video_primary->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
        a->setDuration(TRANSFER_DURATION_MS);
        a->setStartValue(1.0);
        a->setEndValue(0.0);
        a->setEasingCurve(QEasingCurve::OutBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(hide_inactive_layers()));
    }
    
}

void DisplayWidget::display_video(const QString &file)
{
    //if(m_display_mode == IMAGE)
    {
        m_display_mode = VIDEO;

        m_playlist_primary->clear();
        m_playlist_primary->addMedia(QUrl(file));
        m_playlist_primary->setCurrentIndex(0);

        m_image_primary->raise();
        m_video_primary->show();
        m_player_primary->play();

        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        m_image_primary->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
        a->setDuration(TRANSFER_DURATION_MS);
        a->setStartValue(1.0);
        a->setEndValue(0.0);
        a->setEasingCurve(QEasingCurve::OutBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(hide_inactive_layers()));
    }
}

void DisplayWidget::hide_inactive_layers()
{
    if(m_display_mode == IMAGE)
    {
        m_image_secondary->hide();
        
        m_video_primary->hide();
        m_player_primary->pause();
        m_playlist_primary->clear();

        m_video_secondary->hide();
        m_player_secondary->pause();
        m_playlist_secondary->clear();
    }
    else if(m_display_mode == VIDEO)
    {
        m_image_primary->hide();
        m_image_secondary->hide();

        m_video_secondary->hide();
        m_player_secondary->pause();
        m_playlist_secondary->clear();
    }
}

void DisplayWidget::resizeEvent(QResizeEvent *event)
{
    m_window_size = event->size();

    //resize components
    m_image_primary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());
    m_image_secondary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());

    m_video_primary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());
    m_video_secondary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());

    //resize image inside primary component
    if(m_display_mode == IMAGE)
        m_image_primary->setPixmap(m_image_primary->pixmap()->scaled(m_window_size.width(), m_window_size.height()));
}
