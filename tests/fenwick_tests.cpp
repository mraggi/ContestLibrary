#include "FenwickTree.hpp"
#include "Probability.hpp"
#include <gtest/gtest.h>
#include <iostream>

void check_everything(const FenwickTree& F,
                      std::vector<long> A = std::vector<long>())
{
    if (A.empty())
    {
        A.resize(F.size());
        for (long i = 0; i < F.size(); ++i)
        {
            A[i] = F[i];
        }
    }

    for (long i = 0; i < F.size(); ++i)
    {
        ASSERT_EQ(A[i], F[i]);
    }

    // checking prefix sums
    long sum = 0;
    for (long i = 0; i < F.size(); ++i)
    {
        ASSERT_EQ(sum, F.prefix_sum(i));
        sum += A[i];
    }
    ASSERT_EQ(sum, F.prefix_sum(F.size()));

    for (int L = 0; L < F.size(); ++L)
    {
        ASSERT_EQ(F.range_sum(L, L), 0);
        long sum = 0;
        for (long R = L + 1; R < F.size(); ++R)
        {
            sum += A[R - 1];
            ASSERT_EQ(F.range_sum(L, R), sum);
        }
    }
}

TEST(FenwickTree, EmptyTest) { FenwickTree F(0); }

TEST(FenwickTree, SimpleTest)
{
    FenwickTree F(4);
    check_everything(F);
    F.add(0, 1);
    check_everything(F);
    F.add(0, 1);
    check_everything(F);
    F.add(1, 4);
    check_everything(F);
    F.add(2, 1);
    check_everything(F);
}

TEST(FenwickTree, RandomTests)
{
    for (int test = 0; test < 20; ++test)
    {
        int n = random_int(0, 100);
        FenwickTree F(n);
        std::vector<long> A(n, 0);
        for (int i = 0; i < 100; ++i)
        {
            int index = random_int(0, n);
            int value = random_int(-1000, 1000);
            if (probability_of_true(0.5))
            {
                A[index] += value;
                F.add(index, value);
            }
            else
            {
                A[index] = value;
                F.set(index, value);
            }

            check_everything(F, A);
        }
    }
}
