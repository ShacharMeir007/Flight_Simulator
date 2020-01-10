//
// Created by shachar Meir on 10/01/2020.
//

#ifndef FLIGHT_SIMULATOR__THREADLOCK_H_
#define FLIGHT_SIMULATOR__THREADLOCK_H_
#include <thread>
#include "mutex"
#include <string>
#include <sstream>
class ThreadLock {
 public:
  std::string locking_thread;
  std::mutex mutex_;
  bool acquire_lock();
  bool release_lock();
  std::string id_to_str(std::thread::id);
  void set_locking_thread();
};

#endif //FLIGHT_SIMULATOR__THREADLOCK_H_
