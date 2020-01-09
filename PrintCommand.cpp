//
// Created by shachar Meir on 09/01/2020.
//

#include "PrintCommand.h"
void PrintCommand::execute(std::vector<std::string> &args) {
  if (args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::cout<<args[0]<<std::endl;
}
int PrintCommand::numArg() {
  return 1;
}
PrintCommand::PrintCommand(SharedData *data) : Command(data) {}
