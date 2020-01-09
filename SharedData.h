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
  std::vector<std::string>* vars_right_Bind = nullptr;
  std::vector<std::string>* vars_left_Bind = nullptr;
 public:
  SharedData();
  virtual ~SharedData();
  std::vector<std::string> *GetVarsRightBind() const;
  void SetVarsRightBind(std::vector<std::string> *new_vars_right_bind);
  std::vector<std::string> *GetVarsLeftBind() const;
  void SetVarsLeftBind(std::vector<std::string> *new_vars_left_bind);
};

#endif //FLIGHT_SIMULATOR__SHAREDDATA_H_
