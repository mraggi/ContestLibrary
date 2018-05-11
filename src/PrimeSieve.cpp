#include "PrimeSieve.hpp"

int main()
{
    Primes P(100);

    std::cout << "Primes: ";
    for (auto p : P)
        std::cout << p << ' ';
    std::cout << std::endl;

    for (ll n = 2; n <= 30; ++n)
    {
        std::cout << n << " = " << Factorization(n, P) << std::endl;
    }
    std::cout << std::endl;

    ll N = 193L*197*2*167*167*103613L;

    std::cout << N << " = " << Factorization(N, P) << std::endl;

    EulerPhi phi(P);

    for (ll n = 2; n <= 10; ++n)
    {
        std::cout << "phi(" << n << ") = " << phi(n) << std::endl;
    }

    return 0;
}
