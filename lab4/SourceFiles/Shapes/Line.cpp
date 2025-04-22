#include "Line.h"

Line::Line(const QColor& fillColor, const QColor& penColor, const QPointF& start_, const QPointF& end_)
    : Shape(fillColor, penColor), start(start_), end(end_) {}

Shape* Line::Clone() const {
    return new Line(*this);
}

void Line::Draw(QPainter& painter, bool selected) const {
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen = QPen((selected ? "red" : penColor), 2);
    pen.setCapStyle(Qt::RoundCap); // Закругленные концы линии
    painter.setPen(pen);
    painter.drawLine(start, end);
}

bool Line::IsPointIn(QPointF pos) const {
    const float tolerance = 0.03f;
    QRectF lineRect(start, end);
    QRectF thickLine = lineRect.normalized().adjusted(-tolerance, -tolerance, tolerance, tolerance);
    return thickLine.contains(pos);
}

bool Line::IsOutOfBounds(const QRectF& widgetRect) const {
    if (!widgetRect.contains(start.toPoint())) return true;
    if (!widgetRect.contains(end.toPoint())) return true;
    return false;
}

void Line::MoveLeft() {
    start.rx() -= 2.0f;
    end.rx() -= 2.0f;
}

void Line::MoveRight() {
    start.rx() += 2.0f;
    end.rx() += 2.0f;
}

void Line::MoveUp() {
    start.ry() -= 2.0f;
    end.ry() -= 2.0f;
}

void Line::MoveDown() {
    start.ry() += 2.0f;
    end.ry() += 2.0f;
}

void Line::MoveByOffset(const QPointF& offset) {
    start += offset;
    end += offset;
}

void Line::Enlarge() {
    QPointF center = (start + end) / 2.0f;
    start = center + (start - center) * 1.1f;
    end = center + (end - center) * 1.1f;
}

void Line::Shrink() {
    QPointF center = (start + end) / 2.0f;
    start = center + (start - center) * 0.9f;
    end = center + (end - center) * 0.9f;
}
