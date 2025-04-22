#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMap>

#include "Storage.h"
#include "Shapes/Ellips.h"
#include "Shapes/Line.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Triangle.h"
#include "DrawArea.h"

class Window : public QWidget {
    Q_OBJECT
public:
    Window(QWidget* parent = nullptr);
    ~Window() = default;
private:
    ShapeStorage shapes;
    DrawArea* drawArea;
    QWidget* controlPanel;
    QComboBox* shapeTypeCombo;
    QComboBox* fillTypeCombo;
    QComboBox* borderTypeCombo;
};

#endif // WINDOW_H
