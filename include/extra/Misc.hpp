#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>

//////////////////////////////////////////
/// \brief This is what operator%should be but isn't (!).
///
/// C++ modulo operator%is dumb for negative integers: (-7)%3 returns -1,
/// instead of 2. This fixes it. \return an integer in [0,b)
//////////////////////////////////////////
template <class IntType>
inline IntType modulo(IntType a, IntType b)
{
    IntType r = a%b;
    if (r < 0)
        r += b;
    return r;
}

//////////////////////////////////////////
/// \brief This is what operator %= should be but isn't (!).
///
/// C++ modulo operator %= is dumb for negative integers: (-7)%3 returns -1,
/// instead of 2. This fixes it.
//////////////////////////////////////////
template <class IntType>
inline void reduce_modulo(IntType& a, IntType b)
{
    a %= b;
    if (a < 0)
        a += b;
}

template <class T>
inline T pow(T a, std::uint64_t n)
{
    T r = 1L;

    while (n > 0UL)
    {
        if (n & 1UL) // if odd
            r *= a;

        n >>= 1;
        a *= a;
    }

    return r;
}

// Deprecated in c++17. Here for use in c++14.
template <class T>
T gcd(T a, T b)
{
    while (b != 0)
    {
        T r = a%b;
        a = b;
        b = r;
    }
    return a;
}

template <class T, class Container>
T reduce_fraction(Container Numerator, Container Denominator)
{
    for (auto& b : Denominator)
    {
        for (auto& a : Numerator)
        {
            auto d = gcd(a, b);
            a /= d;
            b /= d;
            if (b == 1)
                break;
        }
    }

    T result = 1;
    for (auto a : Numerator)
        result *= a;
    return result;
}

template <class Key,
          class Value,
          class Hash = std::hash<Key>,
          class Map = std::unordered_map<Key, Value, Hash>>
class map_with_default : public Map
{

public:
    // 	using Base = typename Map;
    explicit map_with_default(const Value& default_value)
        : m_default(default_value)
    {}

    Value operator()(const Key& key) const
    {
        auto it = Map::find(key);
        if (it == Map::end())
            return m_default;
        return it->second;
    }

    Value& operator[](const Key& key)
    {
        auto it = Map::find(key);
        if (it == Map::end())
        {
            Map::operator[](key) = m_default;
            return Map::operator[](key);
        }
        return it->second;
    }

private:
    Value m_default;
};

template <class Key,
          class Value,
          class Hash = std::hash<Key>,
          class Map = std::unordered_map<Key, Value, Hash>>
class map_with_default_by_ref : public Map
{

public:
    // 	using Base = typename Map;
    explicit map_with_default_by_ref(const Value& default_value)
        : m_default(default_value)
    {}

    Value operator()(const Key& key) const
    {
        auto it = Map::find(key);
        if (it == Map::end())
            return m_default;
        return it->second;
    }

    Value& operator[](const Key& key)
    {
        auto it = Map::find(key);
        if (it == Map::end())
        {
            it = Map::insert({key, m_default}).first;
            // 			Map::operator[](key) = m_default;
        }
        return it->second;
    }

    // 	void set_default(const Value& new_value) { m_default = new_value; }

private:
    const Value& m_default;
};

template <class T>
class PriorityQueueWithReserve : public std::priority_queue<T>
{
public:
    void reserve(size_t amount) { this->c.reserve(amount); }
};
