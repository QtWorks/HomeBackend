#include "zsocket.h"

#include <Poco/Util/Application.h>
#include <Poco/Util/LayeredConfiguration.h>
#include <Poco/Timestamp.h>
#include <Poco/DateTimeFormat.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/ThreadPool.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/TCPServer.h>
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/Socket.h"

#include "tcpserverhandlerfactory.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerParams;
using Poco::Net::TCPServer;
using Poco::ThreadPool;
using Poco::DateTimeFormat;
using Poco::Timestamp;
using Poco::DateTimeFormatter;

using Poco::Util::Application;
using Poco::Util::LayeredConfiguration;

class ZSocket::Impl {
public:

};

ZSocket::ZSocket() : d_ptr(new Impl)
{
}

ZSocket::~ZSocket()
{
}

bool ZSocket::initialize() {
    LayeredConfiguration& config = Application::instance().config();
    // get parameters from configuration file
    std::string host = config.getString("api.socket.host", "localhost");
    unsigned short port = (unsigned short) config.getInt("api.socket.port", 9981);
    int maxQueued  = config.getInt("api.socket.maxQueued", 4);
    int maxThreads = config.getInt("api.socket.maxThreads", 4);
    ThreadPool::defaultPool().addCapacity(maxThreads);

    Poco::Net::ServerSocket svs(port);
    Poco::Net::TCPServerParams* pParams = new Poco::Net::TCPServerParams();
    pParams->setMaxThreads(maxThreads);
    pParams->setMaxQueued(maxQueued);
    pParams->setThreadIdleTime(100);
    Poco::Net::TCPServer tcpServer(new Poco::Net::TCPServerConnectionFactoryImpl<TCPServerHandlerFactory>(), svs, pParams);
    tcpServer.start();
//    while(1);
    return true;
}

bool ZSocket::start() {
    // start the TCPServer
    return true;
}

bool ZSocket::stop() {
    // Stop the TCPServer
    return true;
}

bool ZSocket::cleanup() {
    return true;
}


