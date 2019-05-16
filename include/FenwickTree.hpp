#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

long least_significant_bit(long S) { return S & (-S); }

class FenwickTree
{
public:
    explicit FenwickTree(long n) : tree_(n + 1, 0), array_(n, 0) {}
    explicit FenwickTree(const std::vector<long>& array)
        : tree_(array.size() + 1, 0), array_(array.size(), 0)
    {
        long n = array.size();
        for (long i = 0; i < n; ++i)
            add(i, array[i]);
    }

    long operator[](long i) const { return array_[i]; }

    // partial sum [0,b)
    long prefix_sum(long b) const
    {
        long sum = 0;
        for (; b != 0; b -= least_significant_bit(b))
            sum += tree_[b];
        return sum;
    }

    // partial sum [a,b)
    long range_sum(long a, long b) const
    {
        if (b <= a)
            return 0;
        return prefix_sum(b) - prefix_sum(a);
    }

    long size() const { return tree_.size() - 1; }

    // add val to A[i]
    void add(long i, long val)
    {
        array_[i] += val;
        ++i; // recall that fenwick trees are 1-ied!
        long n = tree_.size();
        for (; i < n; i += least_significant_bit(i))
            tree_[i] += val;
    }

    void set(long i, long val) { add(i, val - array_[i]); }

private:
    std::vector<long> tree_;
    std::vector<long> array_;
};
