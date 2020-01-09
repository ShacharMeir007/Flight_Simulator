//
// Created by yonathank on 09/01/2020.
//

#include "CommandMap.h"
Command* CommandMap::getCommand(std::string s) {
  return map_.find(s)->second;
}
CommandMap::CommandMap() {
  map_["openDataServer"] = new OpenDataServerCommand();
}
