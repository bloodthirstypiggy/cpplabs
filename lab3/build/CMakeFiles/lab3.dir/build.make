# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/piggy/Downloads/cpplabs/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piggy/Downloads/cpplabs/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/lab3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3.dir/flags.make

CMakeFiles/lab3.dir/main.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/main.cpp.o: ../main.cpp
CMakeFiles/lab3.dir/main.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piggy/Downloads/cpplabs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/main.cpp.o -MF CMakeFiles/lab3.dir/main.cpp.o.d -o CMakeFiles/lab3.dir/main.cpp.o -c /home/piggy/Downloads/cpplabs/lab3/main.cpp

CMakeFiles/lab3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piggy/Downloads/cpplabs/lab3/main.cpp > CMakeFiles/lab3.dir/main.cpp.i

CMakeFiles/lab3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piggy/Downloads/cpplabs/lab3/main.cpp -o CMakeFiles/lab3.dir/main.cpp.s

CMakeFiles/lab3.dir/tests/test.cpp.o: CMakeFiles/lab3.dir/flags.make
CMakeFiles/lab3.dir/tests/test.cpp.o: ../tests/test.cpp
CMakeFiles/lab3.dir/tests/test.cpp.o: CMakeFiles/lab3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piggy/Downloads/cpplabs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab3.dir/tests/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3.dir/tests/test.cpp.o -MF CMakeFiles/lab3.dir/tests/test.cpp.o.d -o CMakeFiles/lab3.dir/tests/test.cpp.o -c /home/piggy/Downloads/cpplabs/lab3/tests/test.cpp

CMakeFiles/lab3.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3.dir/tests/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piggy/Downloads/cpplabs/lab3/tests/test.cpp > CMakeFiles/lab3.dir/tests/test.cpp.i

CMakeFiles/lab3.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3.dir/tests/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piggy/Downloads/cpplabs/lab3/tests/test.cpp -o CMakeFiles/lab3.dir/tests/test.cpp.s

# Object files for target lab3
lab3_OBJECTS = \
"CMakeFiles/lab3.dir/main.cpp.o" \
"CMakeFiles/lab3.dir/tests/test.cpp.o"

# External object files for target lab3
lab3_EXTERNAL_OBJECTS =

lab3: CMakeFiles/lab3.dir/main.cpp.o
lab3: CMakeFiles/lab3.dir/tests/test.cpp.o
lab3: CMakeFiles/lab3.dir/build.make
lab3: ternaryvector/libternaryvector.a
lab3: lib/libgtest.a
lab3: lib/libgtest_main.a
lab3: lib/libgtest.a
lab3: CMakeFiles/lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piggy/Downloads/cpplabs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3.dir/build: lab3
.PHONY : CMakeFiles/lab3.dir/build

CMakeFiles/lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3.dir/clean

CMakeFiles/lab3.dir/depend:
	cd /home/piggy/Downloads/cpplabs/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piggy/Downloads/cpplabs/lab3 /home/piggy/Downloads/cpplabs/lab3 /home/piggy/Downloads/cpplabs/lab3/build /home/piggy/Downloads/cpplabs/lab3/build /home/piggy/Downloads/cpplabs/lab3/build/CMakeFiles/lab3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab3.dir/depend

