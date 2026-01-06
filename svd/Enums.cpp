#include "Enums.h"
#include <algorithm>

namespace Generated {

template<CpuName> CpuName toEnum(const std::string& str) {
    static const std::map<std::string, CpuName> mapping = {
        {"CM0", CpuName::CM0},
        {"CM0PLUS", CpuName::CM0PLUS},
        {"CM0Plus", CpuName::CM0Plus},
        {"CM1", CpuName::CM1},
        {"CM3", CpuName::CM3},
        {"CM4", CpuName::CM4},
        {"CM7", CpuName::CM7},
        {"CM23", CpuName::CM23},
        {"CM33", CpuName::CM33},
        {"CM35P", CpuName::CM35P},
        {"CM52", CpuName::CM52},
        {"CM55", CpuName::CM55},
        {"CM85", CpuName::CM85},
        {"SC000", CpuName::SC000},
        {"SC300", CpuName::SC300},
        {"ARMV8MML", CpuName::ARMV8MML},
        {"ARMV8MBL", CpuName::ARMV8MBL},
        {"ARMV81MML", CpuName::ARMV81MML},
        {"CA5", CpuName::CA5},
        {"CA7", CpuName::CA7},
        {"CA8", CpuName::CA8},
        {"CA9", CpuName::CA9},
        {"CA15", CpuName::CA15},
        {"CA17", CpuName::CA17},
        {"CA53", CpuName::CA53},
        {"CA57", CpuName::CA57},
        {"CA72", CpuName::CA72},
        {"SMC1", CpuName::SMC1},
        {"other", CpuName::other},
        {"CM0+", CpuName::CM0Plus},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for CpuName: " + str);
}

std::string toString(CpuName value) {
    switch(value) {
        case CpuName::CM0: return "CM0";
        case CpuName::CM0PLUS: return "CM0PLUS";
        case CpuName::CM0Plus: return "CM0+";
        case CpuName::CM1: return "CM1";
        case CpuName::CM3: return "CM3";
        case CpuName::CM4: return "CM4";
        case CpuName::CM7: return "CM7";
        case CpuName::CM23: return "CM23";
        case CpuName::CM33: return "CM33";
        case CpuName::CM35P: return "CM35P";
        case CpuName::CM52: return "CM52";
        case CpuName::CM55: return "CM55";
        case CpuName::CM85: return "CM85";
        case CpuName::SC000: return "SC000";
        case CpuName::SC300: return "SC300";
        case CpuName::ARMV8MML: return "ARMV8MML";
        case CpuName::ARMV8MBL: return "ARMV8MBL";
        case CpuName::ARMV81MML: return "ARMV81MML";
        case CpuName::CA5: return "CA5";
        case CpuName::CA7: return "CA7";
        case CpuName::CA8: return "CA8";
        case CpuName::CA9: return "CA9";
        case CpuName::CA15: return "CA15";
        case CpuName::CA17: return "CA17";
        case CpuName::CA53: return "CA53";
        case CpuName::CA57: return "CA57";
        case CpuName::CA72: return "CA72";
        case CpuName::SMC1: return "SMC1";
        case CpuName::other: return "other";
        default: throw std::runtime_error("Invalid CpuName value");
    }
}

template<Endian> Endian toEnum(const std::string& str) {
    static const std::map<std::string, Endian> mapping = {
        {"little", Endian::little},
        {"big", Endian::big},
        {"selectable", Endian::selectable},
        {"other", Endian::other},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for Endian: " + str);
}

std::string toString(Endian value) {
    switch(value) {
        case Endian::little: return "little";
        case Endian::big: return "big";
        case Endian::selectable: return "selectable";
        case Endian::other: return "other";
        default: throw std::runtime_error("Invalid Endian value");
    }
}

template<DataType> DataType toEnum(const std::string& str) {
    static const std::map<std::string, DataType> mapping = {
        {"uint8_t", DataType::uint8_t},
        {"uint16_t", DataType::uint16_t},
        {"uint32_t", DataType::uint32_t},
        {"uint64_t", DataType::uint64_t},
        {"int8_t", DataType::int8_t},
        {"int16_t", DataType::int16_t},
        {"int32_t", DataType::int32_t},
        {"int64_t", DataType::int64_t},
        {"uint8_t_Star", DataType::uint8_t_Star},
        {"uint16_t_Star", DataType::uint16_t_Star},
        {"uint32_t_Star", DataType::uint32_t_Star},
        {"uint64_t_Star", DataType::uint64_t_Star},
        {"int8_t_Star", DataType::int8_t_Star},
        {"int16_t_Star", DataType::int16_t_Star},
        {"int32_t_Star", DataType::int32_t_Star},
        {"int64_t_Star", DataType::int64_t_Star},
        {"uint8_t *", DataType::uint8_t_Star},
        {"uint16_t *", DataType::uint16_t_Star},
        {"uint32_t *", DataType::uint32_t_Star},
        {"uint64_t *", DataType::uint64_t_Star},
        {"int8_t *", DataType::int8_t_Star},
        {"int16_t *", DataType::int16_t_Star},
        {"int32_t *", DataType::int32_t_Star},
        {"int64_t *", DataType::int64_t_Star},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for DataType: " + str);
}

std::string toString(DataType value) {
    switch(value) {
        case DataType::uint8_t: return "uint8_t";
        case DataType::uint16_t: return "uint16_t";
        case DataType::uint32_t: return "uint32_t";
        case DataType::uint64_t: return "uint64_t";
        case DataType::int8_t: return "int8_t";
        case DataType::int16_t: return "int16_t";
        case DataType::int32_t: return "int32_t";
        case DataType::int64_t: return "int64_t";
        case DataType::uint8_t_Star: return "uint8_t *";
        case DataType::uint16_t_Star: return "uint16_t *";
        case DataType::uint32_t_Star: return "uint32_t *";
        case DataType::uint64_t_Star: return "uint64_t *";
        case DataType::int8_t_Star: return "int8_t *";
        case DataType::int16_t_Star: return "int16_t *";
        case DataType::int32_t_Star: return "int32_t *";
        case DataType::int64_t_Star: return "int64_t *";
        default: throw std::runtime_error("Invalid DataType value");
    }
}

template<Access> Access toEnum(const std::string& str) {
    static const std::map<std::string, Access> mapping = {
        {"read_only", Access::read_only},
        {"write_only", Access::write_only},
        {"read_write", Access::read_write},
        {"writeOnce", Access::writeOnce},
        {"read_writeOnce", Access::read_writeOnce},
        {"read-only", Access::read_only},
        {"write-only", Access::write_only},
        {"read-write", Access::read_write},
        {"read-writeOnce", Access::read_writeOnce},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for Access: " + str);
}

std::string toString(Access value) {
    switch(value) {
        case Access::read_only: return "read-only";
        case Access::write_only: return "write-only";
        case Access::read_write: return "read-write";
        case Access::writeOnce: return "writeOnce";
        case Access::read_writeOnce: return "read-writeOnce";
        default: throw std::runtime_error("Invalid Access value");
    }
}

template<ModifiedWriteValues> ModifiedWriteValues toEnum(const std::string& str) {
    static const std::map<std::string, ModifiedWriteValues> mapping = {
        {"oneToClear", ModifiedWriteValues::oneToClear},
        {"oneToSet", ModifiedWriteValues::oneToSet},
        {"oneToToggle", ModifiedWriteValues::oneToToggle},
        {"zeroToClear", ModifiedWriteValues::zeroToClear},
        {"zeroToSet", ModifiedWriteValues::zeroToSet},
        {"zeroToToggle", ModifiedWriteValues::zeroToToggle},
        {"clear", ModifiedWriteValues::clear},
        {"set", ModifiedWriteValues::set},
        {"modify", ModifiedWriteValues::modify},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for ModifiedWriteValues: " + str);
}

std::string toString(ModifiedWriteValues value) {
    switch(value) {
        case ModifiedWriteValues::oneToClear: return "oneToClear";
        case ModifiedWriteValues::oneToSet: return "oneToSet";
        case ModifiedWriteValues::oneToToggle: return "oneToToggle";
        case ModifiedWriteValues::zeroToClear: return "zeroToClear";
        case ModifiedWriteValues::zeroToSet: return "zeroToSet";
        case ModifiedWriteValues::zeroToToggle: return "zeroToToggle";
        case ModifiedWriteValues::clear: return "clear";
        case ModifiedWriteValues::set: return "set";
        case ModifiedWriteValues::modify: return "modify";
        default: throw std::runtime_error("Invalid ModifiedWriteValues value");
    }
}

template<ReadAction> ReadAction toEnum(const std::string& str) {
    static const std::map<std::string, ReadAction> mapping = {
        {"clear", ReadAction::clear},
        {"set", ReadAction::set},
        {"modify", ReadAction::modify},
        {"modifyExternal", ReadAction::modifyExternal},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for ReadAction: " + str);
}

std::string toString(ReadAction value) {
    switch(value) {
        case ReadAction::clear: return "clear";
        case ReadAction::set: return "set";
        case ReadAction::modify: return "modify";
        case ReadAction::modifyExternal: return "modifyExternal";
        default: throw std::runtime_error("Invalid ReadAction value");
    }
}

template<EnumUsage> EnumUsage toEnum(const std::string& str) {
    static const std::map<std::string, EnumUsage> mapping = {
        {"read", EnumUsage::read},
        {"write", EnumUsage::write},
        {"read_write", EnumUsage::read_write},
        {"read-write", EnumUsage::read_write},
    };

    auto it = mapping.find(str);
    if (it != mapping.end()) return it->second;
    throw std::runtime_error("Invalid value for EnumUsage: " + str);
}

std::string toString(EnumUsage value) {
    switch(value) {
        case EnumUsage::read: return "read";
        case EnumUsage::write: return "write";
        case EnumUsage::read_write: return "read-write";
        default: throw std::runtime_error("Invalid EnumUsage value");
    }
}

} // namespace Generated
