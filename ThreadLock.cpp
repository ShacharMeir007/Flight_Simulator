//
// Created by shachar Meir on 10/01/2020.
//


#include "ThreadLock.h"
bool ThreadLock::acquire_lock() {
  std::string current = this->id_to_str(std::this_thread::get_id());
  bool is_same_thread = current == this->locking_thread;
  if (!is_same_thread){
    this->mutex_.lock();
    this->locking_thread = current;
    return true;
  }
  return false;
}
bool ThreadLock::release_lock() {
  std::string current = this->id_to_str(std::this_thread::get_id());
  bool is_same_thread = current == this->locking_thread;
  if (!is_same_thread){
    this->mutex_.unlock();
    this->locking_thread = "";
    return true;
  }
  return false;
}
std::string ThreadLock::id_to_str(std::thread::id id) {
  std::stringstream ss;
  ss << id;
  return ss.str();
}
void ThreadLock::set_locking_thread() {
  this->locking_thread = this->id_to_str(std::this_thread::get_id());
}
