#include <stdio.h>
#include <stdlib.h>
#include "def.h"

dnodo_t *dcrear_nodo(int num)
{
    dnodo_t *nodo = (dnodo_t *)malloc(sizeof(dnodo_t));
    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo");
        return NULL;
    }
    nodo->dato = num;
    nodo->next = NULL;
    return nodo;
}

void dins_first(dnodo_t **first, dnodo_t **last, int num)
{
    dnodo_t *nuevoNodo = dcrear_nodo(num);

    if (*first == NULL)
    {
        *last = nuevoNodo;
        *first = nuevoNodo;
        return;
    }

    nuevoNodo->next = *first;
    (*first)->prev = nuevoNodo;
    *first = nuevoNodo;

    return;
}

void dins_last(dnodo_t **first, dnodo_t **last, int num)
{
    dnodo_t *nuevoNodo = dcrear_nodo(num);

    if (*last == NULL)
    {
        *last = nuevoNodo;
        *first = nuevoNodo;
        return;
    }

    nuevoNodo->prev = *last;
    (*last)->next = nuevoNodo;
    *last = nuevoNodo;

    return;
}

void ddel_first(dnodo_t **first, dnodo_t **last)
{
    if (*first == *last)
    {
        free(*last);
        *last = NULL;
        *first = NULL;
        printf("LISTA VACIA \n");
        return;
    }
    (*first)->next->prev = NULL;
    dnodo_t *aux = *first;
    *first = (*first)->next;
    (*first)->prev = NULL;
    free(aux);
    aux = NULL;

    return;
}

void ddel_last(dnodo_t **first, dnodo_t **last)
{
    if (*first == *last)
    {
        free(*last);
        *last = NULL;
        *first = NULL;
        printf("LISTA VACIA \n");

        return;
    }
    (*last)->prev->next = NULL;
    dnodo_t *aux = *last;
    *last = (*last)->prev;
    (*last)->next = NULL;
    free(aux);
    aux = NULL;

    return;
}