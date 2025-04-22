#include "Triangle.h"

Triangle::Triangle(const QColor& fillColor, const QColor& penColor, const QPointF& vertex1_, const QPointF& vertex2_, const QPointF& vertex3_)
    : Shape(fillColor, penColor), vertex1(vertex1_), vertex2(vertex2_), vertex3(vertex3_) {}

Shape* Triangle::Clone() const {
    return new Triangle(*this);
}

void Triangle::Draw(QPainter& painter, bool selected) const {
    painter.setRenderHint(QPainter::Antialiasing); // Включение сглаживания
    painter.setPen(QPen((selected ? "red" : penColor), 2));
    painter.setBrush(fillColor);
    QPolygonF triangle; triangle << vertex1 << vertex2 << vertex3;
    painter.drawPolygon(triangle);
}

bool Triangle::IsPointIn(QPointF pos) const {
    QPolygonF triangle;
    triangle << vertex1 << vertex2 << vertex3;
    return triangle.containsPoint(pos, Qt::OddEvenFill);
}

bool Triangle::IsOutOfBounds(const QRectF& widgetRect) const {
    if (!widgetRect.contains(vertex1.toPoint())) return true;
    if (!widgetRect.contains(vertex2.toPoint())) return true;
    if (!widgetRect.contains(vertex3.toPoint())) return true;
    return false;
}

void Triangle::MoveLeft() {
    vertex1.rx() -= 2.0f;
    vertex2.rx() -= 2.0f;
    vertex3.rx() -= 2.0f;
}

void Triangle::MoveRight() {
    vertex1.rx() += 2.0f;
    vertex2.rx() += 2.0f;
    vertex3.rx() += 2.0f;
}

void Triangle::MoveUp() {
    vertex1.ry() -= 2.0f;
    vertex2.ry() -= 2.0f;
    vertex3.ry() -= 2.0f;
}

void Triangle::MoveDown() {
    vertex1.ry() += 2.0f;
    vertex2.ry() += 2.0f;
    vertex3.ry() += 2.0f;
}

void Triangle::MoveByOffset(const QPointF& offset) {
    vertex1 += offset;
    vertex2 += offset;
    vertex3 += offset;
}

void Triangle::Enlarge() {
    QPointF center = (vertex1 + vertex2 + vertex3) / 3.0f;  // Центр масс треугольника
    vertex1 = center + (vertex1 - center) * 1.1f;
    vertex2 = center + (vertex2 - center) * 1.1f;
    vertex3 = center + (vertex3 - center) * 1.1f;
}

void Triangle::Shrink() {
    QPointF center = (vertex1 + vertex2 + vertex3) / 3.0f;  // Центр масс треугольника
    vertex1 = center + (vertex1 - center) * 0.9f;
    vertex2 = center + (vertex2 - center) * 0.9f;
    vertex3 = center + (vertex3 - center) * 0.9f;
}
