#pragma once

#include <string>
#include <map>
#include <stdexcept>

namespace Generated {

template <typename E>concept Enum=std::is_enum_v<E>;

template <Enum E>
E stringTo(const std::string& str);

// cpuType specifies a selection of Cortex-M and Secure-Cores. This list will get extended as new processors are released 
enum class CpuName {
    CM0,
    CM0PLUS,
    CM0Plus, // CM0+
    CM1,
    CM3,
    CM4,
    CM7,
    CM23,
    CM33,
    CM35P,
    CM52,
    CM55,
    CM85,
    SC000,
    SC300,
    ARMV8MML,
    ARMV8MBL,
    ARMV81MML,
    CA5,
    CA7,
    CA8,
    CA9,
    CA15,
    CA17,
    CA53,
    CA57,
    CA72,
    SMC1,
    other,
};

// Функции преобразования для cpuName
extern template CpuName stringTo<CpuName>(const std::string& str);
std::string toString(CpuName value);

// EndianType pre-defines the tokens for specifying the endianess of the device 
enum class Endian {
    little,
    big,
    selectable,
    other,
};

// Функции преобразования для endian
extern template Endian stringTo<Endian>(const std::string& str);
std::string toString(Endian value);

// dataType pre-defines the tokens in line with CMSIS data type definitions 
enum class DataType {
    uint8_t,
    uint16_t,
    uint32_t,
    uint64_t,
    int8_t,
    int16_t,
    int32_t,
    int64_t,
    uint8_t_Star, // uint8_t *
    uint16_t_Star, // uint16_t *
    uint32_t_Star, // uint32_t *
    uint64_t_Star, // uint64_t *
    int8_t_Star, // int8_t *
    int16_t_Star, // int16_t *
    int32_t_Star, // int32_t *
    int64_t_Star, // int64_t *
};

// Функции преобразования для dataType
extern template DataType stringTo<DataType>(const std::string& str);
std::string toString(DataType value);

// accessType specfies the pre-defined tokens for the available accesses 
enum class Access {
    read_only, // read-only
    write_only, // write-only
    read_write, // read-write
    writeOnce,
    read_writeOnce, // read-writeOnce
};

// Функции преобразования для access
extern template Access stringTo<Access>(const std::string& str);
std::string toString(Access value);

// modifiedWriteValuesType specifies the pre-defined tokens for the write side effects 
enum class ModifiedWriteValues {
    oneToClear,
    oneToSet,
    oneToToggle,
    zeroToClear,
    zeroToSet,
    zeroToToggle,
    clear,
    set,
    modify,
};

// Функции преобразования для modifiedWriteValues
extern template ModifiedWriteValues stringTo<ModifiedWriteValues>(const std::string& str);
std::string toString(ModifiedWriteValues value);

// readAction type specifies the pre-defined tokens for read side effects 
enum class ReadAction {
    clear,
    set,
    modify,
    modifyExternal,
};

// Функции преобразования для readAction
extern template ReadAction stringTo<ReadAction>(const std::string& str);
std::string toString(ReadAction value);

// enumUsageType specifies the pre-defined tokens for selecting what access types an enumeratedValues set is associated with 
enum class EnumUsage {
    read,
    write,
    read_write, // read-write
};

// Функции преобразования для enumUsage
extern template EnumUsage stringTo<EnumUsage>(const std::string& str);
std::string toString(EnumUsage value);

} // namespace Generated
