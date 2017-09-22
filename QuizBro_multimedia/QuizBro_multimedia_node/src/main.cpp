#include "MainWindow.hpp"
#include "../TestWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TestWindow tw(nullptr, &w);
    tw.show();

    return a.exec();
}
