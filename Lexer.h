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
class Lexer {
 private:
  //members
  std::ifstream input_stream;
  std::vector<std::string> commends;
  //private methods
  //text methods
  void replace(const char token1, const std::string &token2, std::string &str);
  void remove_redundant_signs(std::string &str);
  std::vector<std::string> split(const char token, std::string &str);
  //vector methods
  void copyCommands(const std::vector<std::string>& vector);
  void printvector(std::vector<std::string> vector);
  //file methods
  std::string readLine();
  //public methods
 public:
  explicit Lexer(const std::string&);
  virtual ~Lexer();
  void lex();

  void remove_quotation(std::string &str);
  void strip(std::string &str);
  void hanleOpenDataServer(std::string basic_string);
  void hanleConnectControlClient(std::string basic_string);
  void hanleVar(std::string basic_string);
  void hanleCondition(std::string basic_string);
  void hanlePrint(std::string basic_string);
};

#endif //FLIGHT_SIMULATOR__LEXER_H_
