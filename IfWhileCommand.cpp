//
// Created by shachar Meir on 10/01/2020.
//

#include "IfWhileCommand.h"
#include "Parser.h"
void IfWhileCommand::execute(std::vector<std::string> &args) {
  std::string ifOrWhile = args[0];
  std::string expression1 = args[1];
  std::string condition = args[2];
  std::string expression2 = args[3];
  Parser parser(shared_data);
  std::vector<std::string> commands;
  int size = args.size();
  for (int kI = 4; kI < size; ++kI) {
    commands.push_back(args[kI]);
  }
  try{
    Expression* result1;
    Expression* result2;
    this->shared_data->harsh_lock();
    initInterpreterVar();
    this->shared_data->harsh_release();
    result1 = this->interpreter_->interpret(expression1.c_str());
    result2 = this->interpreter_->interpret(expression2.c_str());
    int u = 1;
    if (ifOrWhile == "while") {
      while (check_condition(result1,condition, result2)){
        parser.parse(&commands);
        std::cout<<"loop number"<<u<<std::endl;
        this->shared_data->harsh_lock();
        initInterpreterVar();
        this->shared_data->harsh_release();
        delete (result1);
        delete (result2);
        result1 = this->interpreter_->interpret(expression1.c_str());
        result2 = this->interpreter_->interpret(expression2.c_str());
        u++;
      }
    } else {
      if (check_condition(result1,condition, result2)) {
        parser.parse(&commands);
      }
    }
  } catch (const char* p){
    std::cout<<p<<std::endl;
    this->shared_data->harsh_release();
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


