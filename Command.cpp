//
// Created by shachar Meir on 05/01/2020.
//

#include "Command.h"

void Command::initInterpreterVar() {
  std::vector<std::string>* var_list = this->shared_data->safe_getVars();
  SymbolTable* table = this->shared_data->safe_getSymbolTable();
  setVariablesFromVector(var_list, table);

}
void Command::setVariablesFromVector(std::vector<std::string> * vector,
                                          SymbolTable* table) {
  for (std::string& s : *vector){
    double value = table->get(s).GetValue();
    std::string var_str = s+"="+std::to_string(value);
    this->interpreter_->setVariables(var_str.c_str());
  }
}
Command::Command(SharedData * data, Interpreter * interpreter) {
  this->shared_data = data;
  this->interpreter_ = interpreter;
}
