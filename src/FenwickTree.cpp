#include "FenwickTree.hpp"

int main()
{
    std::vector<long> A = {1, 5, 3, 2, 7, 1};
    FenwickTree F(A);

    F.set(0, 3); // arreglo: [3,5,3,2,7,1]
    F.set(1, 0); // arreglo: [3,0,3,2,7,1]
    F.add(3, 10); // arreglo: [3,0,3,12,7,1]

    for (int i = 0; i < F.size(); ++i)
        std::cout << F[i] << ' ';

    std::cout << "\nSuma en de intervalo [1,4) = 0 + 3 + 12 = "
              << F.range_sum(1, 4) << std::endl;

    return 0;
}
