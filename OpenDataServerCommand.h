//
// Created by shachar Meir on 06/01/2020.
//

#ifndef FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
#define FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
#include "Command.h"
#include "MyServer.h"
#include <sstream>
#include <future>
class OpenDataServerCommand: public Command {
 public:
 private:
 public:
  OpenDataServerCommand(SharedData *data, Interpreter *interpreter);
 private:
  void execute(std::vector<std::string>& args) override;
  int numArg() override;
};

#endif //FLIGHT_SIMULATOR__OPENDATASERVERCOMMAND_H_
