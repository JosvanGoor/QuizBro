#include <DisplayWidget.hpp>

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)

{
    m_video_widget = new QVideoWidget(this);
    m_video_widget->setObjectName(QStringLiteral("m_video_widget"));
    m_video_widget->setGeometry(0, 0, 0, 0);

    m_image_display = new QLabel("test", this);
    m_image_display->setObjectName(QStringLiteral("m_image_display"));
    m_image_display->setScaledContents(true);
    m_image_display->setGeometry(0, 0, 10, 10);

    m_media_playlist = new QMediaPlaylist;
    m_media_playlist->setObjectName("m_media_playlist");
    m_media_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    m_media_player = new QMediaPlayer;
    m_media_player->setObjectName("m_media_player");
    m_media_player->setVideoOutput(m_video_widget);
    m_media_player->setPlaylist(m_media_playlist);
    m_media_player->setMuted(true);

    //set slideshow stuff to null
    index = 0;
    files = nullptr;
    timer = nullptr;
}

DisplayWidget::~DisplayWidget()
{
    delete m_media_player;
    delete m_media_playlist;
    delete m_video_widget;
    delete m_image_display;
}

void DisplayWidget::set_muted(bool b)
{
    m_media_player->setMuted(b);
}

void DisplayWidget::stop_slideshow()
{
    if(timer != nullptr)
    {
        delete files;
        delete timer;
        files = nullptr;
        timer = nullptr;
    }
}

void DisplayWidget::enable_slideshow(int interval, QString filelist)
{
    if(timer != nullptr)
    {
        stop_slideshow();
    }

    files = new QList<QString>();

    QFile input(filelist);
    if(input.open(QIODevice::ReadOnly))
    {
        QTextStream in(&input);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            files->push_back(line);
        }
        input.close();
    }
    else
    {
        qDebug() << "Failed to open slideshow file list.";
        return;
    }

    index = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(next_slide()));
    timer->start(interval);

    next_slide();
}

void DisplayWidget::display_image(QString file)
{
    QPixmap image(file);
    if(image.isNull())
    {
        qDebug() << "QPixmap is null";
        return;
    }

    m_image_display->setPixmap(image);
    m_image_display->show();
    m_video_widget->hide();
}

void DisplayWidget::display_video(QString file)
{
    m_media_playlist->clear();
    m_media_playlist->addMedia(QUrl(file));
    m_media_playlist->setCurrentIndex(0);

    m_media_player->play();

    m_video_widget->show();
    m_image_display->hide();
}

void DisplayWidget::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    m_video_widget->setGeometry(0, 0, size.width(), size.height());
    m_image_display->setGeometry(0, 0, size.width(), size.height());
    qDebug() << "ResizeEvent: " << event->size().width() << ", " << event->size().height() << ".";
}

void DisplayWidget::next_slide()
{
    static QDir root;
    qDebug() << __PRETTY_FUNCTION__ << " showing image " << root.absolutePath() + "/" + files->at(index);

    display_image(root.absolutePath() + "/" + files->at(index));
    index++;
}

void DisplayWidget::media_player_state_change(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::StoppedState)
        m_media_player->play();
}