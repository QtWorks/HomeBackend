#include "zgroup.h"

class ZGroup::Impl {
public:
    int32_t id;
    std::string name;
    std::string icon;
    int32_t type;
    int64_t createdAt;
    int64_t updateAt;
};

ZGroup::ZGroup() : d_ptr(new Impl)
{
}

ZGroup::~ZGroup()
{
}

void ZGroup::setGroupId(int32_t value) {
    d_ptr->id = value;
}
int32_t ZGroup::getGroupId() {
    return d_ptr->id;
}

void ZGroup::setGroupName(const std::string& value) {
    d_ptr->name = value;
}
std::string ZGroup::getGroupName() {
    return d_ptr->name;
}

void ZGroup::setGroupType(int32_t value) {
    d_ptr->type = value;
}
int32_t ZGroup::getGroupType() {
    return d_ptr->type;
}

void ZGroup::setGroupIcon(std::string& value) {
    d_ptr->icon = value;
}
std::string ZGroup::getGroupIcon() {
    return d_ptr->icon;
}

void ZGroup::setCreateAt(int64_t value) {
    d_ptr->createdAt = value;
}
int64_t ZGroup::getCreateAt() {
    return d_ptr->createdAt;
}

void ZGroup::setUpdateAt(int64_t value) {
    d_ptr->updateAt = value;
}
int64_t ZGroup::getUpdateAt() {
    return d_ptr->updateAt;
}
