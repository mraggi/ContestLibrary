#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "Misc.hpp"

////////////////////////////////////
/// \brief Converts a std::vector<U> into a std::vector<T>, provided U can be
/// converted to T
////////////////////////////////////
template <typename T, typename U>
std::vector<T> Convert(const std::vector<U>& G)
{
    auto n = G.size();
    std::vector<T> toReturn(n);

    for (size_t i = 0; i < n; ++i)
    {
        toReturn[i] = static_cast<T>(G[i]);
    }

    return toReturn;
}

////////////////////////////////////
/// \brief prints out a space separated std::vector.
////////////////////////////////////
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& V)
{
    if (V.empty())
        return os;
    auto it = V.begin();
    os << *it;
    ++it;
    for (; it != V.end(); ++it)
    {
        os << ' ' << *it;
    }

    return os;
}

////////////////////////////////////
/// \brief prints out a matrix
////////////////////////////////////
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& V)
{
    os << std::endl;
    for (auto& v : V)
        os << v << std::endl;

    return os;
}

/////////////////////////////
/// \brief Specialization for std::vector printouts for std::vector<bool> so
/// that it doesn't print out spaces
/////////////////////////////
inline std::ostream& operator<<(std::ostream& os, const std::vector<bool>& V)
{
    for (bool v : V)
        os << v;

    return os;
}

///////////////////////////
/// \brief Function composition
///
/// \return f∘g
///////////////////////////
template <class vecT, class UIntType>
vecT compose(const vecT& f, const std::vector<UIntType>& g)
{
    // 		typename vecT::value_type u(0);
    vecT toReturn(g.size());

    for (size_t i = 0; i < g.size(); ++i)
    {
        assert(g[i] < f.size());
        toReturn[i] = f[g[i]];
    }

    return toReturn;
}

template <class T>
std::vector<T> make_reserved_vector(size_t n)
{
    std::vector<T> A;
    A.reserve(n);
    return A;
}

template <class T, class Iter>
inline void remove_unordered(std::vector<T>& X, Iter it)
{
    *it = X.back();
    X.pop_back();
}

template <class T>
inline void remove_first(std::vector<T>& X, const T& t)
{
    auto it = std::find(X.begin(), X.end(), t);
    X.erase(it);
}

template <class T>
inline void remove_first_unordered(std::vector<T>& X, const T& t)
{
    auto it = std::find(X.begin(), X.end(), t);
    remove_unordered(X, it);
}

template <class T, class Func>
inline void remove_all_if(std::vector<T>& X, Func f)
{
    auto it = std::remove_if(X.begin(), X.end(), f);
    X.erase(it, X.end());
}
