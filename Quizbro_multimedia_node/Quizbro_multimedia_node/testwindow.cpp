#include "testwindow.hpp"
#include "ui_testwindow.h"

TestWindow::TestWindow(DisplayWidget *display, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    m_display = display;
    ui->setupUi(this);

    //connect buttons
    connect(ui->btn_logo, SIGNAL(pressed()), this, SLOT(swap_image()));
    connect(ui->btn_logo_neg, SIGNAL(pressed()), this, SLOT(swap_image()));
    connect(ui->btn_test1, SIGNAL(pressed()), this, SLOT(swap_image()));
    connect(ui->btn_test2, SIGNAL(pressed()), this, SLOT(swap_image()));
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::swap_image()
{
    QObject *sender = QObject::sender();

    if(sender->objectName() == QString("btn_logo"))
    {
        m_display->display_image(":/resources/logo.png");
    }
    else if(sender->objectName() == QString("btn_logo_neg"))
    {
        m_display->display_image(":/resources/logo_neg.png");
    }
    else if(sender->objectName() == QString("btn_test1"))
    {
        m_display->display_image(":/resources/test1.jpg");
    }
    else if(sender->objectName() == QString("btn_test2"))
    {
        m_display->display_image(":/resources/test2.png");
    }
}