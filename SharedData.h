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
  std::vector<std::string>* vars_right_Bind = nullptr;
  std::vector<std::string>* vars_left_Bind = nullptr;
  SymbolTable* symbol_table_ = nullptr;
  std::mutex mutex_;
 public:
  SymbolTable *GetSymbolTable() const;
  void SetSymbolTable(SymbolTable *new_symbol_table);
  SharedData();
  virtual ~SharedData();
  std::vector<std::string> *GetVarsRightBind() const;
  void SetVarsRightBind(std::vector<std::string> *new_vars_right_bind);
  std::vector<std::string> *GetVarsLeftBind() const;
  void SetVarsLeftBind(std::vector<std::string> *new_vars_left_bind);
  void changeValue(std::string&, double value);
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
