#pragma once

#include "xrxmlser.hpp"

namespace CmsisSvd {

template <typename E>concept Enum=std::is_enum_v<E>;

template <Enum E>
E stringTo(const std::string& str);

// cpuType specifies a selection of Cortex-M and Secure-Cores. This list will get extended as new processors are released
enum class Cpuname {
    CM0,
    CM0PLUS,
    CM0Plus[[= XML::Name("CM0+")]],
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

// EndianType pre-defines the tokens for specifying the endianess of the device
enum class Endian {
    little,
    big,
    selectable,
    other,
};

// dataType pre-defines the tokens in line with CMSIS data type definitions
enum class Datatype {
    uint8_t,
    uint16_t,
    uint32_t,
    uint64_t,
    int8_t,
    int16_t,
    int32_t,
    int64_t,
    uint8_t_Star[[= XML::Name("uint8_t *")]],
    uint16_t_Star[[= XML::Name("uint16_t *")]],
    uint32_t_Star[[= XML::Name("uint32_t *")]],
    uint64_t_Star[[= XML::Name("uint64_t *")]],
    int8_t_Star[[= XML::Name("int8_t *")]],
    int16_t_Star[[= XML::Name("int16_t *")]],
    int32_t_Star[[= XML::Name("int32_t *")]],
    int64_t_Star[[= XML::Name("int64_t *")]],
};

// accessType specfies the pre-defined tokens for the available accesses
enum class Access {
    read_only[[= XML::Name("read-only")]],
    write_only[[= XML::Name("write-only")]],
    read_write[[= XML::Name("read-write")]],
    writeOnce,
    read_writeOnce[[= XML::Name("read-writeOnce")]],
};

// modifiedWriteValuesType specifies the pre-defined tokens for the write side effects
enum class Modifiedwritevalues {
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

// readAction type specifies the pre-defined tokens for read side effects
enum class Readaction {
    clear,
    set,
    modify,
    modifyExternal,
};

// enumUsageType specifies the pre-defined tokens for selecting what access types an enumeratedValues set is associated with
enum class Enumusage {
    read,
    write,
    read_write[[= XML::Name("read-write")]],
};

} // namespace CmsisSvd
