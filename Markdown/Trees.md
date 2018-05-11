## Tree Algorithms

Funciones de utilidad para cuando un grafo es árbol. La función `set_root`
regresa un vector con el padre de cada vértice, (-1 es el padre de la raíz).

La función `height_map` regresa la altura del vértice. Equivalente (pero más rápido) a correr dijkstra.

**REQUIERE:** Graph


```c++
%%INCLUDE(Trees.cpp)
```


**Output**:

```txt
    Parents: 1 -1 1 2 2 
	Heights: 1 0 1 2 2 
```
