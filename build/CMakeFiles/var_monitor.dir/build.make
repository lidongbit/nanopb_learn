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
CMAKE_SOURCE_DIR = /home/ld/work/test/var_manager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ld/work/test/var_manager/build

# Include any dependencies generated for this target.
include CMakeFiles/var_monitor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/var_monitor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/var_monitor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/var_monitor.dir/flags.make

CMakeFiles/var_monitor.dir/var_monitor.o: CMakeFiles/var_monitor.dir/flags.make
CMakeFiles/var_monitor.dir/var_monitor.o: ../var_monitor.cpp
CMakeFiles/var_monitor.dir/var_monitor.o: CMakeFiles/var_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/var_monitor.dir/var_monitor.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/var_monitor.dir/var_monitor.o -MF CMakeFiles/var_monitor.dir/var_monitor.o.d -o CMakeFiles/var_monitor.dir/var_monitor.o -c /home/ld/work/test/var_manager/var_monitor.cpp

CMakeFiles/var_monitor.dir/var_monitor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/var_monitor.dir/var_monitor.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ld/work/test/var_manager/var_monitor.cpp > CMakeFiles/var_monitor.dir/var_monitor.i

CMakeFiles/var_monitor.dir/var_monitor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/var_monitor.dir/var_monitor.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ld/work/test/var_manager/var_monitor.cpp -o CMakeFiles/var_monitor.dir/var_monitor.s

CMakeFiles/var_monitor.dir/var_monitor_data.pb.o: CMakeFiles/var_monitor.dir/flags.make
CMakeFiles/var_monitor.dir/var_monitor_data.pb.o: ../var_monitor_data.pb.c
CMakeFiles/var_monitor.dir/var_monitor_data.pb.o: CMakeFiles/var_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/var_monitor.dir/var_monitor_data.pb.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/var_monitor.dir/var_monitor_data.pb.o -MF CMakeFiles/var_monitor.dir/var_monitor_data.pb.o.d -o CMakeFiles/var_monitor.dir/var_monitor_data.pb.o -c /home/ld/work/test/var_manager/var_monitor_data.pb.c

CMakeFiles/var_monitor.dir/var_monitor_data.pb.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/var_monitor.dir/var_monitor_data.pb.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ld/work/test/var_manager/var_monitor_data.pb.c > CMakeFiles/var_monitor.dir/var_monitor_data.pb.i

CMakeFiles/var_monitor.dir/var_monitor_data.pb.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/var_monitor.dir/var_monitor_data.pb.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ld/work/test/var_manager/var_monitor_data.pb.c -o CMakeFiles/var_monitor.dir/var_monitor_data.pb.s

# Object files for target var_monitor
var_monitor_OBJECTS = \
"CMakeFiles/var_monitor.dir/var_monitor.o" \
"CMakeFiles/var_monitor.dir/var_monitor_data.pb.o"

# External object files for target var_monitor
var_monitor_EXTERNAL_OBJECTS =

../bin/libvar_monitor.so: CMakeFiles/var_monitor.dir/var_monitor.o
../bin/libvar_monitor.so: CMakeFiles/var_monitor.dir/var_monitor_data.pb.o
../bin/libvar_monitor.so: CMakeFiles/var_monitor.dir/build.make
../bin/libvar_monitor.so: ../bin/libpb.so
../bin/libvar_monitor.so: CMakeFiles/var_monitor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../bin/libvar_monitor.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/var_monitor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/var_monitor.dir/build: ../bin/libvar_monitor.so
.PHONY : CMakeFiles/var_monitor.dir/build

CMakeFiles/var_monitor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/var_monitor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/var_monitor.dir/clean

CMakeFiles/var_monitor.dir/depend:
	cd /home/ld/work/test/var_manager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ld/work/test/var_manager /home/ld/work/test/var_manager /home/ld/work/test/var_manager/build /home/ld/work/test/var_manager/build /home/ld/work/test/var_manager/build/CMakeFiles/var_monitor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/var_monitor.dir/depend

