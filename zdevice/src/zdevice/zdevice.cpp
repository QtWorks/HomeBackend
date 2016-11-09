#include "zdevice.h"

class ZDevice::Impl {
public:
    int32_t deviceId;
    std::string deviceName;
    int32_t deviceType;
    std::string deviceGroup;
    uint64_t createdAt;
    uint64_t updatedAt;
    std::string apiKey;
};

ZDevice::ZDevice() : d_ptr(new Impl)
{
}

ZDevice::~ZDevice()
{
}

bool ZDevice::operator ==(const ZDevice& other) {
    return d_ptr->deviceId == other.deviceId() &&
            d_ptr->deviceName == other.deviceName() &&
            d_ptr->deviceType == other.deviceType() &&
            d_ptr->deviceGroup == other.deviceGroup() &&
            d_ptr->createdAt == other.createdAt() &&
            d_ptr->apiKey == other.apiKey();
}

bool ZDevice::operator !=(const ZDevice& other) {
    return d_ptr->deviceId != other.deviceId() ||
            d_ptr->deviceName != other.deviceName() ||
            d_ptr->deviceType != other.deviceType() ||
            d_ptr->deviceGroup != other.deviceGroup() ||
            d_ptr->createdAt != other.createdAt() ||
            d_ptr->apiKey != other.apiKey();
}

void ZDevice::setApiKey(const std::string& value) {
    d_ptr->apiKey = value;
}

std::string ZDevice::apiKey() const {
    return d_ptr->apiKey;
}

void ZDevice::setUpdatedAt(const uint64_t value) {
    d_ptr->updatedAt = value;
}

uint64_t ZDevice::updatedAt() const {
    return d_ptr->updatedAt;
}

void ZDevice::setCreatedAt(const uint64_t value) {
    d_ptr->createdAt = value;
}

uint64_t ZDevice::createdAt() const {
    return d_ptr->createdAt;
}

void ZDevice::setDeviceGroup(const std::string& value) {
    d_ptr->deviceGroup = value;
}

std::string ZDevice::deviceGroup() const {
    return d_ptr->deviceGroup;
}

void ZDevice::setDeviceType(const int32_t value) {
    d_ptr->deviceType = value;
}

int32_t ZDevice::deviceType() const {
    return d_ptr->deviceType;
}

void ZDevice::setDeviceName(const std::string& value) {
    d_ptr->deviceName = value;
}

std::string ZDevice::deviceName() const {
    return d_ptr->deviceName;
}

void ZDevice::setDeviceId(const int32_t value) {
    d_ptr->deviceId = value;
}

int32_t ZDevice::deviceId() const {
    return d_ptr->deviceId;
}

