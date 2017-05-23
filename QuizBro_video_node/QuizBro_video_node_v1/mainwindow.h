#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DisplayWidget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void fullscreen();
    void exit_fullscreen();

protected:
    DisplayWidget *m_display;
};

#endif // MAINWINDOW_H
