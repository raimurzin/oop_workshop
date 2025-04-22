#ifndef DRAWAREA_H
#define DRAWAREA_H

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
#include <QList>
#include <QMessageBox>

#include "Storage.h"
#include "Shapes/Ellips.h"
#include "Shapes/Line.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Triangle.h"

class DrawArea : public QWidget {
    Q_OBJECT
public:
    DrawArea(QWidget* parent = nullptr);
    ~DrawArea() = default;

public slots:
    void ShapeTypeChanged(int index);
    void FillTypeChanged(int index);
    void BorderTypeChanged(int index);

public:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

public:
    const QMap<int, QString> shapeTypes = {
        {1, "Ellips"},
        {2, "Round"},
        {3, "Triangle"},
        {4, "Rectangle"},
        {5, "Square"},
        {6, "Line"}
    };
    const QMap<int, QString> colors = {
        {1, "green"},
        {2, "blue"},
        {3, "yellow"},
        {4, "red"},
        {5, "orange"},
        {6, "magenta"}
    };
    const QMap<int, QString> borderTypes = {
        {1, "black"},
        {2, "white"}
    };

private:
    ShapeStorage shapes;
    QList<QPointF> points; // Для отрисовки треугольников и линий
    int currentShapeType = 1;
    int currentShapeColor = 1;
    int currentBorderType = 1;
private:
    QPointF dragStartPos;
    QList<int> shapesToMove; // Для выделенных фигур для премещения (просто для скорости обращения к ним)
private:

};

#endif // DRAWAREA_H
