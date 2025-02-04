/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_HW5SERVER_H_
#define JSONRPC_CPP_STUB_HW5SERVER_H_

#include <jsonrpccpp/server.h>

class hw5Server : public jsonrpc::AbstractServer<hw5Server>
{
    public:
        hw5Server(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<hw5Server>(conn, type)
        {
            this->bindAndAddMethod(jsonrpc::Procedure("dump2JSON", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "action",jsonrpc::JSON_STRING,"arguments",jsonrpc::JSON_STRING,"class_id",jsonrpc::JSON_STRING,"host_url",jsonrpc::JSON_STRING,"object_id",jsonrpc::JSON_STRING, NULL), &hw5Server::dump2JSONI);
        }

        inline virtual void dump2JSONI(const Json::Value &request, Json::Value &response)
        {
            response = this->dump2JSON(request["action"].asString(), request["arguments"].asString(), request["class_id"].asString(), request["host_url"].asString(), request["object_id"].asString());
        }
        virtual Json::Value dump2JSON(const std::string& action, const std::string& arguments, const std::string& class_id, const std::string& host_url, const std::string& object_id) = 0;
};

#endif //JSONRPC_CPP_STUB_HW5SERVER_H_
