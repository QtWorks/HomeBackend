#ifndef TCPSERVERHANDLERFACTORY_H
#define TCPSERVERHANDLERFACTORY_H
#include <iostream>
#include <memory>
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/Socket.h"

class TCPServerHandlerFactory : public Poco::Net::TCPServerConnection
{
public:
    TCPServerHandlerFactory(const Poco::Net::StreamSocket& s);
    void run();
};

#endif // TCPSERVERHANDLERFACTORY_H
