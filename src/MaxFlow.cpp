#include "MaxFlow.hpp"

int main()
{
    PushRelabel G(5);

    G.AddEdge(0, 1, 8);
    G.AddEdge(0, 2, 3);
    G.AddEdge(1, 2, 2);
    G.AddEdge(1, 4, 4);
    G.AddEdge(1, 3, 1);
    G.AddEdge(3, 4, 4);

    std::cout << "Max flow: " << G.GetMaxFlow(0, 4) << std::endl;

    return 0;
}
