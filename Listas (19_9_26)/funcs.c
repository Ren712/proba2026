#include <stdio.h>
#include <stdlib.h>
#include "def.h"

nodo_t *crear_nodo(int num)
{
    nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo");
        return NULL;
    }
    nodo->dato = num;
    nodo->next = NULL;
    return nodo;
}

nodo_t *ins_first(nodo_t *first, int num)
{
    nodo_t *nuevoNodo = crear_nodo(num);
    nuevoNodo->next = first;
    // de esta forma si first es null nos chupa un huevo
    return nuevoNodo;
}

void del_last(nodo_t **first)
{
    // no queremos que nos devuelva nada porque el vector que apunta al ultimo nodo no nos importa

    // DECLARO UN AUXILIAR PARA RECORRER LA LISTA
    nodo_t *aux = *first;

    // VERIFICO QUE HAYA UNA CANTIDAD SUFICIENTE DE NODOS
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }

    // RECORRO LA LISTA
    while (aux->next->next != NULL)
    {
        // comparo con next para pararme en el ante-ultimo, porque necesito que quede apuntando a null
        // printf("%d -> ", aux->dato);
        aux = aux->next;
    }

    nodo_t *aux2 = aux->next;
    free(aux2);
    aux->next = NULL;
}

void ins_last(nodo_t *first, int num)
{
    nodo_t *nuevoNodo = crear_nodo(num);

    nodo_t *aux = first;

    printf("\nINS LAST:\n");
    while (aux->next != NULL)
    {
        printf("%d | ", aux->dato);
        aux = aux->next;
    }
    printf("\n\n");

    aux->next = nuevoNodo;
}

nodo_t *del_first(nodo_t **first)
{
    if (*first == NULL)
    {
        printf("LA LISTA ESTA VACIA \n");
        return NULL;
    }
    nodo_t *nuevoFirst = (*first)->next;
    free(*first);
    *first = NULL;
    return nuevoFirst;
}

void ins_mid(nodo_t **first, int pos, int num)
{
    nodo_t *nuevoNodo = crear_nodo(num);

    nodo_t *aux = *first;
    int i = 0;

    printf("\n INS MID: \n");

    if (pos < 1)
    {
        nuevoNodo->next = *first;
        *first = nuevoNodo;
    }

    while (i + 1 < pos)
    {
        if (aux->next == NULL)
        {
            aux->next = nuevoNodo;
            return;
        }
        printf("%d | ", aux->dato);
        aux = aux->next;
        i++;
    }

    printf("\n\n");

    nuevoNodo->next = aux->next;
    aux->next = nuevoNodo;
}

void del_mid(nodo_t **first, int pos)
{
    if (*first == NULL)
    {
        printf("\n LISTA VACIA \n");
        return;
    }
    if ((*first)->next == NULL)
    {

        printf("\n LISTA VACIA \n");
        free(*first);
        *first = NULL;
        return;
    }
    if (pos < 1)
    {
        *first = del_first(first);
        return;
    }

    nodo_t *aux = *first;

    for (int i = 0; (i + 1 < pos) && (aux->next->next != NULL); i++)
    {
        aux = (aux->next);
    }

    printf("\n aux: %d", aux->dato);

    nodo_t *aux2 = aux->next;

    printf("\n aux2: %d", aux2->dato);

    aux->next = aux->next->next;

    free(aux2);
    return;
}