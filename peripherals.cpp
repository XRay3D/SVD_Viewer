#include "peripherals.h"

#include <QPlainTextEdit>

Peripherals::Peripherals()
{
}

void Peripherals::add(QString name)
{
    if (set.count(name))
        return;
    set.insert(name);
    data.resize(data.size() + 1);
    data.back().name = name;
    //    peripherals_[name]
    //    lastName = peripherals_[name]->name = name;
}

void Peripherals::clear()
{
    //    data.reserve(1000);
    data.clear();
    //    lastName.clear();
    //    peripherals_.clear();
}

Peripheral& Peripherals::current()
{
    return data.back();
    //    return *peripherals_[lastName];
}

void Peripherals::generate(QPlainTextEdit* plainTextEdit) const
{
    for (auto&& val : data) {
        plainTextEdit->appendPlainText("//    description " + val.description);
        plainTextEdit->appendPlainText("inline struct " + val.name + "_ {");
        plainTextEdit->appendPlainText("//    groupName " + val.groupName);
        plainTextEdit->appendPlainText(QString("}&%1=*(%1_*)%2;").arg(val.name).arg(val.baseAddress));
        plainTextEdit->appendPlainText("");
        plainTextEdit->appendPlainText("");
    }
}
