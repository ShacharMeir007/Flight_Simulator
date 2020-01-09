//
// Created by yonathank on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMANDMAP_H_
#define FLIGHT_SIMULATOR__COMMANDMAP_H_
#include <unordered_map>
#include "SharedData.h"
#include "Command.h"
#include "OpenDataServerCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "VarCommand.h"
class CommandMap {
  std::unordered_map<std::string, Command*> map_;
 public:
  Command* getCommand(std::string& s);
  CommandMap(SharedData* data);
};

#endif //FLIGHT_SIMULATOR__COMMANDMAP_H_
