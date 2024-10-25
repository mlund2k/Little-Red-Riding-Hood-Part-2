#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "server.h"
#include <iostream>

MyStubServer::MyStubServer(jsonrpc::AbstractServerConnector &connector,
                           jsonrpc::serverVersion_t type)
    : AbstractStubServer(connector, type) {}

Json::Value MyStubServer::move(const std::string& class_id, const Json::Value& json_object, const std::string& object_id) {
    Json::Value result;
    if(class_id == "Person") {
        std::shared_ptr<Person> person = std::make_shared<Person>();
        person->JSON2Object(json_object);
        if(addPerson(object_id, person)) {
            result["succesful"] = true;
            result["person that was moved"] = (*person).dump2JSON();
        }
        else {
            result["error"] = "Cannot move person because it already exists";
            result["succesful"] = false;
        }
    }
    else if(class_id == "Thing") {
        std::shared_ptr<Thing> thing = std::make_shared<Thing>();
        thing->JSON2Object(json_object);
        if(addThing(object_id, thing)) {
            result["succesful"] = true;
            result["thing that was moved"] = (*thing).dump2JSON();
        }
        else {
            result["error"] = "Cannot move thing because it already exists";
            result["succesful"] = false;
        }
    }
    else {
        result["error"] = "Invalid class_id";
        result["succesful"] = false;
    }
    return result;
}
Json::Value MyStubServer::search(const std::string& class_id, const std::string& object_id) {
    Json::Value result;
    std::cout << "search called with " << class_id << " and " << object_id << std::endl;
    result["found"] = false;
    
    return result;
}

bool MyStubServer::addPerson(const std::string& object_id, std::shared_ptr<Person> arg) {
    //if object is null_ptr or arg exists then return error
    if(!arg || personMap.find(object_id) != personMap.end()) {
        return false;
    }

    personMap[object_id] = arg;
    std::cout << "person moved: " << object_id << " " << arg->dump2JSON().toStyledString() << std::endl;
    return true;

}
bool MyStubServer::addThing(const std::string& object_id, std::shared_ptr<Thing> arg) {
    //if object is null_ptr or arg exists then return error
    if(!arg || thingMap.find(object_id) != thingMap.end()) {
        return false;
    }

    thingMap[object_id] = arg;
    std::cout << "thing moved: " << object_id << " " << arg->dump2JSON().toStyledString() << std::endl;
    return true;
}

std::unordered_map <std::string, std::shared_ptr<Person>> MyStubServer::givePersonMap() {
    return this->personMap;
}

std::unordered_map <std::string, std::shared_ptr<Thing>> MyStubServer::giveThingMap() {
    return this->thingMap;
}

Thing MyStubServer::getThing(const std::string & object_id){
    if (thingMap.find(object_id) == thingMap.end()) {
        return Thing();
    }
    return *(this->thingMap[object_id]);
}

Person MyStubServer::getPerson(const std::string & object_id) {
    if (personMap.find(object_id) == personMap.end()) {
        return Person();
    }
    return *(this->personMap[object_id]);
}

bool MyStubServer::hasPerson(const std::string & object_id) {
    return personMap.find(object_id) != personMap.end();
}

bool MyStubServer::hasThing(const std::string & object_id){
    return thingMap.find(object_id) != thingMap.end();
}