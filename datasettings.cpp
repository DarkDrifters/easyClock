#include "datasettings.h"

// Конструктор
DataSettings::DataSettings(const QString &orgName, const QString &appName,
                           QObject *parent) {
    obj_Settings = new QSettings(orgName, appName, parent);
}
// Деконструктор
DataSettings::~DataSettings() { delete obj_Settings; }
// Установка значения
void DataSettings::setValue(const QString &key, const QVariant &value) {
    obj_Settings->setValue(key, value);
}
// Получение значения
QVariant DataSettings::getValue(const QString &key,
                                const QVariant &defaultValue) const {
    return obj_Settings->value(key, defaultValue);
}
