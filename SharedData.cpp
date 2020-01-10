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
std::vector<std::string> *SharedData::safe_getVarsRightBind()  {
  lock.acquire_lock();
  std::vector<std::string> * right = vars_right_Bind;
  lock.release_lock();
  return right;
}
std::vector<std::string> *SharedData::safe_getVarsLeftBind()  {
  lock.acquire_lock();
  std::vector<std::string> * left = vars_left_Bind;
  lock.release_lock();
  return left;
}
SymbolTable *SharedData::sage_getSymbolTable() {
  lock.acquire_lock();
  SymbolTable* table = symbol_table_;
  lock.release_lock();
  return table;
}
void SharedData::safe_changeValue(std::string & name, double value) {
  lock.acquire_lock();
  this->symbol_table_->get(name).SetValue(value);
  lock.release_lock();
}
double SharedData::safe_getValue(std::string & name) {
  lock.acquire_lock();
  double val = this->symbol_table_->get(name).GetValue();
  lock.release_lock();
  return val;
}
void SharedData::harsh_lock() {
  lock.mutex_.lock();
  lock.set_locking_thread();
}
void SharedData::harsh_release() {
  lock.mutex_.unlock();
  lock.locking_thread ="";
}


