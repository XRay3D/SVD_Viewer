// svd_parser.hpp
#pragma once
#include "types.hpp"
#include <functional>
#include <iostream>
#include <tinyxml2.h>

namespace svd {

class SvdParser {
private:
    std::unique_ptr<Device> device_;

    // Вспомогательные функции парсинга
    AccessType parseAccessType(const std::string& str) {
        static const std::map<std::string, AccessType> mapping = {
            {"read-only",      AccessType::ReadOnly     },
            {"write-only",     AccessType::WriteOnly    },
            {"read-write",     AccessType::ReadWrite    },
            {"writeOnce",      AccessType::WriteOnce    },
            {"read-writeOnce", AccessType::ReadWriteOnce}
        };

        auto it = mapping.find(str);
        return it != mapping.end() ? it->second : AccessType::ReadWrite;
    }

    std::string getText(tinyxml2::XMLElement* elem, const char* childName = nullptr) {
        if(childName) {
            elem = elem->FirstChildElement(childName);
        }
        return elem ? elem->GetText() : "";
    }

    uint32_t getHexValue(tinyxml2::XMLElement* elem, const char* childName = nullptr) {
        std::string text = getText(elem, childName);
        if(text.empty()) return 0;

        // Удаляем префикс "0x" если есть
        if(text.size() > 2 && text[0] == '0' && (text[1] == 'x' || text[1] == 'X')) {
            text = text.substr(2);
        }

        return static_cast<uint32_t>(std::stoul(text, nullptr, 16));
    }

    // Парсинг полей
    std::shared_ptr<Field> parseField(tinyxml2::XMLElement* fieldElem) {
        auto field = std::make_shared<Field>();

        field->setName(getText(fieldElem, "name"));
        field->setDescription(getText(fieldElem, "description"));

        // Парсинг битовых параметров
        if(auto bitOffsetElem = fieldElem->FirstChildElement("bitOffset")) {
            field->setBitOffset(std::stoul(getText(bitOffsetElem)));
        }

        if(auto bitWidthElem = fieldElem->FirstChildElement("bitWidth")) {
            field->setBitWidth(std::stoul(getText(bitWidthElem)));
        }

        if(auto accessElem = fieldElem->FirstChildElement("access")) {
            field->setAccess(parseAccessType(getText(accessElem)));
        }

        return field;
    }

    // Парсинг регистра
    std::shared_ptr<Register> parseRegister(tinyxml2::XMLElement* regElem) {
        auto reg = std::make_shared<Register>();

        reg->setName(getText(regElem, "name"));
        reg->setDescription(getText(regElem, "description"));
        reg->setAddressOffset(getHexValue(regElem, "addressOffset"));

        // Парсинг размеров
        if(auto sizeElem = regElem->FirstChildElement("size")) {
            reg->setSize(std::stoul(getText(sizeElem)));
        }

        if(auto resetValueElem = regElem->FirstChildElement("resetValue")) {
            reg->setResetValue(getHexValue(resetValueElem));
        }

        // Парсинг полей
        auto fieldsElem = regElem->FirstChildElement("fields");
        if(fieldsElem) {
            auto fieldElem = fieldsElem->FirstChildElement("field");
            while(fieldElem) {
                auto field = parseField(fieldElem);
                if(field) {
                    reg->addField(field->getName(), field);
                }
                fieldElem = fieldElem->NextSiblingElement("field");
            }
        }

        return reg;
    }

    // Парсинг периферии
    std::shared_ptr<Peripheral> parsePeripheral(tinyxml2::XMLElement* periphElem) {
        auto peripheral = std::make_shared<Peripheral>();

        peripheral->setName(getText(periphElem, "name"));
        peripheral->setDescription(getText(periphElem, "description"));
        peripheral->setBaseAddress(getHexValue(periphElem, "baseAddress"));

        if(auto groupNameElem = periphElem->FirstChildElement("groupName")) {
            peripheral->setGroupName(getText(groupNameElem));
        }

        // Парсинг регистров
        auto registersElem = periphElem->FirstChildElement("registers");
        if(registersElem) {
            auto regElem = registersElem->FirstChildElement("register");
            while(regElem) {
                auto reg = parseRegister(regElem);
                if(reg) {
                    peripheral->addRegister(reg->getName(), reg);
                }
                regElem = regElem->NextSiblingElement("register");
            }
        }

        // Парсинг прерываний
        auto interruptsElem = periphElem->FirstChildElement("interrupt");
        while(interruptsElem) {
            if(auto nameElem = interruptsElem->FirstChildElement("name")) {
                peripheral->addInterrupt(getText(nameElem));
            }
            interruptsElem = interruptsElem->NextSiblingElement("interrupt");
        }

        return peripheral;
    }

public:
    std::unique_ptr<Device> parse(const std::string& filename) {
        tinyxml2::XMLDocument doc;
        if(doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
            std::cerr << "Failed to load SVD file: " << filename << std::endl;
            return nullptr;
        }

        auto root = doc.FirstChildElement("device");
        if(!root) {
            std::cerr << "Invalid SVD file: no device element" << std::endl;
            return nullptr;
        }

        device_ = std::make_unique<Device>();

        // Парсинг общих свойств устройства
        device_->setName(getText(root, "name"));
        device_->setVersion(getText(root, "version"));
        device_->setDescription(getText(root, "description"));

        if(auto seriesElem = root->FirstChildElement("series")) {
            device_->setSeries(getText(seriesElem));
        }

        if(auto addressUnitBitsElem = root->FirstChildElement("addressUnitBits")) {
            device_->setAddressUnitBits(std::stoul(getText(addressUnitBitsElem)));
        }

        // Парсинг периферии
        auto peripheralsElem = root->FirstChildElement("peripherals");
        if(peripheralsElem) {
            auto periphElem = peripheralsElem->FirstChildElement("peripheral");
            while(periphElem) {
                auto peripheral = parsePeripheral(periphElem);
                if(peripheral) {
                    device_->addPeripheral(peripheral->getName(), peripheral);
                }
                periphElem = periphElem->NextSiblingElement("peripheral");
            }
        }

        return std::move(device_);
    }
};

} // namespace svd
