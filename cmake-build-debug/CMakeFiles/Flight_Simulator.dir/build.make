# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/shacharmeir/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/shacharmeir/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/shacharmeir/CLionProjects/Flight Simulator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Flight_Simulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Flight_Simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Flight_Simulator.dir/flags.make

CMakeFiles/Flight_Simulator.dir/main.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Flight_Simulator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/main.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/main.cpp"

CMakeFiles/Flight_Simulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/main.cpp" > CMakeFiles/Flight_Simulator.dir/main.cpp.i

CMakeFiles/Flight_Simulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/main.cpp" -o CMakeFiles/Flight_Simulator.dir/main.cpp.s

CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o: ../Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/Lexer.cpp"

CMakeFiles/Flight_Simulator.dir/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/Lexer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/Lexer.cpp" > CMakeFiles/Flight_Simulator.dir/Lexer.cpp.i

CMakeFiles/Flight_Simulator.dir/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/Lexer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/Lexer.cpp" -o CMakeFiles/Flight_Simulator.dir/Lexer.cpp.s

CMakeFiles/Flight_Simulator.dir/Command.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/Command.cpp.o: ../Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Flight_Simulator.dir/Command.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/Command.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/Command.cpp"

CMakeFiles/Flight_Simulator.dir/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/Command.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/Command.cpp" > CMakeFiles/Flight_Simulator.dir/Command.cpp.i

CMakeFiles/Flight_Simulator.dir/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/Command.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/Command.cpp" -o CMakeFiles/Flight_Simulator.dir/Command.cpp.s

CMakeFiles/Flight_Simulator.dir/Server.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Flight_Simulator.dir/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/Server.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/Server.cpp"

CMakeFiles/Flight_Simulator.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/Server.cpp" > CMakeFiles/Flight_Simulator.dir/Server.cpp.i

CMakeFiles/Flight_Simulator.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/Server.cpp" -o CMakeFiles/Flight_Simulator.dir/Server.cpp.s

CMakeFiles/Flight_Simulator.dir/Client.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Flight_Simulator.dir/Client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/Client.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/Client.cpp"

CMakeFiles/Flight_Simulator.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/Client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/Client.cpp" > CMakeFiles/Flight_Simulator.dir/Client.cpp.i

CMakeFiles/Flight_Simulator.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/Client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/Client.cpp" -o CMakeFiles/Flight_Simulator.dir/Client.cpp.s

CMakeFiles/Flight_Simulator.dir/Parser.cpp.o: CMakeFiles/Flight_Simulator.dir/flags.make
CMakeFiles/Flight_Simulator.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Flight_Simulator.dir/Parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Flight_Simulator.dir/Parser.cpp.o -c "/Users/shacharmeir/CLionProjects/Flight Simulator/Parser.cpp"

CMakeFiles/Flight_Simulator.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Simulator.dir/Parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shacharmeir/CLionProjects/Flight Simulator/Parser.cpp" > CMakeFiles/Flight_Simulator.dir/Parser.cpp.i

CMakeFiles/Flight_Simulator.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Simulator.dir/Parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shacharmeir/CLionProjects/Flight Simulator/Parser.cpp" -o CMakeFiles/Flight_Simulator.dir/Parser.cpp.s

# Object files for target Flight_Simulator
Flight_Simulator_OBJECTS = \
"CMakeFiles/Flight_Simulator.dir/main.cpp.o" \
"CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o" \
"CMakeFiles/Flight_Simulator.dir/Command.cpp.o" \
"CMakeFiles/Flight_Simulator.dir/Server.cpp.o" \
"CMakeFiles/Flight_Simulator.dir/Client.cpp.o" \
"CMakeFiles/Flight_Simulator.dir/Parser.cpp.o"

# External object files for target Flight_Simulator
Flight_Simulator_EXTERNAL_OBJECTS =

Flight_Simulator: CMakeFiles/Flight_Simulator.dir/main.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/Lexer.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/Command.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/Server.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/Client.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/Parser.cpp.o
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/build.make
Flight_Simulator: CMakeFiles/Flight_Simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Flight_Simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Flight_Simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Flight_Simulator.dir/build: Flight_Simulator

.PHONY : CMakeFiles/Flight_Simulator.dir/build

CMakeFiles/Flight_Simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Flight_Simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Flight_Simulator.dir/clean

CMakeFiles/Flight_Simulator.dir/depend:
	cd "/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/shacharmeir/CLionProjects/Flight Simulator" "/Users/shacharmeir/CLionProjects/Flight Simulator" "/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug" "/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug" "/Users/shacharmeir/CLionProjects/Flight Simulator/cmake-build-debug/CMakeFiles/Flight_Simulator.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Flight_Simulator.dir/depend

