#ifndef _RECORD_H_
#define _RECORD_H_

#include "time2.h"
#include "person.h"
#include "thing.h"
#include "location.h"
#include "common.h"

class Record{
	private:
		Location place;
		Time time;
		//these lists will hold the people/things in the record
		std::list<Person> personList;
		std::list<Thing> thingList;
	public:
		//constructor with a single object of each type
		Record(Person, Thing, Location, Time);
		//constructor that takes in lists for things and people
		Record(std::list<Person>, std::list<Thing>, Location, Time);
		//Default constructor
		Record();
		
		//remove/add a person with the name in arg
		void removePerson(string);
		void addPerson(Person);
		void addPerson(string);

		//remove/add a thing
		void removeThing(string);
		void addThing(string);
		void addThing(Thing);

		//change the value of location
		void setLocation(Location);

		void setTime(Time);

		virtual Json::Value dump2JSON();
		virtual bool JSON2Object(Json::Value);
		void reset();
};

#endif