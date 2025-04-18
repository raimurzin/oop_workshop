#ifndef SUBWIDGET4_H
#define SUBWIDGET4_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QEvent>
#include <QPalette>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>

class SubWidget4 : public QWidget {
    Q_OBJECT
public:
    SubWidget4(QWidget *parent = nullptr);
    ~SubWidget4();
private slots:
    void changeButtonColor();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // SUBWIDGET4_H
