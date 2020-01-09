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
  static bool isNumber(const string &s);

 private:

  std::map<string,double> varMap;
  void addToVarMap(const string &name, const string &val);
  std::queue<string> shunting_yard(const string&);
  static bool is_valid_name(const string &s);
  static bool is_operator(const string& c);
  static Expression *ActivateOper(Expression *left_expression, Expression *right_expression, string &oper);
  static int precedence(const char& c,bool);
  bool is_Unary_operator(string&);
  Expression *ActivateUnaryOper(Expression *p_expression, string basic_string);
  int precedence(const char &c);
};


#endif //EX1_INTERPRETER_H
