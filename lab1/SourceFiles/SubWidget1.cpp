#include "SubWidget1.h"

SubWidget1::SubWidget1(QWidget* parent) : QWidget(parent) {
    LabelSetTime = new QLabel("Установить таймер ");
    LabelTimeLeft = new QLabel("Осталось секунд: ");
    LineEditTime = new QLineEdit();

    gifAnimation = new QMovie("C:/Users/aimur/Desktop/lab/images/animation.gif");
    gifLabel = new QLabel();

    gifLabel->setMovie(gifAnimation);
    gifLabel->setAlignment(Qt::AlignCenter);
    gifLabel->setFixedSize(400, 400);
    gifAnimation->start();

    QHBoxLayout* gifRow = new QHBoxLayout();
    gifRow->addWidget(gifLabel);

    startButton = new QPushButton("Запуск");
    stopButton = new QPushButton("Остановка");
    resetButton = new QPushButton("Сбросить");

    row1 = new QHBoxLayout();
    row1->addWidget(LabelSetTime);
    row1->addWidget(LineEditTime);

    row2 = new QHBoxLayout();
    row2->addWidget(startButton);
    row2->addWidget(stopButton);
    row2->addWidget(resetButton);

    row3 = new QHBoxLayout();
    row3->addWidget(LabelTimeLeft);

    elements = new QVBoxLayout();
    elements->addLayout(gifRow);
    elements->addLayout(row1);
    elements->addLayout(row2);
    elements->addLayout(row3);
    elements->setAlignment(Qt::AlignCenter);

    connect(startButton, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetTimer()));

    setLayout(elements);
    this->setWindowIcon(QIcon("C:/Users/aimur/Desktop/lab/images/fire.png"));

    time_left = 0;
    is_active = false;
    Timer = new QTimer();
    Timer->setInterval(100); // Устанавливаю интервал в 100мс
    connect(Timer, SIGNAL(timeout()), SLOT(updateTimer()));
}

SubWidget1::~SubWidget1() {}

void SubWidget1::startTimer() {
    if (Timer->isActive()) {
        QMessageBox::information(this, "Замечание", "Таймер уже запущен");
        return;
    }

    int seconds = LineEditTime->text().toInt();
    if (seconds <= 0) {
        QMessageBox::warning(this, "Ошибка", "Неправильно введенное количество секунд");
        return;
    }
    time_left = (is_active ? time_left : seconds); // Устанавливаю оставшееся время
    Timer->start();
    updateTimer();
}
void SubWidget1::stopTimer() {
    if (Timer->isActive()) {
        Timer->stop();
        is_active = true;
        QMessageBox::information(this, "Таймер", "Выполнено");
    } else {
        QMessageBox::warning(this, "Ошибка", "Таймер не запущен");
    }
}
void SubWidget1::updateTimer() {
    time_left -= 0.1;
    qDebug() << QTime::currentTime().toString("hh:mm:ss");
    LabelTimeLeft->setText("Осталось секунд: " + QString::fromStdString(std::to_string(time_left)));
    if (time_left <= 0) {
        Timer->stop();
        is_active = false;
        QMessageBox::information(this, "Таймер", "Выключи чайник!");
    }
}
void SubWidget1::resetTimer() {
    time_left = 0;
    is_active = false;
    Timer->stop();
    LabelTimeLeft->setText("Осталось секунд: ");
}
