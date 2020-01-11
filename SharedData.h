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
 private:
  std::vector<std::pair<std::string, std::string>>* vars_right_Bind = nullptr;
  std::vector<std::pair<std::string, std::string>>* vars_left_Bind = nullptr;
  std::vector<std::pair<std::string, std::string>>* vars_changed = nullptr;
  std::vector<std::string>* vars = nullptr;
  SymbolTable* symbol_table_ = nullptr;
 public:
  std::condition_variable server_connected;
  std::vector<std::string> *safe_getVars();
  SymbolTable *safe_getSymbolTable();
  std::mutex mut;
  SharedData();
  virtual ~SharedData();
  void safe_changeValue(std::string &name, double value);
  void safe_add_to_change(std::pair<std::string, std::string>&);
  double safe_getValue(std::string &name);

  std::vector<std::pair<std::string, std::string>> *safe_getVarsRightBind();
  std::vector<std::pair<std::string, std::string>> *safe_getVarsLeftBind();
  std::vector<std::pair<std::string, std::string>> *safe_getChangedVars();
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
