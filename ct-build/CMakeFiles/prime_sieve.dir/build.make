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
include CMakeFiles/prime_sieve.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prime_sieve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prime_sieve.dir/flags.make

CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o: CMakeFiles/prime_sieve.dir/flags.make
CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o: ../src/PrimeSieve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o"
	$(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-fix;--header-filter=.*;-checks=*,-google-readability-braces-around-statements,-readability-braces-around-statements,-fuchsia-*,-hicpp-braces-around-statements,-llvm-header-guard,-misc-unused-parameters,-google-runtime-references,-google-explicit-constructor,-hicpp-explicit-conversions,-readability-implicit-bool-conversion,-google-build-using-namespace,-hicpp-signed-bitwise" --source=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/PrimeSieve.cpp -- /bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o -c /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/PrimeSieve.cpp

CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/PrimeSieve.cpp > CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.i

CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/src/PrimeSieve.cpp -o CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.s

# Object files for target prime_sieve
prime_sieve_OBJECTS = \
"CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o"

# External object files for target prime_sieve
prime_sieve_EXTERNAL_OBJECTS =

prime_sieve: CMakeFiles/prime_sieve.dir/src/PrimeSieve.cpp.o
prime_sieve: CMakeFiles/prime_sieve.dir/build.make
prime_sieve: CMakeFiles/prime_sieve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prime_sieve"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prime_sieve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prime_sieve.dir/build: prime_sieve

.PHONY : CMakeFiles/prime_sieve.dir/build

CMakeFiles/prime_sieve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prime_sieve.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prime_sieve.dir/clean

CMakeFiles/prime_sieve.dir/depend:
	cd /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build /home/mraggi/Dropbox/sources/Mathematics/ContestLibrary/ct-build/CMakeFiles/prime_sieve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prime_sieve.dir/depend
