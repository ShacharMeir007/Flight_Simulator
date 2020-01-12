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
  //used to insert string commends into
  // the final vector of this lexer
  void copyCommands(const std::vector<std::string>& vector);
  void printVector(std::vector<std::string> vector);
  //file methods
  std::string readLine();
  //public methods
 public:
  explicit Lexer(const std::string&);
  virtual ~Lexer();
  std::vector<std::string> lex();

  void handleVar(std::vector<std::string>& vector);
  void handleCondition(std::vector<std::string>& vector);
  void handleQuotation(std::vector<std::string>& vector);
  void handleAssign(std::vector<std::string> &vector);
  void handleDataServer(std::string &str);
  void handleConnectClient(std::string& std);
  void handlePrint(std::string &str);
};

#endif //FLIGHT_SIMULATOR__LEXER_H_
