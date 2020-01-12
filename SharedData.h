//
// Created by shachar Meir on 08/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SHAREDDATA_H_
#define FLIGHT_SIMULATOR__SHAREDDATA_H_
#include <vector>
#include <string>
#include <mutex>
#include "SymbolTable.h"
//This class is for shared data the thread might need.
//Every time you need to share data between threads you'll use
//this class.
class SharedData {
 private:
  //data tp share between threads
  std::vector<std::pair<std::string, std::string>>* vars_right_Bind = nullptr;
  std::vector<std::pair<std::string, std::string>>* vars_left_Bind = nullptr;
  std::vector<std::pair<std::string, std::string>>* vars_changed = nullptr;
  std::vector<std::string>* vars = nullptr;
  SymbolTable* symbol_table_ = nullptr;
  bool terminate = false;
  bool terminated = false;
  std::recursive_mutex mut;

 public:
  SharedData();
  virtual ~SharedData();
  //methods used to safely access shared data between different threads
  std::vector<std::string> safe_getVars();
  void safe_changeValue(std::string &name, double value);
  void safe_add_to_change(std::pair<std::string, std::string>&);
  void safe_add_to_right(std::pair<std::string, std::string>&);
  void safe_add_to_left(std::pair<std::string, std::string>&);
  double safe_getValue(std::string &name);
  std::vector<std::pair<std::string, std::string>> safe_getVarsRightBind();
  std::vector<std::pair<std::string, std::string>> safe_getVarsLeftBind();
  std::vector<std::pair<std::string, std::string>> safe_getChangedVars();

  bool checkTerminate();
  bool checkTerminated();

  void setTerminate();
  void setTerminated();
  void safe_addSymbol(std::string &name, Symbol &symbol);
  void safe_add_to_vars(std::string &var_name);
  std::string safe_getSim(std::string &name);
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
