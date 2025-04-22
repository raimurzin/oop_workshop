#include "DrawArea.h"

DrawArea::DrawArea(QWidget* parent) : QWidget(parent) {
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
    this->setAutoFillBackground(true);
    setFocusPolicy(Qt::StrongFocus); // Виджет сможет получать фокус ввода как через клик мышью, так и через клавиатуру
}

void DrawArea::ShapeTypeChanged(int index) {
    currentShapeType = index + 1;
    points.clear();
    shapesToMove.clear();
    shapes.SetAllUnselected();
}

void DrawArea::FillTypeChanged(int index) {
    currentShapeColor = index + 1;
    for (std::size_t i = 0; i < shapes.GetCount(); ++i) {
        if (shapes.CheckSelected(i))
            shapes.GetFigure(i)->SetFillColor(colors[currentShapeColor]);
    }
    this->repaint();
}

void DrawArea::BorderTypeChanged(int index) {
    currentBorderType = index + 1;
    for (std::size_t i = 0; i < shapes.GetCount(); ++i) {
        if (shapes.CheckSelected(i))
            shapes.GetFigure(i)->SetPenColor(borderTypes[currentBorderType]);
    }
    this->repaint();
}

void DrawArea::paintEvent(QPaintEvent* event) {
    qDebug() << "paintEvent";
    QPainter painter = QPainter(this);
    for (std::size_t i = 0; i < shapes.GetCount(); ++i) {
        if (shapes.GetFigure(i)->IsOutOfBounds(this->rect())) {
            QMessageBox::warning(this, "Ошибка", "Геометрические фигуры не должны быть сокрыты");
            return;
        }
    }
    for (std::size_t i = 0; i < shapes.GetCount(); ++i) {
        shapes.GetFigure(i)->Draw(painter, shapes.CheckSelected(i));
    }
}

void DrawArea::mousePressEvent(QMouseEvent* event) {
    qDebug() << "mousePressEvent";

    if (event->button() == Qt::RightButton) {
        if (currentShapeType == 1) { // Эллипс
            shapes.AddFigure(new Ellips(colors[currentShapeColor], borderTypes[currentBorderType], QPointF(event->pos()), 60, 30));
        }
        else if (currentShapeType == 2) { // Круг
            shapes.AddFigure(new Ellips(colors[currentShapeColor], borderTypes[currentBorderType], QPointF(event->pos()), 60, 60));
        }
        else if (currentShapeType == 3) { // Треугольник
            points.append(event->pos());
            if (points.length() == 3) {
                shapes.AddFigure(new Triangle(colors[currentShapeColor], borderTypes[currentBorderType], points[0], points[1], points[2]));
                points.clear();
            }
        }
        else if (currentShapeType == 4) { // Прямоугольник
            shapes.AddFigure(new Rectangle(colors[currentShapeColor], borderTypes[currentBorderType], QPointF(event->pos()), 100, 60));
        }
        else if (currentShapeType == 5) { // Квадрат
            shapes.AddFigure(new Rectangle(colors[currentShapeColor], borderTypes[currentBorderType], QPointF(event->pos()), 60, 60));
        }
        else if (currentShapeType == 6) { // Отрезок
            points.append(event->pos());
            if (points.length() == 2) {
                shapes.AddFigure(new Line(colors[currentShapeColor], borderTypes[currentBorderType], points[0], points[1]));
                points.clear();
            }
        } else return;
        shapes.SetAllUnselected();
        shapes.SetSelected(shapes.GetCount() - 1, true);
        if (shapes.GetFigure(shapes.GetCount() - 1)->IsOutOfBounds(this->rect()) == true) {
            shapes.RemoveAt(shapes.GetCount() - 1);
        }
        this->repaint();
        return;
    }

    if (event->button() == Qt::LeftButton) {
        if (event->modifiers() & Qt::CTRL) { // множественный выбор
            for (size_t i = 0; i < shapes.GetCount(); ++i) {
                auto currFigure = shapes.GetFigure(i);
                if (currFigure->IsPointIn(event->pos()) || shapes.CheckSelected(i)) {
                    shapes.SetSelected(i, true);
                } else {
                    shapes.SetSelected(i, false);
                }
            }
        }
        else { // выбор одной фигуры
            bool clickedOnShape = false;
            shapes.SetAllUnselected();
            for (size_t i = 0; i < shapes.GetCount(); ++i) {
                if (shapes.GetFigure(i)->IsPointIn(event->pos())) {
                    shapes.SetSelected(i, true);
                    clickedOnShape = true;
                    dragStartPos = event->pos();
                    //break;
                }
            }
            if (!clickedOnShape) shapes.SetAllUnselected(); // Выбора фигуры не произошло

            shapesToMove.clear();
            for (size_t i = 0; i < shapes.GetCount(); ++i) {
                if (shapes.CheckSelected(i)) shapesToMove.append(i);
            }
        }

        this->repaint();

        return;
    }
}

