//
// Created by shachar Meir on 05/11/2019.
//

#include <iostream>
#include <regex>
#include <stack>
#include <queue>
#include "Interpreter.h"

Expression *Interpreter::interpret(const char * in) {

  string input(in);
  queue<string> postfix = shunting_yard(input);
  stack<Expression*> exp_stack;
  //cout<<endl;
  while (!postfix.empty()){
    string fr = postfix.front();
    //cout<<"pulled :"<<fr<<endl;
    if (isNumber(fr)){
      exp_stack.push(new Value(std::stod(fr)));
    } else if(is_operator(fr)){
      Expression *rExp;
      if (!exp_stack.empty()) {
        rExp = exp_stack.top();
        exp_stack.pop();
      } else {
        throw "illegal math expression";
      }
      Expression* lExp;
      if (!exp_stack.empty()) {
        lExp = exp_stack.top();
        exp_stack.pop();
      } else{
        throw "illegal math expression";
      }
      exp_stack.push(ActivateOper(lExp, rExp, fr));
    } else if (is_Unary_operator(fr)) {
      Expression* exp = exp_stack.top();
      exp_stack.pop();
      exp_stack.push(ActivateUnaryOper(exp,fr));
    }
    postfix.pop();
  }
  return exp_stack.top();
}

void Interpreter::setVariables(const char * input) {
  string s(input);
  bool isname = true;
  string name;
  string val;
  for(char& c : s) {
    if (isname) {
      if(c != '=') {
        name+=c;
      } else{
        isname = false;
      }
    } else {
      if (c != ';' && c != '\0') {
        val +=c;
      } else{
        this->addToVarMap(name, val);
        //i
        isname = true;
        name = "";
        val = "";
      }
    }
  }
  if (!val.empty()) {
    this->addToVarMap(name, val);
  }
}

void Interpreter::addToVarMap(const string& name, const string& val) {
//add to list
  if (!Interpreter::isNumber(val)){
    throw "this is not a valid number";

  }
  if (!Interpreter::is_valid_name(name)){
    throw "this is not a valid name";
  }

  double value = stod(val);

  if (this->varMap.find(name) == this->varMap.end()) {
    this->varMap.insert(pair<string,double >(name,value));
  } else {
    this->varMap.find(name)->second = value;
  }
}
bool Interpreter::isNumber(const string& s){
  std::regex number("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
  return std::regex_match(s, number);
}

bool Interpreter::is_valid_name(const string& s){
  std::regex name("([a-z|A-Z]|_)(\\d|[a-z|A-Z]|_)*");
  return std::regex_match(s, name);
}

Interpreter::Interpreter() {

}

queue<string> Interpreter::shunting_yard(const string& input) {
  const string operators[] = {"*", "/", "+", "-"};
  bool is_unary = true;
  bool last_operator = false;
  queue <string> numbers_queue;
  stack <char> operators_stack;
  string number;
  // looping through the characters
  for(const char c : input){
    string s;
    s+= c;
    if (is_operator(s)) {

      //pushing the number or the variable value to the queue
      if (isNumber(number)) {
        numbers_queue.push(number);
        //cout<<"pushed :"<<number<<endl;
        number ="";
        is_unary = false;
      } else if(is_valid_name(number)){
        if(this->varMap.find(number) != this->varMap.end()){
          numbers_queue.push(std::to_string(this->varMap[number]));
          //cout<<"pushed :"<<this->varMap[number]<<endl;
          number ="";
          is_unary = false;
        } else{
          throw "this is not recognized";
        }
      } else if(number.empty()){
        is_unary = true;
      } else if(number.empty() && !last_operator){

      } else {
        throw "this is not recognized";
      }
      //checking if the operator is unary
      is_unary = is_unary&&!last_operator;
      //pushing the operator to the stack
      if(c==')'){
        last_operator = true;
        while (!operators_stack.empty()) {
          if (operators_stack.top() != '(') {
            numbers_queue.push(string(1, operators_stack.top()));
            //cout<<operators_stack.top()<<endl;
            operators_stack.pop();
          } else{
            operators_stack.pop();
            break;
          }
        }
      } else {
        last_operator = false;
        while (!operators_stack.empty()) {
          if (precedence(c, is_unary) < precedence(operators_stack.top())) {
            //moving the smaller precedence operator to the number queue
            numbers_queue.push(string(1, operators_stack.top()));
            //cout << operators_stack.top() << endl;
            operators_stack.pop();
          } else {
            break;
          }
        }
        if (is_unary){
          if (c == '-'){
            operators_stack.push('!');
            //cout<<"pushed :!"<<endl;
          } else if(c == '+'){
            operators_stack.push('@');
            //cout<<"pushed :@"<<endl;
          } else{
            operators_stack.push(c);
            //cout<<"pushed :"<<c<<endl;
          }
        }
        else{
          operators_stack.push(c);
          //cout<<"pushed :"<<c<<endl;
        }
      }

    } else {
      number+=c;
    }
  }
  // operating on last number
  if (!number.empty()) {
    if (isNumber(number)) {
      numbers_queue.push(number);
      //cout<<"pushed :"<<number<<endl;
      number ="";
    } else if(is_valid_name(number)){
      if(this->varMap.find(number) != this->varMap.end()){
        numbers_queue.push(std::to_string(this->varMap[number]));
        number ="";
      } else {
        throw "this is not recognized";

      }
    } else {
      throw "this is not recognized";
    }
  }
  while (!operators_stack.empty()){
    numbers_queue.push(string(1,operators_stack.top()));
    operators_stack.pop();
  }
  return numbers_queue;
}
bool Interpreter::is_operator(const string& c) {
  const string operators[] = {"+","-","*","/","(",")"};
  queue <string> numbers_queue;
  stack <char> operators_stack;
  for(const string& op: operators){
    if (c == op){
      return true;
    }
  }
  return false;
}
Expression *Interpreter::ActivateOper(Expression *left_expression, Expression *right_expression, string& oper) {
  if(oper == "+") {
    return new Plus(left_expression, right_expression);
  } else if(oper == "-") {
    return new Minus(left_expression, right_expression);
  } else if(oper == "*") {
    return new Mul(left_expression, right_expression);
  } else if(oper == "/") {
    return new Div(left_expression, right_expression);
  }
  else {
    throw "not an operator";
  }
}
int Interpreter::precedence(const char & c) {
  switch (c){
    case '+':return 1;
    case '-':return 1;
    case '*':return 2;
    case '/':return 2;
    case '!':return 3;
    case '@':return 3;
    default:return 0;
  }
}
int Interpreter::precedence(const char & c, bool is_unary) {
  switch (c){
    case '+':if (is_unary) {
        return 3;
      } else {
        return 1;
      }
    case '-':
      if (is_unary) {
        return 3;
      } else {
        return 1;
      }
    case '*':return 2;
    case '/':return 2;
    default:return 3;
  }
}
bool Interpreter::is_Unary_operator(string& c) {
  const string operators[] = {"!","@"};
  queue <string> numbers_queue;
  stack <char> operators_stack;
  for(const string& op: operators){
    if (c == op){
      return true;
    }
  }
  return false;
}
Expression *Interpreter::ActivateUnaryOper(Expression *expression, string oper) {
  if(oper == "@") {
    return new UPlus(expression);
  } else if(oper == "!") {
    return new UMinus(expression);
  } else {
    throw "not a unary operator";
  }
}



