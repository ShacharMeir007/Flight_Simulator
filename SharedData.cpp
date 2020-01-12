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
std::vector<std::pair<std::string,std::string>> SharedData::safe_getVarsRightBind()  {

  std::vector<std::pair<std::string,std::string>>* right = vars_right_Bind;

  return *right;
}
std::vector<std::pair<std::string,std::string>>SharedData::safe_getVarsLeftBind()  {

  std::vector<std::pair<std::string,std::string>>* left = vars_left_Bind;

  return *left;
}
/*SymbolTable *SharedData::safe_getSymbolTable() {

  SymbolTable* table = symbol_table_;

  return table;
}*/
std::vector<std::pair<std::string,std::string>> SharedData::safe_getChangedVars()  {

  std::vector<std::pair<std::string,std::string>>* changed = vars_changed;

  return *changed;
}
void SharedData::safe_changeValue(std::string & name, double value) {
  this->mut.lock();
  this->symbol_table_->get(name).SetValue(value);
  this->mut.unlock();
}
double SharedData::safe_getValue(std::string & name) {
  this->mut.lock();
  try {
    double val = this->symbol_table_->get(name).GetValue();
    this->mut.unlock();
    return val;
  } catch(std::out_of_range& e) {
    this->mut.unlock();
    throw "not in symbol table";
  }

}
std::string SharedData::safe_getSim(std::string & name) {
  this->mut.lock();
  std::string sim = this->symbol_table_->get(name).GetSim();
  this->mut.unlock();
  return sim;
}
void SharedData::safe_addSymbol(std::string & name, Symbol& symbol) {
  this->mut.lock();
  this->symbol_table_->add(name,symbol);
  this->mut.unlock();
}
std::vector<std::string> SharedData::safe_getVars() {
  std::vector<std::string> * var = vars;
  return *var;
}
bool SharedData::checkTerminate() {
  this->mut.lock();
  bool b = this->terminate;
  this->mut.unlock();
  return b;
}
bool SharedData::checkTerminated() {
  this->mut.lock();
  bool b = this->terminated;
  this->mut.unlock();
  return b;
}
void SharedData::setTerminate() {
  this->mut.lock();
  this->terminate = true;
  this->mut.unlock();

}
void SharedData::setTerminated() {
  this->mut.lock();
  this->terminated = true;
  this->mut.unlock();

}
void SharedData::safe_add_to_change(std::pair<std::string, std::string>& pair) {
  this->mut.lock();
  this->vars_changed->push_back(pair);
  this->mut.unlock();
}
void SharedData::safe_add_to_right(std::pair<std::string, std::string> & pair) {
  this->mut.lock();
  this->vars_right_Bind->push_back(pair);
  this->mut.unlock();
}
void SharedData::safe_add_to_left(std::pair<std::string, std::string> & pair) {
  this->mut.lock();
  this->vars_left_Bind->push_back(pair);
  this->mut.unlock();
}
void SharedData::safe_add_to_vars( std::string & var_name) {
  this->mut.lock();
  this->vars->push_back(var_name);
  this->mut.unlock();
}


