# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/piggy/Desktop/cpplabs/lab3c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piggy/Desktop/cpplabs/lab3c/buils

# Include any dependencies generated for this target.
include googletest/CMakeFiles/ternaryvector.dir/depend.make

# Include the progress variables for this target.
include googletest/CMakeFiles/ternaryvector.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/CMakeFiles/ternaryvector.dir/flags.make

googletest/CMakeFiles/ternaryvector.dir/vector.cpp.o: googletest/CMakeFiles/ternaryvector.dir/flags.make
googletest/CMakeFiles/ternaryvector.dir/vector.cpp.o: ../ternaryvector/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piggy/Desktop/cpplabs/lab3c/buils/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/ternaryvector.dir/vector.cpp.o"
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ternaryvector.dir/vector.cpp.o -c /home/piggy/Desktop/cpplabs/lab3c/ternaryvector/vector.cpp

googletest/CMakeFiles/ternaryvector.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ternaryvector.dir/vector.cpp.i"
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piggy/Desktop/cpplabs/lab3c/ternaryvector/vector.cpp > CMakeFiles/ternaryvector.dir/vector.cpp.i

googletest/CMakeFiles/ternaryvector.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ternaryvector.dir/vector.cpp.s"
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piggy/Desktop/cpplabs/lab3c/ternaryvector/vector.cpp -o CMakeFiles/ternaryvector.dir/vector.cpp.s

# Object files for target ternaryvector
ternaryvector_OBJECTS = \
"CMakeFiles/ternaryvector.dir/vector.cpp.o"

# External object files for target ternaryvector
ternaryvector_EXTERNAL_OBJECTS =

googletest/libternaryvector.a: googletest/CMakeFiles/ternaryvector.dir/vector.cpp.o
googletest/libternaryvector.a: googletest/CMakeFiles/ternaryvector.dir/build.make
googletest/libternaryvector.a: googletest/CMakeFiles/ternaryvector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piggy/Desktop/cpplabs/lab3c/buils/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libternaryvector.a"
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && $(CMAKE_COMMAND) -P CMakeFiles/ternaryvector.dir/cmake_clean_target.cmake
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ternaryvector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/CMakeFiles/ternaryvector.dir/build: googletest/libternaryvector.a

.PHONY : googletest/CMakeFiles/ternaryvector.dir/build

googletest/CMakeFiles/ternaryvector.dir/clean:
	cd /home/piggy/Desktop/cpplabs/lab3c/buils/googletest && $(CMAKE_COMMAND) -P CMakeFiles/ternaryvector.dir/cmake_clean.cmake
.PHONY : googletest/CMakeFiles/ternaryvector.dir/clean

googletest/CMakeFiles/ternaryvector.dir/depend:
	cd /home/piggy/Desktop/cpplabs/lab3c/buils && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piggy/Desktop/cpplabs/lab3c /home/piggy/Desktop/cpplabs/lab3c/ternaryvector /home/piggy/Desktop/cpplabs/lab3c/buils /home/piggy/Desktop/cpplabs/lab3c/buils/googletest /home/piggy/Desktop/cpplabs/lab3c/buils/googletest/CMakeFiles/ternaryvector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/CMakeFiles/ternaryvector.dir/depend

