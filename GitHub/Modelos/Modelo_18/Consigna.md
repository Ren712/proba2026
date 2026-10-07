# Recuperatorio (M18) - Programacion en C - 2026C1

## Ejercicio 1

La función CATEDRA_CrearGrillaIrregular devuelve la dirección de memoria de el primer nodo (el de arriba a la izquierda) de una grilla irregular (no todas las filas tienen el mismo largo).

```c
typedef struct NodoGrilla {
    char dato;
    struct NodoGrilla* up;
    struct NodoGrilla* down;
    struct NodoGrilla* left;
    struct NodoGrilla* right;
} NodoGrilla;

typedef struct {
    int fila;
    int columna;
} Posicion;
```

- **a**)
    Escriba una función que remueva los ultimos (de la derecha) N nodos de una fila, elimine todas las conexiones y libere de la memoria.
    > imprima la gilla eliminando 2 nodos de la fila 3.

- **b**)
    Escriba una función que, tomando un numero de fila, devuelva la diferencia con la fila mas corta de la grilla.
    > imprima la salida para la fila 6.

- **c**)
    Utilizando las funciones de los ejercicios a y b, elimine los nodos necesarios para que la grilla sea rectangular.
    > imprima la grilla final.

Por ejemplo, para la siguiente grilla:

=========== Original ===========

```c
A R X W E O D H $            //(Fila 0) 
D @ C # K F J U # I U A W    //(Fila 1)
O B Z F Y Y F D R T          //(Fila 2) 
A X O H V R & X G I U        //(Fila 3) 
P V J Q D B A Q O $ A P      //(Fila 4) 
P $ C J Z F # O F U V E D    //(Fila 5) 
I Z S G Z I O I J W M L      //(Fila 6) 
Z M V D $ S F G F C Y        //(Fila 7) 
U I G L E B L @ T K R U Y Z  //(Fila 8) 
Q H K A G G M T J            //(Fila 9) 
```

=========== Ejercicio A ===========

```c
A R X W E O D H $            //(Fila 0) 
D @ C # K F J U # I U A W    //(Fila 1)
O B Z F Y Y F D R T          //(Fila 2) 
A X O H V R & X G            //(Fila 3) 
P V J Q D B A Q O $ A P      //(Fila 4) 
P $ C J Z F # O F U V E D    //(Fila 5) 
I Z S G Z I O I J W M L      //(Fila 6) 
Z M V D $ S F G F C Y        //(Fila 7) 
U I G L E B L @ T K R U Y Z  //(Fila 8) 
Q H K A G G M T J            //(Fila 9) 
```

=========== Ejercicio B ===========

```c
Largo minimo:  9
Largo fila 6: 12
Diferencia:    3
```

=========== Ejercicio C ===========

```c
A R X W E O D H $   //(Fila 0) 
D @ C # K F J U #   //(Fila 1)
O B Z F Y Y F D R   //(Fila 2) 
A X O H V R & X G   //(Fila 3) 
P V J Q D B A Q O   //(Fila 4) 
P $ C J Z F # O F   //(Fila 5) 
I Z S G Z I O I J   //(Fila 6) 
Z M V D $ S F G F   //(Fila 7) 
U I G L E B L @ T   //(Fila 8) 
Q H K A G G M T J   //(Fila 9) 
```
