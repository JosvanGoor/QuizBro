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
    m_slideshow_index = 0;
    m_slideshow_files = nullptr;
    m_slideshow_timer = nullptr;
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
    if(m_slideshow_timer != nullptr)
    {
        delete m_slideshow_timer;
        m_slideshow_timer = nullptr;
    }
    if(m_slideshow_files != nullptr)
    {
        delete m_slideshow_files;
        m_slideshow_files = nullptr;
    }
}

void DisplayWidget::enable_slideshow(int interval, QString filelist, bool random_order)
{
    stop_slideshow(); //has no effect if no slideshow is running.
    m_media_player->stop(); //EXPERIMENTAL

    m_slideshow_files = new QList<QString>();

    QFile input(filelist);
    if(input.open(QIODevice::ReadOnly))
    {
        QTextStream in(&input);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            m_slideshow_files->push_back(line);
        }
        input.close();
    }
    else
    {
        qDebug() << "Failed to open slideshow file list.";
        return;
    }

    m_slideshow_index = 0;
    m_random_order = random_order;
    m_slideshow_timer = new QTimer(this);
    connect(m_slideshow_timer, SIGNAL(timeout()), this, SLOT(next_slide()));
    m_slideshow_timer->start(interval);

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

    stop_slideshow();
    m_media_player->stop();

    m_image_display->setPixmap(image);
    m_image_display->show();
    m_video_widget->hide();
}

void DisplayWidget::display_video(QString file)
{
    m_media_playlist->clear();
    m_media_playlist->addMedia(QUrl(file));
    m_media_playlist->setCurrentIndex(0);
    stop_slideshow();

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
    if(m_random_order && m_slideshow_index == 0) std::random_shuffle(m_slideshow_files->begin(), m_slideshow_files->end());

    qDebug() << __PRETTY_FUNCTION__ << " showing image " << root.absolutePath() + "/" + m_slideshow_files->at(m_slideshow_index);

    display_image(root.absolutePath() + "/" + m_slideshow_files->at(m_slideshow_index));
    m_slideshow_index = (m_slideshow_index + 1) % m_slideshow_files->size();
}

void DisplayWidget::media_player_state_change(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::StoppedState)
        m_media_player->play();
}
