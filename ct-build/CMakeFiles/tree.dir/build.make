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
include CMakeFiles/tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/src/Trees.cpp.o: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/src/Trees.cpp.o: ../src/Trees.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/src/Trees.cpp.o"
	$(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-fix;--header-filter=.*;-checks=*,-google-readability-braces-around-statements,-readability-braces-around-statements,-fuchsia-*,-hicpp-braces-around-statements,-llvm-header-guard,-misc-unused-parameters,-google-runtime-references,-google-explicit-constructor,-hicpp-explicit-conversions,-readability-implicit-bool-conversion,-google-build-using-namespace,-hicpp-signed-bitwise" --source=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/Trees.cpp -- /bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tree.dir/src/Trees.cpp.o -c /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/Trees.cpp

CMakeFiles/tree.dir/src/Trees.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/src/Trees.cpp.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/Trees.cpp > CMakeFiles/tree.dir/src/Trees.cpp.i

CMakeFiles/tree.dir/src/Trees.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/src/Trees.cpp.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/Trees.cpp -o CMakeFiles/tree.dir/src/Trees.cpp.s

# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/src/Trees.cpp.o"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree: CMakeFiles/tree.dir/src/Trees.cpp.o
tree: CMakeFiles/tree.dir/build.make
tree: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree

.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	cd /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles/tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend
