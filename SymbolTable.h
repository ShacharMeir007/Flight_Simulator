//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SYMBOLTABLE_H_
#define FLIGHT_SIMULATOR__SYMBOLTABLE_H_

#include <map>
#include "Symbol.h"
class SymbolTable {
 public:
  Symbol get(std::string& str);
  void add (std::string&, Symbol);
 private:
  std::map<std::string, Symbol> table;

};

#endif //FLIGHT_SIMULATOR__SYMBOLTABLE_H_
