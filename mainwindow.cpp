#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>

// Коеструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Привязка
    connect(ui->actExit, &QAction::triggered, this, &MainWindow::on_ExitApp);
    connect(ui->actInfo, &QAction::triggered, this, &MainWindow::on_InfoOpen);
    connect(ui->actSetting, &QAction::triggered, this, &MainWindow::on_SettingOpen);
    // Настройка и запуск таймера обновления
    timer = new QTimer(this);
    timer->start(1000); // В милисекундах
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDidplayTime); // Привязка слота к событию
}
// Деконструктор
MainWindow::~MainWindow() {
    delete ui;
    delete settingW;
    delete infoW;
}
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
// Открытие настроек
void MainWindow::on_SettingOpen() {
    if (!settingW || !settingW->isVisible()) {
        settingW = new SettingWindow(this);
        settingW->show();
    }
}
