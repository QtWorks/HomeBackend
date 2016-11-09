#ifndef ZDBKEY_H
#define ZDBKEY_H

#include <string>

class ZDBKey {
public:
    //KEY generator
    static std::string generatorUsers();
    static std::string generatorDevices();
    static std::string apiKey();

    static std::string UserSet();
    static std::string UserApiKey();
    static std::string UserEmail();
    static std::string UserEntry(int32_t userId);
    static std::string UserSession(int32_t userId);

    static std::string DevicesSet();
    static std::string DevicesApiKey();
    static std::string DevicesFactory();
    static std::string DeviceEntry(int32_t deviceId);
};

#endif // ZDBKEY_H
