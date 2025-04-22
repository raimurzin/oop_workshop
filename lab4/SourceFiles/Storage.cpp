#include "Storage.h"

ShapeStorage::ShapeStorage(const ShapeStorage& ss) : selected(ss.GetCount(), 0) {
    figures.reserve(ss.GetCount());
    for (const auto& figure : ss.figures) {
        figures.append(figure->Clone());
    }
}

ShapeStorage& ShapeStorage::operator=(const ShapeStorage& other) {
    if (this != &other) {
        ShapeStorage tmp(other);
        swap(*this, tmp);
    }
    return *this;
}

ShapeStorage::~ShapeStorage() {
    for (const auto& el : figures) delete el;
}

void ShapeStorage::AddFigure(Shape* figure) {
    if (figure == nullptr) return;
    figures.append(figure);
    selected.append(false);
}

Shape* ShapeStorage::GetFigure(std::size_t ind) {
    if (this->GetCount() <= ind) throw std::out_of_range("Index out of range");
    return figures[ind];
}

void ShapeStorage::RemoveAt(std::size_t ind) {
    if (this->GetCount() <= ind) throw std::out_of_range("Index out of range");
    figures.removeAt(ind);
    selected.removeAt(ind);
}

bool ShapeStorage::CheckSelected(std::size_t ind) const {
    if (this->GetCount() <= ind) throw std::out_of_range("Index out of range");
    return selected[ind];
}

void ShapeStorage::SetSelected(std::size_t ind, bool condition) {
    if (this->GetCount() <= ind) throw std::out_of_range("Index out of range");
    selected[ind] = condition;
}

void ShapeStorage::SetAllUnselected() {
    for (auto& condition : selected) {
        condition = false;
    }
}

int ShapeStorage::GetSelectedCount() const {
    int result = 0;
    for (const auto& condition : selected) {
        if (condition == true) result++;
    }
    return result;
}

std::size_t ShapeStorage::GetCount() const {
    return figures.size();
}

void ShapeStorage::swap(ShapeStorage& first, ShapeStorage& second) noexcept {
    std::swap(first.figures, second.figures);
}
