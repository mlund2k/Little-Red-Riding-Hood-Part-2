#include "record.h"
#include "time2.h"
#include "thing.h"
#include "location.h"
#include "person.h"
#include <iostream>
//stubclient.h is created by using make
#include "stubclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

int main () {
    //the client connects to FOREST server
    
    jsonrpc::HttpClient httpclient("http://localhost:" + std::to_string(FOREST_PORT));
    StubClient c(httpclient, jsonrpc::JSONRPC_CLIENT_V2); // json-rpc 2.0

    //initializing objects for records
    Person Mom {"Mom"};
    Person LRRH {"Little Red Riding Hood"};
    Thing Cap = {"Red cap", LRRH};
    Thing Cake {"Cake", LRRH, Mom};
    Thing Wine {"Wine", LRRH, Mom};
    Location House {"House"};
    Time time1 {1};
    Time time2 {2};

    // moving objects
    Json::Value result;
    //this will catch the error if the forest server is not ready
    try {
        result = c.move("Person", LRRH.dump2JSON(), "LRRH");
        std::cout << result.toStyledString() << std::endl;
        
    } catch (...) {
        std::cout << "error moving person" << std::endl;
        exit(1);
    }

    result = c.move("Thing", Cap.dump2JSON(), "Cap");
    std::cout << result.toStyledString() << std::endl;

    result = c.move("Thing", Cake.dump2JSON(), "Cake");
    std::cout << result.toStyledString() << std::endl;

    result = c.move("Thing", Wine.dump2JSON(), "Wine");
    std::cout << result.toStyledString() << std::endl;
    
    //Printing the records for the user
    Record Record1{LRRH, Cap, House, time1};
    cout << "Record 1:\n" << Record1.dump2JSON().toStyledString() << endl;

    Record Record2{{LRRH, Mom}, {Cake, Wine}, House, time2};
    cout << "Record 2:\n" << Record2.dump2JSON().toStyledString() << endl;

    return 0;
}