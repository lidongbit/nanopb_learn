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
include CMakeFiles/test_nanopb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_nanopb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_nanopb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_nanopb.dir/flags.make

CMakeFiles/test_nanopb.dir/test_nanopb.o: CMakeFiles/test_nanopb.dir/flags.make
CMakeFiles/test_nanopb.dir/test_nanopb.o: ../test_nanopb.cpp
CMakeFiles/test_nanopb.dir/test_nanopb.o: CMakeFiles/test_nanopb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_nanopb.dir/test_nanopb.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_nanopb.dir/test_nanopb.o -MF CMakeFiles/test_nanopb.dir/test_nanopb.o.d -o CMakeFiles/test_nanopb.dir/test_nanopb.o -c /home/ld/work/test/var_manager/test_nanopb.cpp

CMakeFiles/test_nanopb.dir/test_nanopb.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_nanopb.dir/test_nanopb.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ld/work/test/var_manager/test_nanopb.cpp > CMakeFiles/test_nanopb.dir/test_nanopb.i

CMakeFiles/test_nanopb.dir/test_nanopb.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_nanopb.dir/test_nanopb.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ld/work/test/var_manager/test_nanopb.cpp -o CMakeFiles/test_nanopb.dir/test_nanopb.s

CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o: CMakeFiles/test_nanopb.dir/flags.make
CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o: ../var_monitor_data.pb.c
CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o: CMakeFiles/test_nanopb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o -MF CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o.d -o CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o -c /home/ld/work/test/var_manager/var_monitor_data.pb.c

CMakeFiles/test_nanopb.dir/var_monitor_data.pb.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_nanopb.dir/var_monitor_data.pb.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ld/work/test/var_manager/var_monitor_data.pb.c > CMakeFiles/test_nanopb.dir/var_monitor_data.pb.i

CMakeFiles/test_nanopb.dir/var_monitor_data.pb.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_nanopb.dir/var_monitor_data.pb.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ld/work/test/var_manager/var_monitor_data.pb.c -o CMakeFiles/test_nanopb.dir/var_monitor_data.pb.s

# Object files for target test_nanopb
test_nanopb_OBJECTS = \
"CMakeFiles/test_nanopb.dir/test_nanopb.o" \
"CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o"

# External object files for target test_nanopb
test_nanopb_EXTERNAL_OBJECTS =

../bin/test_nanopb: CMakeFiles/test_nanopb.dir/test_nanopb.o
../bin/test_nanopb: CMakeFiles/test_nanopb.dir/var_monitor_data.pb.o
../bin/test_nanopb: CMakeFiles/test_nanopb.dir/build.make
../bin/test_nanopb: ../bin/libpb.so
../bin/test_nanopb: CMakeFiles/test_nanopb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/test_nanopb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_nanopb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_nanopb.dir/build: ../bin/test_nanopb
.PHONY : CMakeFiles/test_nanopb.dir/build

CMakeFiles/test_nanopb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_nanopb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_nanopb.dir/clean

CMakeFiles/test_nanopb.dir/depend:
	cd /home/ld/work/test/var_manager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ld/work/test/var_manager /home/ld/work/test/var_manager /home/ld/work/test/var_manager/build /home/ld/work/test/var_manager/build /home/ld/work/test/var_manager/build/CMakeFiles/test_nanopb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_nanopb.dir/depend

