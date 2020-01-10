//
// Created by yonathank on 06/01/2020.
//

#ifndef FLIGHT_SIMULATOR__PARSER_H_
#define FLIGHT_SIMULATOR__PARSER_H_
#include <vector>
#include <string>
#include "SharedData.h"
#include "CommandMap.h"
#include "Expression/Interpreter.h"
class Parser {
 private:
  std::vector<std::string> *string_commands_;
  SharedData* data;
 public:

  void parse(std::vector<std::string> *stringCommands);
  Parser(SharedData* data);
};

#endif //FLIGHT_SIMULATOR__PARSER_H_
