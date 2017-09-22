#include "TestWindow.hpp"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent, MainWindow *mw) :
    QMainWindow(parent),
    ui(new Ui::TestWindow),
    m_mainwindow(mw)
{
    ui->setupUi(this);

    //connect img buttons
    connect(ui->btn_img_img1, SIGNAL(pressed()), this, SLOT(img_button_pressed()));
    connect(ui->btn_img_img2, SIGNAL(pressed()), this, SLOT(img_button_pressed()));
    connect(ui->btn_img_logo, SIGNAL(pressed()), this, SLOT(img_button_pressed()));
    connect(ui->btn_img_logo_neg, SIGNAL(pressed()), this, SLOT(img_button_pressed()));

    connect(ui->btn_vid_extra, SIGNAL(pressed()), this, SLOT(vid_button_pressed()));
    connect(ui->btn_vid_long, SIGNAL(pressed()), this, SLOT(vid_button_pressed()));
    connect(ui->btn_vid_medium, SIGNAL(pressed()), this, SLOT(vid_button_pressed()));
    connect(ui->btn_vid_short, SIGNAL(pressed()), this, SLOT(vid_button_pressed()));
}

void TestWindow::img_button_pressed()
{
    QObject *sender = QObject::sender();

    if(sender->objectName() == QString("btn_img_img1"))
    {
        m_mainwindow->display_image(":/resources/test1.jpg");
    }
    else if(sender->objectName() == QString("btn_img_img2"))
    {
        m_mainwindow->display_image(":/resources/test2.png");
    }
    else if(sender->objectName() == QString("btn_img_logo"))
    {
        m_mainwindow->display_image(":/resources/logo.png");
    }
    else if(sender->objectName() == QString("btn_img_logo_neg"))
    {
        m_mainwindow->display_image(":/resources/logo_neg.png");
    }
}

void TestWindow::vid_button_pressed()
{
    QObject *sender = QObject::sender();

    if(sender->objectName() == QString("btn_vid_extra"))
    {
        //niks
    }
    else if(sender->objectName() == QString("btn_vid_long"))
    {
        m_mainwindow->display_video("file:///home/jos/vid_ex/long.mp4");
    }
    else if(sender->objectName() == QString("file://btn_vid_medium"))
    {
        m_mainwindow->display_video("file:///home/jos/vid_ex/medium.mp4");
    }
    else if(sender->objectName() == QString("btn_vid_short"))
    {
        m_mainwindow->display_video("file:///home/jos/vid_ex/short.mp4");
    }
}

TestWindow::~TestWindow()
{
    delete ui;
}
