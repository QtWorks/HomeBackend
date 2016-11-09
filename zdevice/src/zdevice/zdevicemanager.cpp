#include <sstream>
#include <Poco/Types.h>
#include <Poco/NumberParser.h>
#include <Poco/JSON/Parser.h>
#include <src/zcommon/zservicelocator.h>
#include <src/zcommon/zmemproxy.h>
#include <src/zcommon/zdbkey.h>
#include <src/zdb/zdbproxy.h>
#include <src/zdb/zidgenerator.h>
#include "zdevicemanager.h"


class ZDBKey;
ZDeviceManager::ZDeviceManager()
{
}

ZDeviceManager::~ZDeviceManager()
{
}

bool ZDeviceManager::initialize() {
    return true;
}

bool ZDeviceManager::start() {
    return true;
}

bool ZDeviceManager::stop() {
    return true;
}

bool ZDeviceManager::cleanup() {
    return true;
}

int32_t ZDeviceManager::createDeviceInfo(const std::string& deviceName, int32_t deviceType, const std::string& deviceGroup) {
    ZDevice deviceInfo;
    deviceInfo.setDeviceName(deviceName);
    deviceInfo.setDeviceType(deviceType);
    deviceInfo.setDeviceGroup(deviceGroup);
    deviceInfo.setCreatedAt(time(NULL));
    deviceInfo.setUpdatedAt(time(NULL));

    ZIdGenerator* generator = ZServiceLocator::instance()->get<ZIdGenerator>(ZServiceLocator::ServiceId::IDGenerator);
    int32_t deviceId = generator->getNext(ZDBKey::generatorDevices());
    deviceInfo.setDeviceId(deviceId);

    std::string key = ZDBKey::DeviceEntry(deviceId);

    saveDeviceInfoToDB(deviceInfo);
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);

    // create apikey for new device
    std::string uuid_str = generator->createUuid();
    dbProxy->HSET(key, ZDBKey::apiKey(), uuid_str);
    dbProxy->HSET(ZDBKey::DevicesApiKey(), uuid_str, key);
    dbProxy->SADD(ZDBKey::DevicesSet(), {key});
    return deviceId;
}

ZDevice::Ptr ZDeviceManager::getDeviceInfo(int32_t deviceId) {
    std::string key = ZDBKey::DeviceEntry(deviceId);
    return getDeviceInfo(key);
}

ZDevice::Ptr ZDeviceManager::getDeviceInfo(const std::string& deviceKey) {
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    if (dbProxy->HLEN(deviceKey) == 0) {
        ZDevice::Ptr empty;
        return empty;
    }

    ZDevice::Ptr device(new ZDevice);
    ZDBProxy::StringList vals = dbProxy->HMGET(deviceKey,{"name", "createdAt", "updatedAt", "id", "type", "group", "apikey"});
    device->setDeviceName(vals[0]);

    Poco::UInt64 i64Value;
    if (Poco::NumberParser::tryParseUnsigned64(vals[1], i64Value)) {
        device->setCreatedAt(i64Value);
    }
    if (Poco::NumberParser::tryParseUnsigned64(vals[2], i64Value)) {
        device->setUpdatedAt(i64Value);
    }
    Poco::Int32 i32Value;
    if (Poco::NumberParser::tryParse(vals[3], i32Value)) {
        device->setDeviceId(i32Value);
    }
    if (Poco::NumberParser::tryParse(vals[4], i32Value)) {
        device->setDeviceType(i32Value);
    }
    device->setDeviceGroup(vals[5]);
    device->setApiKey(vals[6]);
    return device;
}

ZDeviceManager::ErrorCode ZDeviceManager::removeDeviceInfo(int32_t deviceId) {
    ZDevice::Ptr deviceInfo = getDeviceInfo(deviceId);
    if (!deviceInfo) {
        return ErrorCode::NotFound;
    }

    std::string key = ZDBKey::DeviceEntry(deviceId);
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    std::string uuid = dbProxy->HGET(key, ZDBKey::apiKey());
    dbProxy->DEL(key);

    dbProxy->SREM(ZDBKey::DevicesSet(), {
        key});
    dbProxy->HDEL(ZDBKey::DevicesApiKey(), uuid);

    return ErrorCode::OK;
}

void ZDeviceManager::saveDeviceInfoToDB(const ZDevice& deviceInfo) {
    std::string key = ZDBKey::DeviceEntry(deviceInfo.deviceId());

    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    dbProxy->HMSET(key,{
        { "id", std::to_string(deviceInfo.deviceId())},
        { "name", deviceInfo.deviceName()},
        { "type", std::to_string(deviceInfo.deviceType())},
        { "group", deviceInfo.deviceGroup()},
        { "createdAt", std::to_string(deviceInfo.createdAt())},
        { "updatedAt", std::to_string(deviceInfo.updatedAt())},
    });
}

