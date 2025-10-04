#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Привязка
    connect(ui->actExit, &QAction::triggered, this, &MainWindow::on_ExitApp);
    connect(ui->actInfo, &QAction::triggered, this, &MainWindow::on_InfoOpen);
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
