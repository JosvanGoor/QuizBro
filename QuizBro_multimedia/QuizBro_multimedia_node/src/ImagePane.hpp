#ifndef IMAGEPANE_HPP
#define IMAGEPANE_HPP

#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QSize>
#include <QString>
#include <QWidget>

/*
    Image pane contains 2 labels that can display and crossfade images.
*/

#define FADE_TIME_MS 3500

class ImagePane : public QWidget
{
    Q_OBJECT

    public:
        ImagePane(QWidget *parent = nullptr);
        ~ImagePane();

    public slots:
        void display_image(const QString &fle);
        void hide_inactive_image();

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;

    private:
        QString m_latest_file;

        QLabel *m_image_primary;
        QLabel *m_image_secondary;

};

#endif