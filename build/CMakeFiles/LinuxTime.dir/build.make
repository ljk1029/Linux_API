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
CMAKE_SOURCE_DIR = /root/VMCode/github/A_Linux_API

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/VMCode/github/A_Linux_API/build

# Include any dependencies generated for this target.
include CMakeFiles/LinuxTime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LinuxTime.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LinuxTime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinuxTime.dir/flags.make

CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o: CMakeFiles/LinuxTime.dir/flags.make
CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o: ../clock/LinuxTime.c
CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o: CMakeFiles/LinuxTime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/VMCode/github/A_Linux_API/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o -MF CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o.d -o CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o -c /root/VMCode/github/A_Linux_API/clock/LinuxTime.c

CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/VMCode/github/A_Linux_API/clock/LinuxTime.c > CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.i

CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/VMCode/github/A_Linux_API/clock/LinuxTime.c -o CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.s

# Object files for target LinuxTime
LinuxTime_OBJECTS = \
"CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o"

# External object files for target LinuxTime
LinuxTime_EXTERNAL_OBJECTS =

../bin/LinuxTime: CMakeFiles/LinuxTime.dir/clock/LinuxTime.c.o
../bin/LinuxTime: CMakeFiles/LinuxTime.dir/build.make
../bin/LinuxTime: CMakeFiles/LinuxTime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/VMCode/github/A_Linux_API/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/LinuxTime"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinuxTime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinuxTime.dir/build: ../bin/LinuxTime
.PHONY : CMakeFiles/LinuxTime.dir/build

CMakeFiles/LinuxTime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinuxTime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinuxTime.dir/clean

CMakeFiles/LinuxTime.dir/depend:
	cd /root/VMCode/github/A_Linux_API/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/VMCode/github/A_Linux_API /root/VMCode/github/A_Linux_API /root/VMCode/github/A_Linux_API/build /root/VMCode/github/A_Linux_API/build /root/VMCode/github/A_Linux_API/build/CMakeFiles/LinuxTime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinuxTime.dir/depend
