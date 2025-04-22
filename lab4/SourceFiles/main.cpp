#include "Window.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Window w;
    w.setWindowTitle("Лабораторная работа №4");
    w.resize(1200, 700);
    w.show();
    return a.exec();
}
