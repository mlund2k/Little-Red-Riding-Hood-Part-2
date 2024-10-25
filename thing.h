#ifndef _THING_H_
#define _THING_H_

#include "common.h"
#include "person.h"

class Thing{
    protected:
        std::string thing;
        Person owner;
        Person giver;
    public:
        //constructors with either thing, thing and owner, or all fields
        Thing(std::string, Person, Person);
        Thing(std::string, Person);
        Thing(std::string);
        Thing();

        //accessor methods
        std::string getThing();
        Person getOwner();
        Person getGiver();
        
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
};

#endif