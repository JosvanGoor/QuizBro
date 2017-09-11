#include "Window.hpp"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    m_display = new DisplayWidget();
    this->setCentralWidget(m_display);

    QRect window_rect(QPoint(), QSize(1376, 768));
    window_rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    this->setGeometry(window_rect);
}

Window::~Window()
{

}

DisplayWidget* Window::display_widget()
{
    return m_display;
}