//
// Created by shachar Meir on 06/01/2020.
//
#ifndef FLIGHT_SIMULATOR__MYSERVER_H_
#define FLIGHT_SIMULATOR__SERVER_H_
// Server side C/C++ program to demonstrate Socket programming
#include "MyServer.h"
void runDataServer(int port)
{

  //create socket
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    //error
    std::cerr << "Could not create a socket"<<std::endl;
  }

  //bind socket to IP address
  // we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(port);
  //we need to convert our number
  // to a number that the network understands.

  //the actual bind command
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    std::cerr<<"Could not bind the socket to an IP"<<std::endl;
  }

  //making socket listen to the port
  if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
    std::cerr<<"Error during listening command"<<std::endl;
  } else{
    std::cout<<"Server is now listening ..."<<std::endl;
  }
  
  // accepting a client
  int client_socket = accept(socketfd, (struct sockaddr *)&address,
                             (socklen_t*)&address);

  if (client_socket == -1) {
    std::cerr<<"Error accepting client"<<std::endl;

  }

  close(socketfd); //closing the listening socket

  //reading from client
  while (true) {
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);
    std::cout << buffer << std::endl;
  }
  //writing back to client
  /*char *hello = "Hello, I can hear you! \n";
  send(client_socket , hello , strlen(hello) , 0 );
  std::cout<<"Hello message sent\n"<<std::endl;*/

}
void openDataServer(int port){
  std::thread thread1(runDataServer, port);
  thread1.join();
}
#endif //FLIGHT_SIMULATOR__MYSERVER_H_