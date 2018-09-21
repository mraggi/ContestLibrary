#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <class Int>
inline Int min_that_doesnt_appear(std::vector<Int> A)
{
    std::sort(A.begin(), A.end());

    if (A.empty() || A.front() != 0)
        return 0;

    for (Int i = 0; i + 1 < A.size(); ++i)
    {
        auto a = A[i];
        auto b = A[i + 1];
        if (a != b && a + 1 < b)
            return a + 1;
    }

    return A.back() + 1;
}