//
// Created by shachar Meir on 06/01/2020.
//

// Server side C/C++ program to demonstrate Socket programming
#include "MyServer.h"
void runDataServer(int port, SharedData* data)
{
  data->harsh_lock();
  std::map<std::string, double > map;
  map["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
  map["/sim/time/warp"] = 0;
  map["/controls/switches/magnetos"] = 0;
  map["/instrumentation/heading-indicator/offset-deg"] = 0;
  map["/instrumentation/altimeter/indicated-altitude-ft"] = 0;
  map["/instrumentation/altimeter/pressure-alt-ft"] = 0;
  map["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 0;
  map["/instrumentation/attitude-indicator/indicated-roll-deg"] = 0;
  map["/instrumentation/attitude-indicator/internal-pitch-deg"] = 0;
  map["/instrumentation/attitude-indicator/internal-roll-deg"] = 0;
  map["/instrumentation/encoder/indicated-altitude-ft"] = 0;
  map["/instrumentation/encoder/pressure-alt-ft"] = 0;
  map["/instrumentation/gps/indicated-altitude-ft"] = 0;
  map["/instrumentation/gps/indicated-ground-speed-kt"] = 0;
  map["/instrumentation/gps/indicated-vertical-speed"] = 0;
  map["/instrumentation/heading-indicator/indicated-heading-deg"] = 0;
  map["/instrumentation/magnetic-compass/indicated-heading-deg"] = 0;
  map["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 0;
  map["/instrumentation/turn-indicator/indicated-turn-rate"] = 0;
  map["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 0;
  map["/controls/flight/aileron"] = 0;
  map["/controls/flight/elevator"] = 0;
  map["/controls/flight/rudder"] = 0;
  map["/controls/flight/flaps"] = 0;
  map["/controls/engines/engine/throttle"] = 0;
  map["/controls/engines/current-engine/throttle"] = 0;
  map["/controls/switches/master-avionics"] = 0;
  map["/controls/switches/starter"] = 0;
  map["/engines/active-engine/auto-start"] = 0;
  map["/controls/flight/speedbrake"] = 0;
  map["/sim/model/c172p/brake-parking"] = 0;
  map["/controls/engines/engine/primer"] = 0;
  map["/controls/engines/current-engine/mixture"] = 0;
  map["/controls/switches/master-bat"] = 0;
  map["/controls/switches/master-alt"] = 0;
  map["/engines/engine/rpm"] = 0;
  std::cout<<"running server"<<std::endl;
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


  if (::bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
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
  data->harsh_release();
  //reading from client
  while (true) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    data->harsh_lock();
    std::string buff(buffer);
    std::vector<std::string> str_values = split(',',buff);
    std::vector<double> _values = convert_to_double(str_values);
    insert_values_to_map(map, _values);
    std::vector<std::pair<std::string,std::string>>* bind_vars = data->safe_getVarsLeftBind();
    for (std::pair<std::string,std::string> pair: *bind_vars){
      double new_val = map.at(pair.second);
      data->safe_changeValue(pair.first, new_val);
    }
    std::cout << buffer << std::endl;
    data->harsh_release();
  }
  //writing back to client
  /*char *hello = "Hello, I can hear you! \n";
  send(client_socket , hello , strlen(hello) , 0 );
  std::cout<<"Hello message sent\n"<<std::endl;*/

}
std::vector<double> convert_to_double(std::vector<std::string>& vector){
  std::vector<double> doubles;
  for (std::string& s: vector){
    double value = std::stod(s);
    doubles.push_back(value);
  }
  return doubles;
}
void insert_values_to_map(std::map<std::string,double>& map, std::vector<double >& values){
  map["/instrumentation/airspeed-indicator/indicated-speed-kt"] = values[0];
  map["/sim/time/warp"] = values[1];
  map["/controls/switches/magnetos"] = values[2];
  map["/instrumentation/heading-indicator/offset-deg"] = values[3];
  map["/instrumentation/altimeter/indicated-altitude-ft"] = values[4];
  map["/instrumentation/altimeter/pressure-alt-ft"] = values[5];
  map["/instrumentation/attitude-indicator/indicated-pitch-deg"] = values[6];
  map["/instrumentation/attitude-indicator/indicated-roll-deg"] = values[7];
  map["/instrumentation/attitude-indicator/internal-pitch-deg"] = values[8];
  map["/instrumentation/attitude-indicator/internal-roll-deg"] = values[9];
  map["/instrumentation/encoder/indicated-altitude-ft"] = values[10];
  map["/instrumentation/encoder/pressure-alt-ft"] = values[11];
  map["/instrumentation/gps/indicated-altitude-ft"] = values[12];
  map["/instrumentation/gps/indicated-ground-speed-kt"] = values[13];
  map["/instrumentation/gps/indicated-vertical-speed"] = values[14];
  map["/instrumentation/heading-indicator/indicated-heading-deg"] = values[15];
  map["/instrumentation/magnetic-compass/indicated-heading-deg"] = values[16];
  map["/instrumentation/slip-skid-ball/indicated-slip-skid"] = values[17];
  map["/instrumentation/turn-indicator/indicated-turn-rate"] = values[18];
  map["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = values[19];
  map["/controls/flight/aileron"] = values[20];
  map["/controls/flight/elevator"] = values[21];
  map["/controls/flight/rudder"] = values[22];
  map["/controls/flight/flaps"] = values[23];
  map["/controls/engines/engine/throttle"] = values[24];
  map["/controls/engines/current-engine/throttle"] = values[25];
  map["/controls/switches/master-avionics"] = values[26];
  map["/controls/switches/starter"] = values[27];
  map["/engines/active-engine/auto-start"] = values[28];
  map["/controls/flight/speedbrake"] = values[29];
  map["/sim/model/c172p/brake-parking"] = values[30];
  map["/controls/engines/engine/primer"] = values[31];
  map["/controls/engines/current-engine/mixture"] = values[32];
  map["/controls/switches/master-bat"] = values[33];
  map["/controls/switches/master-alt"] = values[34];
  map["/engines/engine/rpm"] = values[35];
}
void openDataServer(int port, SharedData* shared_data){
  std::thread thread1(runDataServer, port, shared_data);
  thread1.detach();
}