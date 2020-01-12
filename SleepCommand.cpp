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
  //sets argument
  std::string str_milliseconds_exp = args[0];
  //converts time to int
  double val = this->evaluate_expression(str_milliseconds_exp);
  int milliseconds = int(val);

  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

}
int SleepCommand::numArg() {
  return 1;
}
SleepCommand::SleepCommand(SharedData *p_data, Interpreter *p_interpreter) : Command(p_data, p_interpreter) {

}
