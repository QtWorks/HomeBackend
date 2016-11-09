#include <stdint.h>
#include <sstream>
#include <Poco/RegularExpression.h>
#include <Poco/Util/Application.h>
#include <Poco/Dynamic/Struct.h>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Parser.h>
#include <Poco/NumberParser.h>
#include <src/zcommon/zservicelocator.h>
#include <src/zsession/zsessionservice.h>
#include "httpdevicerequesthandler.h"

using namespace Poco::JSON;
using namespace Poco::Dynamic;
using Poco::DynamicStruct;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;

void ReportError::reportTo(HttpApiError error, Poco::JSON::Object::Ptr& responseData) {
    responseData->set("error", static_cast<int> (error));
}

HTTPDeviceRequestHandler::HTTPDeviceRequestHandler(const std::string& path, const std::map<std::string, std::string>& params) :
    HTTPRequestBaseHandler(path),
    _params(params) {
}

HTTPDeviceRequestHandler::~HTTPDeviceRequestHandler() {

}

bool HTTPDeviceRequestHandler::CanHandleRequest(const std::string& path, const std::string& method) {
    if (path.compare("/control") == 0) {
        return true;
    }
    return false;
}

void HTTPDeviceRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
    Application& app = Application::instance();
    app.logger().information("Request from " + request.clientAddress().toString());
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    Poco::JSON::Object::Ptr responseData = new Poco::JSON::Object;

    if (requestPath().compare("/control") == 0) {
        handleControlDevice(request, responseData);
    }

    std::ostream& ostr = response.send();
    Poco::JSON::Stringifier::stringify(responseData, ostr);
}

Poco::Dynamic::Var HTTPDeviceRequestHandler::handleControlDevice(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) {
    using namespace Poco::JSON;
    using namespace Poco::Dynamic;
    Application& app = Application::instance();
    Parser parser;
    try {
        if(_params.size() <= 0)
        {
            ReportError::reportTo(HttpApiError::ParameterMissing, responseData);
            return responseData;
        }

        std::string deviceAddress = _params["deviceAddress"];
        std::string deviceId = _params["deviceId"];
        std::string control = _params["control"];


    } catch (Poco::Exception &ex) {
        app.logger().error("Exception while processing message: %s", ex.displayText());
        ReportError::reportTo(HttpApiError::Unknown, responseData);
        return responseData;
    }
    return responseData;
}


void HTTPDeviceRequestHandler::fillJsonResponseData(const std::string& msg, Poco::JSON::Object::Ptr& responseData) {

}
