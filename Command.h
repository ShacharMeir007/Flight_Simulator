//
// Created by shachar Meir on 05/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMAND_H_
#define FLIGHT_SIMULATOR__COMMAND_H_
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "TextFunctions.h"
#include "SharedData.h"
#include "Expression/ex1.h"
#include "Expression/Interpreter.h"
class Command {
 protected:
  Interpreter* interpreter_;
  SharedData* shared_data;
  // initialize the interpreter's Variables
  void initInterpreterVar();
 public:
  Command(SharedData*, Interpreter*);
  // execute the command
virtual void execute(std::vector<std::string>& args) = 0;
// returns number of arguments the command requires
virtual int numArg() = 0;
virtual ~Command()= default;;
  double evaluate_expression(string &exp);
};

#endif //FLIGHT_SIMULATOR__COMMAND_H_
