#include "BipartiteMatcher.hpp"

using namespace std;

int main()
{
    BipartiteGraph G(4, 4);
    G.add_edge(0, 3);
    G.add_edge(0, 1);
    G.add_edge(1, 0);
    G.add_edge(1, 1);
    G.add_edge(2, 0);
    G.add_edge(2, 1);
    G.add_edge(3, 0);
    G.add_edge(3, 2);
    G.add_edge(3, 3);

    BipartiteMatcher BM(G);
    cout << "Best match has size " << BM.size() << ", which is:" << endl;
    for (auto edge : BM.Edges())
    {
        cout << '(' << edge.from << ',' << edge.to << ')' << endl;
    }

    return 0;
}
