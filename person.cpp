#include "person.h"
using namespace std;

//constructor with person's name
Person::Person(const string name) : name(name) {}
//empty constructor
Person::Person(){}

//to access Person object's name
string Person::getName(){
    return this->name;
}

void Person::setName(std::string name) {
    this->name = name;
}

//returns JSON with person's name
Json::Value Person::dump2JSON (void){
    Json::Value result {};

    if (this->name != ""){
        result["name"] = this->name;
    }

    return result;
}



//Will initilize the fields of "this" with the correspoding data in the inputted JSON.
//preferably "this" is a new object, or has been completely reset
bool Person::JSON2Object(Json::Value input) {
    if(input.isNull() || input["name"].isNull() || !input["name"].isString()) 
        return false;

    this->name = input["name"].asString();
    return true;
}