#pragma once

#include <QObject>
#include <set>
#include <unordered_map>

class QPlainTextEdit;

struct Peripheral {
    QString name;
    QString description;
    QString groupName;
    QString baseAddress;
};

class Peripherals {
    std::vector<Peripheral> data;
    std::set<QString> set;
    //    std::/*unordered_*/ map<QString, Peripheral*> peripherals_;
    QString lastName;

public:
    Peripherals();
    void add(QString name);
    void clear();
    Peripheral& current();
    void generate(QPlainTextEdit* plainTextEdit) const;
    operator bool() const { return data.size(); }
};
