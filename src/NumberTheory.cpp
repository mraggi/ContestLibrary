#include "NumberTheory.hpp"

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
    cout << "modulo(-37,10) = " << modulo(-37, 10) << endl;
    cout << "7^1000 (mod 5) = " << pow_mod(7, 1000, 5) << endl;

    auto dxy = gcd_extended(30, 55);
    cout << "\ngcd(30,55) = " << dxy.d << " = 30*" << dxy.x << " + 55*" << dxy.y
         << endl;
    cout << "lcm(30,55) = " << lcm(30, 55) << endl;

    cout << "\n1/7 (mod 9) = " << mod_inverse(7, 9) << endl;

    std::vector<int> V = {1, 2, 0, 4};
    cout << "\n4021_{5} = " << ReadNumberInBaseB(5, V) << "_{10}" << endl;
    cout << "10 in base 2: " << WriteNumberInBaseB(10, 2) << endl;
    cout << "100 in base 7: " << WriteNumberInBaseB(100, 7) << endl;

    return 0;
}
