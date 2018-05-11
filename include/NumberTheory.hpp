#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using ll = std::int64_t;

template <class T = ll, class U = ll>
void reduce_mod(T& a, const U mod)
{
    a %= mod;
    if (a < 0)
        a += mod;
}

template <class T = ll, class U = ll>
T modulo(T a, const U mod)
{
    reduce_mod(a, mod);
    return a;
}

// calculates a^n efficiently. Mostly like std::pow.
// Can do it for any class that has operator*defined!
template <class T = ll, T identity = 1>
T pow(T a, std::uint64_t n)
{
    T r = identity;

    while (n > 0)
    {
        if (n%2 == 1)
            r *= a;

        n /= 2;
        a *= a;
    }

    return r;
}

// a^n (mod mod)
inline ll pow_mod(ll a, std::uint64_t n, const ll mod)
{
    ll r = 1;
    reduce_mod(a, mod);
    while (n > 0)
    {
        if (n%2 == 1)
        {
            r *= a;
            reduce_mod(r, mod);
        }

        n /= 2;
        a *= a;
        reduce_mod(a, mod);
    }

    return r;
}

inline ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}

inline ll lcm(ll a, ll b) { return a*b/gcd(a, b); }

struct linearcomb
{
    ll d; // gcd
    ll x; // first coefficient
    ll y; // second coefficient
};

// pseudocode taken from wikipedia
inline linearcomb gcd_extended(ll a, ll b)
{
    if (b == 0)
        return {a, 1LL, 0LL};

    ll sa = 1, sb = 0, sc, ta = 0, tb = 1, tc;

    do
    {
        auto K = std::div(a, b);

        a = b;
        b = K.rem;

        sc = sa - K.quot*sb;
        sa = sb;
        sb = sc;

        tc = ta - K.quot*tb;
        ta = tb;
        tb = tc;
    } while (b != 0);

    return {a, sa, ta};
}

inline ll mod_inverse(ll a, const ll n)
{
    ll x = gcd_extended(a, n).x;
    reduce_mod(x, n);
    return x;
}

// digits[i] = coefficient of b^i
template <class IntType>
ll ReadNumberInBaseB(ll b, const std::vector<IntType>& digits)
{
    ll suma = 0;
    ll power = 1;

    for (ll d : digits)
    {
        suma += power*d;
        power *= b;
    }

    return suma;
}

// Does NOT reverse the digits. add std::reverse at end if desired.
inline std::vector<int> WriteNumberInBaseB(ll n, int b)
{
    std::vector<int> digits;

    while (n)
    {
        digits.push_back(n%b);
        n /= b;
    }

    return digits;
}
