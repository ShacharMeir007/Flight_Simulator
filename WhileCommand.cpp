//
// Created by shachar Meir on 10/01/2020.
//

#include "WhileCommand.h"
#include "Parser.h"
void WhileCommand::execute(std::vector<std::string> &args) {
  std::string expression1 = args[0];
  std::string condition = args[1];
  std::string expression2 = args[2];
  Parser parser(shared_data);
  std::vector<std::string> commands;
  int size = args.size();
  for (int kI = 3; kI < size; ++kI) {
    commands.push_back(args[kI]);
  }
  this->shared_data->harsh_lock();
  std::vector<std::string>* right_list = this->shared_data->safe_getVarsRightBind();
  std::vector<std::string>* left_list = this->shared_data->safe_getVarsLeftBind();
  SymbolTable* table = this->shared_data->safe_getSymbolTable();
  setVariablesFromVector(right_list, table);
  setVariablesFromVector(left_list, table);
  try{
    Expression* result1 = this->interpreter_.interpret(expression1.c_str());
    Expression* result2 = this->interpreter_.interpret(expression2.c_str());
    int u = 1;
    while (check_condition(result1,condition, result2)){
      parser.parse(&commands);
      std::cout<<"loop number"<<u<<std::endl;
      u++;
    }
  } catch (const char* p){
    std::cout<<p<<std::endl;
    this->shared_data->harsh_release();
  }
  this->shared_data->harsh_release();
}
int WhileCommand::numArg() {
  return -1;
}
void WhileCommand::setVariablesFromVector(std::vector<std::string> * vector,
                                           SymbolTable* table) {
  for (std::string& s : *vector){
    double value = table->get(s).GetValue();
    std::string var_str = s+"="+std::to_string(value);
    this->interpreter_.setVariables(var_str.c_str());
  }
}

WhileCommand::WhileCommand(SharedData *data) : Command(data) {

}
bool WhileCommand::check_condition(Expression *exp1, std::string condition, Expression *exp2) {
  return false;
}

