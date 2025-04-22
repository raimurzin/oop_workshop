#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPointF>
#include "../Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(const Rectangle& other) = default;
    Rectangle(const QColor& fillColor, const QColor& penColor, const QPointF& ulCorner_, float width_, float height_);
    ~Rectangle() = default;

public:
    virtual Shape* Clone() const override;
    virtual void Draw(QPainter& painter, bool selected = false) const override;
    virtual bool IsPointIn(QPointF pos) const override;
    virtual bool IsOutOfBounds(const QRectF& widgetRect) const override;

public:
    virtual void MoveLeft() override;
    virtual void MoveRight() override;
    virtual void MoveUp() override;
    virtual void MoveDown() override;
    virtual void MoveByOffset(const QPointF& offset) override;
    virtual void Enlarge() override;
    virtual void Shrink() override;

protected:
    QPointF ulCorner;
    float width, height;
};

#endif // RECTANGLE_H
