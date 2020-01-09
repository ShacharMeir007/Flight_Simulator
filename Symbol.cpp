//
// Created by shachar Meir on 09/01/2020.
//

#include "Symbol.h"
double Symbol::GetValue() const {
  return value;
}
void Symbol::SetValue(double value) {
  Symbol::value = value;
}
const std::string &Symbol::GetSim() const {
  return sim;
}
void Symbol::SetSim(const std::string &sim) {
  Symbol::sim = sim;
}
