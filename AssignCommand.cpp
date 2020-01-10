//
// Created by shachar Meir on 10/01/2020.
//

#include "AssignCommand.h"
void AssignCommand::execute(std::vector<std::string> &args) {
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string var_name = args[0];
  std::string expression = args[1];

  this->shared_data->harsh_lock();
  this->initInterpreterVar();
  try{
  Expression* expression1 = this->interpreter_->interpret(expression.c_str());
    double new_val = expression1->calculate();
    this->shared_data->safe_changeValue(var_name, new_val);
  } catch (const char* p){
    std::cout<<p<<std::endl;
    this->shared_data->harsh_release();
  }

  this->shared_data->harsh_release();
}
int AssignCommand::numArg() {
  return 2;
}

AssignCommand::AssignCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}

