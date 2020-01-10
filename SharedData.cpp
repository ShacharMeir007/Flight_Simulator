//
// Created by shachar Meir on 08/01/2020.
//

#include "SharedData.h"
//todo add mutex lock on changing values
SharedData::SharedData() {
  this->vars_left_Bind = new std::vector<std::string>();
  this->vars_right_Bind = new std::vector<std::string>();
  this->symbol_table_ = new SymbolTable();
}
SharedData::~SharedData() {

}
std::vector<std::string> *SharedData::GetVarsRightBind() const {
  return vars_right_Bind;
}
void SharedData::SetVarsRightBind(std::vector<std::string> *new_vars_right_bind) {
  vars_right_Bind = new_vars_right_bind;
}
std::vector<std::string> *SharedData::GetVarsLeftBind() const {
  return vars_left_Bind;
}
void SharedData::SetVarsLeftBind(std::vector<std::string> *new_vars_left_bind) {
  vars_left_Bind = new_vars_left_bind;
}
SymbolTable *SharedData::GetSymbolTable() const {
  return symbol_table_;
}
void SharedData::changeValue(std::string & name, double value) {
  mutex_.lock();
  this->symbol_table_->get(name).SetValue(value);
  mutex_.unlock();
}
