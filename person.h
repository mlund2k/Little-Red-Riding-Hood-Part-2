#ifndef _PERSON_H_
#define _PERSON_H_

#include "common.h"

class Person{
    private:
        std::string name;
    public:
        //constructor with name
        Person(const std::string);
        //empty constructor
        Person();

        bool hasName(string name);
        //to access the Person's name
        std::string getName();
        void setName(std::string);
        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
};

#endif