## Disjoint Intervals

Disjoint Intervals es una estructura de datos que representa una unión de intervalos  
cerrado-abiertos disjuntos de $\mathbb{R}$.

- Tiempo para insertar: $O(\log(n))$.
- Tiempo para buscar si existe: $O(\log(n))$.

```c++
%%INCLUDE(DisjointIntervals.cpp)
```


**Output**:

```txt
	[0, 4)
	[0, 8)
	[-2, 8)
	[-3, 9)
	[-3, 9) U [15, 24)
	[-3, 9) U [10, 12) U [15, 24)
	[-3, 9) U [10, 24)
```

