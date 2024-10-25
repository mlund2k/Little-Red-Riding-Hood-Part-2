#ifndef _Location_H_
#define _Location_H_

#include "common.h"
using namespace std;

class Location{
    private:
        std::string place;
    public:
        //constructor with string place
        Location(string);
        //empty constructor
        Location();
        //to access place from outside
        string getPlace();
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
};

#endif