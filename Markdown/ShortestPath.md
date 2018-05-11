## Shortest Paths

Dado un grafo y un vértice inicial, encuentra el camino de menor peso a un objetivo.

Se incluyen dos algoritmos: Dijkstra y A*.

**REQUIERE:** Graph


```c++
%%INCLUDE(ShortestPaths.cpp)
```


**Output**:

```txt
Dijsktra produces the following path:
	----(w = 0)----> 0 ----(w = 5)----> 1 ----(w = 3)----> 2 ----(w = 4)----> 3 ----(w = 5)----> 4 

A* produces the following path:
	----(w = 0)----> 0 ----(w = 5)----> 1 ----(w = 3)----> 2 ----(w = 4)----> 3 ----(w = 5)----> 4 
```

