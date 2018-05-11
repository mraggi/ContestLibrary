#include "LCA.hpp"

int main()
{
    Graph tree(5);
    tree.add_edge(1, 0);
    tree.add_edge(1, 2);
    tree.add_edge(2, 3);
    tree.add_edge(2, 4);

    LCA lca(tree, 1);

    std::cout << "LCA of 0 and 4: " << lca.FindLCA(0, 4) << std::endl;
    std::cout << "LCA of 3 and 4: " << lca.FindLCA(3, 4) << std::endl;

    return 0;
}
