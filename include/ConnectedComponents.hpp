#pragma once
#include <stack>

#include "Graph.hpp"

using Vertex = Graph::Vertex;

// connected_components(G)[i] = connected component of the i-th vertex.
inline std::vector<int> connected_components(const Graph& G)
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

inline bool is_connected(const Graph& G)
{
    auto CC = connected_components(G);
    return std::all_of(CC.begin(), CC.end(), [](auto t) { return t == 0; });
}

inline int num_connected_components(const Graph& G)
{
    if (G.num_vertices() == 0)
        return 0;
    auto CC = connected_components(G);
    return *std::max_element(CC.begin(), CC.end()) + 1;
}
