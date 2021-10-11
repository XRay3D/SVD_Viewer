#pragma once

#include <QObject>
#include <set>
#include <unordered_map>

class QTextEdit;

struct Field {
    QByteArray name;
    QByteArray description;
    QByteArray bitOffset;
    QByteArray bitWidth;
};

struct Register {
    QByteArray name;
    QByteArray displayName;
    QByteArray description;
    QByteArray addressOffset;
    QByteArray size;
    QByteArray access;
    QByteArray resetValue;
    std::vector<Field> fields;
};

struct Peripheral {
    QByteArray name;
    QByteArray description;
    QByteArray groupName;
    QByteArray baseAddress;
    std::vector<Register> registers;
};

struct Peripherals {
    mutable std::vector<Peripheral> peripherals;
    Peripherals();
    void clear();
    Peripheral& current();
    void generate(QTextEdit* textEdit) const;
    operator bool() const { return peripherals.size(); }
};
