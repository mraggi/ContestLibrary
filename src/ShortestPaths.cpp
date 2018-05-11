#include "ShortestPaths.hpp"

int main()
{
    using std::cout;
    using std::endl;

    Graph G(5);
    G.add_edge(0, 1, 5);
    G.add_edge(0, 2, 9);
    G.add_edge(1, 2, 3);
    G.add_edge(2, 3, 4);
    G.add_edge(3, 4, 5);

    Vertex s = 0;
    Vertex t = 4;

    std::vector<int> heuristic = {5, 5, 4, 4, 0};

    cout << "Dijsktra produces the following path:\n\t";
    for (auto e : Dijkstra(G, s, t))
    {
        cout << "----(w = " << e.weight() << ")----> " << e.vertex << " ";
    }
    cout << endl << endl;

    auto h = [&heuristic](Vertex v) { return heuristic[v]; };

    cout << "A* produces the following path:\n\t";
    for (auto e : Astar(G, s, t, h))
    {
        cout << "----(w = " << e.weight() << ")----> " << e.vertex << " ";
    }

    return 0;
}
