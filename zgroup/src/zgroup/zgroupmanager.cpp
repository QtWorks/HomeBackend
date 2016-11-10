#include <sstream>
#include <Poco/Types.h>
#include <Poco/NumberParser.h>
#include <Poco/JSON/Parser.h>
#include <src/zcommon/zservicelocator.h>
#include <src/zcommon/zmemproxy.h>
#include <src/zcommon/zdbkey.h>
#include <src/zdb/zdbproxy.h>
#include <src/zdb/zidgenerator.h>
#include "zgroupmanager.h"

class ZDBKey;
ZGroupManager::ZGroupManager()
{
}

ZGroupManager::~ZGroupManager()
{
}

bool ZGroupManager::initialize() {
    return true;
}

bool ZGroupManager::start() {
    return true;
}

bool ZGroupManager::stop() {
    return true;
}

bool ZGroupManager::cleanup() {
    return true;
}

void ZGroupManager::setGroupDefault() {
    //group: living, bed, bath, other
    std::list<std::string> listGroup = {"living room", "bed room", " bath room", "other room"};
    std::list<std::string> iconGroup = {"livingroom.ico", "bedroom.ico", " bathroom.ico", "otherroom.ico"};
    ZGroup group;
    int typeRoot = 0; //root, can not delete
//    for(int i = 0; i< listGroup.size(); i++) {
//        int32_t id = generator->getNext(ZDBKey::generatorGroups());
//        group.setGroupId(id);
//        group.setGroupName(listGroup[i]);
//        group.setGroupType(typeRoot);
//        group.setGroupIcon(iconGroup[i]);
//        group.setCreateAt(time(NULL));
//        group.setUpdateAt(time(NULL));
//        saveGroupToDB(group);
//    }
}

int32_t ZGroupManager::setGroup(ZGroup group) {
    ZIdGenerator* generator = ZServiceLocator::instance()->get<ZIdGenerator>(ZServiceLocator::ServiceId::IDGenerator);
    int32_t id = generator->getNext(ZDBKey::generatorGroups());
    group.setGroupId(id);
    std::string key = ZDBKey::GroupEntry(id);
    saveGroupToDB(group);
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);

    // create apikey for new device
    dbProxy->SADD(ZDBKey::GroupSet(), {key});
    return id;
}

ZGroup::Ptr ZGroupManager::getGroup(int32_t id) {
    std::string key = ZDBKey::GroupEntry(id);
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    if (dbProxy->HLEN(key) == 0) {
        ZGroup::Ptr empty;
        return empty;
    }

    ZGroup::Ptr group(new ZGroup);
    ZDBProxy::StringList vals = dbProxy->HMGET(key,{"id", "name", "type", "icon", "createdAt", "updatedAt"});

    Poco::Int32 i32Value;
    Poco::UInt64 i64Value;

    if (Poco::NumberParser::tryParse(vals[0], i32Value)) {
        group->setGroupId(i32Value);
    }
    group->setGroupName(vals[1]);
    if (Poco::NumberParser::tryParse(vals[2], i32Value)) {
        group->setGroupType(i32Value);
    }
    group->setGroupIcon(vals[3]);
    if (Poco::NumberParser::tryParseUnsigned64(vals[4], i64Value)) {
        group->setCreateAt(i64Value);
    }
    if (Poco::NumberParser::tryParseUnsigned64(vals[5], i64Value)) {
        group->setUpdateAt(i64Value);
    }

    return group;
}

ZGroupManager::ErrorCode ZGroupManager::removeGroup(int32_t id) {
    ZGroup::Ptr group = getGroup(id);
    if (!group) {
        return ErrorCode::NotFound;
    }

    std::string key = ZDBKey::GroupEntry(id);
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    dbProxy->DEL(key);
    dbProxy->SREM(ZDBKey::DevicesSet(), {key});

    return ErrorCode::OK;
}


void ZGroupManager::saveGroupToDB(ZGroup group) {
    std::string key = ZDBKey::GroupEntry(group.getGroupId());

    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    dbProxy->HMSET(key,{
        { "id", std::to_string(group.getGroupId())},
        { "name", group.getGroupName()},
        { "type", std::to_string(group.getGroupType())},
        { "icon", group.getGroupIcon()},
        { "createdAt", std::to_string(group.getCreateAt())},
        { "updatedAt", std::to_string(group.getUpdateAt())},
    });
}
