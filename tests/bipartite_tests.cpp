#include "BipartiteGraph.hpp"
#include "CommonGraphs.hpp"
#include "VectorHelpers.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(Bipartite, Creation)
{
    BipartiteGraph B(5, 5);
    B.add_edge(0, 0);
    B.add_edge(1, 1);
    ASSERT_EQ(B.num_vertices(), 10);
    // 	ASSERT_EQ(B.num_edges(), 2);
    ASSERT_EQ(B.degreeX(0), 1);
    ASSERT_EQ(B.degreeY(0), 1);
    ASSERT_EQ(B.degreeX(1), 1);
    ASSERT_EQ(B.degreeY(1), 1);
    ASSERT_EQ(B.degreeX(3), 0);
}

TEST(Bipartite, SortNeighbors)
{
    BipartiteGraph G(4, 5);
    G.add_edge(0, 3);
    G.add_edge(2, 4);
    G.add_edge(1, 1);
    G.add_edge(3, 1);
    G.add_edge(2, 3);
    G.add_edge(2, 2);
    G.add_edge(2, 1);
    G.add_edge(0, 4);

    G.sort_neighbors();

    for (auto x : G.verticesX())
    {
        ASSERT_TRUE(
          std::is_sorted(G.neighborsX(x).begin(), G.neighborsX(x).end()));
    }

    for (auto y : G.verticesY())
    {
        ASSERT_TRUE(
          std::is_sorted(G.neighborsY(y).begin(), G.neighborsY(y).end()));
    }
}
