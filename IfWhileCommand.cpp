//
// Created by shachar Meir on 10/01/2020.
//

#include "IfWhileCommand.h"
#include "Parser.h"
void IfWhileCommand::execute(std::vector<std::string> &args) {
  // sets arguments
  std::string ifOrWhile = args[0];
  std::string expression1 = args[1];
  std::string condition = args[2];
  std::string expression2 = args[3];
  // creates Parser to run the commands inside the while/if
  Parser parser(shared_data);
  // new vector of string commands for the parser
  std::vector<std::string> commands;
  int size = args.size();
  // filling with the commands inside the while/if
  for (int kI = 4; kI < size; ++kI) {
    commands.push_back(args[kI]);
  }
  try{
    Expression* result1;
    Expression* result2;
    initInterpreterVar();
    result1 = this->interpreter_->interpret(expression1.c_str());
    result2 = this->interpreter_->interpret(expression2.c_str());
    if (ifOrWhile == "while") {
      while (check_condition(result1,condition, result2)){
        parser.parse(&commands);
        initInterpreterVar();
        delete (result1);
        delete (result2);
        result1 = this->interpreter_->interpret(expression1.c_str());
        result2 = this->interpreter_->interpret(expression2.c_str());
      }
    } else {
      if (check_condition(result1,condition, result2)) {
        parser.parse(&commands);
      }
    }
  } catch (const char* p){
    std::cout<<p<<std::endl;
  }
}
int IfWhileCommand::numArg() {
  return -1;
}




bool IfWhileCommand::check_condition(Expression *exp1, std::string condition, Expression *exp2) {
  if (condition == "<") {
    return exp1->calculate() < exp2->calculate();
  } else if (condition == "<=") {
    return exp1->calculate() <= exp2->calculate();
  } else if (condition == ">") {
    return exp1->calculate() > exp2->calculate();
  } else if (condition == ">=") {
    return exp1->calculate() >= exp2->calculate();
  } else if (condition == "==") {
    return exp1->calculate() == exp2->calculate();
  } else if (condition == "!=") {
    return exp1->calculate() != exp2->calculate();
  } else {
    throw "condition is invalid";
  }
}
IfWhileCommand::IfWhileCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}


