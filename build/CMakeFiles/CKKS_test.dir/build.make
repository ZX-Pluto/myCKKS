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
CMAKE_SOURCE_DIR = /home/CKKS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/CKKS/build

# Include any dependencies generated for this target.
include CMakeFiles/CKKS_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CKKS_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CKKS_test.dir/flags.make

CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o: CMakeFiles/CKKS_test.dir/flags.make
CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o: ../CKKS_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CKKS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o -c /home/CKKS/CKKS_test.cpp

CMakeFiles/CKKS_test.dir/CKKS_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CKKS_test.dir/CKKS_test.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/CKKS/CKKS_test.cpp > CMakeFiles/CKKS_test.dir/CKKS_test.cpp.i

CMakeFiles/CKKS_test.dir/CKKS_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CKKS_test.dir/CKKS_test.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/CKKS/CKKS_test.cpp -o CMakeFiles/CKKS_test.dir/CKKS_test.cpp.s

# Object files for target CKKS_test
CKKS_test_OBJECTS = \
"CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o"

# External object files for target CKKS_test
CKKS_test_EXTERNAL_OBJECTS =

libCKKS_test.a: CMakeFiles/CKKS_test.dir/CKKS_test.cpp.o
libCKKS_test.a: CMakeFiles/CKKS_test.dir/build.make
libCKKS_test.a: CMakeFiles/CKKS_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/CKKS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCKKS_test.a"
	$(CMAKE_COMMAND) -P CMakeFiles/CKKS_test.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CKKS_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CKKS_test.dir/build: libCKKS_test.a

.PHONY : CMakeFiles/CKKS_test.dir/build

CMakeFiles/CKKS_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CKKS_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CKKS_test.dir/clean

CMakeFiles/CKKS_test.dir/depend:
	cd /home/CKKS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/CKKS /home/CKKS /home/CKKS/build /home/CKKS/build /home/CKKS/build/CMakeFiles/CKKS_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CKKS_test.dir/depend

