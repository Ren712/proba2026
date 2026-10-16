#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/* == == == == == IMPRIMIR GRILLA  == == == == == */

void imprimirGrilla(NodoGrilla *first)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;

  while (aux != NULL)
  {
    while (aux != NULL)
    {
      printf("%c ", aux->dato);
      aux = aux->right;
    }
    printf("\n");
    aux2 = aux2->down;
    aux = aux2;
  }
}

void freeMem(NodoGrilla *first)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  printf("\n");

  while (aux != NULL)
  {
    while (aux != NULL)
    {
      aux3 = aux->right;
      printf("%c | ", aux->dato);
      free(aux);
      aux = aux3;
    }
    printf("\n");
    aux2 = aux2->down;
    aux = aux2;
  }
}
/* == == == == == = Ejercicio A == == == == == == */

/*- **a**)
    Escriba una función que remueva los ultimos (de la derecha) N nodos de una fila, elimine todas las conexiones y libere de la memoria.
    > imprima la gilla eliminando 2 nodos de la fila 3.*/

void borrarNodo(NodoGrilla *aux)
{
  if (aux->left != NULL)
  {
    aux->left->right = NULL;
  }
  if (aux->right != NULL)
  {
    aux->right->left = NULL;
  }
  if (aux->up != NULL)
  {
    aux->up->down = NULL;
  }
  if (aux->down != NULL)
  {
    aux->down->up = NULL;
  }
}

int contadorFila(NodoGrilla *first, int fila)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  int auxFila = 0, cont = 0;

  // printf("\nContando Fila: %d \n", fila);
  while (aux != NULL)
  {
    if (auxFila == fila)
    {
      while (aux != NULL)
      {
        // printf("%c ", aux->dato);
        aux = aux->right;
        cont++;
      }
      // printf("\n");
      break;
    }
    aux2 = aux2->down;
    aux = aux2;
    auxFila++;
  }

  return cont;
}

void recortarGrilla(NodoGrilla *first, int fila, int cant)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  int auxFila = 0, longFila = 0, cont = 0;

  longFila = contadorFila(first, fila);

  printf("\nBorrando Fila: %d \n", fila);
  while (aux != NULL)
  {
    if (auxFila == fila)
    {
      while (cont < longFila - cant)
      {
        printf("%c ", aux->dato);
        aux = aux->right;
        cont++;
      }
      while (cont < longFila)
      {
        printf(" -%c ", aux->dato);
        aux3 = aux->right;
        borrarNodo(aux);
        aux = aux3;
        cont++;
      }
      printf("\n---------Listo---------\n");
      break;
    }
    aux2 = aux2->down;
    aux = aux2;
    auxFila++;
  }
}

/* == == == == == = Ejercicio B == == == == == == */

/*- **b**)
    Escriba una función que, tomando un numero de fila, devuelva la diferencia con la fila mas corta de la grilla.
    > imprima la salida para la fila 6.*/

int difFila(NodoGrilla *first, int fila)
{
  int cantmin = __INT_MAX__, temp = 0, cont = 0, dif = 0;
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;

  while (aux != NULL)
  {
    temp = contadorFila(first, cont);
    if (temp < cantmin)
    {
      cantmin = temp;
    }
    aux2 = aux2->down;
    aux = aux2;
    cont++;
  }

  temp = contadorFila(first, fila);
  dif = temp - cantmin;
  // printf("\n %d \n ", dif);
  return dif;
}

/* == == == == == = Ejercicio C == == == == == == */
