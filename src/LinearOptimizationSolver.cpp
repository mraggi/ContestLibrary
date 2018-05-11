#include "LinearOptimizationSolver.hpp"

using std::cout;
using std::endl;

int main()
{
    Matrix A = {{6, -1, 0}, {-1, -5, 0}, {1, 5, 1}, {-1, -5, -1}};
    Row b = {10, -4, 5, -5};
    Row c = {1, -1, 0};

    LPSolver solver(A, b, c);
    Row x;
    DOUBLE value = solver.Solve(x);

    cout << "VALUE: " << value << endl; // VALUE: 1.29032
    cout << "SOLUTION:"; // SOLUTION: 1.74194 0.451613 1
    for (auto t : x)
        cout << ' ' << t;
    cout << endl;
    return 0;
}
