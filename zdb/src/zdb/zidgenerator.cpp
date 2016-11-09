#include <string>
#include <sstream>
#include <algorithm>
#include <Poco/UUID.h>
#include <Poco/UUIDGenerator.h>
#include <src/zcommon/zservicelocator.h>
#include <src/zdb/zdbproxy.h>
#include "zidgenerator.h"

ZIdGenerator::ZIdGenerator()
{
}

int32_t ZIdGenerator::getNext(const std::string& collectionName) {
    std::stringstream key;
    key << "counter:id:" << collectionName;
    ZDBProxy* dbProxy = ZServiceLocator::instance()->get<ZDBProxy>(ZServiceLocator::ServiceId::DBProxy);
    int64_t retValue = dbProxy->INCR(key.str());
    return retValue;
}

std::string ZIdGenerator::createUuid() const {
    std::string uuid = Poco::UUIDGenerator::defaultGenerator().create().toString();
    std::transform(uuid.begin(), uuid.end(), uuid.begin(), ::tolower);
    return uuid;
}
