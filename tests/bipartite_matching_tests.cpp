#include "BipartiteGraph.hpp"
#include "BipartiteMatcher.hpp"
#include "CommonGraphs.hpp"
#include "Probability.hpp"
#include "TimeHelpers.hpp"
#include "VectorHelpers.hpp"
#include "external/bipartite_matching.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <unordered_set>

using Vertex = BipartiteGraph::Vertex;

void CheckMatching(const BipartiteGraph& G, int expected_size)
{
    BipartiteMatcher M(G);

    ASSERT_EQ(M.size(), expected_size);

    std::set<Vertex> matches;

    for (auto x : G.verticesX())
    {
        auto y = M.MatchX(x);
        if (y != -1)
        {
            ASSERT_EQ(M.MatchY(y), x);
            matches.insert(y);
        }
    }
    ASSERT_EQ(matches.size(), expected_size);

    auto edges = M.Edges();
    auto order = [](const Graph::Edge& A, const Graph::Edge& B) {
        if (A.weight() != B.weight())
            return A.weight() < B.weight();
        if (A.from != B.from)
            return A.from < B.from;
        return A.to < B.to;
    };

    std::set<Graph::Edge, decltype(order)> S(edges.begin(), edges.end(), order);

    ASSERT_EQ(S.size(), matches.size());
}

TEST(BipartiteMatching, Small22)
{
    BipartiteGraph B(2, 2);
    B.add_edges({{0, 0}, {0, 1}, {1, 0}});
    CheckMatching(B, 2);
}

TEST(BipartiteMatching, Small13)
{
    BipartiteGraph B(1, 3);
    B.add_edges({{0, 0}, {0, 1}, {0, 2}});
    CheckMatching(B, 1);
}

TEST(BipartiteMatching, Small24)
{
    BipartiteGraph B(2, 4);
    B.add_edges({{0, 0}, {0, 1}, {1, 0}, {1, 3}});
    CheckMatching(B, 2);
}

TEST(BipartiteMatching, Small55)
{
    BipartiteGraph B(5, 5);
    B.add_edges({{0, 0},
                 {0, 1},
                 {1, 0},
                 {1, 1},
                 {2, 0},
                 {2, 1},
                 {3, 2},
                 {3, 3},
                 {3, 4},
                 {4, 2},
                 {4, 3},
                 {4, 4}});
    CheckMatching(B, 4);
}

TEST(BipartiteMatching, vsJaheup)
{
    for (int n = 1; n < 20; ++n)
    {
        for (int m = 1; m < 20; ++m)
        {
            auto B = graphs::RandomBipartite(n, m, 1.1/m);
            BipartiteMatcher BM(B);
            VI mr, mc;
            auto size = BipartiteMatching(AdjacencyMatrix(B), mr, mc);
            ASSERT_EQ(size, BM.size());
        }
    }
}
