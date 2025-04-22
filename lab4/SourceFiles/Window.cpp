#include "Window.h"

Window::Window(QWidget* parent) : QWidget(parent) {
    controlPanel = new QWidget();
    drawArea = new DrawArea();

    shapeTypeCombo = new QComboBox();
    for (auto it = drawArea->shapeTypes.begin(); it != drawArea->shapeTypes.end(); ++it) {
        shapeTypeCombo->addItem(it.value(), it.key());
    }

    fillTypeCombo = new QComboBox();
    for (auto it = drawArea->colors.begin(); it != drawArea->colors.end(); ++it) {
        fillTypeCombo->addItem(it.value(), it.key());
    }

    borderTypeCombo = new QComboBox();
    for (auto it = drawArea->borderTypes.begin(); it != drawArea->borderTypes.end(); ++it) {
        borderTypeCombo->addItem(it.value(), it.key());
    }

    QFormLayout* panelLayout = new QFormLayout();
    panelLayout->addRow("Тип фигуры:", shapeTypeCombo);
    panelLayout->addRow("Закраска:", fillTypeCombo);
    panelLayout->addRow("Контур:", borderTypeCombo);
    controlPanel->setLayout(panelLayout);
    controlPanel->setFixedWidth(250);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(controlPanel);
    layout->addWidget(drawArea);
    setLayout(layout);

    this->setWindowIcon(QIcon("C:/Users/aimur/Desktop/lab4/images/fire.ico"));

    connect(shapeTypeCombo, SIGNAL(currentIndexChanged(int)), drawArea, SLOT(ShapeTypeChanged(int)));
    connect(fillTypeCombo, SIGNAL(currentIndexChanged(int)), drawArea, SLOT(FillTypeChanged(int)));
    connect(borderTypeCombo, SIGNAL(currentIndexChanged(int)), drawArea, SLOT(BorderTypeChanged(int)));
}
