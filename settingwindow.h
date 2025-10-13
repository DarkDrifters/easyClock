#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include "datasettings.h"
#include <QMainWindow>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();
private slots:
    void on_saveButton_clicked();

    void on_selectFonts_clicked();

    void on_backButton_clicked();

    void on_colorFont_changed(const QColor &newColor);
signals:
    //Сигнал изминения настроек
    void changeSettings();

private:
    Ui::SettingWindow *ui;
    DataSettings *dSettings = nullptr;
};

#endif // SETTINGWINDOW_H
