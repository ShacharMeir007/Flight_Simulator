//
// Created by shachar Meir on 06/01/2020.
//

#ifndef FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
#define FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
#include "Command.h"
class OpenDataServerCommand: public Command {
  void execute(SharedData shared_data) override;
  int numArg() override;
};

#endif //FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
