#include <stdio.h>
#include <stdlib.h>
#include "Catedra_M19.c"
#include "definiciones.h"
#include "funciones.c"

#define EJ1
#define EJ2

int main(void)
{

#ifdef EJ1
    printf("\n ==== EJERCICIO 1 ==== \n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();

    /* Imprimir grilla original */

    imprimirGrilla(primerNodo);
    printf("\n\n");

    /* Ordenar grilla */

    ordenarGrilla(primerNodo);
    printf("\n\n");

    /* Imprimir grilla ordenada */

    imprimirGrilla(primerNodo);
    printf("\n");

#endif

#ifdef EJ2
    printf("\n ==== EJERCICIO 2 ==== \n");
    int numerosParaInsertar[] = {2, 4, 5, 6, 7, 8, 1, 3, 5, 4, 6, 8, 7, 9, 2};

    NodoArbol *raiz = crearNodo(numerosParaInsertar[0]);

    for (int i = 1; i < (sizeof(numerosParaInsertar) / sizeof(int)); i++)
    {
        insOrdenado(&raiz, numerosParaInsertar[i]);
    }

    printf("\n");
    printTree(raiz, 0);
    printf("\n");

#endif

    return 0;
}
