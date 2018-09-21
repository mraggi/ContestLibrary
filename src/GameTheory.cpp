#include "GameTheory.hpp"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& A)
{
    for (const auto& x : A)
        os << x << ' ';
    return os;
}

int main()
{
    std::vector<int> A = {5, 3, 1, 5, 0, 2, 2, 4, 4, 8, 0};
    std::cout << "Min that doesn't appear in {" << A << "} is "
              << min_that_doesnt_appear(std::move(A)) << std::endl;

    return 0;
}
