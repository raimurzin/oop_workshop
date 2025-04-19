#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QChar>
#include <QDebug>
#include "View.h"
#include "Model.h"

class Controller : public QObject {
    Q_OBJECT
public:
    Controller() = delete;
    explicit Controller(View* window, Model* Model);
    ~Controller() = default;
private slots:
    void ChangedA() const;
    void ChangedB() const;
    void ChangedC() const;
private:
    Model* model;
};

#endif // CONTROLLER_H
