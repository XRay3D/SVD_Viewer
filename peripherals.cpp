#include "peripherals.h"

#include <QFile>
#include <QTextEdit>
#include <format>

namespace rng = std::ranges;

Peripherals::Peripherals() { }

void Peripherals::clear() { peripherals.clear(); }

Peripheral& Peripherals::current() { return peripherals.back(); }

void Peripherals::generate(QTextEdit* textEdit) const
{
    QByteArray str;
    str.reserve(1000000);
    str.append("#pragma once\n#include <stdint.h>\n");

#define APPEND(...) std::format_to(std::back_inserter(str), __VA_ARGS__);

    uint bitWidth {};
    auto addField = [&](Field& field) {
        if (int dummu = field.bitOffset.toUInt() - bitWidth; dummu) {
            str.append(QString("        unsigned : %1;// Reserved / Unused").arg(dummu)).append('\n');
            bitWidth += dummu;
        }
        APPEND("            unsigned {0}: {1}; // bitOffset {2}\n", field.name, field.bitWidth, field.bitOffset + " " + field.description);
        bitWidth += field.bitWidth.toUInt();
    };

    auto addRegisters = [&](Register& reg) {
        if (reg.fields.size() > 1 || (reg.fields.size() == 1 && reg.fields.back().bitWidth != "32")) {
            APPEND("    union alignas(4) {}_{{\n", reg.name);
            //APPEND("    union alignas(4) {}_{{\n        uint32_t register_;\n", reg.name);
            rng::sort(reg.fields, {}, [](auto& arg) { return arg.bitOffset.toUInt(); });
            bitWidth = {};
            if (reg.access == "read-only")
                str.append("        const struct{\n");
            else
                str.append("        struct{\n");
            rng::for_each(reg.fields, addField);
            str.append("        };\n");
            str.append("        uint32_t U32;\n");

            str.append("    };\n");
        } else {
            APPEND("    using {}_ = uint32_t;\n", reg.name);
        }
    };

    auto addPeripheral = [&](Peripheral& val) {
        APPEND("// description {}\n", val.description);
        APPEND("// groupName {}\n", val.groupName);
        APPEND("inline volatile struct {}_ {{\n", val.name);

        rng::sort(val.registers, {}, [](auto& arg) { return arg.addressOffset.mid(2).toUInt(nullptr, 16); });

        rng::for_each(val.registers, addRegisters);

        str.append('\n');
        int baseAddress {};
        rng::for_each(val.registers, [&](Register& reg) {
            //            APPEND("    {0}_ {0};//{1}\n", reg.name, reg.addressOffset);
            if (int dummu = reg.addressOffset.mid(2).toUInt(nullptr, 16) - baseAddress; dummu) {
                APPEND("    uint32_t padding{}[{}];\n", baseAddress, dummu / 4);
                baseAddress += dummu;
            }
            APPEND("    {0}_ {0};// {1}\n", reg.name, reg.description);
            baseAddress += 4;
        });

        APPEND("}}&_{0}=*({0}_*){1};\n", val.name, val.baseAddress);
        str.append('\n');
    };

    //    rng::for_each(peripherals, addPeripheral);
    for (auto&& val : peripherals) {
        if (val.name.startsWith("DMA")) {
            addPeripheral(val);
            //break;
        }
    }
    QFile file { R"(C:\Users\bakiev\Junk_Yard\PRO\ARM\NucleoL476_Nokia1616_LCD\Core\Src\_DMA.h)" };
    if (file.open(QFile::WriteOnly))
        file.write(str);
    textEdit->setText(str);
}
