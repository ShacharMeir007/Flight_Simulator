//
// Created by shachar Meir on 09/01/2020.
//

#include "PrintCommand.h"
void PrintCommand::execute(std::vector<std::string> &args) {
  if ((int )args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  if (isInQuotations(args[0])){
    std::string msg = args[0];
    remove_quotation(msg);
    std::cout<<msg<<std::endl;
  } else{
    auto table = shared_data->safe_getSymbolTable();
    double val = table->get(args[0]).GetValue();
    std::cout<<val<<std::endl;
  }
}
int PrintCommand::numArg() {
  return 1;
}
PrintCommand::PrintCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}
