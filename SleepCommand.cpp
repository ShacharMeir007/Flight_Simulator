//
// Created by shachar Meir on 09/01/2020.
//

#include <sstream>
#include "SleepCommand.h"
#include <thread>
void SleepCommand::execute(std::vector<std::string> &args) {
  if (args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string str_milliseconds = args[0];
  std::stringstream geek(str_milliseconds);
  int milliseconds = 0;
  geek >> milliseconds;
  std::this_thread::sleep_for(std::chrono::microseconds(milliseconds));
}
int SleepCommand::numArg() {
  return 1;
}
