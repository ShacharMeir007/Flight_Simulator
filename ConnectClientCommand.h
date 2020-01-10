//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__CONNECTCLIENTCOMMAND_H_
#define FLIGHT_SIMULATOR__CONNECTCLIENTCOMMAND_H_
#include "Command.h"
#include "MyClient.h"
class ConnectClientCommand: public Command {
 public:
  ConnectClientCommand(SharedData *data);
  void execute(std::vector<std::string> &args) override;
  int numArg() override;
  ~ConnectClientCommand() override = default;
};

#endif //FLIGHT_SIMULATOR__CONNECTCLIENTCOMMAND_H_
