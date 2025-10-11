#include "settingwindow.h"
#include "ui_settingwindow.h"

#include <QFontDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

SettingWindow::SettingWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SettingWindow) {
    ui->setupUi(this);
}

SettingWindow::~SettingWindow() { delete ui; }

// Сохранение настроек, реализовано через автоматическую привязку
void SettingWindow::on_saveButton_clicked() { this->close(); }
// Выбор шрифта
void SettingWindow::on_selectFonts_clicked() {
    QFont initFont = ui->exempleText->font();
    QFontDialog fontDialog(initFont, this);
    fontDialog.resize(600,300);
    if(fontDialog.exec() == QDialog::Accepted){
        QFont font = fontDialog.selectedFont();
        ui->textFont->setText(font.family());
        ui->exempleText->setFont(font);
    }
}
// Отмена изминений
void SettingWindow::on_backButton_clicked() { this->close(); }
// Изминение цвета
void SettingWindow::on_kcolorbutton_changed(const QColor &newColor) {
    QPalette pallete = ui->exempleText->palette();
    pallete.setColor(QPalette::WindowText, newColor);
    ui->exempleText->setPalette(pallete);
}
