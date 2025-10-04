#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "infowindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
private slots:
    void on_ExitApp();
    void on_InfoOpen();
    void updateDidplayTime();//Обновление времени, выполняется таймером

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    InfoWindow *infoW = nullptr;
    QTimer *timer;
};
#endif // MAINWINDOW_H
