//
// Created by shachar Meir on 05/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMAND_H_
#define FLIGHT_SIMULATOR__COMMAND_H_
#include <vector>
#include <string>
#include <iostream>
#include "TextFunctions.h"
#include "SharedData.h"
#include "Expression/ex1.h"
#include "Expression/Interpreter.h"
class Command {
 protected:
  Interpreter* interpreter_;
  SharedData* shared_data;
  void initInterpreterVar();
  void setVariablesFromVector(vector<std::string> *vector, SymbolTable *table);
 public:
  Command(SharedData*, Interpreter*);
virtual void execute(std::vector<std::string>& args) = 0;
virtual int numArg() = 0;
virtual ~Command()= default;;
};

#endif //FLIGHT_SIMULATOR__COMMAND_H_
