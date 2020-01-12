//
// Created by shachar Meir on 10/01/2020.
//

#include "AssignCommand.h"
void AssignCommand::execute(std::vector<std::string> &args) {
  if ((int) args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  // set arguments
  std::string var_name = args[0];
  std::string expression = args[1];

  this->initInterpreterVar();

  try{
    //interpret expression
  Expression* expression1 = this->interpreter_->interpret(expression.c_str());
    double new_val = expression1->calculate();
    // sets the value to the signTable
    this->shared_data->safe_changeValue(var_name, new_val);
    //adding the assigned var to the list of changed variables
    //for the client to update the simulator's settings
    auto right_bind = this->shared_data->safe_getVarsRightBind();
    auto changed_vars = this->shared_data->safe_getChangedVars();
    if (is_in_vector(var_name, right_bind) &&!is_in_vector(var_name, changed_vars)){
      std::string sim = this->shared_data->safe_getSim(var_name);
      std::pair<std::string, std::string> p(var_name, sim);
      this->shared_data->safe_add_to_change(p);
    }
  } catch (const char* p){
    std::cout<<p<<std::endl;
  }

}
int AssignCommand::numArg() {
  return 2;
}
bool AssignCommand::is_in_vector(std::string var_name,std::vector<std::pair<std::string, std::string>> vector){
  for (auto& pair: vector) {
    if (var_name == pair.first){
      return true;
    }
  }
  return false;
}
AssignCommand::AssignCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}

