#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "NumberTheory.hpp"
using namespace std;

// a0x^(m-1) + a1x^(m-2) + ... + a_{m-1}x^0
template <class Iter>
ll polynomial_hash(Iter first, Iter last, ll x = 31, ll p = 1000000007)
{
    ll result = 0;

    for (; first != last; ++first)
    {
        result *= x;
        result += ll(*first);
        reduce_mod(result, p);
    }

    return result;
}

ll polynomial_hash(const std::string& s, ll x = 31, ll p = 1000000007)
{
    return polynomial_hash(s.begin(), s.end(), x, p);
}

template <class Iter>
auto rabin_karp(Iter Pfirst, Iter Plast, Iter first, Iter last)
{
    constexpr ll x = 31;
    constexpr ll p = 2147483497; // just pick any large prime < 2^31

    ll m = Plast - Pfirst;

    if (last - first < m)
        return last;

    auto mid = first + m;

    auto Phash = polynomial_hash(Pfirst, Plast, x, p);
    auto Thash = polynomial_hash(first, mid, x, p);

    if (Phash == Thash)
        return first;

    auto xpow = pow_mod(x, m - 1, p); // x^(m-1)

    for (; mid != last; ++first, ++mid)
    {
        // a0x^(m-1) + a1x^(m-2) + a2x^(m-3) + ... + a_{m-1}x^0 ->
        //             a1x^(m-1) + a2x^(m-2) + ... + a_{m-1}x^1 + a_m

        ll a0 = *first;
        ll am = *mid;

        Thash -= (a0*xpow)%p;
        reduce_mod(Thash, p);

        Thash *= x;
        reduce_mod(Thash, p);

        Thash += am;
        reduce_mod(Thash, p);

        if (Thash == Phash && std::equal(first + 1, mid + 1, Pfirst, Plast))
            return first + 1;
    }

    return last;
}

auto rabin_karp(const std::string& Pattern, const std::string& Text)
{
    return rabin_karp(Pattern.begin(), Pattern.end(), Text.begin(), Text.end());
}
