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
std::list<std::string> Lexer::split(const char token, std::string& str) {
  std::list<std::string> list;
  std::string temp;
  bool in_text = false;
  for(char& c:str){
    if (!in_text) {
      if (c == token) {
        list.push_back(temp);
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
    list.push_back(temp);
  }
  return list;
}

//list methods
void Lexer::printList(std::list<std::string> list){
  for(std::string s: list){
    std::cout<<s<<std::endl;
  }
}

void Lexer::copyCommands( const std::list<std::string>& list) {
  for(const std::string& s: list){
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
void Lexer::lex() {
  std::string line;
  while (!(line = readLine()).empty()){
    this->replace('('," ",line);
    this->replace(')',"",line);
    this->replace(','," ", line);
    this->remove_redundant_signs(line);
    std::list<std::string>list = split(' ', line);
    this->copyCommands(list);
  }
  this->printList(this->commends);
}
