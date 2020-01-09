//
// Created by shachar Meir on 08/01/2020.
//

#ifndef FLIGHT_SIMULATOR__SHAREDDATA_H_
#define FLIGHT_SIMULATOR__SHAREDDATA_H_
#include <vector>
#include <string>
//This class is for shared data the thread might need.
//Every time you need to share data between threads you'll use
//this class.
class SharedData {
  std::vector<std::string> vars_right_Bind;
  std::vector<std::string> vars_left_Bind;
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
