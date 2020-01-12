//
// Created by shachar Meir on 05/01/2020.
//


#include "Lexer.h"
//constructor
Lexer::Lexer(const std::string& filename) {
  this->input_stream.open(filename);
  if (!input_stream.is_open()) {
    throw "The File could not have been opened";
  }
}
//destructor
Lexer::~Lexer() {
  this->input_stream.close();
}

//vector methods
void Lexer::printVector(std::vector<std::string> vector){
  for(std::string s: vector){
    std::cout<<s<<std::endl;
  }
}

void Lexer::copyCommands( const std::vector<std::string>& vector) {
  for(const std::string& s: vector){
    this->commends.push_back(s);
  }
}

//file methods
std::string Lexer::readLine() {
  //creating input stream
  std::string line;
  std::getline(input_stream,line);
  return line;
}


//public methods
std::vector<std::string> Lexer::lex() {
  std::string line;
  while (!(line = readLine()).empty()){
    strip(line);
    if (!isAssign(line)){
      replace('('," ",line);
      replace(')',"",line);
      replace(','," ", line);
    }
    makeConditionBetSpaces(line);
    //spacen(line);
    remove_redundant_signs(line);
    std::vector<std::string> vector = split(' ', line);
    if(isVar(line)){
      handleVar(vector);
    } else if(isCondition(line)){
      handleCondition(vector);
    } else if(isAssign(line)) {
      handleAssign(vector);
    }
    //handleQuotation(vector);
    this->copyCommands(vector);
  }
  this->printVector(this->commends);
  return this->commends;
}
//handle functions
void Lexer::handleVar(std::vector<std::string>& vector) {
  std::vector<std::string> elements;
  std::string expressionString;
  bool is_equality = false;
  int size = vector.size();
  for (int kI = 0; kI < size; ++kI) {
    if (!is_equality) {
      if (vector[kI] != "sim") {
        remove_quotation(vector[kI]);
        elements.push_back(vector[kI]);
      }
      if (vector[kI] == "=") {
        is_equality = true;
      }
    } else{
      expressionString += vector[kI];
    }
  }
  if (!expressionString.empty()){
    elements.push_back(expressionString);
  }
  vector = elements;
}
void Lexer::handleCondition(std::vector<std::string>& vector) {
  std::vector<std::string> newVec;
  std::string expressionString1;
  std::string expressionString2;
  newVec.push_back(vector[0]);
  int i =1;
  while (!isLogicOperator(vector[i])){
    expressionString1 += vector[i];
    i++;
  }
  newVec.push_back(expressionString1);
  newVec.push_back(vector[i]);
  i++;
  while (vector[i]!="{"){
    expressionString2 += vector[i];
    i++;
  }
  newVec.push_back(expressionString2);
  newVec.push_back(vector[i]);
  vector = newVec;
}
void Lexer::handleQuotation(std::vector<std::string>& vector) {
  for (std::string& s: vector){
    remove_quotation(s);
  }
}
void Lexer::handleAssign(std::vector<std::string> &vector) {
  std::vector<std::string> newVec;
  std::string expressionString;
  //adding the '='
  newVec.push_back(vector[1]);
  //adding var name
  newVec.push_back(vector[0]);
  //creating Expression string
  for (unsigned int kI = 2; kI < vector.size() ; ++kI) {
    expressionString += vector[kI];
  }
  newVec.push_back(expressionString);
  vector = newVec;
}
