#ifndef HTTPREQUESTBASEHANDLER_H
#define HTTPREQUESTBASEHANDLER_H
#include <memory>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <include/zcommon/errorcode.h>

enum class HttpApiError {
    InvalidRequest = (int) ZErrorCode::APIHTTP_Start,
    ParameterMissing,
    AuthenticationMissing,
    NotImplemented,
    Unknown = 1999
};

class ReportError {
public:
    static void reportTo(HttpApiError error, Poco::JSON::Object::Ptr& responseData);
};

class HTTPRequestBaseHandler : public Poco::Net::HTTPRequestHandler {
public:
    HTTPRequestBaseHandler(const std::string& path);
    virtual ~HTTPRequestBaseHandler();
protected:
    Poco::Dynamic::Var parseServerRequest(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData);
    Poco::Dynamic::Var parseRequest(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData);

    const std::string& requestPath() const {
        return _requestPath;
    }
    int32_t getAuthenticatedUser(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) const;
    std::string getAuthenticationToken(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) const;   
private:
    std::string _requestPath;
};

#endif // HTTPREQUESTBASEHANDLER_H
