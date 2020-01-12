//
// Created by shachar Meir on 06/01/2020.
//


#include "OpenDataServerCommand.h"

void OpenDataServerCommand::execute(std::vector<std::string>& args) {
  // checking amount of arguments
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  //sets argument
  std::string port_str_exp = args[0];
  //converts port to number
  double val = this->evaluate_expression(port_str_exp);
  int port = int(val);
  // open thread to receive connection from client
  //and waits for it to be done
  std::future<int> connectionFuture = std::async(receiveConnection,port);
  //gets returned connection
  int connection = connectionFuture.get();
  //runs server with connection and continues program
  std::thread thread(runDataServer, connection, shared_data);
  thread.detach();
}
int OpenDataServerCommand::numArg() {
  return 1;
}
OpenDataServerCommand::OpenDataServerCommand(SharedData *data, Interpreter *interpreter) : Command(data, interpreter) {}
