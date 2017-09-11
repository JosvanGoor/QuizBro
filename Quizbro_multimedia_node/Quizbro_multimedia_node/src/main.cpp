#include <QApplication>

#include "Window.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.show();

    w.display_widget()->display_image(":/resources/logo_neg.png");

    return a.exec();
}
