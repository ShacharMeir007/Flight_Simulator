//
// Created by shachar Meir on 09/01/2020.
//

#include "VarCommand.h"
void VarCommand::execute(std::vector<std::string> &args) {
  if ((int)args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string var_name = args[0];
  std::string bind = args[1];
  std::string sim = args[2];
  this->initInterpreterVar();
  if(bind == "="){
    Expression* e = this->interpreter_->interpret(sim.c_str());
    double value = e->calculate();
    Symbol symbol(value, "");
    shared_data->safe_addSymbol(var_name, symbol);
  } else {
    Symbol symbol(0, sim);
    shared_data->safe_addSymbol(var_name, symbol);

    if (bind == "->") {
      std::vector<std::pair<std::string,std::string>> right_bind = this->shared_data->safe_getVarsRightBind();
      std::pair<std::string,std::string> pair(var_name,sim);
      shared_data->safe_add_to_right(pair);
      //check
    } else if (bind == "<-") {
      std::vector<std::pair<std::string,std::string>> left_bind = this->shared_data->safe_getVarsLeftBind();
        std::pair<std::string,std::string> pair(var_name,sim);
      shared_data->safe_add_to_left(pair);
    } else {
      throw "couldn't find bind type";
    }
  }
  shared_data->safe_add_to_vars(var_name);
}
VarCommand::VarCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}
int VarCommand::numArg() {
  return 3;
}
