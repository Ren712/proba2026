#include <stdio.h>
#include <stdlib.h>
#include "funcs.c"
#include "def.h"

int main(void)
{

    // CREO UN PRIMER VALOR
    nodo_t *first = NULL;

    // VOY INGRESANDO VALORES DESDE EL PRINCIPIO DE LA FILA
    first = ins_first(first, -4);
    first = ins_first(first, -3);
    first = ins_first(first, -2);
    first = ins_first(first, -1);
    first = ins_first(first, 0);
    first = ins_first(first, 1);
    first = ins_first(first, 2);

    del_last(&first);
    ins_last(first, 263);
    first = del_first(&first);
    ins_mid(&first, 0, 454);
    del_mid(&first, 3);
    nodo_t *aux = first;

    /*
     Esto es lo que voy a usar para ir moviendome por la
     lista sin cambiar el valor del los nodos
     que son parte de la lista
    */

    // RECORRO LA LISTA
    printf("\n MAIN: \n");
    while (aux != NULL)
    {
        printf("%d | ", aux->dato);
        aux = aux->next;
    }
    printf("\n\n");

    //:)
    return 0;
}