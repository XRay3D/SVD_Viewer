// svd_codegen.hpp
#pragma once
#include "types.hpp"
#include <fstream>
#include <sstream>

namespace svd {

class CodeGenerator {
private:
    std::string toUpperCase(const std::string& str) {
        std::string result = str;
        for(auto& c: result) c = toupper(c);
        return result;
    }

    std::string toCamelCase(const std::string& str) {
        std::string result;
        bool capitalize = true;

        for(char c: str) {
            if(c == '_' || c == ' ') {
                capitalize = true;
            } else if(capitalize) {
                result += toupper(c);
                capitalize = false;
            } else {
                result += tolower(c);
            }
        }
        return result;
    }

public:
    void generateRegisterAccessors(std::ofstream& file,
        const Peripheral& peripheral,
        const Register& reg) {
        std::string periphName = toCamelCase(peripheral.getName());
        std::string regName = toCamelCase(reg.getName());

        // Генерация константы адреса
        file << "// " << reg.getDescription() << "\n";
        file << "#define " << toUpperCase(peripheral.getName())
             << "_" << toUpperCase(reg.getName())
             << "_OFFSET 0x" << std::hex << reg.getAddressOffset() << std::dec << "u\n";

        file << "#define " << toUpperCase(peripheral.getName())
             << "_" << toUpperCase(reg.getName())
             << "_ADDR ((" << toUpperCase(peripheral.getName())
             << "_BASE + " << toUpperCase(peripheral.getName())
             << "_" << toUpperCase(reg.getName()) << "_OFFSET))\n\n";

        // Генерация функций доступа
        file << "inline uint32_t " << periphName << "_get" << regName << "() {\n";
        file << "    return *((volatile uint32_t*)"
             << toUpperCase(peripheral.getName()) << "_"
             << toUpperCase(reg.getName()) << "_ADDR);\n";
        file << "}\n\n";

        file << "inline void " << periphName << "_set" << regName << "(uint32_t value) {\n";
        file << "    *((volatile uint32_t*)"
             << toUpperCase(peripheral.getName()) << "_"
             << toUpperCase(reg.getName()) << "_ADDR) = value;\n";
        file << "}\n\n";

        // Генерация функций для полей
        for(const auto& [fieldName, field]: reg.getFields()) {
            std::string fieldCamel = toCamelCase(fieldName);

            file << "// " << field->getDescription() << "\n";
            file << "#define " << toUpperCase(peripheral.getName())
                 << "_" << toUpperCase(reg.getName())
                 << "_" << toUpperCase(fieldName)
                 << "_POS " << field->getBitOffset() << "u\n";

            file << "#define " << toUpperCase(peripheral.getName())
                 << "_" << toUpperCase(reg.getName())
                 << "_" << toUpperCase(fieldName)
                 << "_MSK (0x" << std::hex << field->getBitMask()
                 << std::dec << "u)\n\n";

            file << "inline uint32_t " << periphName << "_get" << regName
                 << fieldCamel << "() {\n";
            file << "    return (" << periphName << "_get" << regName
                 << "() & " << toUpperCase(peripheral.getName()) << "_"
                 << toUpperCase(reg.getName()) << "_"
                 << toUpperCase(fieldName) << "_MSK) >> "
                 << toUpperCase(peripheral.getName()) << "_"
                 << toUpperCase(reg.getName()) << "_"
                 << toUpperCase(fieldName) << "_POS;\n";
            file << "}\n\n";

            file << "inline void " << periphName << "_set" << regName
                 << fieldCamel << "(uint32_t value) {\n";
            file << "    uint32_t reg = " << periphName << "_get" << regName << "();\n";
            file << "    reg &= ~" << toUpperCase(peripheral.getName()) << "_"
                 << toUpperCase(reg.getName()) << "_"
                 << toUpperCase(fieldName) << "_MSK;\n";
            file << "    reg |= (value << " << toUpperCase(peripheral.getName())
                 << "_" << toUpperCase(reg.getName()) << "_"
                 << toUpperCase(fieldName) << "_POS) & "
                 << toUpperCase(peripheral.getName()) << "_"
                 << toUpperCase(reg.getName()) << "_"
                 << toUpperCase(fieldName) << "_MSK;\n";
            file << "    " << periphName << "_set" << regName << "(reg);\n";
            file << "}\n\n";
        }

        file << "// ----------------------------------------------------------------------\n\n";
    }

    void generateHeader(const Device& device, const std::string& outputFile) {
        std::ofstream file(outputFile);

        if(!file.is_open()) {
            throw std::runtime_error("Cannot open output file");
        }

        // Заголовок файла
        file << "// Generated from SVD: " << device.getName() << "\n";
        file << "// Version: " << device.getVersion() << "\n";
        file << "#pragma once\n\n";
        file << "#include <stdint.h>\n\n";
        file << "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n";

        // Генерация для каждой периферии
        for(const auto& [periphName, peripheral]: device.getPeripherals()) {
            file << "// ======================================================================\n";
            file << "// " << peripheral->getName() << ": "
                 << peripheral->getDescription() << "\n";
            file << "// ======================================================================\n\n";

            // Базовый адрес
            file << "#define " << toUpperCase(peripheral->getName())
                 << "_BASE 0x" << std::hex << peripheral->getBaseAddress()
                 << std::dec << "u\n\n";

            // Регистры
            for(const auto& [regName, reg]: peripheral->getRegisters()) {
                generateRegisterAccessors(file, *peripheral, *reg);
            }
        }

        file << "#ifdef __cplusplus\n}\n#endif\n";
    }
};

} // namespace svd
