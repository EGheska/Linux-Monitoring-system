# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pc/Desktop/Linux-Monitoring-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pc/Desktop/Linux-Monitoring-system/build

# Include any dependencies generated for this target.
include CMakeFiles/Linux-Monitoring-system.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Linux-Monitoring-system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Linux-Monitoring-system.dir/flags.make

CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/flags.make
CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o: ../main.cpp
CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o -MF CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o.d -o CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o -c /home/pc/Desktop/Linux-Monitoring-system/main.cpp

CMakeFiles/Linux-Monitoring-system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linux-Monitoring-system.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/Desktop/Linux-Monitoring-system/main.cpp > CMakeFiles/Linux-Monitoring-system.dir/main.cpp.i

CMakeFiles/Linux-Monitoring-system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linux-Monitoring-system.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/Desktop/Linux-Monitoring-system/main.cpp -o CMakeFiles/Linux-Monitoring-system.dir/main.cpp.s

CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/flags.make
CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o: ../src/linux_parser.cpp
CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o -MF CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o.d -o CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o -c /home/pc/Desktop/Linux-Monitoring-system/src/linux_parser.cpp

CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/Desktop/Linux-Monitoring-system/src/linux_parser.cpp > CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.i

CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/Desktop/Linux-Monitoring-system/src/linux_parser.cpp -o CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.s

CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/flags.make
CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o: ../src/process.cpp
CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o -MF CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o.d -o CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o -c /home/pc/Desktop/Linux-Monitoring-system/src/process.cpp

CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/Desktop/Linux-Monitoring-system/src/process.cpp > CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.i

CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/Desktop/Linux-Monitoring-system/src/process.cpp -o CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.s

CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/flags.make
CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o: ../src/system.cpp
CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o -MF CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o.d -o CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o -c /home/pc/Desktop/Linux-Monitoring-system/src/system.cpp

CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/Desktop/Linux-Monitoring-system/src/system.cpp > CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.i

CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/Desktop/Linux-Monitoring-system/src/system.cpp -o CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.s

CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/flags.make
CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o: ../src/processor.cpp
CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o: CMakeFiles/Linux-Monitoring-system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o -MF CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o.d -o CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o -c /home/pc/Desktop/Linux-Monitoring-system/src/processor.cpp

CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/Desktop/Linux-Monitoring-system/src/processor.cpp > CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.i

CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/Desktop/Linux-Monitoring-system/src/processor.cpp -o CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.s

# Object files for target Linux-Monitoring-system
Linux__Monitoring__system_OBJECTS = \
"CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o" \
"CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o" \
"CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o" \
"CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o" \
"CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o"

# External object files for target Linux-Monitoring-system
Linux__Monitoring__system_EXTERNAL_OBJECTS =

Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/main.cpp.o
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/src/linux_parser.cpp.o
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/src/process.cpp.o
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/src/system.cpp.o
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/src/processor.cpp.o
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/build.make
Linux-Monitoring-system: CMakeFiles/Linux-Monitoring-system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Linux-Monitoring-system"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Linux-Monitoring-system.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Linux-Monitoring-system.dir/build: Linux-Monitoring-system
.PHONY : CMakeFiles/Linux-Monitoring-system.dir/build

CMakeFiles/Linux-Monitoring-system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Linux-Monitoring-system.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Linux-Monitoring-system.dir/clean

CMakeFiles/Linux-Monitoring-system.dir/depend:
	cd /home/pc/Desktop/Linux-Monitoring-system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pc/Desktop/Linux-Monitoring-system /home/pc/Desktop/Linux-Monitoring-system /home/pc/Desktop/Linux-Monitoring-system/build /home/pc/Desktop/Linux-Monitoring-system/build /home/pc/Desktop/Linux-Monitoring-system/build/CMakeFiles/Linux-Monitoring-system.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Linux-Monitoring-system.dir/depend

