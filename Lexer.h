//
// Created by shachar Meir on 05/01/2020.
//

#ifndef FLIGHT_SIMULATOR__LEXER_H_
#define FLIGHT_SIMULATOR__LEXER_H_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <vector>
#include "TextFunctions.h"
class Lexer {
 private:
  //members
  std::ifstream input_stream;
  std::vector<std::string> commends;
  //private methods
  //text methods
  //vector methods
  void copyCommands(const std::vector<std::string>& vector);
  void printVector(std::vector<std::string> vector);
  //file methods
  std::string readLine();
  //public methods
 public:
  explicit Lexer(const std::string&);
  virtual ~Lexer();
  std::vector<std::string> lex();

  void handleVar(std::vector<std::string>& basic_string);
  void handleCondition(std::vector<std::string>& vector);
  void handleQuotation(std::vector<std::string>& vector);
  void handleAssign(std::vector<std::string> &vector);
};

#endif //FLIGHT_SIMULATOR__LEXER_H_
