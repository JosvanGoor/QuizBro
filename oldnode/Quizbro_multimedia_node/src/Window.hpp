#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>

#include "DisplayWidget.hpp"

class Window : public QMainWindow
{
    Q_OBJECT

    public:
        Window(QWidget *parent = nullptr);
        ~Window();

        DisplayWidget* display_widget();

    protected:
        DisplayWidget *m_display;
    
};

#endif