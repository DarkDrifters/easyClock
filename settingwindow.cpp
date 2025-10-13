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
    // создание объекта настроек
    dSettings = new DataSettings("DarkDrifters", "easyClock", this);
    // Получение настроек из сохранения
    ui->colorFont->setColor(dSettings->getValue("ColorFont").value<QColor>());
    ui->exempleText->setFont(dSettings->getValue("FontClock").value<QFont>());
    ui->textFont->setText(ui->exempleText->font().family());
    // Установка цвета для примера шрифта
    QPalette pallete = ui->exempleText->palette();
    pallete.setColor(QPalette::WindowText, ui->colorFont->color());
    ui->exempleText->setPalette(pallete);
}

SettingWindow::~SettingWindow() { delete ui; }

// Сохранение настроек, реализовано через автоматическую привязку
void SettingWindow::on_saveButton_clicked() {
    dSettings->setValue("ColorFont", ui->colorFont->color());
    dSettings->setValue("FontClock", ui->exempleText->font());
    emit changeSettings();//Подача сигнала
    this->close();
}
// Выбор шрифта через диалоговое окно
void SettingWindow::on_selectFonts_clicked() {
    QFont initFont = ui->exempleText->font();
    QFontDialog fontDialog(initFont, this);
    fontDialog.resize(600, 300);
    if (fontDialog.exec() == QDialog::Accepted) {
        QFont font = fontDialog.selectedFont();
        ui->textFont->setText(font.family());
        ui->exempleText->setFont(font);
    }
}
// Отмена изминений
void SettingWindow::on_backButton_clicked() { this->close(); }
// Изминение цвета
void SettingWindow::on_colorFont_changed(const QColor &newColor) {
    QPalette pallete = ui->exempleText->palette();
    pallete.setColor(QPalette::WindowText, newColor);
    ui->exempleText->setPalette(pallete);
}
