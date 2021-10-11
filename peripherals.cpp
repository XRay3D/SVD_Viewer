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

#define STR_APPEND(...) std::format_to(std::back_inserter(str), __VA_ARGS__)

    QByteArray str;
    str.reserve(1000000);
    str.append("#pragma once\n"
               "#include <stdint.h>\n"
               "#include <stm32l476xx.h>\n");

    str.append(R"(
#define MASK_TO_BIT31(A)    (A==0x80000000)? 31 : 0
#define MASK_TO_BIT30(A)    (A==0x40000000)? 30 : MASK_TO_BIT31(A)
#define MASK_TO_BIT29(A)    (A==0x20000000)? 29 : MASK_TO_BIT30(A)
#define MASK_TO_BIT28(A)    (A==0x10000000)? 28 : MASK_TO_BIT29(A)
#define MASK_TO_BIT27(A)    (A==0x08000000)? 27 : MASK_TO_BIT28(A)
#define MASK_TO_BIT26(A)    (A==0x04000000)? 26 : MASK_TO_BIT27(A)
#define MASK_TO_BIT25(A)    (A==0x02000000)? 25 : MASK_TO_BIT26(A)
#define MASK_TO_BIT24(A)    (A==0x01000000)? 24 : MASK_TO_BIT25(A)
#define MASK_TO_BIT23(A)    (A==0x00800000)? 23 : MASK_TO_BIT24(A)
#define MASK_TO_BIT22(A)    (A==0x00400000)? 22 : MASK_TO_BIT23(A)
#define MASK_TO_BIT21(A)    (A==0x00200000)? 21 : MASK_TO_BIT22(A)
#define MASK_TO_BIT20(A)    (A==0x00100000)? 20 : MASK_TO_BIT21(A)
#define MASK_TO_BIT19(A)    (A==0x00080000)? 19 : MASK_TO_BIT20(A)
#define MASK_TO_BIT18(A)    (A==0x00040000)? 18 : MASK_TO_BIT19(A)
#define MASK_TO_BIT17(A)    (A==0x00020000)? 17 : MASK_TO_BIT18(A)
#define MASK_TO_BIT16(A)    (A==0x00010000)? 16 : MASK_TO_BIT17(A)
#define MASK_TO_BIT15(A)    (A==0x00008000)? 15 : MASK_TO_BIT16(A)
#define MASK_TO_BIT14(A)    (A==0x00004000)? 14 : MASK_TO_BIT15(A)
#define MASK_TO_BIT13(A)    (A==0x00002000)? 13 : MASK_TO_BIT14(A)
#define MASK_TO_BIT12(A)    (A==0x00001000)? 12 : MASK_TO_BIT13(A)
#define MASK_TO_BIT11(A)    (A==0x00000800)? 11 : MASK_TO_BIT12(A)
#define MASK_TO_BIT10(A)    (A==0x00000400)? 10 : MASK_TO_BIT11(A)
#define MASK_TO_BIT09(A)    (A==0x00000200)? 9  : MASK_TO_BIT10(A)
#define MASK_TO_BIT08(A)    (A==0x00000100)? 8  : MASK_TO_BIT09(A)
#define MASK_TO_BIT07(A)    (A==0x00000080)? 7  : MASK_TO_BIT08(A)
#define MASK_TO_BIT06(A)    (A==0x00000040)? 6  : MASK_TO_BIT07(A)
#define MASK_TO_BIT05(A)    (A==0x00000020)? 5  : MASK_TO_BIT06(A)
#define MASK_TO_BIT04(A)    (A==0x00000010)? 4  : MASK_TO_BIT05(A)
#define MASK_TO_BIT03(A)    (A==0x00000008)? 3  : MASK_TO_BIT04(A)
#define MASK_TO_BIT02(A)    (A==0x00000004)? 2  : MASK_TO_BIT03(A)
#define MASK_TO_BIT01(A)    (A==0x00000002)? 1  : MASK_TO_BIT02(A)
#define MASK_TO_BIT00(A)    (A==0x00000001)? 0  : MASK_TO_BIT01(A)

#define BIT_BAND_PER(REG,BIT_MASK) (*(volatile uint32_t*)(PERIPH_BB_BASE+32*((uint32_t)(&(REG))-PERIPH_BASE)+4*((uint32_t)(MASK_TO_BIT00(BIT_MASK)))))
#define BIT_BAND_SRAM(RAM,BIT) (*(volatile uint32_t*)(SRAM_BB_BASE+32*((uint32_t)((void*)(RAM))-SRAM_BASE)+4*((uint32_t)(BIT))))

//Example: BIT_BAND_PER(TIM1->SR, TIM_SR_UIF) = 0; //сбросить бит TIM_SR_UIF в TIM1->SR
//Example2: BIT_BAND_SRAM(&a, 13) = 1; //установить 13-й бит в переменной "a"
//Example3: BIT_BAND_SRAM(&a, 13) ^= 1; //инвертировать 13-й бит в "a", не задевая другие биты переменной (псевдо-атомарность)
)");
    /*
"    class alignas(4) NAME_ {"
"        union {"
"            struct {"
"                unsigned FIELD : 1;"
"            };"
"            uint32_t U32;"
"        } U;"
"    public:"
"        auto FIELD() const { return U.FIELD; }"
"    };"
*/

    class alignas(4) NAME_ {
        union {
            struct {
                unsigned FIELD : 1;
            };
            uint32_t U32;
        } U;

    public:
        /** @brief  Disable SPI peripheral */
        void FIELD() { U.U32 = 1; }
    };

    union alignas(4) NAME__ {
        struct {
            unsigned FIELD : 1;
        };
        uint32_t U32;
    };

    uint bitWidth {};

    enum {
        ReadOnly = 1,
        WriteOnly,
        ReadWrite,
    };
    int access { ReadWrite };

    auto addField = [&](Field& field) {
        if (int dummu = field.bitOffset.toUInt() - bitWidth; dummu) {
            str.append(QString("\t\tunsigned : %1;// Reserved / Unused").arg(dummu)).append('\n');
            bitWidth += dummu;
        }
        STR_APPEND("\t\t\tunsigned {0}: {1}; // bitOffset {2}\n", field.name, field.bitWidth, field.bitOffset + " " + field.description);
        bitWidth += field.bitWidth.toUInt();
    };

    auto addFieldRead = [&](Field& field) {
        STR_APPEND("        /** @brief {} */\n", field.description);
        STR_APPEND("        auto {0}() const {{ return U.{0}; }}\n", field.name);
    };

    auto addFieldWrite = [&](Field& field) {
        STR_APPEND("        /** @brief {} */\n", field.description);
        if (field.bitWidth == "1")
            STR_APPEND("        void {0}() volatile {{ U.{0} = 1; }}\n", field.name);
    };
    auto addFieldWriteSetRes = [&](Field& field) {
        STR_APPEND("        /** @brief {} */\n", field.description);
        if (field.bitWidth == "1") {
            STR_APPEND("        auto {0}() const {{ return U.{0}; }}\n", field.name);
            STR_APPEND("        void {0}_Set() volatile {{ BIT_BAND_PER(U.U32, 1 << {1}) = 1; }}\n", field.name, field.bitOffset);
            STR_APPEND("        void {0}_Res() volatile {{ BIT_BAND_PER(U.U32, 1 << {1}) = 0; }}\n", field.name, field.bitOffset);
        } else {
        }
    };

    auto addRegisters = [&](Register& reg) {
        if (reg.access == "read-only")
            access = ReadOnly;
        else if (reg.access == "write-only")
            access = WriteOnly;
        else
            access = ReadWrite;

        rng::sort(reg.fields, {}, [](auto& arg) { return arg.bitOffset.toUInt(); });

        if (reg.fields.size() > 1 || (reg.fields.size() == 1 && reg.fields.back().bitWidth != "32")) {
            switch (access) {
            case ReadOnly:
            case WriteOnly:
                STR_APPEND("    class alignas(4) {0}_ {{ // {1}\n", reg.name, reg.description);
                str.append("        union {\n");
                str.append("            struct {\n");
                bitWidth = {};
                break;
            case ReadWrite:
                //                STR_APPEND("\tunion alignas(4) {}_{{\n", reg.name);
                //                //APPEND("\tunion alignas(4) {}_{{\n        uint32_t register_;\n", reg.name);
                //                bitWidth = {};
                //                str.append("\t\tstruct{\n");
                STR_APPEND("    class alignas(4) {0}_ {{ // {1}\n", reg.name, reg.description);
                str.append("        union {\n");
                str.append("            struct {\n");
                bitWidth = {};
                break;
            }

            rng::for_each(reg.fields, addField);

            //            if (access != ReadWrite) {
            str.append("            };\n");
            str.append("            uint32_t U32;\n");
            str.append("        } U;\n");
            str.append("    public:\n");
            //            }

            switch (access) {
            case ReadOnly:
                str.append("        auto U32() const { return U.U32; }\n");
                rng::for_each(reg.fields, addFieldRead);
                break;
            case WriteOnly:
                rng::for_each(reg.fields, addFieldWrite);
                break;
            case ReadWrite:
                str.append("        auto U32() const { return U.U32; }\n");
                rng::for_each(reg.fields, addFieldWriteSetRes);
                //                str.append("        };\n");
                //                str.append("        uint32_t U32;\n");
                break;
            }
            str.append("    };\n");
        } else {
            STR_APPEND("\t/** @brief {} */\n", reg.description);
            STR_APPEND("\tusing {}_ = uint32_t;\n", reg.name);
        }
    };

    auto addPeripheral = [&](Peripheral& val) {
        STR_APPEND("// description {}\n", val.description);
        STR_APPEND("// groupName {}\n", val.groupName);
        STR_APPEND("inline volatile struct {}_ {{\n", val.name);

        rng::sort(val.registers, {}, [](auto& arg) { return arg.addressOffset.mid(2).toUInt(nullptr, 16); });

        rng::for_each(val.registers, addRegisters);

        str.append('\n');
        int baseAddress {};
        rng::for_each(val.registers, [&](Register& reg) {
            //        APPEND("\t{0}_ {0};//{1}\n", reg.name, reg.addressOffset);
            if (int dummu = reg.addressOffset.mid(2).toUInt(nullptr, 16) - baseAddress; dummu) {
                STR_APPEND("\tuint32_t padding{}[{}];\n", baseAddress, dummu / 4);
                baseAddress += dummu;
            }
            STR_APPEND("\t{0}_ {0};// {1}\n", reg.name, reg.description);
            baseAddress += 4;
        });

        STR_APPEND("}}&_{0}=*  reinterpret_cast<{0}_*>({1});\n", val.name, val.baseAddress);
        str.append('\n');
    };

    //    rng::for_each(peripherals, addPeripheral);
    for (auto&& val : peripherals) {
        if (val.name.startsWith("DMA")) {
            addPeripheral(val);
            //break;
        }
    }

    QFile file { R"(D:\ARM\NucleoL476_Nokia1616_LCD\Core\Src\_DMA.h)" };
    //QFile file { R"(C:\Users\bakiev\Junk_Yard\PRO\ARM\NucleoL476_Nokia1//616_LCD\Core\Src\_DMA.h)" };
    str.replace('\t', "    ");
    if (file.open(QFile::WriteOnly))
        file.write(str);
    textEdit->setText(str);
}
