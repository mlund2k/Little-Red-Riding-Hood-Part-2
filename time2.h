#ifndef _TIME2_H_
#define _TIME2_H_

#include "common.h"

class Time{
    private:
        int order;
    public:
        //constructor with order
        Time(int);
        //default constructor
        Time();
        //Accessor function
        int getTime();

        virtual Json::Value dump2JSON();
        virtual bool JSON2Object(Json::Value);
};

#endif