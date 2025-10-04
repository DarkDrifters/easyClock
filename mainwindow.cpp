#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Привязка
    connect(ui->actExit, &QAction::triggered, this, &MainWindow::on_ExitApp);
    connect(ui->actInfo, &QAction::triggered, this, &MainWindow::on_InfoOpen);
    // Настройка и запуск таймера обновления
    timer = new QTimer(this);
    timer->start(1000); // В милисекундах
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDidplayTime); //Привязка слота к событию

}

MainWindow::~MainWindow() { delete ui; }
// Выход из программы
void MainWindow::on_ExitApp() { QApplication::exit(); }
// Открытия окно о программе
void MainWindow::on_InfoOpen() {
    if (!infoW || !infoW->isVisible()) {
        infoW = new InfoWindow(this);
        infoW->show();
    }
}
// Утоновка времени в окно
void MainWindow::updateDidplayTime() {
    QString str = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->textClock->setText(str);
}
