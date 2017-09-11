#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include <QWidget>
#include <QMainWindow>
#include "src/DisplayWidget.hpp"

namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();
    
public slots:
    void swap_image();

private:
    Ui::TestWindow *ui;
};

#endif // TESTWINDOW_HPP