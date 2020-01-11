//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__MYSERVER_H_
#define FLIGHT_SIMULATOR__MYSERVER_H_
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include "SharedData.h"
#include "TextFunctions.h"
void runDataServer(int port, SharedData* data);
void openDataServer(int port, SharedData* data);
std::vector<double> convert_to_double(std::vector<std::string>& vector);
void insert_values_to_map(std::map<std::string,double>& map, std::vector<double >& values);
#endif //FLIGHT_SIMULATOR__MYSERVER_H_
