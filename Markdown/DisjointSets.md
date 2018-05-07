# Disjoint Sets

Disjoint sets es una estructura de datos que permite, muy rápidamente, pegar elementos. Tiene heurística de compresión.

- Tiempo para merge y FindRoot: Amortizado $O(\log^*(n))$


```c++
%%INCLUDE(DisjointSets.cpp)
```


**Output**:

```txt
    Num components: 4
	Num components: 3
	Num components: 2
	Num components: 1
	Num components: 1
```

