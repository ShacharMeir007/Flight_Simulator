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

  this->initInterpreterVar();
  try{
  Expression* expression1 = this->interpreter_->interpret(expression.c_str());
    double new_val = expression1->calculate();
    this->shared_data->safe_changeValue(var_name, new_val);
    auto right_bind = this->shared_data->safe_getVarsRightBind();
    auto changed_vars = this->shared_data->safe_getChangedVars();
    for (auto& pair: *right_bind) {
      if (is_in_vector(var_name, right_bind) &&!is_in_vector(var_name, changed_vars)){
        std::string sim = this->shared_data->safe_getSymbolTable()->get(var_name).GetSim();
        std::pair<std::string, std::string> p(var_name, sim);
        this->shared_data->safe_add_to_change(p);
      }
    }
  } catch (const char* p){
    std::cout<<p<<std::endl;
  }

}
int AssignCommand::numArg() {
  return 2;
}
bool AssignCommand::is_in_vector(std::string var_name,std::vector<std::pair<std::string, std::string>>* vector){
  for (auto& pair: *vector) {
    if (var_name == pair.first){
      return true;
    }
  }
  return false;
}
AssignCommand::AssignCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}

