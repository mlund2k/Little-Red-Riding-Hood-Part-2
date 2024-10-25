/*#include "common.h"
#include "person.h"
#include "thing.h"
#include "jsonrpc.h"
#include <thread>
#include <chrono>
*/
#include "time2.h"
#include "location.h"
#include "record.h"
#include <iostream>
#include "server.h"
#include "stubclient.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

int main() {
    
    jsonrpc::HttpServer httpserver(FOREST_PORT);
    MyStubServer s(
        httpserver,
        jsonrpc::JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    std::cout << "Hit enter to stop the server and then send objects to GRANDMA" << std::endl;
    getchar();
    s.StopListening();

    //getting objects from server
    Person LRRH = s.getPerson("LRRH");
    Person Wolf {"Wolf"};
    Thing Cap = s.getThing("Cap");
    Thing Cake = s.getThing("Cake");
    Thing Wine = s.getThing("Wine");
    Location place {"(Forest) A particular spot in the wood"};
    Time time {3};

    jsonrpc::HttpClient httpclient("http://localhost:" + std::to_string(GRANDMA_PORT));
    StubClient c(httpclient, jsonrpc::JSONRPC_CLIENT_V2);

    Json::Value result;
    //this will catch the error if the grandma server is not ready
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
    
    Record record3 {{LRRH, Wolf}, {Cap, Cake, Wine}, place, time};
    cout << "Record 3:\n" << record3.dump2JSON().toStyledString() << endl;
    return 0;
}
