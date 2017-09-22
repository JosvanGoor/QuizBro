#include <QApplication>

#include "Window.hpp"
#include "../testwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.show();

    TestWindow tw(w.display_widget());
    tw.show();

    return a.exec();
}
