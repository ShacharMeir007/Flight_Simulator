//
// Created by shachar Meir on 05/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMAND_H_
#define FLIGHT_SIMULATOR__COMMAND_H_
#include <vector>
#include <string>
class Command {
virtual void execute(std::vector<std::string>& args)=0;
virtual int numArg()=0;
};

#endif //FLIGHT_SIMULATOR__COMMAND_H_
