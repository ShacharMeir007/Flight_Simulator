//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#define FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#include "Command.h"
class AssignCommand: public Command {
 private:
  Interpreter interpreter_;
  void setVariablesFromVector(std::vector<std::string>*,SymbolTable*);
 public:
  AssignCommand(SharedData *data);
  void execute(std::vector<std::string> &args) override;
  int numArg() override;

  ~AssignCommand() override = default;

};

#endif //FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
