//
// Created by shachar Meir on 05/01/2020.
//

#include "Command.h"

void Command::initInterpreterVar() {
  std::vector<std::string> var_list = this->shared_data->safe_getVars();
  for (std::string& s : var_list){
    double value = shared_data->safe_getValue(s);
    std::string var_str = s+"="+std::to_string(value);
    this->interpreter_->setVariables(var_str.c_str());
  }
}
double Command::evaluate_expression(std::string& exp){
  initInterpreterVar();
  Expression* expression = this->interpreter_->interpret(exp.c_str());
  return expression->calculate();
}
Command::Command(SharedData * data, Interpreter * interpreter) {
  this->shared_data = data;
  this->interpreter_ = interpreter;
}
