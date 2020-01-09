//
// Created by shachar Meir on 09/01/2020.
//

#include "Symbol.h"
double Symbol::GetValue() const {
  return value;
}
void Symbol::SetValue(double newValue) {
  Symbol::value = newValue;
}
const std::string &Symbol::GetSim() const {
  return sim;
}
void Symbol::SetSim(const std::string &newSim) {
  Symbol::sim = newSim;
}
Symbol::Symbol(double value, const std::string &sim) : value(value), sim(sim) {}
