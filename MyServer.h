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
#include <future>
#include "SharedData.h"
#include "TextFunctions.h"
//runs the server
void runDataServer(int port, SharedData* data);
// converts values from a vector of strings to a vector of doubles
std::vector<double> convert_to_double(std::vector<std::string>& vector);
//inserts values from vector to map in order
void insert_values_to_map(std::map<std::string,double>& map, std::vector<double >& values);
// opens thread to receive a connection from a client and returns it
int receiveConnection(int port);
#endif //FLIGHT_SIMULATOR__MYSERVER_H_
