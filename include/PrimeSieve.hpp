#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using ll = std::int64_t;

class Primes
{
public:
    using value_type = ll;
    using difference_type = ll;
    using const_iterator = std::vector<ll>::const_iterator;
    using iterator = const_iterator; // you can't modify this data structure.

    explicit Primes(ll primes_up_to = 1000000) : m_upto(primes_up_to)
    {
        eratosthenes_sieve(m_upto);
    }

    // Number of primes
    ll size() const { return primes.size(); }

    // Calculated all primes up to
    ll up_to() const { return m_upto; }

    iterator begin() const { return primes.begin(); }
    iterator end() const { return primes.end(); }

    ll operator[](ll index) const { return primes[index]; }
    ll back() const { return primes.back(); }

    const auto& prime_array() const { return primes; }

private:
    void eratosthenes_sieve(ll n)
    {
        // primecharfunc[a] == true means 2*a+1 is prime
        std::vector<bool> primecharfunc = {false};
        primecharfunc.resize(n/2 + 1, true);

        primes.reserve((1.1*n)/std::log(n) + 10); // can remove this line

        ll i = 1;
        ll p = 3; // p = 2*i + 1
        for (; p*p <= n; p += 2, ++i)
        {
            if (primecharfunc[i])
            {
                primes.emplace_back(p);
                for (ll j = i + p; j < primecharfunc.size(); j += p)
                    primecharfunc[j] = false;
            }
        }

        for (; p < n; p += 2, ++i)
        {
            if (primecharfunc[i])
                primes.emplace_back(p);
        }
    }

    ll m_upto;
    std::vector<ll> primes = {2};
}; // end class Primes

// returns the biggest integer t such that t*t <= n
inline ll integral_sqrt(ll n)
{
    ll t = std::round(std::sqrt(n));
    if (t*t > n)
        return t - 1;

    return t;
}

inline bool is_square(ll N)
{
    ll t = std::round(std::sqrt(N));
    return t*t == N;
}

inline ll FermatFactor(ll N)
{
    assert(N%2 == 1);
    ll a = std::ceil(std::sqrt(N));
    ll b2 = a*a - N;

    while (b2 >= 0 && !is_square(b2))
    {
        ++a;
        b2 = a*a - N;
    }

    return a - integral_sqrt(b2);
}

// This class only purpose is to factorize numbers
// Works much better if the primes calculated go up to at least sqrt(n)
class Factorization
{
public:
    // Represents p^a
    struct prime_to_power
    {
        prime_to_power(ll prime, ll power) : p(prime), a(power) {}
        ll p;
        ll a;

        explicit operator ll() const { return std::pow(p, a); }
    };

    using value_type = prime_to_power;
    using iterator = std::vector<prime_to_power>::iterator;
    using const_iterator = std::vector<prime_to_power>::const_iterator;

    Factorization() = default;
    Factorization(ll n, const Primes& P) : m_value(n)
    {
        if (n <= 1)
            return;

        for (auto p : P)
        {
            ll a = 0;
            while (n%p == 0)
            {
                n /= p;
                ++a;
            }

            if (a != 0)
                emplace_back(p, a);

            if (p*p > n)
            {
                if (n > 1)
                    emplace_back(n, 1);
                return;
            }
        }

        if (n > 1)
        {
            fermat_factorization(n);
            m_dirty = false;
        }
    }

    // warning!! This can easily overflow!
    explicit operator ll() const
    {
        if (m_dirty)
        {
            m_dirty = false;
            m_value = 1;

            for (auto& pa : m_prime_factors)
                m_value *= ll(pa);
        }

        return m_value;
    }

    // returns the power of prime p
    ll operator()(ll p) const
    {
        auto it = first_with_geq_prime(p);

        if (it == end() || it->p != p)
            return 0;

        return it->a;
    }

    ll& operator[](ll p)
    {
        m_dirty = true;
        auto it = first_with_geq_prime(p);

        if (it == end())
        {
            emplace_back(p, 0);
            return m_prime_factors.back().a;
        }

        // if it exists, everything is fine
        if (it->p == p)
            return it->a;

        it = m_prime_factors.insert(it, prime_to_power(p, 0));
        return it->a;
    }

    const_iterator begin() const { return m_prime_factors.begin(); }
    const_iterator end() const { return m_prime_factors.end(); }

    iterator begin() { return m_prime_factors.begin(); }
    iterator end() { return m_prime_factors.end(); }

    ll size() const { return m_prime_factors.size(); }

private:
    mutable ll m_value{1};
    mutable bool m_dirty{false};
    std::vector<prime_to_power> m_prime_factors{};

    const_iterator first_with_geq_prime(ll p) const
    {
        return std::partition_point(
          begin(), end(), [p](const prime_to_power& p_a) { return p_a.p < p; });
    }

    iterator first_with_geq_prime(ll p)
    {
        return std::partition_point(
          begin(), end(), [p](const prime_to_power& p_a) { return p_a.p < p; });
    }

    void emplace_back(ll p, ll a)
    {
        assert(m_prime_factors.empty() || p > m_prime_factors.back().p);
        m_prime_factors.emplace_back(p, a);
    }

    // private because n has to be odd, and maybe
    // is already a factor in something.
    void fermat_factorization(ll n)
    {
        auto& F = *this;

        assert(n%2 == 1);
        assert(n > 5);
        ll a = FermatFactor(n);

        ll b = n/a;

        assert(a*b == n);

        if (a == 1)
        {
            ++F[b];
        }
        else
        {
            fermat_factorization(a);
            fermat_factorization(b);
        }
    }
};

inline std::ostream& operator<<(std::ostream& os, const Factorization& F)
{
    ll i = 0;

    for (auto f : F)
    {
        os << f.p;

        if (f.a != 1)
            os << "^" << f.a;

        if (i + 1 != F.size())
            os << ' ' << '*' << ' ';

        ++i;
    }

    return os;
}

inline bool does_any_prime_divide(ll n, const Primes& P)
{
    for (auto p : P)
    {
        if (p*p > n)
            break;

        if (n%p == 0)
            return true;
    }

    return false;
}

inline bool is_prime(ll n, const Primes& P)
{
    if (n <= P.up_to())
        return std::binary_search(P.begin(), P.end(), n);

    // Try dividing by all small primes
    if (does_any_prime_divide(n, P))
        return false;

    // We now heavily suspect n is prime but maybe n is too big

    if (n <= P.back()*P.back())
        return true;

    // If n is pretty big, try to do fermat factorization
    ll a = FermatFactor(n);
    return a == 1;
}

class EulerPhi
{
public:
    explicit EulerPhi(const Primes& P) : m_phi(P.up_to() + 1)
    {
        m_phi[0] = 0;
        m_phi[1] = 1;
        dfs_helper(P, 1, 0);
    }

    // TODO(mraggi): only works if already calculated.
    ll operator()(ll k) const { return m_phi[k]; }

    ll size() const { return m_phi.size(); }

private:
    void dfs_helper(const Primes& P, ll a, ll i)
    {
        ll n = m_phi.size();
        for (; i < P.size() && P[i]*a < n; ++i)
        {
            ll p = P[i];

            ll multiplier = p - 1;
            if (a%p == 0)
                multiplier = p;

            m_phi[p*a] = multiplier*m_phi[a];

            dfs_helper(P, p*a, i);
        }
    }

    std::vector<ll> m_phi;
};
