//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__PRINTCOMMAND_H_
#define FLIGHT_SIMULATOR__PRINTCOMMAND_H_
#include "Command.h"
#include <iostream>
class PrintCommand: public Command {
 public:
  PrintCommand(SharedData *p_data, Interpreter *p_interpreter);
 private:
  void execute(std::vector<std::string> &args) override;
  int numArg() override;

};

#endif //FLIGHT_SIMULATOR__PRINTCOMMAND_H_
