#include <stdio.h>
#include <stdlib.h>
#include "funcs.c"
#include "def.h"

int main(void)
{

    // CREO UN PRIMER VALOR
    nodo_t *first = crear_nodo(13);

    // VOY INGRESANDO VALORES DESDE EL PRINCIPIO DE LA FILA
    first = ins_first(first, -4);
    first = ins_first(first, -3);
    first = ins_first(first, -2);
    first = ins_first(first, -1);
    first = ins_first(first, 0);
    first = ins_first(first, 1);
    first = ins_first(first, 2);
    del_last(&first);

    nodo_t *aux = first;

    /*
     Esto es lo que voy a usar para ir moviendome por la
     lista sin cambiar el valor del los nodos
     que son parte de la lista
    */

    // RECORRO LA LISTA
    while (aux != NULL)
    {
        printf("%d -> ", aux->dato);
        aux = aux->next;
    }

    //:)
    return 0;
}