#include "jsonrpc.h"
/*
output_json will have person, 
a string showing what the Location is
a string showing where it came from
a boolean showing whether or not it was succesful

*/

void move(Json::Value person, std::string origin, std::string location) {
    Json::Value output_json;
    output_json["person"] = person;
    output_json["origin"] = origin;
    output_json["location"] = location;
    output_json["succesful_status"] = false;
    myJSON2File("rpc.json", &output_json);
}

void move(Json::Value person, std::string origin, Location location) {
    move(person, origin, location.getPlace());
}
void move(Json::Value person, Location origin, Location location) {
    move(person, origin.getPlace(), location.getPlace());
}

//returns a boolean true if succesfully found, false if otherwise
//if corresponding json was found then output_json was overriden with that json
bool search(Json::Value & result, const std::string & origin, const std::string & location) {
    myFile2JSON("rpc.json", &result);
    if
    (
        result.isNull() || 
        result["location"].isNull() ||
        !result["location"].isString() ||
        result["origin"].isNull() ||
        !result["origin"].isString() ||
        result["person"].isNull() ||
        !result["person"].isObject() ||
        result["succesful_status"].isNull() ||
        !result["succesful_status"].isBool()
    ) {
        return false;
    }

    if (result["location"] != location || result["origin"] != origin) {
        return false;
    }
    
    return true;
}

bool wasFound (const std::string & origin, const std::string & location) {
    Json::Value result;
    if(!search(result, origin, location)) {
        return false;
    }

    return result["succesful_status"].asBool();
}