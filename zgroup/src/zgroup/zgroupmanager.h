#ifndef ZGROUPMANAGER_H
#define ZGROUPMANAGER_H

#include <string>
#include <src/zgroup/zgroup.h>
#include <include/zcommon/zserviceinterface.h>
class ZGroupManager : public ZServiceInterface
{
public:
    ZGroupManager();
    virtual ~ZGroupManager();
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
    virtual void setGroupDefault();
    virtual int32_t setGroup(ZGroup group);
    virtual ZGroup::Ptr getGroup(int32_t id);
    virtual ErrorCode removeGroup(int32_t id);

private:
    void saveGroupToDB(ZGroup group);
};

#endif // ZGROUPMANAGER_H
