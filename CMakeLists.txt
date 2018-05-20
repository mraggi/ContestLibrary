project(contestlibrary)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_BUILD_TYPE Release)

include_directories(include)
include_directories(include/extra)

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

option(BUILD_TESTS "Build unit tests (requires gtest)" ON)


if (${BUILD_TESTS})
	find_package(GTest REQUIRED)
	find_package(Threads REQUIRED)
	enable_testing()
	include_directories(${GTEST_INCLUDE_DIRS})
	set(PROJECT_TEST_NAME all_tests)
	
	# Add test source files here
	add_executable(${PROJECT_TEST_NAME} tests/main.cpp 
										tests/basic_tests.cpp
										tests/disjoint_set_tests.cpp
										tests/mst_tests.cpp
										tests/connected_component_tests.cpp
										tests/shortest_path_tests.cpp
										tests/graph_creation_tests.cpp
										tests/tree_tests.cpp
										tests/rmq_tests.cpp
										tests/bipartite_tests.cpp
										tests/bipartite_matching_tests.cpp
										tests/number_theory_tests.cpp
										tests/natural_number_tests.cpp)
	target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_BOTH_LIBRARIES} Threads::Threads)
	add_test(AllTests ${PROJECT_TEST_NAME})
endif()
