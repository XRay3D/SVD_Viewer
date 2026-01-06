#pragma once

#include "enums.h"

namespace CmsisSvd {

struct[[= XML::Name("R")]] Range {
    uint32_t minimum;
    uint32_t maximum;
};

// writeContraintType specifies how to describe the restriction of the allowed values that can be written to a resource
struct[[= XML::Name("writeConstraint")]] Writeconstraint {
    // std::variant<bool, bool, Range> writeAsRead_useEnumeratedValues_range_;
};

// addressBlockType specifies the elements to describe an address block
struct[[= XML::Name("addressBlock")]] Addressblock {
    uint32_t offset;
    uint32_t size;
    std::string usage;
    // Version 1.3.2: optional access protection for an address block s=secure n=non-secure p=privileged
    std::optional<std::string> protection;
};

// interruptType specifies how to describe an interrupt associated with a peripheral
struct[[= XML::Name("interrupt")]] Interrupt {
    std::string name;
    std::optional<std::string> description;
    int32_t value;
};

// addressBlockType specifies the elements to describe an address block
struct[[= XML::Name("Re")]] Region {
    uint32_t base;
    uint32_t limit;
    std::string access;
    //
    // [По умолчанию: true]
    [[= XML::Attr]] std::optional<bool> enabled;
    [[= XML::Attr]] std::optional<std::string> name;
};

struct[[= XML::Name("Sauregionsco")]] Sauregionsconfig {
    [[= XML::Elem]] std::vector<Region> region;
    //
    // [По умолчанию: true]
    [[= XML::Attr]] std::optional<bool> enabled;
    //
    // [По умолчанию: s]
    [[= XML::Attr]] std::optional<std::string> protectionWhenDisabled;
};

struct[[= XML::Name("cpu")]] Cpu {
    // V1.1: ARM processor name: Cortex-Mx / SCxxx
    Cpuname name;
    // V1.1: ARM defined revision of the cpu
    std::string revision;
    // V1.1: Endian specifies the endianess of the processor/device
    Endian endian;
    // V1.1: mpuPresent specifies whether or not a memory protection unit is physically present
    std::optional<bool> mpuPresent;
    // V1.1: fpuPresent specifies whether or not a floating point hardware unit is physically present
    std::optional<bool> fpuPresent;
    // V1.2: fpuDP specifies a double precision floating point hardware unit is physically present
    std::optional<bool> fpuDP;
    // V1.3: dspPresent specifies whether the optional SIMD instructions are supported by processor
    std::optional<bool> dspPresent;
    // V1.2: icachePresent specifies that an instruction cache is physically present
    std::optional<bool> icachePresent;
    // V1.2: dcachePresent specifies that a data cache is physically present
    std::optional<bool> dcachePresent;
    // V1.2: itcmPresent specifies that an instruction tightly coupled memory is physically present
    std::optional<bool> itcmPresent;
    // V1.2: dtcmPresent specifies that an data tightly coupled memory is physically present
    std::optional<bool> dtcmPresent;
    // V1.1: vtorPresent is used for Cortex-M0+ based devices only. It indicates whether the VectorTable Offset Register is implemented in the device or not
    std::optional<bool> vtorPresent;
    // V1.1: nvicPrioBits specifies the number of bits used by the Nested Vectored Interrupt Controllerfor defining the priority level = # priority levels
    uint32_t nvicPrioBits;
    // V1.1: vendorSystickConfig is set true if a custom system timer is implemented in the deviceinstead of the ARM specified SysTickTimer
    bool vendorSystickConfig;
    // V1.3: reports the total number of interrupts implemented by the device (optional)
    std::optional<uint32_t> deviceNumInterrupts;
    // V1.3: indicates whether a PMU is present and how many event counter are present
    std::optional<bool> pmuPresent;
    std::optional<uint32_t> pmuNumEventCnt;
    // V1.3: sauRegions specifies the available number of address regionsif not specified a value of zero is assumed
    std::optional<uint32_t> sauNumRegions;
    // V1.3: SAU Regions Configuration (if fully or partially predefined)
    std::optional<Sauregionsconfig> sauRegionsConfig;
};

struct[[= XML::Name("enumeratedValue")]] Enumeratedvalue {
    // name is a ANSI C indentifier representing the value (C Enumeration)
    std::string name;
    // description contains the details about the semantics/behavior specified by this value
    std::optional<std::string> description;
    // isDefault specifies the name and description for all values that are not
    // specifically described individually
    // std::variant<std::string, bool> value_isDefault_;
};

struct[[= XML::Name("enumeration")]] Enumeration {
    // name specfies a reference to this enumeratedValues section for reuse purposes
    // this name does not appear in the System Viewer nor the Header File.
    std::optional<std::string> name;
    // overrides the hierarchical enumeration type in the device header file. User is responsible for uniqueness across description
    std::optional<std::string> headerEnumName;
    // usage specifies whether this enumeration is to be used for read or write or
    // (read and write) accesses
    std::optional<Enumusage> usage;
    // enumeratedValues derivedFrom=<referenceIdentifierType>
    [[= XML::Elem]] std::vector<Enumeratedvalue> enumeratedValue;
    [[= XML::Attr]] std::optional<std::string> derivedFrom;
};

struct[[= XML::Name("dimArrayIndex")]] Dimarrayindex {
    std::optional<std::string> headerEnumName;
    [[= XML::Elem]] std::vector<Enumeratedvalue> enumeratedValue;
};

struct[[= XML::Name("field")]] Field {
    uint32_t dim;
    uint32_t dimIncrement;
    std::optional<std::string> dimIndex;
    std::optional<std::string> dimName;
    std::optional<Dimarrayindex> dimArrayIndex;
    // name specifies a field's name. The System Viewer and the device header file will
    // use the name of the field as identifier
    std::string name;
    // description contains reference manual level information about the function and
    // options of a field
    std::optional<std::string> description;
    // bit field described by [<msb>:<lsb>]
    // std::variant<std::string> bitRange_;
    // access describes the predefined permissions for the field.
    std::optional<Access> access;
    // predefined description of write side effects
    std::optional<Modifiedwritevalues> modifiedWriteValues;
    // writeContstraint specifies the subrange of allowed values
    std::optional<Writeconstraint> writeConstraint;
    // readAction specifies the read side effects.
    std::optional<Readaction> readAction;
    // enumeratedValues derivedFrom=<identifierType>
    [[= XML::Elem]] std::vector<Enumeration> enumeratedValues;
    [[= XML::Attr]] std::optional<std::string> derivedFrom;
};

struct[[= XML::Name("fields")]] Fields {
    // field derivedFrom=<identifierType>
    [[= XML::Elem]] std::vector<Field> field;
};

struct[[= XML::Name("register")]] Register {
    uint32_t dim;
    uint32_t dimIncrement;
    std::optional<std::string> dimIndex;
    std::optional<std::string> dimName;
    std::optional<Dimarrayindex> dimArrayIndex;
    // name specifies the name of the register. The register name is used by System Viewer and
    // device header file generator to represent a register
    std::string name;
    // display name specifies a register name without the restritions of an ANSIS C identifier.
    // The use of this tag is discouraged because it does not allow consistency between
    // the System View and the device header file.
    std::optional<std::string> displayName;
    // description contains a reference manual level description about the register and it's purpose
    std::optional<std::string> description;
    // alternateGroup specifies the identifier of the subgroup a register belongs to.
    // This is useful if a register has a different description per mode but a single name
    // V1.1: alternateRegister specifies an alternate register description for an address that is
    // already fully described. In this case the register name must be unique within the peripheral
    // std::variant<std::string, std::string> alternateGroup_alternateRegister_;
    // addressOffset describes the address of the register relative to the baseOffset of the peripheral
    uint32_t addressOffset;
    std::optional<uint32_t> size;
    std::optional<Access> access;
    // V 1.3: extended register access protection
    std::optional<std::string> protection;
    std::optional<uint32_t> resetValue;
    std::optional<uint32_t> resetMask;
    // V1.1: dataType specifies a CMSIS compliant native dataType for a register (i.e. signed, unsigned, pointer)
    std::optional<Datatype> data;
    // modifiedWriteValues specifies the write side effects
    std::optional<Modifiedwritevalues> modifiedWriteValues;
    // writeConstraint specifies the subset of allowed write values
    std::optional<Writeconstraint> writeConstraint;
    // readAcction specifies the read side effects
    std::optional<Readaction> readAction;
    // fields section contains all fields that belong to this register
    std::optional<Fields> fields;
    [[= XML::Attr]] std::optional<std::string> derivedFrom;
};

// V1.1: A cluster is a set of registers that are composed into a C data structure in the device header file
struct[[= XML::Name("cluster")]] Cluster {
    uint32_t dim;
    uint32_t dimIncrement;
    std::optional<std::string> dimIndex;
    std::optional<std::string> dimName;
    std::optional<Dimarrayindex> dimArrayIndex;
    std::string name;
    std::string description;
    // V1.1: alternateCluster specifies an alternative description for a cluster address range that is
    // already fully described. In this case the cluster name must be unique within the peripheral
    std::optional<std::string> alternateCluster;
    // V1.1: headerStructName specifies the name for the cluster structure typedef
    // used in the device header generation instead of the cluster name
    std::optional<std::string> headerStructName;
    uint32_t addressOffset;
    std::optional<uint32_t> size;
    std::optional<Access> access;
    // V 1.3: extended register access protection
    std::optional<std::string> protection;
    std::optional<uint32_t> resetValue;
    std::optional<uint32_t> resetMask;
    // 1.3: nesting of cluster is supported
    // std::variant<Register, Cluster> register__cluster_;
    [[= XML::Attr]] std::optional<std::string> derivedFrom;
};

// the registers section can have an arbitrary list of cluster and register sections
struct[[= XML::Name("registers")]] Registers {
    // std::variant<Cluster, Register> cluster_register__;
    [[= XML::Elem]] std::vector<Register> peripheral;
    [[= XML::Elem]] std::vector<Register> cluster;
};

struct[[= XML::Name("peripheral")]] Peripheral {
    uint32_t dim;
    uint32_t dimIncrement;
    std::optional<std::string> dimIndex;
    std::optional<std::string> dimName;
    std::optional<Dimarrayindex> dimArrayIndex;
    // name specifies the name of a peripheral. This name is used for the System View and device header file
    std::string name;
    // version specifies the version of the peripheral descriptions
    std::optional<std::string> version;
    // description provides a high level functional description of the peripheral
    std::optional<std::string> description;
    // V1.1: alternatePeripheral specifies an alternative description for an address range that is
    // already fully by a peripheral described. In this case the peripheral name must be unique within the device description
    std::optional<std::string> alternatePeripheral;
    // groupName assigns this peripheral to a group of peripherals. This is only used bye the System View
    std::optional<std::string> groupName;
    // prependToName specifies a prefix that is placed in front of each register name of this peripheral.
    // The device header file will show the registers in a C-Struct of the peripheral without the prefix.
    std::optional<std::string> prependToName;
    // appendToName is a postfix that is appended to each register name of this peripheral. The device header
    // file will sho the registers in a C-Struct of the peripheral without the postfix
    std::optional<std::string> appendToName;
    // V1.1: headerStructName specifies the name for the peripheral structure typedef
    // used in the device header generation instead of the peripheral name
    std::optional<std::string> headerStructName;
    // disableCondition contains a logical expression based on constants and register or bit-field values
    // if the condition is evaluated to true, the peripheral display will be disabled
    std::optional<std::string> disableCondition;
    // baseAddress specifies the absolute base address of a peripheral. For derived peripherals it is mandatory
    // to specify a baseAddress.
    uint32_t baseAddress;
    std::optional<uint32_t> size;
    std::optional<Access> access;
    // V 1.3: extended register access protection
    std::optional<std::string> protection;
    std::optional<uint32_t> resetValue;
    std::optional<uint32_t> resetMask;
    // addressBlock specifies one or more address ranges that are assigned exclusively to this peripheral.
    // derived peripherals may have no addressBlock, however none-derived peripherals are required to specify
    // at least one address block
    [[= XML::Elem]] std::vector<Addressblock> addressBlock;
    // interrupt specifies can specify one or more interrtupts by name, description and value
    [[= XML::Elem]] std::vector<Interrupt> interrupt;
    // registers section contains all registers owned by the peripheral. In case a peripheral gets derived it does
    // not have its own registers section, hence this section is optional. A unique peripheral without a
    // registers section is not allowed
    std::optional<Registers> registers;
    [[= XML::Attr]] std::optional<std::string> derivedFrom;
};

struct[[= XML::Name("Periphe")]] Peripherals {
    [[= XML::Elem]] std::vector<Peripheral> peripheral;
};

struct[[= XML::Name("Vendorextens")]] Vendorextensions {
};

struct[[= XML::Root("device")]] Device {
    // V1.1: Vendor Name
    std::optional<std::string> vendor;
    // V1.1: Vendor ID - a short name for referring to the vendor (e.g. Texas Instruments = TI)
    std::optional<std::string> vendorID;
    // name specifies the device name being described
    std::string name;
    // V1.1: series specifies the device series or family name
    std::optional<std::string> series;
    // version specifies the version of the device description
    std::string version;
    // description is a string describing the device features (e.g. memory size, peripherals, etc.)
    std::string description;
    // V1.1: licenseText specifies the file header section to be included in any derived file
    std::optional<std::string> licenseText;
    // V1.1: cpu specifies the details of the processor included in the device
    std::optional<Cpu> cpu;
    // V1.1: the tag specifies the filename without extension of the CMSIS System Device include file.
    // This tag is used by the header file generator for customizing the include statement referencing the
    // CMSIS system file within the CMSIS device header file. By default the filename is "system_<device.name>"
    // In cases a device series shares a single system header file, the name of the series shall be used
    // instead of the individual device name.
    std::optional<std::string> headerSystemFilename;
    // V1.1: headerDefinitionPrefix specifies the string being prepended to all names of types defined in
    // generated device header file
    std::optional<std::string> headerDefinitionsPrefix;
    // addressUnitBits specifies the size of the minimal addressable unit in bits
    uint32_t addressUnitBits;
    // width specifies the number of bits for the maximum single transfer size allowed by the bus interface.
    // This sets the maximum size of a single register that can be defined for an address space
    uint32_t width;
    std::optional<uint32_t> size;
    std::optional<Access> access;
    // V 1.3: extended register access protection
    std::optional<std::string> protection;
    std::optional<uint32_t> resetValue;
    std::optional<uint32_t> resetMask;
    // peripherals is containing all peripherals
    Peripherals peripherals;
    // Vendor Extensions: this section captures custom extensions. This section will be ignored by default
    std::optional<Vendorextensions> vendorExtensions;
    [[= XML::Attr]] double schemaVersion;
};

} // namespace CmsisSvd
