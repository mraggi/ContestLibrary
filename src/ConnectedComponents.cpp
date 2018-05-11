#include "ConnectedComponents.hpp"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& A)
{
    for (const auto& x : A)
        os << x << ' ';
    return os;
}

int main()
{
    Graph G(5);

    G.add_edge(0, 1);
    G.add_edge(2, 3);

    std::cout << connected_components(G) << std::endl;

    return 0;
}
