/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"

/* === EJERCICIO 1 === */
/*uint16_t leerArchivo()
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
}*/
nodo *crear_nodo(int num)
{
  nodo *nodoaux = (nodo *)malloc(sizeof(nodo));
  if (nodoaux == NULL)
  {
    printf("No se pudo crear el nodo");
    return NULL;
  }
  nodoaux->dato = num;
  nodoaux->next = NULL;
  return nodoaux;
}

void toggleCirc(nodo **first)
{
  nodo *aux = *first;
  nodo *aux2 = NULL;

  while (1)
  {
    aux2 = aux;
    if (aux->next == NULL)
    {
      printf("\n La lista no es circular, La hago circular\n");
      aux->next = *first;
      break;
    }
    if (aux2->next == *first)
    {
      printf("\n La lista es circular, la corto \n");
      aux->next = NULL;
      break;
    }
    aux = aux->next;
  }
  printf("\n");
}

void freeLista(nodo *first)
{
  nodo *aux = first;
  nodo *aux2 = NULL;

  while ((aux2 != first) && (aux != NULL))
  {
    aux2 = aux->next;
    free(aux);
    aux = aux2;
  }
  printf("Memoria Liberada \n");
}

void *ins_first(nodo **first, int num)
{
  nodo *aux = (*first);
  nodo *nuevoNodo = crear_nodo(num);
  nodo *aux2 = NULL;

  while ((aux != NULL))
  {
    aux2 = aux->next;
    if (aux2 == (*first))
    {
      aux->next = nuevoNodo;
      break;
    }
    aux = aux2;
  }

  nuevoNodo->next = (*first);
  (*first) = nuevoNodo;

  // de esta forma si first es null nos chupa un huevo
  return 0;
}

void del_last(nodo **first)
{
  // no queremos que nos devuelva nada porque el vector que apunta al ultimo nodo no nos importa

  // DECLARO UN AUXILIAR PARA RECORRER LA LISTA
  nodo *aux = *first;

  // VERIFICO QUE HAYA UNA CANTIDAD SUFICIENTE DE NODOS
  if (((*first)->next == NULL) || ((*first)->next == (*first)))
  {
    free(*first);
    *first = NULL;
  }
  nodo *aux2 = aux->next;
  // RECORRO LA LISTA
  while ((aux->next->next != NULL))
  {
    // comparo con next para pararme en el ante-ultimo, porque necesito que quede apuntando a null
    // printf("%d -> ", aux->dato);
    aux = aux->next;
    if ((aux->next->next == (*first)))
    {
      aux2 = aux->next;
      free(aux2);
      aux->next = (*first);
      return;
    }
  }
  aux2 = aux->next;
  free(aux2);
  aux->next = NULL;
  return;
}

void imprimirlista(nodo *first)
{
  nodo *aux = first;
  nodo *aux2 = NULL;

  while ((aux2 != first) && (aux != NULL))
  {
    printf("%d -> ", aux->dato);
    aux = aux->next;
    aux2 = aux;
  }
  printf("NULL \n");

  printf("\n");
}

void armarLista()
{
  FILE *list = fopen("M12.dat", "rb");
  M12_t templeido;
  nodo *first = NULL;

  while (fread(&templeido, sizeof(M12_t), 1, list))
  {
    if (templeido.mask == 10)
    {
      printf("%b - %d - 10\n", templeido.mask, templeido.mask);
      toggleCirc(&first);
      imprimirlista(first);
      printf("\n");
    }
    else if (templeido.mask == 11)
    {
      printf("%b - %d - 11\n", templeido.mask, templeido.mask);
      freeLista(first);
      imprimirlista(first);
      printf("\n");
    }
    else if ((templeido.mask & 3) == 2)
    {
      printf("%b - %d - 2\n", templeido.mask, templeido.mask);
      ins_first(&first, templeido.dato);
      imprimirlista(first);
      printf("\n");
    }
    else if ((templeido.mask & 3) == 3)
    {
      printf("%b - %d - 3\n", templeido.mask, templeido.mask);
      del_last(&first);
      imprimirlista(first);
      printf("\n");
      // freeLista(first);
    }
    else
    {
      printf("no se ha podido interpretar la consigna");
    }
  }
}

/* === EJERCICIO 2 === */
