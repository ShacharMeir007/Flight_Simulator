//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SYMBOL_H_
#define FLIGHT_SIMULATOR__SYMBOL_H_

#include <string>
class Symbol {
 public:
  Symbol(double value, const std::string &sim);
  double GetValue() ;
  void SetValue(double);
  const std::string &GetSim() const;
  void SetSim(const std::string &);
 private:
  double value;
  std::string sim;
};

#endif //FLIGHT_SIMULATOR__SYMBOL_H_
