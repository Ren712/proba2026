#include <stdio.h>
#include <stdlib.h>
#include "defTree.h"

nodo_t *crearNodo(int num)
{
    nodo_t *nodo = (nodo_t *)malloc(sizeof(nodo_t));

    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo");
        return NULL;
    }

    nodo->dato = num;
    nodo->left = NULL;
    nodo->right = NULL;

    return nodo;
}

void insOrdenado(nodo_t **first, int num)
{
    nodo_t *nuevoNodo = crearNodo(num);

    if (*first == NULL)
    {
        *first = nuevoNodo;
        return;
    }

    nodo_t *temp = *first;

    while (1)
    {

        if (temp->dato > num)
        {
            printf("\nYendo a la izquierda de : %d |\n", temp->dato);
            if (temp->left == NULL)
            {
                temp->left = nuevoNodo;
                printf("\nValor final  %d |\n\n\n\n", nuevoNodo->dato);
                return;
            }

            temp = temp->left;
        }
        else if (temp->dato < num)
        {
            printf("\nYendo a la derecha de : %d |\n", temp->dato);
            if (temp->right == NULL)
            {
                temp->right = nuevoNodo;
                printf("\nValor final  %d |\n\n\n\n", nuevoNodo->dato);
                return;
            }

            temp = temp->right;
        }
    }
}

nodo_t *search(nodo_t **first, int num)
{
    nodo_t *temp = *first;

    while (1)
    {
        if (temp == NULL)
        {
            printf("\nEl valor no esta en la lista\n ");
            return temp;
        }
        if (temp->dato > num)
        {
            printf("\nYendo a la izquierda de : %d |\n", temp->dato);
            temp = temp->left;
        }
        else if (temp->dato < num)
        {
            printf("\nYendo a la derecha de : %d |\n", temp->dato);
            temp = temp->right;
        }
        else if (temp->dato == num)
        {
            printf("\nEl valor encontrado es %d", temp->dato);
            return temp;
        }
    }
}