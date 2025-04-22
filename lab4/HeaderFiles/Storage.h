#ifndef STORAGE_H
#define STORAGE_H

#include <QList>
#include <QMap>
#include <QPointF>
#include "Shape.h"

class ShapeStorage {
public:
    ShapeStorage() = default;
    ShapeStorage(const ShapeStorage& ss);
    ShapeStorage& operator=(const ShapeStorage& p);
    ~ShapeStorage();

public:
    void AddFigure(Shape* figure);
    Shape* GetFigure(std::size_t ind);
    void RemoveAt(std::size_t ind);

public:
    bool CheckSelected(std::size_t ind) const;
    void SetSelected(std::size_t ind, bool condition);
    void SetAllUnselected();
    int GetSelectedCount() const;

public:
    std::size_t GetCount() const;
    static void swap(ShapeStorage& first, ShapeStorage& second) noexcept;

private:
    QList<Shape*> figures;
    QList<bool> selected;
};

#endif // STORAGE_H
