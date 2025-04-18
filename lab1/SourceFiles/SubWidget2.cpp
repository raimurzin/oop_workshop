#include "SubWidget2.h"
#include <QMessageBox>

SubWidget2::SubWidget2(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Выберите факультет:"));
    QuestionCombo = new QComboBox(this);
    QuestionCombo->addItem("-- Выберите факультет --");
    QuestionCombo->addItem("ФИРТ");
    QuestionCombo->addItem("ИНЭК");
    layout->addWidget(QuestionCombo);

    QVBoxLayout* question1 = new QVBoxLayout();
    QuestionGroup1 = new QGroupBox("Какие языки программирования вы знаете?", this);
    QStringList languages = {"C++", "Python", "Java"};
    for (const auto& l : languages) {
        QCheckBox* newCheckBox = new QCheckBox(l);
        checkBoxes.append(newCheckBox);
        question1->addWidget(newCheckBox);
    }
    QuestionGroup1->setLayout(question1);
    layout->addWidget(QuestionGroup1);

    QVBoxLayout* question2 = new QVBoxLayout();
    QuestionGroup2 = new QGroupBox("Какой курс вы сейчас проходите?", this);
    QStringList courses = {"Первый курс", "Второй курс", "Третий курс"};
    for (const auto& c : courses) {
        QRadioButton* newRadioButton = new QRadioButton(c);
        radioButtons.append(newRadioButton);
        question2->addWidget(newRadioButton);
    }
    QuestionGroup2->setLayout(question2);
    layout->addWidget(QuestionGroup2);

    QuestionText = new QLineEdit();
    layout->addWidget(new QLabel("Введите ваш ответ:"));
    layout->addWidget(QuestionText);

    submitAnswer = new QPushButton("Отправить результаты", this);
    connect(submitAnswer, SIGNAL(clicked()), this, SLOT(SubmitClick()));
    layout->addWidget(submitAnswer);

    layout->addStretch();
    this->setLayout(layout);
}

SubWidget2::~SubWidget2() {}

void SubWidget2::SubmitClick() {
    QMessageBox::information(this, "Информция", "Данные отправлены на проверку");
    QuestionCombo->setCurrentIndex(0);
    for (auto& checkbox : checkBoxes) {
        checkbox->setChecked(false);
    }
    radioButtons.first()->setChecked(true);
    QuestionText->clear();
}
