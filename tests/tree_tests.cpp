#include "CommonGraphs.hpp"
#include "LCA.hpp"
#include "Probability.hpp"
#include "Trees.hpp"
#include <gtest/gtest.h>
#include <iostream>

Vertex lowest_common_ancestor_naive(const std::vector<Vertex>& parents,
                                    Vertex u,
                                    Vertex v)
{
    std::vector<bool> explored(parents.size(), false);

    Vertex root = find(parents.begin(), parents.end(), -1) - parents.begin();

    while (u != root)
    {
        explored[u] = true;
        u = parents[u];
    }

    while (v != root)
    {
        if (explored[v])
            return v;
        v = parents[v];
    }
    return root;
}

TEST(TreeAlgorithms, is_tree)
{
    for (int i = 0; i < 10; ++i)
    {
        Graph P = graphs::Path(random_int(1, 100));
        Graph C = graphs::Cycle(random_int(3, 100));
        Graph T = graphs::RandomTree(random_int(1, 100));
        Graph B = graphs::RandomBinaryTree(random_int(1, 10));

        ASSERT_TRUE(is_tree(P));
        ASSERT_FALSE(is_tree(C));
        ASSERT_TRUE(is_tree(T));
        ASSERT_TRUE(is_tree(B));
    }
}

TEST(TreeAlgorithms, SetRootPath)
{
    Graph P = graphs::Path(random_int(1, 100));

    auto parents = set_root(P, 0);

    for (auto v : P.vertices())
    {
        if (v == 0)
            continue;
        ASSERT_EQ(parents[v], v - 1);
    }
}

TEST(TreeAlgorithms, SetRootStar)
{
    Graph G(10);
    for (int i = 0; i < 10; ++i)
    {
        if (i != 4)
            G.add_edge(i, 4);
    }

    auto parents = set_root(G, 4);

    for (auto v : G.vertices())
    {
        if (v == 4)
            continue;
        ASSERT_EQ(parents[v], 4);
    }
}

TEST(TreeAlgorithms, HeightMapPath)
{
    Graph P = graphs::Path(random_int(1, 100));

    auto levels = height_map(P, 0);

    for (auto v : P.vertices())
    {
        ASSERT_EQ(levels[v], v);
    }
}

TEST(TreeAlgorithms, HeightMapStar)
{
    Graph G(10);
    for (int i = 0; i < 10; ++i)
    {
        if (i != 4)
            G.add_edge(i, 4);
    }

    auto level = height_map(G, 4);

    for (auto v : G.vertices())
    {
        if (v == 4)
        {
            ASSERT_EQ(level[v], 0);
            continue;
        }
        ASSERT_EQ(level[v], 1);
    }
}

TEST(TreeAlgorithms, lcaSparseStar)
{
    Graph G(10);
    for (int i = 0; i < 10; ++i)
    {
        if (i != 4)
            G.add_edge(i, 4);
    }

    LCA lca(G, 4);

    ASSERT_EQ(lca.FindLCA(0, 1), 4);
    ASSERT_EQ(lca.FindLCA(3, 4), 4);
    ASSERT_EQ(lca.FindLCA(6, 6), 6);
}

TEST(TreeAlgorithms, lcaSparsePath)
{
    using Vertex = Graph::Vertex;
    for (int i = 0; i < 10; ++i)
    {
        Graph G = graphs::Path(random_int(1, 100));
        auto root = random_int<Vertex>(0, G.num_vertices());

        LCA lca(G, root);

        for (auto u : G.vertices())
        {
            for (auto v = u + 1; v < G.num_vertices(); ++v)
            {
                if (v <= root)
                    ASSERT_EQ(lca.FindLCA(u, v), v);
                else if (u <= root)
                    ASSERT_EQ(lca.FindLCA(u, v), root);
                else
                    ASSERT_EQ(lca.FindLCA(u, v), u);
            }
        }
    }
}

TEST(TreeAlgorithms, lcaBalancedBinary)
{
    Graph G = graphs::BalancedBinaryTree(32);

    LCA lca(G, 0);

    ASSERT_EQ(lca.FindLCA(1, 2), 0);
    ASSERT_EQ(lca.FindLCA(1, 8), 1);
    ASSERT_EQ(lca.FindLCA(1, 6), 0);
    ASSERT_EQ(lca.FindLCA(7, 8), 3);
    ASSERT_EQ(lca.FindLCA(8, 9), 1);
}

TEST(TreeAlgorithms, lcaComparisonWithBF)
{
    for (int i = 0; i < 100; ++i)
    {
        int n = random_int(1, 35);
        auto G = graphs::RandomTree(n);
        int root = random_int(0, n);

        LCA lca(G, root);
        auto parents = lca.GetParents();
        ASSERT_EQ(parents, set_root(G, root));

        for (int w = 0; w < 100; ++w)
        {
            int u = random_int(0, n);
            int v = random_int(0, n);
            auto fast_lca = lca.FindLCA(u, v);
            auto slow_lca = lowest_common_ancestor_naive(parents, u, v);

            ASSERT_EQ(fast_lca, slow_lca);
        }
    }
}
