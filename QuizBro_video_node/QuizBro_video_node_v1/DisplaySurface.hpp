#ifndef QUIZBRO_DISPLAYSURFACE_HPP
#define QUIZBRO_DISPLAYSURFACE_HPP

#include <QAbstractVideoSurface>

class DisplaySurface : QAbstractVideoSurface
{
    Q_OBJECT
    
public:
    DisplaySurface(QWidget *widget, QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const; )
    bool isFormatSupported(const QVideoSurfaceFormat &format, QVideoSurfaceFormat *similar) const;

    bool start(const QVideoSurfaceFormat &format);
    void stop();

    bool present(const QVideoFrame &frame);
    
    QRect video_rect const { return targetRect; } 
    void update_video_rect();

    void paint(QPainter *painter);

private:
    QWidget *m_widget;
    QImage::Format m_image_format;
    QRect m_target_rect;
    QSize m_image_size;
    QRect m_source_rect;
    QVideoFrame m_current_frame;
};

#endif