//
// Created by shachar Meir on 06/01/2020.
//

#include <sstream>
#include "OpenDataServerCommand.h"
#include "MyServer.h"
void OpenDataServerCommand::execute(std::vector<std::string>& args) {
  if (args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string port_str = args[0];
  std::stringstream geek(port_str);
  int port = 0;
  geek>>port;
  openDataServer(port);
}
int OpenDataServerCommand::numArg() {
  return 1;
}
