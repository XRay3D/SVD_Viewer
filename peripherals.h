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
struct Interrupt {
    QByteArray name;
    QByteArray description;
    QByteArray value;
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
    Peripheral* peripheral {};
    QByteArray name;
    QByteArray description;
    QByteArray groupName;
    QByteArray baseAddress;
    std::vector<Register> registers;
    std::vector<Interrupt> interrupts;
};

struct Peripherals {
    mutable std::vector<Peripheral> peripherals;
    mutable std::map<QString, Peripheral*> peripheralsMap;
    mutable std::map<QString, std::vector<Peripheral*>> groupMap;
    Peripherals();
    void clear();
    Peripheral& current();
    void generate(QTextEdit* textEdit) const;
    operator bool() const { return peripherals.size(); }

private:
    void generateDma(QByteArray& str, Peripheral& peripheral, QTextEdit* textEdit) const;
};
