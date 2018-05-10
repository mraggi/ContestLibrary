#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using pii = std::array<int, 2>;

const long loo = std::numeric_limits<long>::max()/2;
const int oo = std::numeric_limits<int>::max()/2;
const short soo = std::numeric_limits<short>::max()/2;

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
    for (const auto& x : rhs)
        os << x << " ";
    return os;
}

template <>
std::ostream& operator<<(std::ostream& os, const vector<bool>& rhs)
{
    for (const auto& x : rhs)
        os << x;
    return os;
}

// template <>
// std::ostream& operator<<(std::ostream& os,
// const vector<short>& rhs)
// {
// 	for (const auto& x : rhs)
// 		os << std::bitset<10>(x) << " ";
// 	return os;
// }

template <>
std::ostream& operator<<(std::ostream& os, const vector<char>& rhs)
{
    for (const auto& x : rhs)
        os << short(x) << " ";
    return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<vector<T>>& rhs)
{
    cout << endl;
    for (const auto& x : rhs)
        os << x << endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const pii& rhs)
{
    os << "(" << rhs[0] << ", " << rhs[1] << ")";
    return os;
}

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

long lcm(long a, long b) { return a*b/gcd(a, b); }

long gcd(const vector<long>& A)
{
    auto a = A.front();

    for (size_t i = 1; i < A.size(); ++i)
    {
        a = gcd(a, A[i]);
    }
    return a;
}

long lcm(const vector<long>& A)
{
    auto a = A.front();

    for (size_t i = 1; i < A.size(); ++i)
    {
        a = lcm(a, A[i]);
    }
    return a;
}

int main()
{
    cout << lcm({8, 24, 16, 4}) << endl;

    //     int T;
    //     cin >> T;
    //     while (T--)
    //     {
    //         // do stuff
    //     }
    return 0;
}
