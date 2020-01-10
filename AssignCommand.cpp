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
  std::vector<std::string>* right_list = this->shared_data->safe_getVarsRightBind();
  std::vector<std::string>* left_list = this->shared_data->safe_getVarsLeftBind();
  SymbolTable* table = this->shared_data->sage_getSymbolTable();
  setVariablesFromVector(right_list, table);
  setVariablesFromVector(left_list, table);
  try{
  Expression* expression1 = this->interpreter_.interpret(expression.c_str());
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
void AssignCommand::setVariablesFromVector(std::vector<std::string> * vector,
    SymbolTable* table) {
  for (std::string& s : *vector){
    double value = table->get(s).GetValue();
    std::string var_str = s+"="+std::to_string(value);
    this->interpreter_.setVariables(var_str.c_str());
  }
}
AssignCommand::AssignCommand(SharedData *data) : Command(data) {}

