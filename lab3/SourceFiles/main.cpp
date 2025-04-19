#include <QApplication>
#include "View.h"
#include "Controller.h"
#include "Model.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    View w;
    Model m(&w);
    Controller c(&w, &m);
    w.setWindowTitle("Лабораторная работа №3");
    w.resize(600, 300);
    w.show();
    return a.exec();
}
