//
// Created by shachar Meir on 09/01/2020.
//

#include "PrintCommand.h"
void PrintCommand::execute(std::vector<std::string> &args) {
  if ((int )args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  if (isInQuotations(args[0])){
    std::cout<<args[0]<<std::endl;
  } else{
    shared_data->harsh_lock();
    auto table = shared_data->safe_getSymbolTable();
    double val = table->get(args[0]).GetValue();
    shared_data->harsh_release();
    std::cout<<val<<std::endl;
  }
}
int PrintCommand::numArg() {
  return 1;
}
PrintCommand::PrintCommand(SharedData *data) : Command(data) {}
