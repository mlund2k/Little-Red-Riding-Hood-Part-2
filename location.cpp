#include "location.h"
using namespace std;

//constructor with place
Location::Location(std::string place) : place(place) {}
//empty constructor
Location::Location(){}
//to access place from outside
string Location::getPlace(){
    return this->place;
}

//returns JSON with place
Json::Value Location::dump2JSON (void){
    Json::Value result { };

    if (this->place != ""){
        result["place"] = this->place;
    }

    return result;
}

//Will initilize the fields of "this" with the correspoding data in the inputted JSON.
//preferably "this" is a new object, or has been completely reset
bool Location::JSON2Object(Json::Value input) {
    if(input.isNull() || input["place"].isNull() || !input["place"].isString())
        return false;
    
    this->place = input["place"].asString();
    return true;
}