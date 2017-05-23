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

    m_media_player = new QMediaPlayer;
    m_media_player->setObjectName("m_media_player");
    m_media_player->setVideoOutput(m_video_widget);
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
    QMediaContent *mc = new QMediaContent(QUrl(file));
    m_media_player->setMedia(*mc);

    m_image_display->hide();
    m_video_widget->show();

    m_media_player->play();
}

void DisplayWidget::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    m_video_widget->setGeometry(0, 0, size.width(), size.height());
    m_image_display->setGeometry(0, 0, size.width(), size.height());
    qDebug() << "ResizeEvent: " << event->size().width() << ", " << event->size().height() << ".";
}