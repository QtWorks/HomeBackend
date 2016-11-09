#ifndef HTTPDEVICEREQUESTHANDLER_H
#define HTTPDEVICEREQUESTHANDLER_H


#include <memory>
#include <map>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <include/zcommon/errorcode.h>
#include <src/zhttp/httprequestbasehandler.h>

class HTTPDeviceRequestHandler : public HTTPRequestBaseHandler
{
public:
    HTTPDeviceRequestHandler(const std::string& path, const std::map<std::string, std::string>& params);
    virtual ~HTTPDeviceRequestHandler();
public:
    static bool CanHandleRequest(const std::string& path, const std::string& method);
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    Poco::Dynamic::Var handleControlDevice(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData);
public:
    void fillJsonResponseData(const std::string& msg, Poco::JSON::Object::Ptr& responseData);
private:
    std::map<std::string, std::string> _params;
};

#endif // HTTPDEVICEREQUESTHANDLER_H
