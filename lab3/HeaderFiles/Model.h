#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
#include <QMutex>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "View.h"

class Model {
public:
    explicit Model(View* window);
    ~Model() = default;
public:
    void SetValueA(const QString& value);
    void SetValueB(const QString& value);
    void SetValueC(const QString& value);
private:
    QVariant CheckValue(const QString& value) const;
private:
    uint a, b, c;
    QMutex mutex;
    View* window;
};

#endif // MODEL_H
