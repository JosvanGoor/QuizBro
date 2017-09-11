#include "DisplayWidget.hpp"

#include <QDebug>

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)
{
    m_image_primary = new QLabel("", this);
    m_image_primary->setObjectName(QStringLiteral("m_image_primary"));
    m_image_primary->setGeometry(0, 0, 10, 10);
    m_image_primary->setPixmap(QPixmap("images/test1.jpg"));

    m_image_secondary = new QLabel("", this);
    m_image_secondary->setObjectName(QStringLiteral("m_image_secondary"));
    m_image_secondary->setGeometry(0, 0, 10, 10);
    m_image_secondary->hide();

    m_display_mode = IMAGE;
}

DisplayWidget::~DisplayWidget()
{

}

void DisplayWidget::display_image(const QString &file)
{
    if(m_display_mode == IMAGE)
    {
        QPixmap image(file);
        if(image.isNull())
        {
            qDebug() << "QPixmap is null";
            return;
        }

        m_image_secondary->setPixmap(image.scaled(m_window_size.width(), m_window_size.height()));
        if(m_image_secondary->graphicsEffect())
            m_image_secondary->graphicsEffect()->setEnabled(false);
        m_image_primary->raise();
        m_image_secondary->show();

        QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        m_image_primary->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
        a->setDuration(2500);
        a->setStartValue(1.0);
        a->setEndValue(0.0);
//        a->setEasingCurve(QEasingCurve::OutBack);
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SLOT(hide_inactive_layers()));

        //swap pointers
        QLabel *tmp = m_image_primary;
        m_image_primary = m_image_secondary;
        m_image_secondary = tmp;
    }
    //TODO: display mode video
}

void DisplayWidget::hide_inactive_layers()
{
    if(m_display_mode == IMAGE) m_image_secondary->hide();
    //TODO: add video layers
}

void DisplayWidget::resizeEvent(QResizeEvent *event)
{
    m_window_size = event->size();

    //resize components
    m_image_primary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());
    m_image_secondary->setGeometry(0, 0, m_window_size.width(), m_window_size.height());

    //resize image inside primary component
    if(m_display_mode == IMAGE)
        m_image_primary->setPixmap(m_image_primary->pixmap()->scaled(m_window_size.width(), m_window_size.height()));
}
