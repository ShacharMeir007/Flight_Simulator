//
// Created by shachar Meir on 05/01/2020.
//


#include "Lexer.h"
#include "Expression/ex1.h"
#include "Expression/Interpreter.h"
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

// text methods
void Lexer::replace(const char token1,const std::string & token2, std::string& str){
  std::string tmp;
  bool in_text = false;
  for (char& c:str){
    if (!in_text) {
      if (c == token1) {
        tmp += token2;
      } else {
        tmp += c;
        if(c=='"'){
          in_text = true;
        }
      }
    } else{
      tmp += c;
      if(c=='"'){
        in_text = false;
      }
    }
  }
  str = tmp;
}

void Lexer::remove_redundant_signs(std::string& str){
  std::string tmp;
  bool space_mode = false;
  for (char& c:str) {
    //trailing spaces
    if (c==' '){
      if (!space_mode){
        space_mode = true;
        tmp += c;
      }
    } else{
      space_mode = false;
      if (c!= '\t') {
        tmp += c;
      }
    }
  }
  str = tmp;
}

void Lexer::remove_quotation(std::string& str){
  std::string tmp;
  for (char& c:str) {
    if(c!= '"'){
      tmp += c;
    }
  }
  str = tmp;
}
std::vector<std::string> Lexer::split(const char token, std::string& str) {
  std::vector<std::string> vector;
  std::string temp;
  bool in_text = false;
  for(char& c:str){
    if (!in_text) {
      if (c == token) {
        vector.push_back(temp);
        temp = std::string();
      } else {
        temp += c;
        if (c == '"'){
          in_text = true;
        }
      }
    } else{
      temp += c;
      if (c == '"'){
        in_text = false;
      }
    }
  }
  if(!temp.empty()){
    vector.push_back(temp);
  }
  return vector;
}

void Lexer::strip(std::string& str) {
  std::string tmp;
  int i = 0;
  int j = str.length() - 1;
  while (str.substr(i,1)==" "){
    i++;
  }
  while (str.substr(j,1)==" "){
    j--;
  }
  str = str.substr(i,j-i+1);
}
//vector methods
void Lexer::printvector(std::vector<std::string> vector){
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
bool isOpenDataServer(std::string& str) {
  return str.substr(0, 14) == "openDataServer";
}
bool isConnectControlClient(std::string& str) {
  return str.substr(0, 20) == "connectControlClient";
}
bool isVar(std::string& str) {
  return str.substr(0, 3) == "var";
}
bool isPrint(std::string& str) {
  return str.substr(0, 5) == "Print";
}
bool isAssign(std::string& str) {
  for (char& c: str){
    if(c=='=') {
      return true;
    }
  }
  return false;
}
bool isCondition(std::string& str) {
  return str.substr(0, 5) == "while" || str.substr(0, 2) == "if";
}

//public methods
void Lexer::lex() {
  std::string line;
  int i = 1;
  while (!(line = readLine()).empty()){
    strip(line);
    this->replace('('," ",line);
    this->replace(')',"",line);
    this->replace(','," ", line);
    this->remove_redundant_signs(line);
    //this->remove_quotation(line);
    std::vector<std::string> vector = split(' ', line);
    if(isVar(line)){
      handleVar(vector);
    } else if(isCondition(line)){
      handleCondition(line);
    } else if(isPrint(line)){
      handlePrint(line);
    } else if(isAssign(line)) {
      handleAssign(vector);
    }
    handleGeneral(vector);
    this->copyCommands(vector);
    i++;
  }
  this->printvector(this->commends);
}


void Lexer::handleVar(std::vector<std::string>& basic_string) {
  std::vector<std::string> elements;
  for (std::string s: basic_string){
    if (s!="sim"){
      remove_quotation(s);
      elements.push_back(s);
    }
  }
  basic_string = elements;
}
void Lexer::handleCondition(std::string basic_string) {

}
void Lexer::handlePrint(std::string basic_string) {

}
void Lexer::handleGeneral(std::vector<std::string>& vector) {
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
  for (int kI = 2; kI < vector.size() ; ++kI) {
    expressionString += vector[kI];
  }
  newVec.push_back(expressionString);
  vector = newVec;
}
