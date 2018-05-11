## Range Minimum Query

Dada una lista, permite preprocesarla para poder contestar preguntas de tipo
"¿Cuál es el índice con el valor mínimo en el rango [L,R)?"

- Tiempo de preprocesamiento: $O(n\log(n))$
- Tiempo para contestar pregunta: $O(1)$.

Permite definir qué significa "menor qué".

```c++
%%INCLUDE(RangeMinQuery.cpp)
```

**Output**:

```txt
    A = 1 5 3 9 6 10 1 5 7 9 8 0 7 4 2 10 2 3 8 6 5 7 8 9 9 
	Min value between index 5 and index 15 is at: 11 with val 0
	And the max value is at: 5 with val 10
```



