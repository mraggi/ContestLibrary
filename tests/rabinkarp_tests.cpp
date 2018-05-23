#include "Probability.hpp"
#include "RabinKarp.hpp"
#include <gtest/gtest.h>
#include <iostream>

std::string random_string(int n)
{
    std::string s(n, 'a');
    for (auto& c : s)
        c = random_int('a', 'b');
    return s;
}

TEST(Strings, RabinKarpEasy)
{
    std::string T = "Hello World!";
    std::string P = "llo";
    auto first_match = rabin_karp(P, T);
    ASSERT_EQ(first_match - T.begin(), 2);
    ASSERT_EQ(rabin_karp("llw", T) - T.begin(), T.size());
}

TEST(Strings, RabinKarpRandom)
{
    for (int i = 0; i < 1000; ++i)
    {
        int t = random_int(0, 1000);
        int p = random_int(0, 100);
        auto T = random_string(t);
        auto P = random_string(p);

        auto first_match = rabin_karp(P, T) - T.begin();
        auto first_real_match = T.find(P);

        if (first_real_match == std::string::npos)
        {
            first_real_match = T.size();
        }

        ASSERT_EQ(first_match, first_real_match);
    }
}