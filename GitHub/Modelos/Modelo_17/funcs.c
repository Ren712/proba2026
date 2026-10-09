#include "header.h"

/* Funciones Ejercicio 1 */
void imprimirPos(NodoGrilla *first, NodoGrilla *start, int size, int distancia, int *posFinalx, int *posFinaly)
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
        *posFinalx = posx;
        *posFinaly = posy;
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

void printPath(NodoGrilla *first, int posStartx, int posStarty, int posFinalx, int posFinaly)
{
  NodoGrilla *aux = first;
  NodoGrilla *aux2 = first;
  NodoGrilla *aux3 = first;
  int posx = 0, posy = 0;

  while (posx != posStartx)
  {
    if (posx < posStartx)
    {
      aux = aux->right;
      posx++;
    }
    if (posx > posStartx)
    {
      aux = aux->left;
      posx--;
    }
  }

  while (posy != posStarty)
  {
    if (posy < posStarty)
    {
      aux = aux->down;
      posy++;
    }
    if (posy > posStarty)
    {
      aux = aux->up;
      posy--;
    }
  }

  printf("\n");

  printf(" %c", aux->dato);
  while (posx != posFinalx)
  {
    if (posx < posFinalx)
    {
      aux = aux->right;
      printf(" > %c", aux->dato);
      posx++;
    }
    if (posx > posFinalx)
    {
      aux = aux->left;
      printf(" < %c", aux->dato);
      posx--;
    }
  }

  while (posy != posFinaly)
  {
    if (posy < posFinaly)
    {
      aux = aux->down;
      printf(" / %c", aux->dato);
      posy++;
    }
    if (posy > posFinaly)
    {
      aux = aux->up;
      printf(" ^ %c", aux->dato);
      posy--;
    }
  }
}
/* Funciones Ejercicio 2 */

void imprimirGrilla(Node *first)
{
  Node *aux = first;
  Node *aux2 = aux->next;

  while (aux2 != first)
  {
    printf("%b -> ", aux->dato);
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");
  aux2 = aux->next;
  while (aux2 != first)
  {
    printf("%d -> ", aux->dato);
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");
}

void imprimirGrillaM(Node *first)
{
  Node *aux = first;
  Node *aux2 = aux->next;

  printf("\n");
  while (aux2 != first)
  {
    if ((aux->dato & 3) == 3)
    {
      printf("(%d) -> ", aux->dato);
    }
    else
    {
      printf("%d -> ", aux->dato);
    }
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");
}

void limpiarGrilla(Node *first)
{
  Node *aux = first;
  Node *aux2 = aux->next;
  Node *aux3 = aux->next;
  int count = 1, i = 0;
  Node *punt;

  punt = (Node *)malloc(sizeof(Node));
  if (punt == NULL)
  {
    perror("No se pudo guardar el espacio");
    return;
  }

  printf("\n");

  while (aux2 != first)
  {
    if (((aux->dato & 3) == 3) && ((count % 2 == 0)))
    {
      i++;
      punt = (Node *)realloc(punt, sizeof(Node) * (i)); // no sumo count para actualizar cuales son los pares y cuales no
      punt[i - 1] = *aux;
      aux3->next = aux->next;
    }
    else
    {
      printf("%d -> ", aux->dato);
      count++;
    }
    aux3 = aux;
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");

  for (int x = 0; x < i; x++)
  {
    printf("%d -> ", (punt + x)->dato);
  }
  printf("NULL \n");

  for (int x = 0; x < i; x++)
  {
    free(&punt[x]);
  }

  printf("\n");
}

void freeLista(Node *first)
{
  Node *aux = first;
  Node *aux2 = aux->next;

  while (aux2 != first)
  {
    aux2 = aux->next;
    free(aux);
    aux = aux2;
  }
  printf("Memoria Liberada \n");
}
