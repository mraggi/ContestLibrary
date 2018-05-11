## Árbol Generador de Peso Mínimo (MST)

Dado un grafo, encuentra el árbol generador de peso mínimo.

Se incluyen dos algoritmos: Prim y Kruskal. En la práctica es más rápido Prim, aunque hay varios problemas que se resuelven con un algoritmo que sea una modificación de uno de ellos.

- Tiempo: $O(E\log(E))$

**REQUIERE:** Graph, DisjointSets (para kruskal)


```c++
%%INCLUDE(MinSpanningTree.cpp)
```


**Output**:

```txt
Prim has the following edges:
(0,2,2)
(2,1,1)
(2,4,2)
(2,3,3)

Kruskal has the following edges:
(1,2,1)
(0,2,2)
(2,4,2)
(2,3,3)
```

