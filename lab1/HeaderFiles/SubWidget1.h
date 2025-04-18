#ifndef SUBWIDGET1_H
#define SUBWIDGET1_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMovie>
#include <QMessageBox>

class SubWidget1 : public QWidget {
    Q_OBJECT
public:
    SubWidget1(QWidget* parent = nullptr);
    ~SubWidget1();

private slots:
    void stopTimer();
    void startTimer();
    void updateTimer();
    void resetTimer();

private:
    bool is_active;
    long double time_left;
    QTimer* Timer;
private:
    QLabel* LabelSetTime;
    QLabel* LabelTimeLeft;
    QLineEdit *LineEditTime;
private:
    QMovie* gifAnimation;
    QLabel* gifLabel;
private:
    QPushButton* stopButton;
    QPushButton* startButton;
    QPushButton* resetButton;
private:
    QVBoxLayout* elements;
    QHBoxLayout* row1;
    QHBoxLayout* row2;
    QHBoxLayout* row3;
};

#endif // SUBWIDGET1_H
