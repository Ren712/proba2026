#include "header.h"

/* Funciones Ejercicio 1 */
void imprimirPos(NodoGrilla *first, NodoGrilla *start, int size, int distancia, int *posFinalx, int *posFinaly)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  int posx = 0, posy = -1;

  printf("\n");
  while (aux != NULL)
  {
    posx = 0;
    posy++;
    while (aux != NULL)
    {
      aux3 = aux->right;
      printf("%c | ", aux->dato);
      if (aux->dato == start->dato)
      {
        *posFinalx = posx;
        *posFinaly = posy;
        return;
      }
      aux = aux3;
      posx++;
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

  return;
}

/* Funciones Ejercicio 2 */