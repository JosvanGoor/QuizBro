#include "mainwindow.h"

#include <QDir>
#include <QWindow>
#include <QApplication>
#include <QMediaContent>
#include <QDesktopWidget>

#include "DisplayWidget.hpp"

#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_display = new DisplayWidget;
    this->setCentralWidget(m_display);

    QRect window_rect(QPoint(), QSize(1376, 768));
    window_rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    this->setGeometry(window_rect);

    m_flags = this->windowHandle()->flags();

    m_display->display_video("file:///home/jos/Downloads/samples/small.mp4");
    //m_display->display_image("//home/jos/Downloads/samples/bunny.jpg");

    m_display->enable_slideshow(10000, QDir().absolutePath() + "/filelist.txt");
}

void MainWindow::fullscreen()
{
    this->windowHandle()->setFlags(Qt::FramelessWindowHint);
    this->windowHandle()->showFullScreen();
}

void MainWindow::exit_fullscreen()
{
    this->windowHandle()->setFlags(m_flags);
    QRect window_rect(QPoint(), QSize(1376, 768));
    window_rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    this->setGeometry(window_rect);
}

MainWindow::~MainWindow()
{

}
