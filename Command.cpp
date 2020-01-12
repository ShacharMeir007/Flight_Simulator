//
// Created by shachar Meir on 05/01/2020.
//

#include "Command.h"

void Command::initInterpreterVar() {
  std::vector<std::string> var_list = this->shared_data->safe_getVars();
  setVariablesFromVector(var_list);
}
void Command::setVariablesFromVector(std::vector<std::string>  vector) {
  for (std::string& s : vector){
    double value = shared_data->safe_getValue(s);
    std::string var_str = s+"="+std::to_string(value);
    this->interpreter_->setVariables(var_str.c_str());
  }
}
Command::Command(SharedData * data, Interpreter * interpreter) {
  this->shared_data = data;
  this->interpreter_ = interpreter;
}
