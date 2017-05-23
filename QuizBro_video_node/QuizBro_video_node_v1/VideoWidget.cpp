#include "VideoWidget.hpp"

VideoWidget::VideoWidget(QWidget *parent)
    : QWidget(parent)
    , m_display_surface(0)
{
    setAutoFillBackground(false);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_PaintOnScreen, true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::black);
    setPalette(palette);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    m_display_surface = new DisplaySurface(this);
}

VideoWidget::~VideoWidget()
{
    delete m_display_surface;
}

QSize VideoWidget::sizeHint() const 
{
    return m_display_surface->surfaceFormat().sizeHint();
}

void VideoWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (m_display_surface->isActive()) {
        const QRect videoRect = m_display_surface->videoRect();

        if (!videoRect.contains(event->rect())) {
            QRegion region = event->region();
            region.subtracted(videoRect);

            QBrush brush = palette().background();

            foreach (const QRect &rect, region.rects())
                painter.fillRect(rect, brush);
        }

        m_display_surface->paint(&painter);
    } else {
        painter.fillRect(event->rect(), palette().background());
    }
}

void VideoWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_display_surface->updateVideoRect();
}
