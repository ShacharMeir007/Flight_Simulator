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
  Symbol symbol(0, sim);
  SymbolTable* symbol_table = this->shared_data->GetSymbolTable();
  if (symbol_table){
    symbol_table->add(var_name, symbol);
  } else {
    throw "symbol table was not initialized";
  }
  if (bind == "->"){
    std::vector<std::string>* right_bind = this->shared_data->GetVarsRightBind();
    if (right_bind){
      right_bind->push_back(var_name);
    } else {
      throw "right bind vector was not initialized";
    }

  } else if (bind == "<-"){
    std::vector<std::string>* left_bind = this->shared_data->GetVarsLeftBind();
    if (left_bind){
      left_bind->push_back(var_name);
    } else {
      throw "left bind vector was not initialized";
    }
  } else {
    throw "couldn't find bind type";
  }
}
int VarCommand::numArg() {
  return 3;
}
