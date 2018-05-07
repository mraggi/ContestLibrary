project(contestlibrary)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_BUILD_TYPE Release)


add_executable(disjoint_intervals DisjointIntervals.cpp)
add_executable(disjoint_sets DisjointSets.cpp)
add_executable(number_theory NumberTheory.cpp)
add_executable(prime_sieve PrimeSieve.cpp)
add_executable(longest_increasing_subsequence LongestIncreasingSubsequence.cpp)
add_executable(rmq RangeMinQuery.cpp)
add_executable(nn NaturalNumber.cpp)
add_executable(simplex LinearOptimizationSolver.cpp)
add_executable(connected GraphConnectedComponents.cpp)
add_executable(bipartitematch BipartiteMatcher.cpp)
add_executable(tree Trees.cpp)
add_executable(lca LCA.cpp)
add_executable(mst MinSpanningTree.cpp)
add_executable(shortest_path ShortestPath.cpp)
add_executable(max_flow MaxFlow.cpp)
