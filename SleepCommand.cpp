//
// Created by shachar Meir on 09/01/2020.
//

#include <sstream>
#include "SleepCommand.h"
#include <thread>
void SleepCommand::execute(std::vector<std::string> &args) {
  if ((int)args.size() != numArg()){
    throw "Not amount of arguments required";
  }
  std::string str_milliseconds = args[0];
  std::stringstream geek(str_milliseconds);
  int milliseconds = 0;
  geek >> milliseconds;
  std::cout<<"now sleeping for "<<milliseconds<<std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
  std::cout<<"I'm awake now"<<std::endl;
}
int SleepCommand::numArg() {
  return 1;
}
SleepCommand::SleepCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}
