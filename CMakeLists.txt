cmake_minimum_required(VERSION 3.15)
project(Flight_Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flight_Simulator main.cpp Lexer.cpp Lexer.h Command.cpp Command.h Server.cpp Client.cpp Parser.cpp Parser.h OpenDataServerCommand.cpp OpenDataServerCommand.h SharedData.cpp SharedData.h BindDirection.h SymbolTable.cpp SymbolTable.h)