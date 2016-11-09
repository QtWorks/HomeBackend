#include <iostream>
#include <Poco/Util/Application.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/IntValidator.h>
#include <Poco/Util/HelpFormatter.h>

#include <src/zcommon/zservicelocator.h>
#include <src/zcommon/zmemproxy.h>
#include <src/zcommon/zmemproxylocal.h>
#include <src/zsession/zsessionservice.h>
#include <src/zhttp/http.h>
//#include <src/zsocket/zsocket.h>
#include <src/zdevice/zdevicemanager.h>
#include <src/zdb/zdbproxy.h>
#include <src/zdb/zidgenerator.h>
#include <src/zworker/zworker.h>

#include "serverapp.h"
class ServerApp::Impl {
public:
    Impl() :
    memcachedProxy(new ZMemProxyLocal()),
    sessionService(new ZSessionService()) {
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::MemCacheProxy, memcachedProxy.get());
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::SessionService, sessionService.get());
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::DBProxy, dbProxy.get());
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::DeviceManager, deviceManager.get());
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::IDGenerator, idGen.get());
        ZServiceLocator::instance()->registerService(ZServiceLocator::ServiceId::Worker, woker.get());

        services.push_back(new Http());
//        services.push_back(new ZSocket());
        services.push_back(deviceManager);
        services.push_back(woker);
    }
public:
    Poco::SharedPtr<ZMemProxy> memcachedProxy;
    Poco::SharedPtr<ZSessionService> sessionService;
    Poco::SharedPtr<ZDBProxy> dbProxy;
    Poco::SharedPtr<ZDeviceManager> deviceManager;
    Poco::SharedPtr<ZIdGenerator> idGen;
    Poco::SharedPtr<ZWorker> woker;

    typedef Poco::SharedPtr<ZServiceInterface> ZServiceInterfacePtr;
    typedef std::vector<ZServiceInterfacePtr> ZServiceList;
    typedef std::vector<ZServiceInterfacePtr>::iterator ServiceIterator;
    typedef std::vector<ZServiceInterfacePtr>::reverse_iterator ServiceReverseIterator;
    std::vector<ZServiceInterfacePtr> services;
};

ServerApp::ServerApp()
: _helpRequested(false) {
}

ServerApp::~ServerApp() {

}

void ServerApp::initialize(Application& self) {
    loadConfiguration(); // load default configuration files, if present
    ServerApplication::initialize(self);
}

void ServerApp::uninitialize() {
    ServerApplication::uninitialize();
}

void ServerApp::defineOptions(Poco::Util::OptionSet& options) {
    ServerApplication::defineOptions(options);

    options.addOption(
            Poco::Util::Option("help", "h", "display help information on command line arguments")
            .required(false)
            .repeatable(false));

    options.addOption(
        Poco::Util::Option("port", "p", "Set http api listening port")
            .required(false)
            .argument("value")
            .validator(new Poco::Util::IntValidator(1000, 65535))
            .binding("api.http.port"));
}

void ServerApp::handleOption(const std::string& name, const std::string& value) {
    ServerApplication::handleOption(name, value);

    if (name == "help") {
        _helpRequested = true;
    }
}

void ServerApp::displayHelp() {
    Poco::Util::HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A server application that serves the current date and time.");
    helpFormatter.format(std::cout);
}

int ServerApp::main(const std::vector<std::string>& args) {
    (void) args;
    if (_helpRequested) {
        displayHelp();
    } else {
        d_ptr = new Impl();


        for (Impl::ServiceIterator iter = d_ptr->services.begin();
                iter != d_ptr->services.end();
                iter++) {
            (*iter)->initialize();
        }

        for (Impl::ServiceIterator iter = d_ptr->services.begin();
                iter != d_ptr->services.end();
                iter++) {
            (*iter)->start();
        }

        // get parameters from configuration file
        //        _messageBus = new iot::messagebus::MessageBus();
        //        _messageBus->initialize(config());
        //
        //        _service = iot::service::ServiceFactory::createService();
        //        _service->setLogger(logger());
        //        _service->initialize(_messageBus);
        //        _service->start();
        // wait for CTRL-C or kill
        logger().information("Service is started");
        waitForTerminationRequest();

        // Stop the TCPServer
        //        _service->stop();
        for (Impl::ServiceReverseIterator riter = d_ptr->services.rbegin();
                riter != d_ptr->services.rend();
                riter++) {
            (*riter)->stop();
        }

        for (Impl::ServiceReverseIterator riter = d_ptr->services.rbegin();
                riter != d_ptr->services.rend();
                riter++) {
            (*riter)->cleanup();
        }
        logger().information("Service is stoped");
    }
    return Application::EXIT_OK;
}