void DrawArea::keyPressEvent(QKeyEvent* event) {
    qDebug() << "keyPressEvent";

    auto checkMoving = [&](std::function<bool(Shape*)> condition) -> bool {
        for (size_t i = 0; i < shapes.GetCount(); ++i) {
            if (shapes.CheckSelected(i)) {
                if (!condition(shapes.GetFigure(i))) return false;
            }
        }
        return true;
    };

    auto updateSelected = [&](std::function<void(Shape*)> action) {
        for (size_t i = 0; i < shapes.GetCount(); ++i) {
            if (shapes.CheckSelected(i)) {
                action(shapes.GetFigure(i));
            }
        }
    };

    bool can_move = true;
    switch (event->key()) {
    case Qt::Key_Plus:
        can_move = checkMoving([&](Shape* shape) {
                auto shapeCopy = shape->Clone();
                shapeCopy->Enlarge();
                return (shapeCopy->IsOutOfBounds(this->rect()));
            });
        if (can_move == false) return;
        updateSelected([](Shape* shape) { shape->Enlarge(); });
        break;

    case Qt::Key_Minus:
        updateSelected([](Shape* shape) { shape->Shrink(); });
        break;

    case Qt::Key_Up:
        can_move = checkMoving([&](Shape* shape) {
            auto shapeCopy = shape->Clone();
            shapeCopy->MoveUp();
            return (shapeCopy->IsOutOfBounds(this->rect()));
        });
        if (can_move == false) return;
        updateSelected([](Shape* shape) { shape->MoveUp(); });
        break;

    case Qt::Key_Down:
        can_move = checkMoving([&](Shape* shape) {
            auto shapeCopy = shape->Clone();
            shapeCopy->MoveDown();
            return (shapeCopy->IsOutOfBounds(this->rect()));
        });
        if (can_move == false) return;
        updateSelected([](Shape* shape) { shape->MoveDown(); });
        break;

    case Qt::Key_Left:
        can_move = checkMoving([&](Shape* shape) {
            auto shapeCopy = shape->Clone();
            shapeCopy->MoveLeft();
            return (shapeCopy->IsOutOfBounds(this->rect()));
        });
        if (can_move == false) return;
        updateSelected([](Shape* shape) { shape->MoveLeft(); });
        break;

    case Qt::Key_Right:
        can_move = checkMoving([&](Shape* shape) {
            auto shapeCopy = shape->Clone();
            shapeCopy->MoveRight();
            return (shapeCopy->IsOutOfBounds(this->rect()));
        });
        if (can_move == false) return;
        updateSelected([](Shape* shape) { shape->MoveRight(); });
        break;

    case Qt::Key_Delete:
        ShapeStorage newFigures;
        for (size_t i = 0; i < shapes.GetCount(); ++i) {
            if (!(shapes.CheckSelected(i))) {
                newFigures.AddFigure(shapes.GetFigure(i)->Clone());
            }
        }
        shapes = newFigures;
        shapes.SetAllUnselected();
        break;
    }
    this->repaint();
}

void DrawArea::mouseMoveEvent(QMouseEvent* event) {
    qDebug() << "mouseMoveEvent";
    if (event->buttons() & Qt::LeftButton) {
        QPointF offset = event->pos() - dragStartPos;
        dragStartPos = event->pos();

        // Проверка выхода за границу
        for (const auto& ind : shapesToMove) {
            Shape* shape = shapes.GetFigure(ind);
            if (auto ellips = dynamic_cast<Ellips*>(shape)) {
                auto el_copy = ellips->Clone();
                el_copy->MoveByOffset(offset);
                if (el_copy->IsOutOfBounds(this->rect()) == true) return;
            }
            else if (auto line = dynamic_cast<Line*>(shape)) {
                auto line_copy = line->Clone();
                line_copy->MoveByOffset(offset);
                if (line_copy->IsOutOfBounds(this->rect()) == true) return;
            }
            else if (auto triangle = dynamic_cast<Triangle*>(shape)) {
                auto tr_copy = triangle->Clone();
                tr_copy->MoveByOffset(offset);
                if (tr_copy->IsOutOfBounds(this->rect()) == true) return;
            }
            else if (auto rectangle = dynamic_cast<Rectangle*>(shape)) {
                auto rec_copy = rectangle->Clone();
                rec_copy->MoveByOffset(offset);
                if (rec_copy->IsOutOfBounds(this->rect()) == true) return;
            }
        }

        // Изменение координат (если не вышли за границу)
        for (const auto& ind : shapesToMove) {
            Shape* shape = shapes.GetFigure(ind);
            if (auto ellips = dynamic_cast<Ellips*>(shape)) {
                ellips->MoveByOffset(offset);
            }
            else if (auto line = dynamic_cast<Line*>(shape)) {
                line->MoveByOffset(offset);
            }
            else if (auto triangle = dynamic_cast<Triangle*>(shape)) {
                triangle->MoveByOffset(offset);
            }
            else if (auto rectangle = dynamic_cast<Rectangle*>(shape)) {
                rectangle->MoveByOffset(offset);
            }
        }
        this->repaint();
    }
}

void DrawArea::mouseReleaseEvent(QMouseEvent* event) {
    qDebug() << "mouseReleaseEvent";
    if (event->button() == Qt::LeftButton) {
        shapesToMove.clear();
    }
}
