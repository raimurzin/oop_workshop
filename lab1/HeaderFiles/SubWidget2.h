#ifndef SUBWIDGET2_H
#define SUBWIDGET2_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class SubWidget2 : public QWidget {
    Q_OBJECT

public:
    SubWidget2(QWidget *parent = nullptr);
    ~SubWidget2();

private slots:
    void SubmitClick();

private:
    QComboBox* QuestionCombo;
    QGroupBox* QuestionGroup1;
    QGroupBox* QuestionGroup2;
    QLineEdit* QuestionText;
    QPushButton* submitAnswer;

private:
    QList<QCheckBox*> checkBoxes;
    QList<QRadioButton*> radioButtons;
};

#endif // SUBWIDGET2_H
