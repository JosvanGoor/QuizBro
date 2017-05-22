#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setObjectName(QStringLiteral("MainWindow"));
    this->resize(1378, 768);

    central_widget = new QWidget(this);
    central_widget->setObjectName(QStringLiteral("central_widget"));
}

MainWindow::~MainWindow()
{

}
