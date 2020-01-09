//
// Created by shachar Meir on 05/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMAND_H_
#define FLIGHT_SIMULATOR__COMMAND_H_
#include "SharedData.h"
class Command {
virtual void execute(SharedData shared_data)=0;
virtual int numArg();
};

#endif //FLIGHT_SIMULATOR__COMMAND_H_
