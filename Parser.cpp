//
// Created by yonathank on 06/01/2020.
//

#include "Parser.h"
Parser::Parser(std::vector<std::string> *stringCommands) {
  string_commands_ = stringCommands;
}
void Parser::parse() {
  int size = string_commands_->size(), index = 0, numArgs;
  CommandMap cm = CommandMap();
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
      auto first = string_commands_->begin() + index + 2;
      auto last = first;
      for (last = first; *last != "}"; ++last);
      args = new std::vector<std::string>(first, last);
      c->execute(*args);
    }
  }
}
