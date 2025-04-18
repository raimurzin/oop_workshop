#include "SubWidget3.h"

SubWidget3::SubWidget3(QWidget *parent) : QWidget(parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);

    auto createArea = [&](const QString &color) -> QFrame* {
        QFrame* area = new QFrame(this);
        area->setFixedSize(100, 100);
        area->setStyleSheet(QString("background-color: %1;").arg(color));
        area->setAttribute(Qt::WA_Hover);
        area->installEventFilter(this);
        return area;
    };

    Area1 = createArea("#FF5733");
    Area2 = createArea("#33FF57");
    Area3 = createArea("#3357FF");

    layout->addWidget(Area1);
    layout->addWidget(Area2);
    layout->addWidget(Area3);

    this->setMouseTracking(true);
    this->setLayout(layout);
    this->setWindowIcon(QIcon("C:/Users/aimur/Desktop/lab/images/fire.png"));
}

SubWidget3::~SubWidget3() {}

bool SubWidget3::eventFilter(QObject* obj, QEvent* event) {
    QFrame* frame = qobject_cast<QFrame*>(obj);
    if (!frame) return false;

    if (event->type() == QEvent::HoverEnter) {
        QString color = frame->palette().color(QPalette::Window).name();
        frame->setProperty("originalColor", color);
        frame->setStyleSheet("background-color: #bd33ff;");
        return true;
    }
    else if (event->type() == QEvent::HoverLeave) {
        QString originalColor = frame->property("originalColor").toString();
        frame->setStyleSheet(QString("background-color: %1;").arg(originalColor));
        return true;
    }
    return QWidget::eventFilter(obj, event);
}
