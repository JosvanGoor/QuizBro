#include "ImagePane.hpp"

ImagePane::ImagePane(QWidget *parent)
    : QWidget(parent)
{
    m_image_primary = new QLabel("", this);
    m_image_primary->setObjectName(QStringLiteral("m_image_primary"));
    m_latest_file = ":/resources/logo.png";
    m_image_primary->setPixmap(m_latest_file);

    m_image_secondary = new QLabel("", this);
    m_image_secondary->setObjectName(QStringLiteral("m_image_secondary"));
    m_image_secondary->hide();
}

ImagePane::~ImagePane()
{
    delete m_image_primary;
    delete m_image_secondary;
}

void ImagePane::display_image(const QString &file)
{
    QPixmap image(file);
    if(image.isNull())
    {
        qDebug() << __PRETTY_FUNCTION__ << "received bad filename.";
        return;
    }

    m_latest_file = file;
    QSize size = this->size();
    m_image_secondary->setPixmap(image.scaled(size.width(), size.height()));
    if(m_image_secondary->graphicsEffect())
    { //disable any lingering graphics effect.
        m_image_secondary->graphicsEffect()->setEnabled(false);
    }
    m_image_primary->raise();
    m_image_secondary->show();

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    m_image_primary->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
    a->setDuration(FADE_TIME_MS);
    a->setStartValue(1.0);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::OutBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a, SIGNAL(finished()), this, SLOT(hide_inactive_image()));

    //swap image slots
    QLabel *tmp = m_image_primary;
    m_image_primary = m_image_secondary;
    m_image_secondary = tmp;
}

void ImagePane::hide_inactive_image()
{
    m_image_secondary->hide();
}

void ImagePane::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();

    //resize image displays
    m_image_primary->setGeometry(0, 0, size.width(), size.height());
    m_image_secondary->setGeometry(0, 0, size.width(), size.height());

    if(this->isVisible() || m_latest_file == ":/resources/logo.png")
    {
        m_image_primary->setPixmap(QPixmap(m_latest_file).scaled(size.width(), size.height()));
    }
}
