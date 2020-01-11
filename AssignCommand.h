//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#define FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
#include "Command.h"
#include <algorithm>
class AssignCommand: public Command {
  bool is_in_vector(string var_name, vector<std::pair<std::string, std::string>> *vector);
 public:
  void execute(std::vector<std::string> &args) override;

  int numArg() override;

  ~AssignCommand() override = default;
  AssignCommand(SharedData *p_data, Interpreter *p_interpreter);
};

#endif //FLIGHT_SIMULATOR__ASSIGNCOMMAND_H_
