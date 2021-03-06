//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__MYCLIENT_H_
#define FLIGHT_SIMULATOR__MYCLIENT_H_
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "SharedData.h"
#include <thread>
// client function
void runClient(int port, std::string addr, SharedData* shared_data);
// runs new thread with client function
void connectMyClient(int port, std::string addr, SharedData* shared_data);
#endif //FLIGHT_SIMULATOR__MYCLIENT_H_
