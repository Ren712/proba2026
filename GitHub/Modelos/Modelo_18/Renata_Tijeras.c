#include <stdio.h>
#include <stdlib.h>
#include "CATEDRA_M18.c"
#include "header.h"
#include "funcs.c"

int main(void)
{
    printf("\n\n--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrillaIrregular();

    printf("\nOriginal:\n");

    imprimirGrilla(primerNodo);

    printf("\nA)\n");

    recortarGrilla(primerNodo, 5, 4);

    printf("\nB)\n");

    difFila(primerNodo, 3);

    printf("\nC)\n\n");

    NodoGrilla *aux = primerNodo;
    NodoGrilla *aux2 = primerNodo;
    int dif = 0, cont = 0;

    while (aux != NULL)
    {
        dif = difFila(primerNodo, cont);
        recortarGrilla(primerNodo, cont, dif);
        printf("\n");
        aux2 = aux2->down;
        aux = aux2;
        cont++;
    }

    imprimirGrilla(primerNodo);

    freeMem(primerNodo);
    printf("\n\n");
    return 0;
}