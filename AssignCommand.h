//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#define FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#include "Command.h"
class AssignCommand: public Command {
 public:
  void execute(std::vector<std::string> &args) override;
  int numArg() override;

  ~AssignCommand() override = default;

  AssignCommand(SharedData *p_data, Interpreter *p_interpreter);
};

#endif //FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
