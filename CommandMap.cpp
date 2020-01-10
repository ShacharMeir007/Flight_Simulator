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
CommandMap::CommandMap(SharedData* data) {
  map_["openDataServer"] = new OpenDataServerCommand(data);
  map_["Print"] = new PrintCommand(data);
  map_["Sleep"] = new SleepCommand(data);
  map_["var"] = new VarCommand(data);
  map_["="] = new AssignCommand(data);
}
