#ifndef ELLIPS_H
#define ELLIPS_H

#include <QPointF>
#include "../Shape.h"

class Ellips : public Shape {
public:
    Ellips(const Ellips& other) = default;
    Ellips(const QColor& fillColor, const QColor& penColor, const QPointF& center_, float b_, float c_);
    ~Ellips() = default;

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
    QPointF center;
    float b, c;
};

#endif // ELLIPS_H
