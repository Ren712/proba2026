
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "funcs.c"
#include "Catedra_M17.c"

// #define EJ1
#define EJ2

int main()
{

#ifdef EJ1
    printf("--- EJERCICIO 1 ---\n\n");
    NodoGrilla *primerNodo = CATEDRA_CrearGrilla();
    /* Imprimir Grilla */

    /* Info Item B  */
    NodoGrilla **targets;
    int size, distancia, alg = 0;
    NodoGrilla *start = CATEDRA_InfoRandom(primerNodo, &targets, &size, &distancia);

    /* Imprimir start, targets y distancia */
    printf("\nstart: %c", start->dato);
    printf("\ncant: %d", size);
    for (int i = 0; i < size; i++)
    {
        printf("\nTarget %d: %c", i + 1, (*(targets + i))->dato);
    }
    printf("\ndist: %d", distancia);

    /* Imprimir los caminos que cumplan */
    int posStartx, posStarty, posFinalx, posFinaly;

    posStartx = 0;
    posStarty = 0;
    posFinalx = 0;
    posFinaly = 0;

    imprimirPos(primerNodo, start, size, distancia, &posStartx, &posStarty);
    for (int i = 0; i < size; i++)
    {
        // printf("\n");
        // printf("\n");
        imprimirPos(primerNodo, *(targets + i), size, distancia, &posFinalx, &posFinaly);
        if ((abs(posStartx - posFinalx) + abs(posStarty - posFinaly)) == distancia)
        {
            printf("\n\n Camino Valido para %c", (*(targets + i))->dato);
            printPath(primerNodo, posStartx, posStarty, posFinalx, posFinaly);
            alg = 1;
        }
    }

    if (alg == 0)
    {
        printf("\n\nNo hay ningun camino valido");
    }

    printf("\n");
    // printf(" X: %d", posStartx);
    // printf("\n");
    // printf(" Y: %d", posStarty);

    freeMem(primerNodo);

#endif // EJ1

#ifdef EJ2
    printf("\n\n--- EJERCICIO 2 ---\n\n");
    int tamanio = 0;
    Node *first = CATEDRA_CrearLista();

    /* Item a --> Lista original */
    imprimirGrilla(first);

    /* item b --> Lista original "marcada" */
    imprimirGrillaM(first);

    /* Item c --> Funcion */
    limpiarGrilla(first);

    /* item d --> Lista final y vector*/
    freeLista(first);

#endif // EJ2
    printf("\n");
    return 0;
}