#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPointF>
#include "../Shape.h"

class Triangle : public Shape {
public:
    Triangle(const Triangle& other) = default;
    Triangle(const QColor& fillColor, const QColor& penColor,
             const QPointF& vertex1_, const QPointF& vertex2_, const QPointF& vertex3_);

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
    QPointF vertex1, vertex2, vertex3;
};

#endif // TRIANGLE_H
