#include "common.h"
#include "location.h"
#ifndef _AA_
#define _AA_

void move(Json::Value person, std::string origin, std::string location);
void move(Json::Value person, std::string origin, Location location);
void move(Json::Value person, Location origin, Location location);

bool search(Json::Value & output_json, const std::string & origin, const std::string & location);

bool wasFound(const std::string & origin, const std::string & location);
#endif