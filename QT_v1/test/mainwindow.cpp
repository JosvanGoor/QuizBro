#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*  
        Link signals and slots.
    */
    QObject::connect(ui->sld_blinkspeed, SIGNAL(valueChanged(int)), this, SLOT(on_blinkspeed_slider_changed(int)));
}

/*
    Personally defined slots.
*/
void MainWindow::on_blinkspeed_slider_changed(int val)
{
    std::cout << "slider changed: " << val << std::endl;
    ui->lbl_blinkspeed->setText(QString((std::to_string(val) + "ms.").c_str()bakker
    ));
}
/*
    End of handwritten code.
*/

MainWindow::~MainWindow()
{
    delete ui;
}
