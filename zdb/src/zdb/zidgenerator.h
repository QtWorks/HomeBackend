#ifndef ZIDGENERATOR_H
#define ZIDGENERATOR_H

#include <string>
#include <map>
class ZIdGenerator {
public:
    ZIdGenerator();
public:
    int32_t getNext(const std::string& collectionName);
    std::string createUuid() const;
};

#endif // ZIDGENERATOR_H
