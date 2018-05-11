#include "RangeMinQuery.hpp"

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
    std::vector<int> A = {1, 5, 3,  9, 6, 10, 1, 5, 7, 9, 8, 0, 7,
                          4, 2, 10, 2, 3, 8,  6, 5, 7, 8, 9, 9};

    auto RMQ = make_range_min_query(A);
    auto GRMQ = make_range_min_query(A, std::greater<>());

    cout << "A = " << A << endl;

    cout << "Min value between index 5 and index 15 is at: "
         << RMQ.GetMinIndex(5, 15) << " with val " << A[RMQ.GetMinIndex(5, 15)]
         << std::endl;

    cout << "And the max value is at: " << GRMQ.GetMinIndex(5, 15)
         << " with val " << A[GRMQ.GetMinIndex(5, 15)] << endl;
}
