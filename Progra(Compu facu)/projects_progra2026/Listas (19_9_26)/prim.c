#include <stdio.h>
#include <stdlib.h>
#include "funcs.c"
#include "def.h"

int main(void)
{
    // DEFINO LOS BLOQUES
    nodo_t *nodo1 = crear_nodo(13);
    nodo_t *nodo2 = crear_nodo(6);
    nodo_t *nodo3 = crear_nodo(3);

    // CREO LAS "FLECHITAS"
    nodo1->next = nodo2;
    nodo2->next = nodo3;

    nodo_t *aux = nodo1;

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