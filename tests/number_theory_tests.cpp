#include <bitset>
#include <gtest/gtest.h>
#include <iostream>

#include "NumberTheory.hpp"
#include "PrimeSieve.hpp"
#include "Probability.hpp"

ll recursive_gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return recursive_gcd(b, a%b);
}

TEST(NumberTheory, GCD)
{
    for (int n = 0; n < 20; ++n)
    {
        for (int m = 0; m < 20; ++m)
        {
            ASSERT_EQ(gcd(n, m), recursive_gcd(n, m));
        }
    }

    for (int i = 0; i < 1000; ++i)
    {
        ll n = random_int(0, 1000000);
        ll m = random_int(0, 1000000);
        ASSERT_EQ(gcd(n, m), recursive_gcd(n, m));
        ASSERT_EQ(n*m, gcd(n, m)*lcm(n, m));
    }

    for (int i = 0; i < 1000; ++i)
    {
        ll a = random_int(0, 1000000);
        ll b = random_int(0, 1000000);
        auto w = gcd_extended(a, b);
        ASSERT_EQ(gcd(a, b), w.d);
        ASSERT_EQ(a*w.x + b*w.y, w.d);
    }

    for (int i = 0; i < 1000; ++i)
    {
        const ll MOD = 1000000007LL;
        ll a = random_int<ll>(1, MOD);
        ll b = mod_inverse(a, MOD);
        ASSERT_EQ(modulo(a*b, MOD), 1);
    }
}

TEST(NumberTheory, Primes)
{
    Primes P(1000);
    std::vector<ll> REAL_PRIMES = {
      2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
      47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
      109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
      191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
      269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
      353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
      439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
      523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
      617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
      709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
      811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
      907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    for (int i = 0; i < P.size(); ++i)
    {
        ASSERT_EQ(P[i], REAL_PRIMES[i]);
    }

    ASSERT_TRUE(is_prime(104729, P));
    ASSERT_TRUE(is_prime(98849, P));
    ASSERT_TRUE(is_prime(97553, P));
    ASSERT_TRUE(is_prime(3389, P));
    ASSERT_TRUE(is_prime(269, P));
    ASSERT_TRUE(is_prime(6397, P));

    ASSERT_FALSE(is_prime(97554, P));
    ASSERT_FALSE(is_prime(1821*9187, P));
    ASSERT_FALSE(is_prime(5171*9413, P));
}

// using std::cout;
// using std::endl;

TEST(NumberTheory, Factorization)
{
    Primes Q(10000);
    Primes P(50);

    for (int i = 1; i <= 6000; ++i)
    {
        Factorization F(i, P);
        F[29] = F(29); // this is to dirty the factorization!
        ASSERT_EQ(i, ll(F));
        for (auto pa : F)
        {
            ASSERT_TRUE(is_prime(pa.p, Q));
        }
        ASSERT_TRUE(std::is_sorted(
          F.begin(), F.end(), [](auto pa, auto qb) { return pa.p < qb.p; }));
    }
}

TEST(NumberTheory, EulerPhi)
{
    std::vector<ll> PHI_OEIS = {
      0,  1,  1,  2,  2,  4,  2,  6,  4,  6,  4,  10, 4,  12, 6,  8,  8,  16,
      6,  18, 8,  12, 10, 22, 8,  20, 12, 18, 12, 28, 8,  30, 16, 20, 16, 24,
      12, 36, 18, 24, 16, 40, 12, 42, 20, 24, 22, 46, 16, 42, 20, 32, 24, 52,
      18, 40, 24, 36, 28, 58, 16, 60, 30, 36, 32, 48, 20, 66, 32, 44};

    Primes P(PHI_OEIS.size());

    EulerPhi phi(P);

    for (int i = 0; i < PHI_OEIS.size(); ++i)
    {
        ASSERT_EQ(phi(i), PHI_OEIS[i]);
    }
}
