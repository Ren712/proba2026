
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "funcs.c"
#include "Catedra_M16.c"

// #define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();

    /* Imprimir Grilla */
    // HECHO EN EL FREEMEM

    /* Caminos que cumplen (ejercicio 2) */
    Posicion start, finish;
    finish.columna = 1;
    finish.fila = 1;
    NodoGrilla *nodoRand = CATEDRA_NodoRandom(primerNodo);

    printf("\n Var: %c", nodoRand->dato);
    imprimirPos(primerNodo, nodoRand, &start);
    printf("\n X: %d", start.columna);
    printf("\n Y: %d", start.fila);

    printPath(primerNodo, &start, &finish);

    freeMem(primerNodo);
#endif // EJ1

#ifdef EJ2
    printf("--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    customElement *vec = CATEDRA_CrearVector(&tamanio);

    for (int i = 0; i < tamanio; i++)
    {
        if (vec[i].esNro)
        {
            printf("%d : %d \n", i, vec[i].dato.numero);
        }
        else
        {
            printf("%d : %c \n", i, vec[i].dato.caracter);
        }
    }

    NodoDoble *first;
    NodoDoble *last = first;

    funcionb(vec, tamanio, &first, &last);

    NodoDoble *aux = first;
    int cont = 0;

    printf("MAIN:\n");
    while (aux != NULL)
    {
        printf("%d | ", aux->numero);
        aux = aux->next;
        cont++;
    }
    printf("\n\n");

    printf("MAIN 2:\n");
    for (int i = 0; i < tamanio - cont; i++)
    {
        if (vec[i].esNro)
        {
            printf("%d : %d \n", i, vec[i].dato.numero);
        }
        else
        {
            printf("%d : %c \n", i, vec[i].dato.caracter);
        }
    }

#endif // EJ2
    printf("\n");
    return 0;
}