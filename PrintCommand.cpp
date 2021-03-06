//
// Created by shachar Meir on 09/01/2020.
//

#include "PrintCommand.h"
void PrintCommand::execute(std::vector<std::string> &args) {
  if ((int )args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  //checks if the argument is a string to print
  if (isInQuotations(args[0])){
    std::string msg = args[0];
    remove_quotation(msg);
    std::cout<<msg<<std::endl;
  } else{
    //getting variable to print
    try {
      double val = shared_data->safe_getValue(args[0]);
      std::cout<<val<<std::endl;

    } catch (const char* e){
      //evaluate expression
      double val = this->evaluate_expression(args[0]);
      std::cout<<val<<std::endl;
    }

  }
}
int PrintCommand::numArg() {
  return 1;
}
PrintCommand::PrintCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}
