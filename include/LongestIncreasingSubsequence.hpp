#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

// Pseudocode taken from wikipedia and tweaked for speed :)
template <class T, class Compare = std::less<T>>
auto longest_increasing_subsequence(const std::vector<T>& X,
                                    Compare comp = std::less<T>())
{
    std::int64_t n = X.size();

    using PII = std::pair<int, T>;

    // M[k] = index i of smallest X[i] for which
    // there is a subsequence of length k ending
    // at X[i]. Note that M will be increasing.
    std::vector<PII> M(2);
    M.reserve((n + 2)/2);

    // P[i] = parent of i.
    std::vector<int> P(n);

    int L = 1;
    M[1].first = 0;
    M[1].second = X[0];
    for (std::int64_t i = 1; i < n; ++i)
    {
        auto first = M.begin() + 1;
        auto last = M.begin() + L + 1;

        const auto& xi = X[i];

        auto newL = std::partition_point(first,
                                         last,
                                         [xi, &comp](const PII& p) {
                                             return comp(p.second, xi);
                                         }) -
          first + 1;

        P[i] = M[newL - 1].first;

        if (newL < M.size())
        {
            M[newL].first = i;
            M[newL].second = xi;
        }
        else
        {
            M.push_back({i, xi});
        }

        if (newL > L)
            L = newL;
    }

    std::vector<T> S(L);
    std::int64_t k = M[L].first;

    for (auto it = S.rbegin(); it != S.rend(); ++it, k = P[k])
    {
        *it = X[k];
    }

    return S;
}
