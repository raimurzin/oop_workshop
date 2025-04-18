#include <QApplication>
#include <QWidget>
#include "TabWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TabWidget window;
    window.setWindowTitle("Лабораторная работа №1");
    window.resize(800, 600);
    window.show();
    return app.exec();
}
