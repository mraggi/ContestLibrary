## Lowest Common Ancestors

Una clase que, dado un árbol, puede responder a la pregunta "¿quién es el ancestro común más cercano de dos vértices $u$ y $v$?" rápidamente.

Se incluyen sólo la implementación de los $2^i$-ancestros. Hay una mejor pero más complicada de escribir.

- Tiempo de preprocesamiento: $O(n\log(n))$.
- Tiempo para pregunta: $O(\log(n))$

**REQUIERE:** Graph, Tree


```c++
%%INCLUDE(LCA.cpp)
```


**Output**:

```txt
    LCA of 0 and 4: 1
	LCA of 3 and 4: 2
```

