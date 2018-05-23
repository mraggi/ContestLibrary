project(contestlibrary)
cmake_minimum_required(VERSION 3.2)
enable_language(C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/include/extra
                    ${PROJECT_SOURCE_DIR}/external/googletest
                    ${PROJECT_SOURCE_DIR}/external/googletest/include)

SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-sign-compare")

option(BUILD_TESTS "Build unit tests (requires gtest)" ON)
option(BUILD_OWN_GOOGLETEST "Build own google's unit testing framework, even if found" OFF)

string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_tolower)
if (cmake_build_type_tolower STREQUAL "coverage")
    set(BUILD_TESTS ON)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(ConfigSafeGuards)
include(Colors)

if(${BUILD_TESTS})
    find_package(GTest)
    find_package(Threads REQUIRED)
    set(TEST_LIB googletest)
    file(GLOB TESTFILES "tests/*.cpp")
    set(TEST_MAIN unit_tests.x)
	if (${GTEST_FOUND} AND NOT ${BUILD_OWN_GOOGLETEST})
        include_directories(${GTEST_INCLUDE_DIRS})
        set(TEST_LIB ${GTEST_BOTH_LIBRARIES})
        add_executable(${TEST_MAIN} ${TESTFILES})
	else()
		message("Google testing framework not found. Building our own!")
        add_custom_target( git_update
        COMMAND git submodule init
        COMMAND git submodule update
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} )
        add_library(googletest
            ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest-all.cc
            ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest_main.cc)
        add_dependencies(googletest git_update)
        set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/src/gtest-all.cc  PROPERTIES GENERATED 1)
        set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/src/gtest_main.cc PROPERTIES GENERATED 1)
        add_executable(${TEST_MAIN} ${TESTFILES})
        add_dependencies(${TEST_MAIN} ${TEST_LIB})
    endif()
    
    target_link_libraries(${TEST_MAIN} ${TEST_LIB} Threads::Threads)
    add_custom_target(gtest COMMAND "${PROJECT_BINARY_DIR}/${TEST_MAIN}" DEPENDS ${TEST_MAIN})

    # Add a standard make target 'test' that runs the tests under CTest (only as an alt. to gtest).
    include(CTest)
    enable_testing()
    add_test(unit_tests ${PROJECT_BINARY_DIR}/${TEST_MAIN})
endif()

include(CodeCoverage)
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )


add_executable(disjoint_intervals src/DisjointIntervals.cpp)
add_executable(disjoint_sets src/DisjointSets.cpp)
add_executable(number_theory src/NumberTheory.cpp)
add_executable(prime_sieve src/PrimeSieve.cpp)
add_executable(longest_increasing_subsequence src/LongestIncreasingSubsequence.cpp)
add_executable(rmq src/RangeMinQuery.cpp)
add_executable(nn src/NaturalNumber.cpp)
add_executable(simplex src/LinearOptimizationSolver.cpp)
add_executable(connected src/ConnectedComponents.cpp)
add_executable(bipartitematch src/BipartiteMatcher.cpp)
add_executable(tree src/Trees.cpp)
add_executable(lca src/LCA.cpp)
add_executable(mst src/MinSpanningTree.cpp)
add_executable(shortest_path src/ShortestPaths.cpp)
add_executable(max_flow src/MaxFlow.cpp)
add_executable(rabin_karp src/RabinKarp.cpp)
