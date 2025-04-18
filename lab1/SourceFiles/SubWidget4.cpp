#include "SubWidget4.h"

SubWidget4::SubWidget4(QWidget *parent) {
    installEventFilter(this);
}

SubWidget4::~SubWidget4() {}

bool SubWidget4::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Delete) {
            qDebug() << "Клавиша Delete нажата";
        }
    } else if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QPushButton* button = new QPushButton("Покрасить", this);
            button->setGeometry(mouseEvent->pos().x(), mouseEvent->pos().y(), 80, 40);
            connect(button, SIGNAL(clicked()), this, SLOT(changeButtonColor()));
            button->show();
        }
    } else if (event->type() == QEvent::Paint) {
        QPaintEvent* paintEvent = dynamic_cast<QPaintEvent*>(event);
        qDebug() << "Обработка PaintEvent";
    }
    return true;
}

void SubWidget4::changeButtonColor() {
    if (QPushButton *button = qobject_cast<QPushButton*>(sender())) {
        button->setStyleSheet("background-color: #bd33ff;");
    }
}
