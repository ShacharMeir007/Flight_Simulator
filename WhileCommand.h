//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__WHILECOMMAND_H_
#define FLIGHT_SIMULATOR__WHILECOMMAND_H_
#include "Command.h"


class WhileCommand: public Command {
 public:
  WhileCommand(SharedData *data);
  void execute(std::vector<std::string> &args) override;
  int numArg() override;
  ~WhileCommand() override = default;

  bool check_condition(Expression *exp1, std::string condition, Expression *exp2);
};

#endif //FLIGHT_SIMULATOR__WHILECOMMAND_H_
