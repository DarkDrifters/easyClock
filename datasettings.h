#ifndef DATASETTINGS_H
#define DATASETTINGS_H

#include <QObject>
#include <QSettings>

class DataSettings {
private:
    QSettings *obj_Settings = nullptr;

public:
    explicit DataSettings(const QString &orgName, const QString &appName,
                          QObject *parent = nullptr);
    ~DataSettings();

    // Метод устоновки значений key -  имя параметра настройки
    void setValue(const QString &key, const QVariant &value);
    // Метод получения значений, строчка const QVariant &defaultValue = QVariant()
    // даст значение если парметр не найден
    QVariant getValue(const QString &key,
                      const QVariant &defaultValue = QVariant()) const;
};

#endif // DATASETTINGS_H
