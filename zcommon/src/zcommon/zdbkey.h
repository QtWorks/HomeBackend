#ifndef ZDBKEY_H
#define ZDBKEY_H

#include <string>
#include <sstream>
class ZDBKey {
public:
    //KEY generator
    static std::string generatorUsers() {
        return "users";
    }
    static std::string generatorDevices() {
        return "devices";
    }
    static std::string apiKey() {
        return "apikey";
    }

    static std::string UserSet() {
        return "users:set";
    }
    static std::string UserApiKey() {
        return "users:lookup:apikey";
    }
    static std::string UserEmail() {
        return "users:lookup:email";
    }
    static std::string UserEntry(int32_t userId) {
        std::stringstream stream;
        stream << "users:" << userId;
        return stream.str();
    }
    static std::string UserSession(int32_t userId) {
        std::stringstream stream;
        stream << "users:" << userId << ":sessions";
        return stream.str();
    }
    static std::string DevicesSet() {
        return "devices:set";
    }
    static std::string DevicesApiKey() {
        return "devices:lookup:apikey";
    }
    static std::string DevicesFactory() {
        return "factorydevices:set";
    }
    static std::string DeviceEntry(int32_t deviceId) {
        std::stringstream stream;
        stream << "devices:" << deviceId;
        return stream.str();
    }
};

#endif // ZDBKEY_H
