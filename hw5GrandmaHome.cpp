/*#include "common.h"
#include "location.h"
#include "person.h"
#include "record.h"
#include "thing.h"
#include "time2.h"
#include "jsonrpc.h"
#include <thread>
*/

#include "time2.h"
#include "location.h"
#include "record.h"
#include <iostream>
#include "server.h"
#include "stubclient.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
int main() {
    jsonrpc::HttpServer httpserver(GRANDMA_PORT);
    MyStubServer s(
        httpserver,
        jsonrpc::JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    std::cout << "Hit enter to stop the server" << std::endl;
    getchar();
    
    Person LRRH;
    if(s.hasPerson("LRRH"))
        LRRH = s.getPerson("LRRH");
    else {
        std::cout << "Error couldn't find person" << std::endl;
        exit(1);
    }
    Thing Cap = s.getThing("Cap");
    Thing Cake = s.getThing("Cake");
    Thing Wine = s.getThing("Wine");
    Location place {"(Grandma's House) House under three large oak trees"};
    Time time {4};

    Record record4 {{LRRH}, {Cap, Cake, Wine}, place, time};
    cout << "Record 4:\n" << record4.dump2JSON().toStyledString() << endl;

    s.StopListening();
}

/*
int main() {

    
    Json::Value LRRH_json;
    bool found = search(LRRH_json, "forest", "grandma");;
    while (!found) {
        cout << "waiting for 3 seconds ";
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        found = search(LRRH_json, "forest", "grandma");
    }
    
    Json::Value inputJSON;

    myFile2JSON("LRRH.json", &inputJSON);
    LRRH.JSON2Object(inputJSON);
    
    Person LRRH;
    LRRH.JSON2Object(LRRH_json);
    //newRecord.removePerson("Wolf");

    Person Grandmother {"Grandmother"};
    Person Wolf {"Wolf"};
	Thing Nothing;
	Location GrandmaHouse {"House under three large oak trees"};
    Time Time4{4};

    Record newRecord {{LRRH, Grandmother, Wolf}, {Nothing}, GrandmaHouse, Time4};
    //Record Record4{Grandmother, Nothing, GrandmaHouse, time4};
    //cout << Record4.dump2JSON().toStyledString() << endl;
    cout << "this is the Grandmother's House json: " << endl << newRecord.dump2JSON().toStyledString();
    } 
*/