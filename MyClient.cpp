//
// Created by shachar Meir on 06/01/2020.
//

// Client side C/C++ program to demonstrate Socket programming
#include "MyClient.h"
void runClient(int port, std::string addr, SharedData* shared_data)
{
  //create socket
  shared_data->harsh_lock();
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    //error
    std::cerr << "Could not create a socket"<<std::endl;
  }

  //We need to create a sockaddr obj to hold address of server
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;//IP4
  address.sin_addr.s_addr = inet_addr(addr.c_str());  //the localhost address
  address.sin_port = htons(port);
  //we need to convert our number (both port & localhost)
  // to a number that the network understands.

  // Requesting a connection with the server on local host with port 8081
  int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
  if (is_connect == -1) {
    std::cerr << "Could not connect to host server"<<std::endl;
  } else {
    std::cout<<"Client is now connected to server" <<std::endl;
  }
  shared_data->harsh_release();
  //if here we made a connection
  char hello[] = "Hi from client";
  int is_sent = send(client_socket , hello , strlen(hello) , 0 );
  if (is_sent == -1) {
    std::cout<<"Error sending message"<<std::endl;
  } else {
    std::cout<<"Hello message sent to server" <<std::endl;
  }

  char buffer[1024] = {0};
  int valread = read( client_socket , buffer, 1024);
  std::cout<<buffer<<std::endl;

  close(client_socket);

}
void connectMyClient(int port, std::string addr, SharedData* shared_data) {
  std::thread client_thread(runClient, port,addr , shared_data);
  client_thread.detach();
}
