//
// Created by shachar Meir on 06/01/2020.
//


#include "OpenDataServerCommand.h"

void OpenDataServerCommand::execute(std::vector<std::string>& args) {
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string port_str = args[0];
  std::stringstream geek(port_str);
  int port = 0;
  geek>>port;

  std::future<int> connectionFuture = std::async(receiveConnection,port);
  int connection = connectionFuture.get();
  std::thread thread(runDataServer, connection, shared_data);
  thread.detach();
}
int OpenDataServerCommand::numArg() {
  return 1;
}
OpenDataServerCommand::OpenDataServerCommand(SharedData *data, Interpreter *interpreter) : Command(data, interpreter) {}
