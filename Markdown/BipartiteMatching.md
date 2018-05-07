# Bipartite Matching

Encuentra el apareamiento máximo en una gráfica bipartita.

**REQUIERE:** BipartiteGraph

- Tiempo de ejecución: $O(VE)$, pero en general es muuucho más rápido que eso.

**Nota**: Encuentra el apareamiento de cardinalidad máxima, no el de peso máximo. 
Si se requiere max weight matching, mejor usar max flow con el truco de agregar dos vértices fantasmas.

```c++
%%INCLUDE(BipartiteMatcher.cpp)
```


**Output**:

```txt
    0 0 1 1 2 
```

