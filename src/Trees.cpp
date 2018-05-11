#include "Trees.hpp"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& A)
{
    for (const auto& x : A)
        os << x << ' ';
    return os;
}

int main()
{
    Graph tree(5);
    tree.add_edge(1, 0);
    tree.add_edge(1, 2);
    tree.add_edge(2, 3);
    tree.add_edge(2, 4);

    auto parents = set_root(tree, 1);
    std::cout << "Parents: " << parents << std::endl;

    auto height = height_map(tree, 1);
    std::cout << "Heights: " << height << std::endl;

    return 0;
}
