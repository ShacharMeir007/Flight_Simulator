//
// Created by yonathank on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMANDMAP_H_
#define FLIGHT_SIMULATOR__COMMANDMAP_H_
#include "Command.h"
#include <unordered_map>
#include "OpenDataServerCommand.h"
class CommandMap {
  std::unordered_map<std::string, Command*> map_;
 public:
  Command* getCommand(std::string s);
  CommandMap();
};

#endif //FLIGHT_SIMULATOR__COMMANDMAP_H_
