#include "header.h"
#include <stdio.h>

/* Funciones Ejercicio 1 */
void imprimirPos(NodoGrilla *first, NodoGrilla *start, Posicion *pos)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  int posx = 0, posy = -1;

  // printf("\n");
  while (aux != NULL)
  {
    posx = 0;
    posy++;
    while (aux != NULL)
    {
      aux3 = aux->right;
      // printf("%c | ", aux->dato);
      if (aux->dato == start->dato)
      {
        pos->columna = posx;
        pos->fila = posy;
        return;
      }
      aux = aux3;
      posx++;
    }
    // printf("\n");
    aux2 = aux2->down;
    aux = aux2;
  }
}

void printPath(NodoGrilla *first, Posicion *posStart, Posicion *posFinal)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  int posx = 0, posy = 0;

  while (posx != posStart->columna)
  {
    if (posx < posStart->columna)
    {
      aux = aux->right;
      posx++;
    }
    if (posx > posStart->columna)
    {
      aux = aux->left;
      posx--;
    }
  }

  while (posy != posStart->fila)
  {
    if (posy < posStart->fila)
    {
      aux = aux->down;
      posy++;
    }
    if (posy > posStart->fila)
    {
      aux = aux->up;
      posy--;
    }
  }

  printf("\n");

  printf(" %c", aux->dato);
  while (posx != posFinal->columna)
  {
    if (posx < posFinal->columna)
    {
      aux = aux->right;
      printf(" > %c", aux->dato);
      posx++;
    }
    if (posx > posFinal->columna)
    {
      aux = aux->left;
      printf(" < %c", aux->dato);
      posx--;
    }
  }

  while (posy != posFinal->fila)
  {
    if (posy < posFinal->fila)
    {
      aux = aux->down;
      printf(" ⌄ %c", aux->dato);
      posy++;
    }
    if (posy > posFinal->fila)
    {
      aux = aux->up;
      printf(" ^ %c", aux->dato);
      posy--;
    }
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

  return;
}

/* Funciones Ejercicio 2 */