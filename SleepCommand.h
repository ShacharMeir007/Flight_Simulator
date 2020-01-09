//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SLEEPCOMMAND_H_
#define FLIGHT_SIMULATOR__SLEEPCOMMAND_H_
#include "Command.h"
class SleepCommand: public Command {
 public:
  SleepCommand(SharedData *data);
 private:
  void execute(std::vector<std::string> &args) override;
  int numArg() override;
};

#endif //FLIGHT_SIMULATOR__SLEEPCOMMAND_H_
