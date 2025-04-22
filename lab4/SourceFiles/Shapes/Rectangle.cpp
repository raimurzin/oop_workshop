#include "Rectangle.h"

Rectangle::Rectangle(const QColor& fillColor, const QColor& penColor, const QPointF& ulCorner_, float width_, float height_)
    : Shape(fillColor, penColor), ulCorner(ulCorner_), width(width_), height(height_) {}

Shape* Rectangle::Clone() const {
    return new Rectangle(*this);
}

void Rectangle::Draw(QPainter& painter, bool selected) const {
    painter.setRenderHint(QPainter::Antialiasing); // Сглаживание
    painter.setPen(QPen((selected ? "red" : penColor), 2));
    painter.setBrush(fillColor);
    painter.drawRect(QRectF(ulCorner.x() - width / 2, ulCorner.y() - height / 2, width, height));
}

bool Rectangle::IsPointIn(QPointF pos) const {
    QPolygonF rect;
    rect << QPointF(ulCorner.x() - width / 2, ulCorner.y() - height / 2);
    rect << QPointF(ulCorner.x() - width / 2, ulCorner.y() + height / 2);
    rect << QPointF(ulCorner.x() + width / 2, ulCorner.y() + height / 2);
    rect << QPointF(ulCorner.x() + width / 2, ulCorner.y() - height / 2);
    return rect.containsPoint(pos, Qt::OddEvenFill);
}

bool Rectangle::IsOutOfBounds(const QRectF& widgetRect) const {
    if (!widgetRect.contains(QPointF(ulCorner.x() - width / 2, ulCorner.y() - height / 2))) return true;
    if (!widgetRect.contains(QPointF(ulCorner.x() - width / 2, ulCorner.y() + height / 2))) return true;
    if (!widgetRect.contains(QPointF(ulCorner.x() + width / 2, ulCorner.y() + height / 2))) return true;
    if (!widgetRect.contains(QPointF(ulCorner.x() + width / 2, ulCorner.y() - height / 2))) return true;
    return false;
}

void Rectangle::MoveLeft() {
    ulCorner.rx() -= 2.0f;
}

void Rectangle::MoveRight() {
    ulCorner.rx() += 2.0f;
}

void Rectangle::MoveUp() {
    ulCorner.ry() -= 2.0f;
}

void Rectangle::MoveDown() {
    ulCorner.ry() += 2.0f;
}

void Rectangle::MoveByOffset(const QPointF& offset) {
    ulCorner += offset;
}

void Rectangle::Enlarge() {
    width += width * 0.05f;
    height += height * 0.05f;
}

void Rectangle::Shrink() {
    width -= width * 0.05f;
    height -= height * 0.05f;
}
