#include "Model.h"

Model::Model(View* window) : window(window), a(0), b(0), c(0) {}

QVariant Model::CheckValue(const QString& value) const {
    bool conversionOk;
    int intValue = value.toInt(&conversionOk);

    if (!conversionOk) {
        window->GiveWarning(QString("Не удается распознать число"));
        return QVariant();
    }
    if (intValue < 0 || intValue > 100) {
        window->GiveWarning(QString("Число должно принадлежать диапазону от 0 до 100"));
        return QVariant();
    }
    return QVariant(intValue);
}

void Model::SetValueA(const QString& value) {
    qDebug() << "A";
    QMutexLocker locker(&mutex);
    QVariant v = this->CheckValue(value);
    if (!v.isValid()) return;
    uint val = v.toInt();
    c = qMax(val, c);
    b = qMax(val, b);
    a = val;
    window->SetCondition(a, b, c);
}

void Model::SetValueB(const QString& value) {
    qDebug() << "B";
    QMutexLocker locker(&mutex);
    QVariant v = this->CheckValue(value);
    if (!v.isValid()) return;
    uint val = v.toInt();
    if (val <= c && val >= a) b = val;
    window->SetCondition(a, b, c);
}

void Model::SetValueC(const QString& value) {
    qDebug() << "C";
    QMutexLocker locker(&mutex);
    QVariant v = this->CheckValue(value);
    if (!v.isValid()) return;
    uint val = v.toInt();
    c = val;
    b = qMin(val, b);
    a = qMin(val, a);
    window->SetCondition(a, b, c);
}
