CC = g++ -std=c++14
#LIB_HW5 = -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl
LIB_HW5 = -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl
CFLAGS = -g

all: house forest grandma

house: client.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5Home.o
	$(CC) client.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5Home.o $(LIB_HW5) -o house

forest: server.o client.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5Forest.o
	$(CC) server.o client.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5Forest.o $(LIB_HW5) -o forest

grandma: server.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5GrandmaHome.o
	$(CC) server.o location.o person.o record.o thing.o time2.o ecs36b_JSON.o hw5GrandmaHome.o $(LIB_HW5) -o grandma

abstractstubserver.h stubclient.h: spec.json
	jsonrpcstub spec.json --cpp-server=AbstractStubServer --cpp-client=StubClient

location.o: location.cpp
	$(CC) -c $(CFLAGS) location.cpp

person.o: person.cpp
	$(CC) -c $(CFLAGS) person.cpp

record.o: record.cpp
	$(CC) -c $(CFLAGS) record.cpp

thing.o: thing.cpp
	$(CC) -c $(CFLAGS) thing.cpp

time2.o: time2.cpp
	$(CC) -c $(CFLAGS) time2.cpp

ecs36b_JSON.o: ecs36b_JSON.cpp
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

hw5Forest.o: hw5Forest.cpp
	$(CC) -c $(CFLAGS) hw5Forest.cpp

hw5GrandmaHome.o: hw5GrandmaHome.cpp
	$(CC) -c $(CFLAGS) hw5GrandmaHome.cpp

hw5Home.o: hw5Home.cpp
	$(CC) -c $(CFLAGS) hw5Home.cpp

client.o: client.cpp stubclient.h
	$(CC) -c $(CFLAGS) client.cpp

server.o: server.cpp abstractstubserver.h
	$(CC) -c $(CFLAGS) server.cpp

#rm means remove, *.0 means "anything with a .o at the end", forest, grandma, and house are the executables to removed
clean:
	rm -fr *.o forest grandma house stubclient.h abstractstubserver.h