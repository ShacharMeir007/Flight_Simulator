//
// Created by yonathank on 09/01/2020.
//

#ifndef FLIGHT_SIMULATOR__COMMANDMAP_H_
#define FLIGHT_SIMULATOR__COMMANDMAP_H_
#include <unordered_map>
#include "SharedData.h"
#include "Command.h"
#include "OpenDataServerCommand.h"
#include "ConnectClientCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "VarCommand.h"
#include "AssignCommand.h"
#include "IfWhileCommand.h"
class CommandMap {
  std::unordered_map<std::string, Command*> map_;
 public:
  Command* getCommand(std::string& s);
  CommandMap(SharedData* data, Interpreter* interpreter);
};

#endif //FLIGHT_SIMULATOR__COMMANDMAP_H_
