#ifndef DISPLAYWIDGET_HPP
#define DISPLAYWIDGET_HPP

#include <QLabel>
#include <QString>
#include <QWidget>
#include <QResizeEvent>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

enum DisplayMode
{
    IMAGE,
    VIDEO
};

class DisplayWidget : public QWidget
{
    Q_OBJECT

    public:
        DisplayWidget(QWidget *parent = nullptr);
        ~DisplayWidget();

    public slots:
        void display_image(const QString &file);
    
    private slots:
        void hide_inactive_layers();

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;

    private:
        QSize m_window_size;
        QLabel *m_image_primary;
        QLabel *m_image_secondary;
        DisplayMode m_display_mode;
};

#endif