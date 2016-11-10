#include <Poco/Util/Application.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/RegularExpression.h>

#include "timerequesthandler.h"
#include "versionrequesthandler.h"
#include "src/zhttp/http.h"
#include "src/zcommon/common.h"
#include "httpdevicerequesthandler.h"
#include "httprequesthandlerfactory.h"

using Poco::Util::Application;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPRequestHandler;
using Poco::RegularExpression;

HTTPRequestHandler* HTTPRequestHandlerFactory::createRequestHandler(const HTTPServerRequest& request) {
    const std::string& requestURI = request.getURI();

    Application& app = Application::instance();
    app.logger().information("Request URI " + requestURI);
    std::vector<std::string> v_Request = HTTPRequestHandlerFactory::split(requestURI, '?');
    std::string path = "";
    std::string params = "";
    if(v_Request.size() == 2){
        path = v_Request[0];
        params = v_Request[1];
    }

    if (HTTPDeviceRequestHandler::CanHandleRequest(requestURI, request.getMethod())) {
        return new HTTPDeviceRequestHandler(requestURI);
    }

    if (requestURI == "/time") {
        return new TimeRequestHandler(_format);
    } else if (requestURI == "/version") {
        return new VersionRequestHandler();
    } else {
        return 0;
    }
}

std::vector<std::string> HTTPRequestHandlerFactory::split(const std::string& str, char delimiter) {
    std::vector<std::string> vector_result;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while (getline(ss, tok, delimiter)) {
        vector_result.push_back(tok);
    }

    return vector_result;
}

std::map<std::string, std::string> HTTPRequestHandlerFactory::params(const std::string& str) {
    std::map<std::string, std::string> map_result;
    std::vector<std::string> param = HTTPRequestHandlerFactory::split(str, '&');
    for(int i = 0; i < param.size(); i++) {
        std::vector<std::string> items = HTTPRequestHandlerFactory::split(param[i], '=');
        map_result[items[0]] = items[1];
    }
    return map_result;
}
