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
