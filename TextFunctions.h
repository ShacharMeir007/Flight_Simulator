//
// Created by shachar Meir on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__TEXTFUNCTIONS_H_
#define FLIGHT_SIMULATOR__TEXTFUNCTIONS_H_
#include <vector>
#include <string>
#include <iostream>
//functions to help manage operations on strings
void replace(char token1,const std::string & token2, std::string& str);
void remove_redundant_signs(std::string& str);
void remove_spaces(std::string& str);
void remove_quotation(std::string& str);
std::vector<std::string> split(char token, std::string& str);
void strip(std::string& str);
bool isVar(std::string& str);
bool isInQuotations(std::string& str);
bool isAssign(std::string& str);
bool isCondition(std::string& str);
bool isLogicOperator(std::string &str);
bool isOpenDataServer(std::string &str);
bool isConnectControlClient(std::string &str);
bool isPrint(std::string &str);
bool isSleep(std::string &str);
void makeConditionBetSpaces(std::string &s);

#endif //FLIGHT_SIMULATOR__TEXTFUNCTIONS_H_
