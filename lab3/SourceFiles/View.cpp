#include "View.h"

View::View(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    label = new QLabel("A <= B <= C");
    QFont font = label->font();
    font.setBold(true); // Жирный шрифт
    font.setPointSize(54);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(font);
    layout->addWidget(label);

    QHBoxLayout* layoutA = new QHBoxLayout();
    inputLineA = new QLineEdit();
    inputLineB = new QLineEdit();
    inputLineC = new QLineEdit();
    layoutA->addWidget(inputLineA);
    layoutA->addWidget(inputLineB);
    layoutA->addWidget(inputLineC);

    QHBoxLayout* layoutB = new QHBoxLayout();
    spinBoxA = new QSpinBox();
    spinBoxB = new QSpinBox();
    spinBoxC = new QSpinBox();
    layoutB->addWidget(spinBoxA);
    layoutB->addWidget(spinBoxB);
    layoutB->addWidget(spinBoxC);

    QHBoxLayout* layoutC = new QHBoxLayout();
    sliderA = new QSlider(Qt::Horizontal);
    sliderA->setRange(0, 100);
    sliderB = new QSlider(Qt::Horizontal);
    sliderB->setRange(0, 100);
    sliderC = new QSlider(Qt::Horizontal);
    sliderC->setRange(0, 100);
    layoutC->addWidget(sliderA);
    layoutC->addWidget(sliderB);
    layoutC->addWidget(sliderC);

    layout->addLayout(layoutA);
    layout->addLayout(layoutB);
    layout->addLayout(layoutC);
    layout->addStretch();
    layout->setAlignment(Qt::AlignCenter);

    this->setWindowIcon(QIcon("C:/Users/aimur/Desktop/lab32/images/fire.ico"));
    this->setLayout(layout);
}

void View::SetCondition(uint a, uint b, uint c) {
    // Блокируем все сигналы
    QList<QWidget*> widgets = {
        inputLineA, spinBoxA, sliderA,
        inputLineB, spinBoxB, sliderB,
        inputLineC, spinBoxC, sliderC
    };

    for (auto* w : widgets) w->blockSignals(true);

    inputLineA->setText(QString::number(a));
    spinBoxA->setValue(a);
    sliderA->setValue(a);

    inputLineB->setText(QString::number(b));
    spinBoxB->setValue(b);
    sliderB->setValue(b);

    inputLineC->setText(QString::number(c));
    spinBoxC->setValue(c);
    sliderC->setValue(c);

    for (auto* w : widgets) w->blockSignals(false);
}

void View::GiveWarning(const QString& s) {
    QMessageBox::warning(this, "Предупреждение", s);
}

const QLineEdit* View::GetInputLine(const QChar& type) const {
    if (!type.isLetter()) return nullptr;
    const QChar upper = type.toUpper();
    if (upper == 'A') return inputLineA;
    if (upper == 'B') return inputLineB;
    if (upper == 'C') return inputLineC;
    return nullptr;
}

const QSpinBox* View::GetSpinBox(const QChar& type) const {
    if (!type.isLetter()) return nullptr;
    const QChar upper = type.toUpper();
    if (upper == 'A') return spinBoxA;
    if (upper == 'B') return spinBoxB;
    if (upper == 'C') return spinBoxC;
    return nullptr;
}

const QSlider* View::GetSlider(const QChar& type) const {
    if (!type.isLetter()) return nullptr;
    const QChar upper = type.toUpper();
    if (upper == 'A') return sliderA;
    if (upper == 'B') return sliderB;
    if (upper == 'C') return sliderC;
    return nullptr;
}
