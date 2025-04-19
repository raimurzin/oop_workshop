#include "Controller.h"

Controller::Controller(View* window, Model* model) : model(model) {
    connect(window->GetInputLine('A'), SIGNAL(textChanged(const QString&)), this, SLOT(ChangedA()));
    connect(window->GetInputLine('B'), SIGNAL(textChanged(const QString&)), this, SLOT(ChangedB()));
    connect(window->GetInputLine('C'), SIGNAL(textChanged(const QString&)), this, SLOT(ChangedC()));

    connect(window->GetSpinBox('A'), SIGNAL(valueChanged(int)), this, SLOT(ChangedA()));
    connect(window->GetSpinBox('B'), SIGNAL(valueChanged(int)), this, SLOT(ChangedB()));
    connect(window->GetSpinBox('C'), SIGNAL(valueChanged(int)), this, SLOT(ChangedC()));

    connect(window->GetSlider('A'), SIGNAL(valueChanged(int)), this, SLOT(ChangedA()));
    connect(window->GetSlider('B'), SIGNAL(valueChanged(int)), this, SLOT(ChangedB()));
    connect(window->GetSlider('C'), SIGNAL(valueChanged(int)), this, SLOT(ChangedC()));
}

void Controller::ChangedA() const {
    QObject* obj = sender();
    if (QLineEdit* edit = qobject_cast<QLineEdit*>(obj)) {
        model->SetValueA(edit->text());
    } else if (QSpinBox* spinBox = qobject_cast<QSpinBox*>(obj)) {
        model->SetValueA(QString::number(spinBox->value()));
    } else if (QSlider* slider = qobject_cast<QSlider*>(obj)) {
        model->SetValueA(QString::number(slider->value()));
    }
}
void Controller::ChangedB() const {
    QObject* obj = sender();
    if (QLineEdit* edit = qobject_cast<QLineEdit*>(obj)) {
        model->SetValueB(edit->text());
    } else if (QSpinBox* spinBox = qobject_cast<QSpinBox*>(obj)) {
        model->SetValueB(QString::number(spinBox->value()));
    } else if (QSlider* slider = qobject_cast<QSlider*>(obj)) {
        model->SetValueB(QString::number(slider->value()));
    }
}
void Controller::ChangedC() const {
    QObject* obj = sender();
    if (QLineEdit* edit = qobject_cast<QLineEdit*>(obj)) {
        model->SetValueC(edit->text());
    } else if (QSpinBox* spinBox = qobject_cast<QSpinBox*>(obj)) {
        model->SetValueC(QString::number(spinBox->value()));
    } else if (QSlider* slider = qobject_cast<QSlider*>(obj)) {
        model->SetValueC(QString::number(slider->value()));
    }
}
