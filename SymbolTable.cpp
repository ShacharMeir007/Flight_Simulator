//
// Created by shachar Meir on 09/01/2020.
//

#include "SymbolTable.h"
Symbol SymbolTable::get(std::string &str) {
  try {
    Symbol symbol = this->table.at(str);
    return symbol;
  } catch (std::out_of_range& ofRange) {
    throw ofRange;
  }
}
