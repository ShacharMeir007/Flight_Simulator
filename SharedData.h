//
// Created by shachar Meir on 08/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SHAREDDATA_H_
#define FLIGHT_SIMULATOR__SHAREDDATA_H_
#include <vector>
#include <string>
#include "SymbolTable.h"
#include "ThreadLock.h"
//This class is for shared data the thread might need.
//Every time you need to share data between threads you'll use
//this class.
class SharedData {
  std::vector<std::string>* vars_right_Bind = nullptr;
  std::vector<std::string>* vars_left_Bind = nullptr;
  std::vector<std::string>* vars = nullptr;
 public:
  std::vector<std::string> *safe_getVars();
 private:
  SymbolTable* symbol_table_ = nullptr;
  ThreadLock lock;
 public:
  SymbolTable *safe_getSymbolTable();
  SharedData();
  virtual ~SharedData();
  std::vector<std::string> *safe_getVarsRightBind();
  std::vector<std::string> *safe_getVarsLeftBind();
  void safe_changeValue(std::string &name, double value);
  double safe_getValue(std::string &name);
  void harsh_lock();
  void harsh_release();
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
