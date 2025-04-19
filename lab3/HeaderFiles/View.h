#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QChar>
#include <QFont>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class View : public QWidget {
    Q_OBJECT
public:
    View(QWidget* parent = nullptr);
    ~View() = default;
public:
    void SetCondition(uint a, uint b, uint c);
    void GiveWarning(const QString& s);
public:
    const QLineEdit* GetInputLine(const QChar& type) const;
    const QSpinBox* GetSpinBox(const QChar& type) const;
    const QSlider* GetSlider(const QChar& type) const;
private:
    QLabel* label;

    QLineEdit* inputLineA;
    QSpinBox* spinBoxA;
    QSlider* sliderA;

    QLineEdit* inputLineB;
    QSpinBox* spinBoxB;
    QSlider* sliderB;

    QLineEdit* inputLineC;
    QSpinBox* spinBoxC;
    QSlider* sliderC;
};

#endif // VIEW_H
