/* Utilice este archivo para escribir sus funciones */
#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

/* === EJERCICIO 1 === */
void imprimirGrilla(NodoGrilla *first)
{
    NodoGrilla *aux = first;
    NodoGrilla *aux2 = first;

    while (aux != NULL)
    {
        while (aux != NULL)
        {
            printf("%d | ", aux->dato);
            aux = aux->right;
        }
        printf("\n");
        aux2 = aux2->down;
        aux = aux2;
    }
}
void ordenarGrilla(NodoGrilla *first)
{
    NodoGrilla *aux = first;
    NodoGrilla *aux2 = first;
    int auxvalor = 58;
    int cambios = 1;

    while (cambios != 0)
    {
        cambios = 0;
        aux = first;
        aux2 = first;
        printf("\n\n");
        while (aux != NULL)
        {
            while (aux != NULL)
            {
                if (aux->down != NULL)
                {
                    if (aux->dato > aux->down->dato)
                    {
                        aux->down->nextDato = aux->dato;
                        aux->dato = aux->down->dato;
                        aux->down->dato = aux->down->nextDato;
                        cambios = 1;
                    }
                }
                printf("%d | ", aux->dato);
                aux = aux->down;
            }
            printf("\n");
            aux2 = aux2->right;
            aux = aux2;
        }
    }
}
void imprimirnextGrilla(NodoGrilla *first)
{
    NodoGrilla *aux = first;
    NodoGrilla *aux2 = first;

    while (aux != NULL)
    {
        while (aux != NULL)
        {
            printf("%d | ", aux->nextDato);
            aux = aux->right;
        }
        printf("\n");
        aux2 = aux2->down;
        aux = aux2;
    }
}

/* === EJERCICIO 2 === */
NodoArbol *crearNodo(int num)
{
    NodoArbol *nodo = (NodoArbol *)malloc(sizeof(NodoArbol));

    if (nodo == NULL)
    {
        printf("No se pudo crear el nodo");
        return NULL;
    }

    nodo->dato = num;
    nodo->cantidad = 1;
    nodo->izq = NULL;
    nodo->der = NULL;

    return nodo;
}

void insOrdenado(NodoArbol **first, int num)
{
    NodoArbol *nuevoNodo = crearNodo(num);

    if (*first == NULL)
    {
        *first = nuevoNodo;
        return;
    }

    NodoArbol *temp = *first;

    while (1)
    {

        if (temp->dato > num)
        {
            printf("\nYendo a la izquierda de : %d |", temp->dato);
            if (temp->izq == NULL)
            {
                temp->izq = nuevoNodo;
                printf("\nValor final  %d |\n\n\n\n", nuevoNodo->dato);
                return;
            }

            temp = temp->izq;
        }
        else if (temp->dato < num)
        {
            printf("\nYendo a la derecha de : %d |", temp->dato);
            if (temp->der == NULL)
            {
                temp->der = nuevoNodo;
                printf("\nValor final  %d |\n\n\n\n", nuevoNodo->dato);
                return;
            }

            temp = temp->der;
        }
        else if (temp->dato == num)
        {
            temp->cantidad = temp->cantidad + 1;
            printf("\n Ahora la cantidad de %d es %d \n\n", num, temp->cantidad);
            return;
        }
    }
}

void printTree(NodoArbol *n, int level)
{
    if (n == NULL)
    {
        return;
    }

    printf("\n");

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("└── %d - Q: %d ", n->dato, n->cantidad);
    printTree(n->der, level + 1);
    printTree(n->izq, level + 1);
}