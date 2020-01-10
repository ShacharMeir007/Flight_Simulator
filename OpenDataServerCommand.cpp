//
// Created by shachar Meir on 06/01/2020.
//

#include <sstream>
#include "OpenDataServerCommand.h"
#include "MyServer.h"
void OpenDataServerCommand::execute(std::vector<std::string>& args) {
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string port_str = args[0];
  std::stringstream geek(port_str);
  int port = 0;
  geek>>port;
  openDataServer(port,this->shared_data);
}
int OpenDataServerCommand::numArg() {
  return 1;
}
OpenDataServerCommand::OpenDataServerCommand(SharedData *data) : Command(data) {}
