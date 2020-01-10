//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__IFWHILECOMMAND_H_
#define FLIGHT_SIMULATOR__IFWHILECOMMAND_H_
#include "Command.h"


class IfWhileCommand: public Command {
 public:
  IfWhileCommand(SharedData *data);
  void execute(std::vector<std::string> &args) override;
  int numArg() override;
  ~IfWhileCommand() override = default;

  bool check_condition(Expression *exp1, std::string condition, Expression *exp2);
};

#endif //FLIGHT_SIMULATOR__IFWHILECOMMAND_H_
