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
include pb/CMakeFiles/pb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pb/CMakeFiles/pb.dir/compiler_depend.make

# Include the progress variables for this target.
include pb/CMakeFiles/pb.dir/progress.make

# Include the compile flags for this target's objects.
include pb/CMakeFiles/pb.dir/flags.make

pb/CMakeFiles/pb.dir/src/pb_common.o: pb/CMakeFiles/pb.dir/flags.make
pb/CMakeFiles/pb.dir/src/pb_common.o: ../pb/src/pb_common.c
pb/CMakeFiles/pb.dir/src/pb_common.o: pb/CMakeFiles/pb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object pb/CMakeFiles/pb.dir/src/pb_common.o"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pb/CMakeFiles/pb.dir/src/pb_common.o -MF CMakeFiles/pb.dir/src/pb_common.o.d -o CMakeFiles/pb.dir/src/pb_common.o -c /home/ld/work/test/var_manager/pb/src/pb_common.c

pb/CMakeFiles/pb.dir/src/pb_common.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pb.dir/src/pb_common.i"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ld/work/test/var_manager/pb/src/pb_common.c > CMakeFiles/pb.dir/src/pb_common.i

pb/CMakeFiles/pb.dir/src/pb_common.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pb.dir/src/pb_common.s"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ld/work/test/var_manager/pb/src/pb_common.c -o CMakeFiles/pb.dir/src/pb_common.s

pb/CMakeFiles/pb.dir/src/pb_decode.o: pb/CMakeFiles/pb.dir/flags.make
pb/CMakeFiles/pb.dir/src/pb_decode.o: ../pb/src/pb_decode.c
pb/CMakeFiles/pb.dir/src/pb_decode.o: pb/CMakeFiles/pb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object pb/CMakeFiles/pb.dir/src/pb_decode.o"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pb/CMakeFiles/pb.dir/src/pb_decode.o -MF CMakeFiles/pb.dir/src/pb_decode.o.d -o CMakeFiles/pb.dir/src/pb_decode.o -c /home/ld/work/test/var_manager/pb/src/pb_decode.c

pb/CMakeFiles/pb.dir/src/pb_decode.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pb.dir/src/pb_decode.i"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ld/work/test/var_manager/pb/src/pb_decode.c > CMakeFiles/pb.dir/src/pb_decode.i

pb/CMakeFiles/pb.dir/src/pb_decode.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pb.dir/src/pb_decode.s"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ld/work/test/var_manager/pb/src/pb_decode.c -o CMakeFiles/pb.dir/src/pb_decode.s

pb/CMakeFiles/pb.dir/src/pb_encode.o: pb/CMakeFiles/pb.dir/flags.make
pb/CMakeFiles/pb.dir/src/pb_encode.o: ../pb/src/pb_encode.c
pb/CMakeFiles/pb.dir/src/pb_encode.o: pb/CMakeFiles/pb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object pb/CMakeFiles/pb.dir/src/pb_encode.o"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pb/CMakeFiles/pb.dir/src/pb_encode.o -MF CMakeFiles/pb.dir/src/pb_encode.o.d -o CMakeFiles/pb.dir/src/pb_encode.o -c /home/ld/work/test/var_manager/pb/src/pb_encode.c

pb/CMakeFiles/pb.dir/src/pb_encode.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pb.dir/src/pb_encode.i"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ld/work/test/var_manager/pb/src/pb_encode.c > CMakeFiles/pb.dir/src/pb_encode.i

pb/CMakeFiles/pb.dir/src/pb_encode.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pb.dir/src/pb_encode.s"
	cd /home/ld/work/test/var_manager/build/pb && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ld/work/test/var_manager/pb/src/pb_encode.c -o CMakeFiles/pb.dir/src/pb_encode.s

# Object files for target pb
pb_OBJECTS = \
"CMakeFiles/pb.dir/src/pb_common.o" \
"CMakeFiles/pb.dir/src/pb_decode.o" \
"CMakeFiles/pb.dir/src/pb_encode.o"

# External object files for target pb
pb_EXTERNAL_OBJECTS =

../bin/libpb.so: pb/CMakeFiles/pb.dir/src/pb_common.o
../bin/libpb.so: pb/CMakeFiles/pb.dir/src/pb_decode.o
../bin/libpb.so: pb/CMakeFiles/pb.dir/src/pb_encode.o
../bin/libpb.so: pb/CMakeFiles/pb.dir/build.make
../bin/libpb.so: pb/CMakeFiles/pb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ld/work/test/var_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library ../../bin/libpb.so"
	cd /home/ld/work/test/var_manager/build/pb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pb/CMakeFiles/pb.dir/build: ../bin/libpb.so
.PHONY : pb/CMakeFiles/pb.dir/build

pb/CMakeFiles/pb.dir/clean:
	cd /home/ld/work/test/var_manager/build/pb && $(CMAKE_COMMAND) -P CMakeFiles/pb.dir/cmake_clean.cmake
.PHONY : pb/CMakeFiles/pb.dir/clean

pb/CMakeFiles/pb.dir/depend:
	cd /home/ld/work/test/var_manager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ld/work/test/var_manager /home/ld/work/test/var_manager/pb /home/ld/work/test/var_manager/build /home/ld/work/test/var_manager/build/pb /home/ld/work/test/var_manager/build/pb/CMakeFiles/pb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pb/CMakeFiles/pb.dir/depend
