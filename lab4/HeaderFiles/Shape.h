#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QColor>
#include <QPointF>
#include <QRectF>

class Shape {
public:
    Shape(const QColor& fillColor_, const QColor& penColor_) : fillColor(fillColor_), penColor(penColor_) {}
    virtual ~Shape() = default;

public:
    virtual Shape* Clone() const = 0;
    virtual void Draw(QPainter& painter, bool selected = false) const = 0;
    virtual bool IsPointIn(QPointF pos) const = 0;
    virtual bool IsOutOfBounds(const QRectF& widgetRect) const = 0;

public:
    void SetFillColor(const QColor& fillColor_) { fillColor = fillColor_; }
    void SetPenColor(const QColor& penColor_) { penColor = penColor_; }

public:
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual void MoveByOffset(const QPointF& offset) = 0;
    virtual void Enlarge() = 0;
    virtual void Shrink() = 0;

protected:
    QColor fillColor;
    QColor penColor;
};

#endif // SHAPE_H
