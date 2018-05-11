#include "DisjointSets.hpp"

int main()
{
    disjoint_sets D(4);

    std::cout << "Num components: " << D.num_components() << std::endl;
    D.merge(0, 1);
    std::cout << "Num components: " << D.num_components() << std::endl;
    D.merge(2, 3);
    std::cout << "Num components: " << D.num_components() << std::endl;
    D.merge(0, 3);
    std::cout << "Num components: " << D.num_components() << std::endl;
    D.merge(1, 2);
    std::cout << "Num components: " << D.num_components() << std::endl;

    return 0;
}
