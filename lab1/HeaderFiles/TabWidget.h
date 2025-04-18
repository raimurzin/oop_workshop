#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QApplication>
#include <QTabWidget>

#include "SubWidget1.h"
#include "SubWidget2.h"
#include "SubWidget3.h"
#include "SubWidget4.h"

class TabWidget : public QTabWidget {
    Q_OBJECT
public:
    TabWidget(QTabWidget* parent = nullptr);
    ~TabWidget();
private:
    SubWidget1* sub1;
    SubWidget2* sub2;
    SubWidget3* sub3;
    SubWidget4* sub4;
};

#endif // TABWIDGET_H
