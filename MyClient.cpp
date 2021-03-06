//
// Created by shachar Meir on 06/01/2020.
//

// Client side C/C++ program to demonstrate Socket programming

#include "MyClient.h"
void runClient(int port, std::string addr, SharedData* shared_data)
{
  //create socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    //error
    std::cerr << "Could not create a socket"<<std::endl;
  }

  //configure settings
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(addr.c_str());
  address.sin_port = htons(port);

  // Requesting a connection with the server
  int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
  if (is_connect == -1) {
    std::cerr << "Could not connect to host server"<<std::endl;
  } else {
    std::cout<<"Client is now connected to server" <<std::endl;
  }
  //if here we made a connection
  //
  while (true) {
    // checks break condition
    if(shared_data->checkTerminate()){
      break;
    }
    // gets variables to update
    auto bind_vars = shared_data->safe_getChangedVars();
    // compose set message and sends it
    // for each variable
    for (auto pair: bind_vars) {
      std::string message;
      double val = shared_data->safe_getValue(pair.first);
      message += "set";
      message += pair.second;
      message = message + " " + std::to_string(val);
      int is_sent = send(client_socket, message.c_str(), message.size(), 0);
      if (is_sent == -1) {
        std::cout << "Error sending message" << std::endl;
      }
    }
  }
  // closes connection to server
  close(client_socket);
  // notifies that this thread is terminates
  shared_data->setTerminated();

}
void connectMyClient(int port, std::string addr, SharedData* shared_data) {
  std::thread client_thread(runClient, port,addr , shared_data);
  client_thread.detach();
}
