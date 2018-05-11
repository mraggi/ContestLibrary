#include "NaturalNumber.hpp"

int main()
{
    using std::cout;
    using std::endl;

    for (int i : natural_number(5))
        cout << i << ' ';

    cout << endl;

    std::vector<int> W = {2, 4, 6, 8};
    for (auto i : indices(W))
        cout << i << ": " << W[i] << endl;

    return 0;
}
