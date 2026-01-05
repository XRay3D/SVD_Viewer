#pragma once
#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace svd {

// Базовые типы
enum class AccessType {
    ReadOnly,
    WriteOnly,
    ReadWrite,
    WriteOnce,
    ReadWriteOnce
};

enum class ProtectionType {
    Secure,
    NonSecure,
    Privileged
};

enum class ModifiedWriteValues {
    Clear,
    Set,
    Modify,
    OneToClear,
    OneToSet,
    OneToToggle,
    ZeroToClear,
    ZeroToSet,
    ModifyExternal
};

enum class ReadAction {
    Clear,
    Set,
    Modify,
    ModifyExternal
};

// Базовый класс для всех SVD элементов
class SvdElement {
protected:
    std::string name_;
    std::string description_;
    std::string derivedFrom_;

public:
    virtual ~SvdElement() = default;

    const std::string& getName() const { return name_; }
    const std::string& getDescription() const { return description_; }
    void setDerivedFrom(const std::string& derived) { derivedFrom_ = derived; }
};

// Класс для описания поля регистра
class Field : public SvdElement {
public: // private:
    uint32_t bitOffset_;
    uint32_t bitWidth_;
    AccessType access_;
    std::optional<ModifiedWriteValues> modifiedWriteValues_;
    std::optional<ReadAction> readAction_;

public:
    Field() = default;

    void setBitOffset(uint32_t offset) { bitOffset_ = offset; }
    void setBitWidth(uint32_t width) { bitWidth_ = width; }
    void setAccess(AccessType access) { access_ = access; }

    uint32_t getBitOffset() const { return bitOffset_; }
    uint32_t getBitWidth() const { return bitWidth_; }
    uint32_t getBitMask() const {
        return ((1u << bitWidth_) - 1) << bitOffset_;
    }

    bool isInRange(uint32_t bit) const {
        return bit >= bitOffset_ && bit < bitOffset_ + bitWidth_;
    }

    uint32_t extractValue(uint32_t registerValue) const {
        return (registerValue >> bitOffset_) & ((1u << bitWidth_) - 1);
    }

    uint32_t applyValue(uint32_t registerValue, uint32_t fieldValue) const {
        uint32_t mask = getBitMask();
        return (registerValue & ~mask) | ((fieldValue << bitOffset_) & mask);
    }
};

// Класс для описания регистра
class Register : public SvdElement {
public: // private:
    uint32_t addressOffset_;
    uint32_t size_;
    AccessType access_;
    uint32_t resetValue_;
    uint32_t resetMask_;
    ProtectionType protection_;
    std::map<std::string, std::shared_ptr<Field>> fields_;

public:
    Register()
        : size_(32)
        , resetValue_(0)
        , resetMask_(0xFFFFFFFF) {
    }

    void setAddressOffset(uint32_t offset) { addressOffset_ = offset; }
    void setSize(uint32_t size) { size_ = size; }
    void setResetValue(uint32_t value) { resetValue_ = value; }

    void addField(const std::string& name, std::shared_ptr<Field> field) {
        fields_[name] = field;
    }

    uint32_t getAddressOffset() const { return addressOffset_; }
    std::shared_ptr<Field> getField(const std::string& name) const {
        auto it = fields_.find(name);
        return it != fields_.end() ? it->second : nullptr;
    }

    const std::map<std::string, std::shared_ptr<Field>>& getFields() const {
        return fields_;
    }

    uint32_t getResetValue() const { return resetValue_; }
};

// Класс для описания кластера регистров
class RegisterCluster : public SvdElement {
public: // private:
    uint32_t addressOffset_;
    std::map<std::string, std::shared_ptr<Register>> registers_;
    std::map<std::string, std::shared_ptr<RegisterCluster>> clusters_;

public:
    void setAddressOffset(uint32_t offset) { addressOffset_ = offset; }

    void addRegister(const std::string& name, std::shared_ptr<Register> reg) {
        registers_[name] = reg;
    }

    void addCluster(const std::string& name,
        std::shared_ptr<RegisterCluster> cluster) {
        clusters_[name] = cluster;
    }

    std::shared_ptr<Register> getRegister(const std::string& name) const {
        auto it = registers_.find(name);
        return it != registers_.end() ? it->second : nullptr;
    }
};

// Класс для описания периферии
class Peripheral : public SvdElement {
public: // private:
    uint64_t baseAddress_;
    std::string groupName_;
    std::string version_;
    uint32_t addressBlockSize_;
    AccessType access_;
    ProtectionType protection_;
    std::map<std::string, std::shared_ptr<Register>> registers_;
    std::map<std::string, std::shared_ptr<RegisterCluster>> clusters_;
    std::vector<std::string> interrupts_;

public:
    Peripheral()
        : baseAddress_(0)
        , addressBlockSize_(0) {
    }

    void setBaseAddress(uint64_t address) { baseAddress_ = address; }
    void setGroupName(const std::string& group) { groupName_ = group; }

    void addRegister(const std::string& name, std::shared_ptr<Register> reg) {
        registers_[name] = reg;
    }

    void addCluster(const std::string& name,
        std::shared_ptr<RegisterCluster> cluster) {
        clusters_[name] = cluster;
    }

    void addInterrupt(const std::string& interrupt) {
        interrupts_.push_back(interrupt);
    }

    uint64_t getBaseAddress() const { return baseAddress_; }
    uint64_t getRegisterAddress(const std::string& regName) const {
        auto reg = getRegister(regName);
        return reg ? baseAddress_ + reg->getAddressOffset() : 0;
    }

    std::shared_ptr<Register> getRegister(const std::string& name) const {
        auto it = registers_.find(name);
        return it != registers_.end() ? it->second : nullptr;
    }

    const std::vector<std::string>& getInterrupts() const {
        return interrupts_;
    }
};

// Класс для представления всего устройства
class Device : public SvdElement {
public: // private:
    std::string version_;
    std::string series_;
    uint32_t addressUnitBits_;
    uint32_t width_;
    uint32_t size_;
    std::map<std::string, std::shared_ptr<Peripheral>> peripherals_;

public:
    Device()
        : addressUnitBits_(8)
        , width_(32)
        , size_(32) {
    }

    void setVersion(const std::string& version) { version_ = version; }
    void setSeries(const std::string& series) { series_ = series; }
    void setAddressUnitBits(uint32_t bits) { addressUnitBits_ = bits; }

    void addPeripheral(const std::string& name,
        std::shared_ptr<Peripheral> peripheral) {
        peripherals_[name] = peripheral;
    }

    std::shared_ptr<Peripheral> getPeripheral(const std::string& name) const {
        auto it = peripherals_.find(name);
        return it != peripherals_.end() ? it->second : nullptr;
    }

    const std::map<std::string, std::shared_ptr<Peripheral>>& getPeripherals()
        const {
        return peripherals_;
    }

    uint32_t getAddressUnitBits() const { return addressUnitBits_; }
};

} // namespace svd
