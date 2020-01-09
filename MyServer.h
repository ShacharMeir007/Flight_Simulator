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
#include "Parser.h"
void runDataServer(int port, SharedData* data);
void openDataServer(int port, SharedData* data);
#endif //FLIGHT_SIMULATOR__MYSERVER_H_
