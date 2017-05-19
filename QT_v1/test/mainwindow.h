#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/*
    Personally defined slots, to receive actions from buttons etc.
*/
private slots:
    void on_blinkspeed_slider_changed(int val);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
