#include <memory>
#include <sstream>
#include <Poco/Util/Application.h>
#include <Poco/RegularExpression.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Parser.h>
#include <src/zcommon/zservicelocator.h>
#include <src/zcommon/stringutil.h>
#include <src/zcommon/zdbkey.h>
#include <src/zsession/zsessionservice.h>
#include <src/zdevice/zdevice.h>
#include <src/zdevice/zdevicemanager.h>
#include "zworker.h"


using Poco::Util::Application;
ZWorker::ZWorker() {
}

ZWorker::~ZWorker() {
}

bool ZWorker::initialize() {
    return true;
}

bool ZWorker::start() {
    return true;
}

bool ZWorker::stop() {
    return true;
}

bool ZWorker::cleanup() {
    return true;
}

ZWorkerResult ZWorker::addDevice(const std::string& userToken,
                                 const std::string& deviceName,
                                 const std::string& deviceGroup,
                                 int32_t deviceType) {
    Application& app = Application::instance();
    ZDeviceManager* deviceManager = ZServiceLocator::instance()->get<ZDeviceManager>(ZServiceLocator::ServiceId::DeviceManager);
    int deviceId = deviceManager->createDeviceInfo(deviceName, deviceType, deviceGroup);
    ZDevice::Ptr devices = deviceManager->getDeviceInfo(deviceId);
    return ZWorkerResult(devices);
}

ZWorkerResult ZWorker::deleteDevice(const std::string& userToken, int32_t deviceId) {

}

ZWorkerResult ZWorker::validateUserAuthentication(const std::string& token) {
    ZSessionService* sessionService = ZServiceLocator::instance()->
                get<ZSessionService>(ZServiceLocator::ServiceId::SessionService);
    int32_t userId;
    ZErrorCode errorCode = sessionService->validate_jwt(token, userId);
    if (errorCode != ZErrorCode::OK) {
        return errorCode;
    }

    return ZWorkerResult(Poco::Dynamic::Var(userId));
}
