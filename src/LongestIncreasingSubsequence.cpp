#include "LongestIncreasingSubsequence.hpp"

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
    std::vector<int> A = {0, 4, 2, 3, 5, 2, 1, 7, 3, 5, 4, 3,
                          4, 5, 6, 4, 5, 3, 1, 5, 2, 6, 9};

    cout << "A = " << A << endl;

    cout << "Longest increasing subsequence: "
         << longest_increasing_subsequence(A) << endl;

    cout << "Longest non-decreasing subsequence: "
         << longest_increasing_subsequence(A, std::less_equal<>()) << endl;

    cout << "Longest decreasing subsequence: "
         << longest_increasing_subsequence(A, std::greater<>()) << endl;

    return 0;
}
