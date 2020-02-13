//
// Created by yonathank on 09/01/2020.
//

#include "CommandMap.h"
Command* CommandMap::getCommand(std::string& s) {
  try {
    Command* command = map_.at(s);
    return command;
  } catch (std::out_of_range& ofRange){
    std::cout<<"couldn't find command: "<<s<<std::endl;
    return nullptr;
  }

}
CommandMap::CommandMap(SharedData* data, Interpreter* interpreter) {
  // create every Command type object in advance more efficient
  // for run time
  map_["openDataServer"] = new OpenDataServerCommand(data, interpreter);
  map_["connectControlClient"] = new ConnectClientCommand(data, interpreter);
  map_["Print"] = new PrintCommand(data, interpreter);
  map_["Sleep"] = new SleepCommand(data, interpreter);
  map_["var"] = new VarCommand(data, interpreter);
  map_["="] = new AssignCommand(data, interpreter);
  map_["while"] = new IfWhileCommand(data, interpreter);
  map_["if"] = new IfWhileCommand(data, interpreter);
}
