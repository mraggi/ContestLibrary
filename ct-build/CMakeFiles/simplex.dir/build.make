# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build

# Include any dependencies generated for this target.
include CMakeFiles/simplex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simplex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simplex.dir/flags.make

CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o: CMakeFiles/simplex.dir/flags.make
CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o: ../src/LinearOptimizationSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o"
	$(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-fix;--header-filter=.*;-checks=*,-google-readability-braces-around-statements,-readability-braces-around-statements,-fuchsia-*,-hicpp-braces-around-statements,-llvm-header-guard,-misc-unused-parameters,-google-runtime-references,-google-explicit-constructor,-hicpp-explicit-conversions,-readability-implicit-bool-conversion,-google-build-using-namespace,-hicpp-signed-bitwise" --source=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/LinearOptimizationSolver.cpp -- /bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o -c /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/LinearOptimizationSolver.cpp

CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/LinearOptimizationSolver.cpp > CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.i

CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/LinearOptimizationSolver.cpp -o CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.s

# Object files for target simplex
simplex_OBJECTS = \
"CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o"

# External object files for target simplex
simplex_EXTERNAL_OBJECTS =

simplex: CMakeFiles/simplex.dir/src/LinearOptimizationSolver.cpp.o
simplex: CMakeFiles/simplex.dir/build.make
simplex: CMakeFiles/simplex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simplex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simplex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simplex.dir/build: simplex

.PHONY : CMakeFiles/simplex.dir/build

CMakeFiles/simplex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simplex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simplex.dir/clean

CMakeFiles/simplex.dir/depend:
	cd /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles/simplex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simplex.dir/depend

