#include "DisjointSets.hpp"
#include "VectorHelpers.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(DisjointSets, Creation)
{
    disjoint_sets A(10);
    ASSERT_EQ(A.size(), 10);
}

TEST(DisjointSets, EasyTest)
{
    disjoint_sets A(4);

    for (int i = 0; i < 4; ++i)
        ASSERT_EQ(i, A.find_root(i));

    A.merge(0, 1);

    ASSERT_TRUE(A.are_in_same_connected_component(0, 1));

    A.merge(2, 1);

    ASSERT_TRUE(A.are_in_same_connected_component(0, 1));
    ASSERT_TRUE(A.are_in_same_connected_component(1, 2));
    ASSERT_TRUE(A.are_in_same_connected_component(0, 2));

    ASSERT_NE(A.find_root(0), A.find_root(3));
    ASSERT_FALSE(A.are_in_same_connected_component(0, 3));
}

TEST(DisjointSets, HardTest)
{
    disjoint_sets A(8);
    A.merge(0, 1);
    A.merge(2, 3);
    A.merge(4, 5);
    A.merge(6, 7);

    A.merge(0, 2);
    A.merge(3, 5);
    ASSERT_TRUE(A.are_in_same_connected_component(1, 4));

    ASSERT_NE(A.find_root(0), A.find_root(7));
}

TEST(DisjointSets, BigTest)
{
    int n = 10000;
    disjoint_sets A(n);
    for (int i = 0; i + 1 < n/2; ++i)
        A.merge(i, i + 1);

    for (int i = n/2; i + 1 < n; ++i)
        A.merge(i, i + 1);

    ASSERT_FALSE(A.are_in_same_connected_component(0, n - 1));
    ASSERT_TRUE(A.are_in_same_connected_component(0, n/2 - 1));
    ASSERT_TRUE(A.are_in_same_connected_component(n/2, n - 1));
}
