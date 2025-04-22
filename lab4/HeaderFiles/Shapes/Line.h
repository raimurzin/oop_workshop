#ifndef LINE_H
#define LINE_H

#include <QPointF>
#include <QRectF>
#include <QLineF>
#include "../Shape.h"

class Line : public Shape {
public:
    Line(const Line& other) = default;
    Line(const QColor& fillColor, const QColor& penColor, const QPointF& start_, const QPointF& end_);
    ~Line() = default;

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
    QPointF start;
    QPointF end;
};

#endif // LINE_H
