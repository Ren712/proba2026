#include <stdio.h>
#include <stdlib.h>
#include "dfuncs.c"
#include "def.h"

int main(void)
{
    dnodo_t *first = NULL;
    dnodo_t *last = NULL;

    dins_first(&first, &last, 5);
    dins_first(&first, &last, 4);
    dins_first(&first, &last, 3);
    dins_first(&first, &last, 2);
    dins_first(&first, &last, 1);
    dins_first(&first, &last, 0);

    dnodo_t *aux = first;

    printf("MAIN:\n");
    while (aux != NULL)
    {
        printf("%d | ", aux->dato);
        aux = aux->next;
    }
    printf("\n\n");

    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_first(&first, &last);
    ddel_last(&first, &last);

    aux = first;

    /*
     Esto es lo que voy a usar para ir moviendome por la
     lista sin cambiar el valor del los nodos
     que son parte de la lista
    */

    // RECORRO LA LISTA
    printf("MAIN:\n");
    while (aux != NULL)
    {
        printf("%d | ", aux->dato);
        aux = aux->next;
    }
    printf("\n\n");

    return 0;
}