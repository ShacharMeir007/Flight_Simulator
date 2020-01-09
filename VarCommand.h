//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__VARCOMMAND_H_
#define FLIGHT_SIMULATOR__VARCOMMAND_H_
#include "Command.h"
#include "Parser.h"
#include "Symbol.h"
class VarCommand: public Command {
  void execute(std::vector<std::string> &args) override;
  int numArg() override;

};

#endif //FLIGHT_SIMULATOR__VARCOMMAND_H_
