cmake_minimum_required(VERSION 3.15)
project(Flight_Simulator)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Flight_Simulator main.cpp Lexer.cpp Lexer.h Command.cpp Command.h MyServer.cpp Client.cpp Parser.cpp Parser.h OpenDataServerCommand.cpp OpenDataServerCommand.h SharedData.cpp SharedData.h BindDirection.h SymbolTable.cpp SymbolTable.h Symbol.cpp Symbol.h PrintCommand.cpp PrintCommand.h VarCommand.cpp VarCommand.h SleepCommand.cpp SleepCommand.h TextFunctions.h TextFunctions.cpp MyServer.h CommandMap.cpp CommandMap.h AssignCommand.cpp AssignCommand.h ConnectClientCommand.cpp ConnectClientCommand.h Expression/ex1.cpp Expression/Expression.cpp Expression/Interpreter.cpp ThreadLock.cpp ThreadLock.h)