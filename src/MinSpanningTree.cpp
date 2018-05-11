#include "MinSpanningTree.hpp"

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
    Graph G(5);
    G.add_edge(0, 1, 5);
    G.add_edge(0, 2, 2);
    G.add_edge(0, 3, 4);
    G.add_edge(1, 2, 1);
    G.add_edge(1, 3, 8);
    G.add_edge(1, 4, 7);
    G.add_edge(2, 3, 3);
    G.add_edge(2, 4, 2);
    G.add_edge(3, 4, 9);

    cout << "Prim has the following edges:" << endl;
    for (auto e : prim(G))
    {
        cout << "(" << e.from << "," << e.to << "," << e.weight() << ")\n";
    }

    cout << "\nKruskal has the following edges:" << endl;
    for (auto e : kruskal(G))
    {
        cout << "(" << e.from << "," << e.to << "," << e.weight() << ")\n";
    }

    return 0;
}
