#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

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

    void on_kcolorbutton_changed(const QColor &newColor);

private:
    Ui::SettingWindow *ui;
};

#endif // SETTINGWINDOW_H
