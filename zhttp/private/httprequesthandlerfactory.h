#ifndef HTTPREQUESTHANDLERFACTORY_H
#define HTTPREQUESTHANDLERFACTORY_H

#include <vector>
#include <string>
#include <list>
#include <map>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>

class Http;
class Common;

class HTTPRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
    HTTPRequestHandlerFactory(const std::string& format, const std::string& apiPrefix, Http* api):
            _format(format),
            _apiPrefix(apiPrefix),
            _api(api)
    {
    }

public:
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::map<std::string, std::string> params(const std::string& str);
private:
    std::string _format;
    std::string _apiPrefix;
    Http* _api;
};
#endif // HTTPREQUESTHANDLERFACTORY_H
