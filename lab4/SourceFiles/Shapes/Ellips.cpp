#include "Ellips.h"

Ellips::Ellips(const QColor& fillColor, const QColor& penColor, const QPointF& center_, float b_, float c_)
    : Shape(fillColor, penColor), center(center_), b(b_), c(c_) {}

Shape* Ellips::Clone() const {
    return new Ellips(*this);
}

void Ellips::Draw(QPainter& painter, bool selected) const {
    painter.setRenderHint(QPainter::Antialiasing); // Сглаживание
    painter.setPen(QPen((selected ? "red" : penColor), 2));
    painter.setBrush(fillColor);
    painter.drawEllipse(center, b, c);
}

bool Ellips::IsPointIn(QPointF pos) const {
    float dx = pos.x() - center.x();
    float dy = pos.y() - center.y();
    return ((dx * dx) / (b * b) + (dy * dy) / (c * c) <= 1.0f);
}

bool Ellips::IsOutOfBounds(const QRectF& widgetRect) const {
    if (!widgetRect.contains(QPointF(center.x() - b, center.y()))) return true;
    if (!widgetRect.contains(QPointF(center.x() + b, center.y()))) return true;
    if (!widgetRect.contains(QPointF(center.x(), center.y() - c))) return true;
    if (!widgetRect.contains(QPointF(center.x(), center.y() + c))) return true;
    return false;
}

void Ellips::MoveLeft() {
    center.rx() -= 2.0f;
}

void Ellips::MoveRight() {
    center.rx() += 2.0f;
}

void Ellips::MoveUp() {
    center.ry() -= 2.0f;
}

void Ellips::MoveDown() {
    center.ry() += 2.0f;
}

void Ellips::MoveByOffset(const QPointF& offset) {
    center += offset;
}

void Ellips::Enlarge() {
    b += b * 0.05f;
    c += c * 0.05f;
}

void Ellips::Shrink() {
    b -= b * 0.05f;
    c -= c * 0.05f;
}
