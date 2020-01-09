//
// Created by yonathank on 06/01/2020.
//

#ifndef FLIGHT_SIMULATOR__PARSER_H_
#define FLIGHT_SIMULATOR__PARSER_H_
#include <vector>
#include <string>
#include "SharedData.h"
class Parser {
 private:
  std::vector<std::string> string_commands_;
 public:
  static SharedData shared_data_;
  void parse();
  Parser();
};

#endif //FLIGHT_SIMULATOR__PARSER_H_
