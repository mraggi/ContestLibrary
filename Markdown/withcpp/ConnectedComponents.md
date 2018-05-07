# Connected Components

Encuentra las componentes conexas de un grafo. Regresa un vector cuyo $i$-ésimo valor es la componente conexa a la que pertence el vértice $i$.

**REQUIERE:** Graph

- Tiempo de ejecución: $O(E)$.

```c++
#include <stack>

#include "Graph.hpp"

using Vertex = Graph::Vertex;

std::vector<int> connected_components(const Graph& G)
{
    auto n = G.num_vertices();
    std::vector<int> components(n, -1);
    int current_component = 0;

    for (auto v : G.vertices())
    {
        if (components[v] != -1)
            continue;

        std::stack<Vertex> frontier;
        frontier.emplace(v);
        while (!frontier.empty())
        {
            auto p = frontier.top();
            frontier.pop();
            if (components[p] != -1)
                continue;
            components[p] = current_component;
            for (auto u : G.neighbors(p))
            {
                if (components[u] == -1)
                    frontier.emplace(u);
            }
        }
        ++current_component;
    }

    return components;
}

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

    G.add_edge(0, 1);
    G.add_edge(2, 3);

    std::cout << connected_components(G) << std::endl;

    return 0;
}
```


**Output**:

```txt
    0 0 1 1 2 
```

