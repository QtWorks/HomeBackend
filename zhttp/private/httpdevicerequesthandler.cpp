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

HTTPDeviceRequestHandler::HTTPDeviceRequestHandler(const std::string& path) :
    HTTPRequestBaseHandler(path)
{
}

HTTPDeviceRequestHandler::~HTTPDeviceRequestHandler() {

}

bool HTTPDeviceRequestHandler::CanHandleRequest(const std::string& path, const std::string& method) {
    if (path.compare("/control") == 0) {
        return true;
    }

    if (path.compare("/add") == 0) {
        return true;
    }

    if (path.compare("/remove") == 0) {
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

    if (requestPath().compare("/add") == 0) {
        handleAddDevice(request, responseData);
    }

    if (requestPath().compare("/remove") == 0) {
        handleRemoveDevice(request, responseData);
    }

    std::ostream& ostr = response.send();
    Poco::JSON::Stringifier::stringify(responseData, ostr);
}

Poco::Dynamic::Var HTTPDeviceRequestHandler::handleControlDevice(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) {
    using namespace Poco::JSON;
    using namespace Poco::Dynamic;
    Application& app = Application::instance();
    try {
        Var result = parseServerRequest(request, responseData);
        if (result.isEmpty()) {
            ReportError::reportTo(HttpApiError::ParameterMissing, responseData);
            return responseData;
        }
        Object::Ptr object = result.extract<Object::Ptr>();

        std::string address = object->optValue("address", std::string());
        int id = object->optValue("id", -1);
        int control = object->optValue("control", -1);
        fillJsonResponseData(address, id, control, responseData);
    } catch (Poco::Exception &ex) {
        app.logger().error("Exception while processing message: %s", ex.displayText());
        ReportError::reportTo(HttpApiError::Unknown, responseData);
        return responseData;
    }
    return responseData;
}

Poco::Dynamic::Var HTTPDeviceRequestHandler::handleAddDevice(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) {
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

        std::string address = _params["address"];
        std::string id = _params["id"];
        std::string control = _params["control"];


    } catch (Poco::Exception &ex) {
        app.logger().error("Exception while processing message: %s", ex.displayText());
        ReportError::reportTo(HttpApiError::Unknown, responseData);
        return responseData;
    }
    return responseData;
}

Poco::Dynamic::Var HTTPDeviceRequestHandler::handleRemoveDevice(Poco::Net::HTTPServerRequest& request, Poco::JSON::Object::Ptr& responseData) {
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

        std::string address = _params["address"];
        std::string id = _params["id"];
        std::string control = _params["control"];


    } catch (Poco::Exception &ex) {
        app.logger().error("Exception while processing message: %s", ex.displayText());
        ReportError::reportTo(HttpApiError::Unknown, responseData);
        return responseData;
    }
    return responseData;
}


void HTTPDeviceRequestHandler::fillJsonResponseData(const std::string& address,
                                                    int id,
                                                    int control,
                                                    Poco::JSON::Object::Ptr& responseData) {
    responseData->set("error", "0");
    responseData->set("adress", address);
    responseData->set("id", id);
    responseData->set("control", control);
}
