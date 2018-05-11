## Teoría de Números

Tenemos las siguientes funciones:

- `reduce_mod(a,mod)` reduce a a su residuo **positivo** de dividir a entre mod.
- `modulo(a,mod)` regresa reduce_mod(a,mod)
- `pow(a,n)` y `pow_mod(a,n,mod)` regresan a^n y a^n%mod respectivamente.
- `gcd_extended(a,b)` regresa el máximo común divisor d = gcd(a,b) y también la combinación lineal ax+by=d.
- `mod_inverse(a,n)` regresa el inverso modular de a módulo n. Ejemplo: $4\cdot 3 \equiv 1$ (mod 11), así que 4 y 3 son inversos módulo 11.

Además, hay funciones para convertir enteros de una base a otra.


```c++
%%INCLUDE(NumberTheory.cpp)
```

**Output**:

```txt
modulo(-37,10) = 3
7^1000 (mod 5) = 1

gcd(30,55) = 5 = 30*2 + 55*-1
lcm(30,55) = 330

1/7 (mod 9) = 4

4021_{5} = 511_{10}
10 in base 2: 0 1 0 1 
100 in base 7: 2 0 2 
```

