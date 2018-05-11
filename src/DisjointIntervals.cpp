#include "DisjointIntervals.hpp"

using namespace std;
// Example program
int main()
{
    DisjointIntervals<int> D;
    D.Insert(0, 4);
    cout << D << endl;
    D.Insert(2, 8); // Intersects on the right
    cout << D << endl;
    D.Insert(-2, 1); // Intersects on the left
    cout << D << endl;
    D.Insert(-3, 9); // Contains
    cout << D << endl;

    D.Insert(15, 24); // Doesn't intersect at all
    cout << D << endl;

    D.Insert(10, 12); // In between, no intersect
    cout << D << endl;

    D.Insert(12, 15); // Joins two existing ones.
    cout << D << endl;

    return 0;
}
