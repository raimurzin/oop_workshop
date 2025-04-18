#include "TabWidget.h"

TabWidget::TabWidget(QTabWidget* parent) : QTabWidget(parent) {
    sub1 = new SubWidget1(this);
    sub2 = new SubWidget2(this);
    sub3 = new SubWidget3(this);
    sub4 = new SubWidget4(this);

    this->addTab(sub1, "Пример 1");
    this->addTab(sub2, "Пример 2");
    this->addTab(sub3, "Пример 3");
    this->addTab(sub4, "Пример 4");

    this->setWindowIcon(QIcon("C:/Users/aimur/Desktop/lab/images/fire.png"));
}

TabWidget::~TabWidget() {}
