#ifndef ZDEVICE_H
#define ZDEVICE_H
#include <map>
#include <list>
#include <string>
#include <vector>
#include <memory>
class ZDevice
{
public:
    typedef std::shared_ptr<ZDevice> Ptr;
    typedef std::vector<Ptr> List;
    typedef std::map<int32_t, Ptr> Map;
    typedef std::map<std::string, Ptr> MapStr;
    typedef std::vector<int32_t> KeyList;
    typedef std::vector<std::string> KeyListString;
public:
    ZDevice();
    virtual ~ZDevice();
public:
    bool operator ==(const ZDevice& other);
    bool operator !=(const ZDevice& other);

    void setApiKey(const std::string& value);
    std::string apiKey() const;

    void setUpdatedAt(const uint64_t value);
    uint64_t updatedAt() const;

    void setCreatedAt(const uint64_t value);
    uint64_t createdAt() const;

    void setDeviceGroup(const std::string& value);
    std::string deviceGroup() const;

    void setDeviceType(const int32_t value);
    int32_t deviceType() const;

    void setDeviceName(const std::string& value);
    std::string deviceName() const;

    void setDeviceId(const int32_t value);
    int32_t deviceId() const;
private:
    class Impl;
    std::shared_ptr<Impl> d_ptr;
};

#endif // ZDEVICE_H
