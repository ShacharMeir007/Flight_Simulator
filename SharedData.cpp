//
// Created by shachar Meir on 08/01/2020.
//

#include "SharedData.h"
//todo add mutex lock on changing values
SharedData::SharedData() {
  this->vars = new std::vector<std::string>();
  this->vars_left_Bind = new std::vector<std::pair<std::string,std::string>>();
  this->vars_right_Bind = new std::vector<std::pair<std::string,std::string>>();
  this->vars_changed = new std::vector<std::pair<std::string,std::string>>();
  this->symbol_table_ = new SymbolTable();
}
SharedData::~SharedData() {

}
std::vector<std::pair<std::string,std::string>>* SharedData::safe_getVarsRightBind()  {

  std::vector<std::pair<std::string,std::string>>* right = vars_right_Bind;

  return right;
}
std::vector<std::pair<std::string,std::string>>*SharedData::safe_getVarsLeftBind()  {

  std::vector<std::pair<std::string,std::string>>* left = vars_left_Bind;

  return left;
}
SymbolTable *SharedData::safe_getSymbolTable() {

  SymbolTable* table = symbol_table_;

  return table;
}
std::vector<std::pair<std::string,std::string>>* SharedData::safe_getChangedVars()  {

  std::vector<std::pair<std::string,std::string>>* changed = vars_changed;

  return changed;
}
void SharedData::safe_changeValue(std::string & name, double value) {

  this->symbol_table_->get(name).SetValue(value);

}
double SharedData::safe_getValue(std::string & name) {

  double val = this->symbol_table_->get(name).GetValue();

  return val;
}

std::vector<std::string> *SharedData::safe_getVars() {

  std::vector<std::string> * var = vars;

  return var;
}
void SharedData::safe_add_to_change(std::pair<std::string, std::string>& pair) {

  this->vars_changed->push_back(pair);

}


