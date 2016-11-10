#ifndef ZGROUP_H
#define ZGROUP_H

#include <map>
#include <list>
#include <string>
#include <vector>
#include <memory>

class ZGroup
{
public:
    typedef std::shared_ptr<ZGroup> Ptr;
    typedef std::vector<Ptr> List;
    typedef std::map<int32_t, Ptr> Map;
    typedef std::map<std::string, Ptr> MapStr;
    typedef std::vector<int32_t> KeyList;
    typedef std::vector<std::string> KeyListString;
public:
    ZGroup();
    virtual ~ZGroup();
public:
    void setGroupId(int32_t value);
    int32_t getGroupId();

    void setGroupName(const std::string& value);
    std::string getGroupName();

    void setGroupType(int32_t value);
    int32_t getGroupType();

    void setGroupIcon(std::string& value);
    std::string getGroupIcon();

    void setCreateAt(int64_t value);
    int64_t getCreateAt();

    void setUpdateAt(int64_t value);
    int64_t getUpdateAt();
private:
    class Impl;
    std::shared_ptr<Impl> d_ptr;
};

#endif // ZGROUP_H
