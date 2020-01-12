//
// Created by shachar Meir on 10/01/2020.
//

#include "ConnectClientCommand.h"
void ConnectClientCommand::execute(std::vector<std::string> &args) {
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string addr = args[0];
  std::string port_str = args[1];
  remove_quotation(addr);
  //converting port to int
  std::stringstream stream(port_str);
  int port = 0;
  stream >> port;
  //runs Client on new thread
  connectMyClient(port, addr, this->shared_data);
}
int ConnectClientCommand::numArg() {
  return 2;
}
ConnectClientCommand::ConnectClientCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data,
                                                                                                     p_interpreter) {

}
