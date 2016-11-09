#ifndef ZDEVICEMANAGER_H
#define ZDEVICEMANAGER_H

#include <string>
#include <src/zdevice/zdevice.h>
#include <include/zcommon/zserviceinterface.h>
class ZDeviceManager : public ZServiceInterface
{
public:
    ZDeviceManager();
    virtual ~ZDeviceManager();
public:
    virtual bool initialize();
    virtual bool start();
    virtual bool stop();
    virtual bool cleanup();
public:
    enum class ErrorCode : int32_t {
        OK = 0,
        NotFound,
        InvalidInput
    };
public:
    virtual int32_t createDeviceInfo(const std::string& deviceName, int32_t deviceType, const std::string& deviceGroup);
    virtual ZDevice::Ptr getDeviceInfo(int32_t deviceId);
    virtual ZDevice::Ptr getDeviceInfo(const std::string& deviceKey);
    virtual ErrorCode removeDeviceInfo(int32_t deviceId);
private:
    void saveDeviceInfoToDB(const ZDevice& deviceInfo);
};

#endif // ZDEVICEMANAGER_H
