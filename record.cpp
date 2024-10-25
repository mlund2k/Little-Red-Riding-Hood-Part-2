#include "record.h"
//constructor with no lists for arguments, just a person, thing, location, time
Record::Record(Person name, Thing thing, Location place, Time time) : place(place), time(time)  {
        //initialize lists with these arguments
        personList.push_back(name); 
        thingList.push_back(thing);
}
//constructor that takes in lists for things and people
Record::Record(list<Person>personList, list<Thing> thingList, Location place, Time time)
: personList(personList), thingList(thingList), place(place), time(time) {}
//default constructor
Record::Record(){}

//removes person with matching name
void Record::removePerson(string name) {
    list<Person>::iterator iter = personList.begin();
    for (int i = 0; i < personList.size(); i++) {
        if ((*iter).getName() == name) {
            personList.erase(iter);
            return;
        }
        iter++;
    }
}

//adds the given input Person
void Record::addPerson(Person person) {
    personList.push_back(person);
}
void Record::addPerson(string name) {
    Person newPerson {name};
    personList.push_back(newPerson);
}

void Record::removeThing(string nameOfThing) {
    list<Thing>::iterator iter = thingList.begin();
    for (int i = 0; i < thingList.size(); i++) {
        if ((*iter).getThing() == nameOfThing) {
            thingList.erase(iter);
            return;
        }
        iter++;
    }
}
void Record::addThing(string nameOfThing) {
    thingList.push_back(Thing {nameOfThing});
}
void Record::addThing(Thing thing) {
    thingList.push_back(thing);
}

//changes the record's location into place
void Record::setLocation(Location place) {
    this->place = place;
}

void Record::setTime(Time time) {
    this->time = time;
}

//returns JSON of the entire record
Json::Value Record::dump2JSON(void){
    Json::Value result {};
    Json::Value jv_result;

    //makes json arrayValue for "people" that has every JSON of the people in personList
    result["people"] = Json::arrayValue;
    for (Person person: personList) {
        jv_result = person.dump2JSON();
        result["people"].append(jv_result);
    }

    //makes json arrayValue for "things" that has every JSON of the thing in thingList
    result["things"] = Json::arrayValue;
    for (Thing thing: thingList) {
        jv_result = thing.dump2JSON();
        result["things"].append(jv_result);
    }
    
    //sets place and time JSON as well
    jv_result = place.dump2JSON();
    result["place"] = jv_result;

    jv_result = time.dump2JSON();
    result["time"] = jv_result;

    return result;
}

//Will initilize the fields of "this" with the correspoding data in the inputted JSON.
//preferably "this" is a new object, or has been completely reset
bool Record::JSON2Object(Json::Value arg) {
    //the itWorked bool will be true if the the JSON2Object operations created an 
    //object with any correct parameters.
    bool itWorked;
    Person emptyP;
    this->personList.empty();
    Thing emptyThing;
    this->thingList.empty();

    if(!arg["people"].isNull() && arg["people"].isArray()) {
        for(Json::Value personJson : arg["people"]) {
            //empty person object calls JSON2Object to initialize itself
            itWorked = emptyP.JSON2Object(personJson);
            if (itWorked) {
                //if empty person object is not null then put it the record's personList
                personList.push_back(emptyP);
            }
        }
    }

    if(!arg["things"].isNull() && arg["things"].isArray()) {
        for(Json::Value thingJson : arg["things"]) {
            //empty thing object calls JSON2Object to initialize itself
            itWorked = emptyThing.JSON2Object(thingJson);
            if (itWorked) {
                //if empty thing object is not null then put it the record's thingList
                thingList.push_back(emptyThing);
            }
        }
    }
    
    //if JSON2Object created a non-null Time/Location object then this initializes
    Location emptyL;
    Time emptyTime;
    
    itWorked = emptyL.JSON2Object(arg["place"]);
    if(itWorked) {
        this->place = emptyL;
    }
    itWorked = emptyTime.JSON2Object(arg["time"]);
    if(itWorked) {
        this->time = emptyTime;
    }
    return true;
}

void Record::reset(){
    this->personList.clear();
    this->thingList.clear();
    this->place = Location();
    this->time = Time();
}