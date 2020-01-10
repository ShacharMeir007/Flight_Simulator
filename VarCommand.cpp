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
  this->shared_data->harsh_lock();
  SymbolTable* symbol_table = this->shared_data->safe_getSymbolTable();
  this->initInterpreterVar();
  if(bind == "="){
    Expression* e = this->interpreter_.interpret(sim.c_str());
    double value = e->calculate();
    Symbol symbol(value, "");
    symbol_table->add(var_name, symbol);
  } else {
    Symbol symbol(0, sim);
    symbol_table->add(var_name, symbol);
    if (bind == "->") {
      std::vector<std::string> *right_bind = this->shared_data->safe_getVarsRightBind();
      if (right_bind) {
        right_bind->push_back(var_name);
      } else {
        this->shared_data->harsh_release();
        throw "right bind vector was not initialized";
      }
    } else if (bind == "<-") {
      std::vector<std::string> *left_bind = this->shared_data->safe_getVarsLeftBind();
      if (left_bind) {
        left_bind->push_back(var_name);
      } else {
        this->shared_data->harsh_release();
        throw "left bind vector was not initialized";
      }
    } else {
      this->shared_data->harsh_release();
      throw "couldn't find bind type";
    }
  }
  std::vector<std::string>* vars = this->shared_data->safe_getVars();
  if (vars){
    vars->push_back(var_name);
  } else {
    this->shared_data->harsh_release();
    throw "right bind vector was not initialized";
  }
  this->shared_data->harsh_release();
}
int VarCommand::numArg() {
  return 3;
}
