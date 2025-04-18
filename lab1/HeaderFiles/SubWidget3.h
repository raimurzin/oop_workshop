#ifndef SUBWIDGET3_H
#define SUBWIDGET3_H

#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <QEvent>
#include <QPalette>
#include <QMessageBox>
#include <QDebug>
#include <QTabWidget>

class SubWidget3 : public QWidget {
    Q_OBJECT
public:
    SubWidget3(QWidget *parent = nullptr);
    ~SubWidget3();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    QFrame* Area1;
    QFrame* Area2;
    QFrame* Area3;
};

#endif // SUBWIDGET3_H
