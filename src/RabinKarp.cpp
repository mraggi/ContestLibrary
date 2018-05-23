#include "RabinKarp.hpp"

using namespace std;

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& A)
{
    for (const auto& x : A)
        os << x << ' ';
    return os;
}

int main()
{
    string T = "Hello World!";
    string P = "llo";

    auto it = rabin_karp(P, T); // there is also a version that takes iterators

    if (it != T.end())
        cout << "FOUND, string = " << string(it, it + P.size()) << " = " << P
             << endl;
    else
        cout << "NOT FOUND" << endl;
    return 0;
}
