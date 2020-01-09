//
// Created by shachar Meir on 09/01/2020.
//

// text methods
#include "TextFunctions.h"
void replace(const char token1,const std::string & token2, std::string& str){
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

void remove_redundant_signs(std::string& str){
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

void remove_quotation(std::string& str){
  std::string tmp;
  for (char& c:str) {
    if(c!= '"'){
      tmp += c;
    }
  }
  str = tmp;
}
std::vector<std::string> split(const char token, std::string& str) {
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

void strip(std::string& str) {
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

// checkers
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
bool isLogicOperator(std::string &str) {
  const std::string operators[] = {">", "<", ">=", "<=","==", "!="};
  for (const std::string& s: operators){
    if (s == str){
      return true;
    }
  }
  return false;
}
