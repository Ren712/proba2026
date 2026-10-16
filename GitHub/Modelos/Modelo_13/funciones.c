/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"

/* === EJERCICIO 1 === */

void imprimirhex(uint16_t dato)
{
  char digitos[] = "0123456789ABCDEF";

  printf("0x");
  for (int i = 16; i > 0; i--)
  {
    printf("%c", digitos[(dato >> (i - 1) * 4) & 0xF]);
  }
  printf("\n");
}

void imprimirbin(uint64_t dato)
{
  for (int i = 64; i > 0; i--)
  {
    if (i % 4 == 0)
    {
      printf(" ");
    }
    printf("%ld", (dato >> i - 1) & 1);
  }
  printf("\n");
}

uint16_t leerArchivo()
{
  FILE *list = fopen("M13.bin", "rb");
  M13_t templeido;
  int16_t canvas = 0, editor = 0;

  if (list == NULL)
  {
    perror("No se pudo abrir el archivo");
    return 1;
  }

  while (fread(&templeido, sizeof(M13_t), 1, list))
  {
    if (templeido.act == SET)
    {
      editor = 1 << templeido.nrBits - 1;
      canvas = canvas | editor;
    }
    else if (templeido.act == RESET)
    {
      editor = 1 << templeido.nrBits - 1;
      canvas = canvas & ~editor;
    }
    else
    {
      printf("no se ha podido interpretar la consigna");
    }
  }

  return canvas;
}

/* === EJERCICIO 2 === */

void imprimirGrilla(qnode_t *first)
{
  qnode_t *aux = first;
  qnode_t *aux2 = first;

  while (aux != NULL)
  {
    while (aux != NULL)
    {
      printf("%d | ", aux->valor);
      aux = aux->right;
    }
    printf("\n");
    aux2 = aux2->down;
    aux = aux2;
  }
}

void imprimirGrilla2(qnode_t *first)
{
  qnode_t *aux = first;
  qnode_t *aux2 = first;
  int count = 0;

  while (aux != NULL)
  {
    while (aux != NULL)
    {
      printf(" %d ", aux->valor);
      if ((aux->right == NULL) && (aux->down != NULL) && (aux->down->right != NULL))
      {
        aux->right = aux->down->right->up;
      }
      else if ((aux->right == NULL) && (aux->up != NULL) && (aux->up->right != NULL))
      {
        aux->right = aux->up->right->down;
      }
      aux = aux->right;
      count++;
    }
    printf("\t %d\n", count);
    count = 0;
    aux2 = aux2->down;
    aux = aux2;
  }
}

void freeMem(qnode_t *first)
{
  qnode_t *aux = first;
  qnode_t *aux2 = first;
  qnode_t *aux3 = first;
  printf("\nLIBERANDO MEMORIA \n");

  while (aux != NULL)
  {
    aux2 = aux2->down;
    while (aux != NULL)
    {
      aux3 = aux->right;
      printf("%d | ", aux->valor);
      free(aux);
      aux = aux3;
    }
    printf("\n");
    aux = aux2;
  }

  return;
}

// Esto es una prueba

/* === EJERCICIO 3 === */
void imprimirlistasolo(dnode_t *first)
{
  dnode_t *aux = first;
  dnode_t *aux2 = NULL;

  while ((aux2 != first) && (aux != NULL))
  {
    printf("%d -> ", aux->dato);
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");
}

void imprimirLista(dnode_t **middle, dnode_t **first, dnode_t **last)
{
  dnode_t *aux = *middle;
  dnode_t *aux2 = aux->next; // por si es circular
  dnode_t *auxprev = *middle;
  dnode_t *auxnext = *middle;

  int firstFound = 0, lastFound = 0;

  printf("\n");
  while (((firstFound == 0) || (lastFound == 0)) && (aux2 != *middle))
  {
    if (auxprev->prev == NULL)
    {
      printf("\nSe encontro el principio\n");
      if (firstFound == 0 && lastFound == 0)
      {
        auxprev->prev = (*middle);
        (*middle)->next->prev = (*middle)->prev;
        (*middle)->prev->next = (*middle)->next;
        (*middle)->next = auxprev;
        (*middle)->prev = NULL;
        auxprev = *middle;
      }
      *first = auxprev;
      auxprev = auxnext;
      firstFound = 1;
    }
    if (auxnext->next == NULL)
    {
      printf("\nSe encontro el final\n");
      *last = auxnext;
      if (firstFound == 0 && lastFound == 0)
      {
        auxnext->next = (*middle);
        (*middle)->next->prev = (*middle)->prev;
        (*middle)->prev->next = (*middle)->next;
        (*middle)->next = NULL;
        (*middle)->prev = auxnext;
        auxnext = *middle;
      }
      *last = auxnext;
      auxnext = auxprev;
      lastFound = 1;
    }
    auxprev = auxprev->prev;
    auxnext = auxnext->next;
    aux2 = auxnext;
  }

  printf("\n");
}

void toggleCirc(dnode_t **first)
{
  dnode_t *aux = *first;
  dnode_t *aux2 = aux->next;

  while (1)
  {
    if (aux->next == NULL)
    {
      printf("\n La lista no es circular, La hago circular\n");
      aux->next = *first;
      (*first)->prev = aux;
      break;
    }
    if (aux2 == *first)
    {
      printf("\n La lista es circular, la corto \n");
      (*first)->prev->next = NULL;
      (*first)->prev = NULL;
      break;
    }
    aux = aux->next;
    aux2 = aux;
  }

  printf("\n");
}
