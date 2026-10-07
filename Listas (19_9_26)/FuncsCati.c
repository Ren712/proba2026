#include <stdlib.h>
#include "def.h"

nodo_t *crear_nodo(int dato)
{
    nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));
    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo\n");
    }
    nodo->num = dato; //
    nodo->next = NULL;
    return nodo;
}

// Inserta algo al principio de la lista
nodo_t *ins_first(nodo_t *first, int dato)
{
    nodo_t *nuevoNodo = crear_nodo(dato);
    nuevoNodo->next = first;
    return nuevoNodo;
}

void del_last(nodo_t **first)
{
    if (*first == NULL)
    {
        return;
    }
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }
    nodo_t *aux = *first;
    while (aux->next->next != NULL)
    {

        aux = (aux->next);
    }
    nodo_t *aux2 = aux->next;
    free(aux2);
    aux->next = NULL;
}

void *ins_last(nodo_t *first, int dato)
{
    nodo_t *aux = first;
    nodo_t *nuevoNodo = crear_nodo(dato);
    while (aux->next != NULL)
    {
        // printf("-> %d \n", aux->num);
        aux = (aux->next);
    }
    aux->next = nuevoNodo;
}

nodo_t *del_first(nodo_t **first)
{
    if (*first == NULL)
    {
        return NULL;
    }
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return NULL; // ayudaaaaaaaaaaaaaaa
    }
    nodo_t *aux = (*first)->next;
    free(*first);
    *first = NULL;

    return aux;
}

void ins_mid(nodo_t *first, int dato, int pos)
{
    nodo_t *aux = first;

    nodo_t *nuevoNodo = crear_nodo(dato);

    for (int i = 1; (i < pos - 1) && (aux->next->next != NULL); i++)
    {
        aux = (aux->next);
        if (aux->next->next == NULL)
        {
            aux->next->next = nuevoNodo;
            return;
        }
    }

    nuevoNodo->next = aux->next;
    aux->next = nuevoNodo;
    return;
}

void del_mid(nodo_t **first, int pos)
{
    if (*first == NULL)
    {
        return;
    }
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }
    nodo_t *aux = *first;

    for (int i = 1; (i < pos - 1) && (aux->next->next != NULL); i++)
    {
        aux = (aux->next);
    }

    nodo_t *aux2 = aux->next;
    aux->next = aux->next->next;

    free(aux2);
    return;
}

void del_search(nodo_t **first, int dato) // no funciona si tengo que eliminar el primero, ayuda
{
    nodo_t *aux = *first;
    nodo_t *aux2 = *first;

    if (*first == NULL)
    {
        return;
    }
    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }
    while ((aux->next != NULL) && (aux->num != dato))
    {
        aux2 = aux;
        aux = (aux->next);
    }
    if (aux->num == dato)
    {

        aux2->next = aux2->next->next;

        free(aux);
        return;
    }

    return;
}