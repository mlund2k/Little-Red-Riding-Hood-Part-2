#pragma once
//abstractstubserver.h is created by using make
#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <unordered_map>
#include "person.h"
#include "thing.h"

class MyStubServer : public AbstractStubServer {

private:
    std::unordered_map <std::string, std::shared_ptr<Person>> personMap;
    std::unordered_map <std::string, std::shared_ptr<Thing>> thingMap;
public:
    MyStubServer(jsonrpc::AbstractServerConnector &connector, jsonrpc::serverVersion_t type);
    Json::Value move(const std::string& class_id, const Json::Value& json_object, const std::string& object_id) override;
    Json::Value search(const std::string& class_id, const std::string& object_id) override;

    bool addPerson(const std::string& object_id, std::shared_ptr<Person> arg);
    bool addThing(const std::string& object_id, std::shared_ptr<Thing> arg);

    std::unordered_map<std::string, std::shared_ptr<Person>> givePersonMap();
    std::unordered_map<std::string, std::shared_ptr<Thing>> giveThingMap();

    Thing getThing(const std::string & object_id);
    Person getPerson(const std::string & object_id);

    bool hasThing(const std::string & object_id); 
    bool hasPerson(const std::string & object_id); 
};