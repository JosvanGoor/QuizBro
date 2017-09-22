#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "src/MainWindow.hpp"
#include "ui_testwindow.h"

class TestWindow : public QMainWindow
{
    Q_OBJECT

    public:
        TestWindow(QWidget *parent, MainWindow *mw);
        ~TestWindow();

    public slots:
        void img_button_pressed();
        void vid_button_pressed();

    private:
        Ui::TestWindow *ui;
        MainWindow *m_mainwindow;
};

#endif // TESTWINDOW_HPP
