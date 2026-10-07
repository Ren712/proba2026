#include <stdio.h>
#include <stdlib.h>
#include "funcsTree.c"
#include "defTree.h"

int main(void)
{
    nodo_t *first = crearNodo(10);
    insOrdenado(&first, 5);
    insOrdenado(&first, 15);
    insOrdenado(&first, 7);
    insOrdenado(&first, 20);
    insOrdenado(&first, 18);
    insOrdenado(&first, 23);

    nodo_t *buscar = search(&first, 59);
    return 0;
}