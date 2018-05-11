## Maximum Flow

ESTE CÓDIGO NO LO ESCRIBÍ YO.

Dada una gráfica dirigida con capacidades, una fuente y un pozo, encuentra el máximo flujo. Puede usarse para resolver mínimo corte, con el teorema de mínimo corte y máximo flujo, simplemente considerando todas las parejas de flujo $(0,v)$ con $v > 0$.

**NOTA**: Al llamar `GetMaxFlow` se mofica permanentemente el grafo. Si se necesita llamar varias veces, hay que hacer copias. Después hago un método "Reset".

```c++
%%INCLUDE(MaxFlow.cpp)
```


**Output**:

```txt
    Max flow: 5
```

