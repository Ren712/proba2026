#include "header.h"
#include <stdio.h>
#include <stdlib.h>

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
NodoDoble *crear_nodo(int num)
{
  NodoDoble *nodo = (NodoDoble *)malloc(sizeof(NodoDoble));
  if (nodo == NULL)
  {
    printf("No se pudo crear el nodo");
    return NULL;
  }
  nodo->numero = num;
  nodo->next = NULL;
  nodo->prev = NULL;

  return nodo;
}

void funcionb(customElement *vector, int tamanio, NodoDoble **first, NodoDoble **last)
{

  int cantdel = 0;
  NodoDoble *nuevoNodo;
  NodoDoble *aux = *first;
  customElement *chusma;

  for (int i = 0; i < tamanio - cantdel; i++)
  {
    aux = *first;
    chusma = &vector[i];
    if (vector[i].esNro)
    {
      nuevoNodo = crear_nodo((vector[i].dato.numero));
      if (cantdel == 0)
      {
        *first = nuevoNodo;
        *last = nuevoNodo;
      }
      else
      {
        if (aux->next == NULL)
        {
          *last = nuevoNodo;
        }
        else
        {
          while (aux->next->numero > nuevoNodo->numero)
          {
            aux = aux->next;
            if (aux->next == NULL)
            {
              *last = nuevoNodo;
              break;
            }
          }
        }
        if (aux->next != NULL)
        {
          aux->next->prev = nuevoNodo;
        }
        nuevoNodo->next = aux->next;
        aux->next = nuevoNodo;
        nuevoNodo->prev = aux;
      }
      cantdel++;
      printf("%d : %d \n", i, vector[i].dato.numero);
      if (i + 1 < tamanio)
      {
        vector[i] = vector[i + cantdel];
        i--;
      }
    }
    else
    {
      printf("%d : %c \n", i, vector[i].dato.caracter);
    }
  }
}
