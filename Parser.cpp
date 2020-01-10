//
// Created by yonathank on 06/01/2020.
//

#include "Parser.h"
Parser::Parser(SharedData* data) {
  this->data = data;
}
void Parser::parse(std::vector<std::string> * string_commands_) {

  int size = string_commands_->size(), index = 0, numArgs;
  CommandMap cm = CommandMap(data);
  Command *c;
  std::vector<std::string> *args;
  while (index < size) {
    c = cm.getCommand(string_commands_->at(index));
    if (!c){
      std::string invalid_command = string_commands_->at(index);
      throw "don't recognize command";
    }
    numArgs = c->numArg();
    if (numArgs >= 0) {
      auto first = string_commands_->begin() + index + 1;
      auto last = string_commands_->begin() + index + numArgs + 1;
      args = new std::vector<std::string>(first, last);
      c->execute(*args);
      index += numArgs + 1;
    } else {
      std::vector<std::string> argv;
      auto first = string_commands_->begin() + index;
      int j = 0;
      while (*first!="{"){
        argv.push_back(*first);
        j++;
        first++;
      }
      j++;
      first++;
      while (*first!="}"){
        argv.push_back(*first);
        j++;
        first++;
      }
      j++;
      c->execute(argv);
      index += j;
    }
  }
}
