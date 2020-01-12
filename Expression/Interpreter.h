//
// Created by shachar Meir on 05/11/2019.
//

#ifndef EX1_INTERPRETER_H
#define EX1_INTERPRETER_H
#include <queue>
#include <map>
#include "Expression.h"
#include "ex1.h"
class Interpreter {
public:
  Interpreter();
//Interpreter()= default;
    Expression* interpret(const char*);
  void setVariables(const char *input);
  static bool isNumber(const std::string &s);

 private:

  std::map<std::string,double> varMap;
  void addToVarMap(const std::string &name, const std::string &val);
  std::queue<std::string> shunting_yard(const std::string&);
  static bool is_valid_name(const std::string &s);
  static bool is_operator(const std::string& c);
  static Expression *ActivateOper(Expression *left_expression, Expression *right_expression, std::string &oper);
  static int precedence(const char& c,bool);
  bool is_Unary_operator(std::string&);
  Expression *ActivateUnaryOper(Expression *p_expression, std::string basic_string);
  int precedence(const char &c);
};


#endif //EX1_INTERPRETER_H
