#include "mainwindow.h"

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaContent>

#include "DisplayWidget.hpp"

#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_display = new DisplayWidget;
    this->setCentralWidget(m_display);

    m_display->display_video("file:///home/jos/Downloads/izombie.mkv");
    m_display->display_image("//home/jos/Downloads/samples/bunny.jpg");
}

MainWindow::~MainWindow()
{

}
