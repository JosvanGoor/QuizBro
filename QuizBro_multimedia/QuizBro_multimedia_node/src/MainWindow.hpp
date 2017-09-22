#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QRect>
#include <QResizeEvent>
#include <QString>

#include "ImagePane.hpp"
#include "VideoPane.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void display_image(const QString &file);
        void display_video(const QString &file);

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;
    
    private:
        QWidget *m_central_pane;
        ImagePane *m_images;
        VideoPane *m_videos;
};

#endif // MAINWINDOW_HPP
