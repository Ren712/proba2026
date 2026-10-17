#include <stdio.h>
#include "definiciones.h"
#include "funciones.c"
#include "Catedra_M13.c"

// #define EJ1
// #define EJ2
#define EJ3

int main(void)
{
#ifdef EJ1
  printf("\n ==== EJERCICIO 1 ==== \n");
  int16_t canvas = leerArchivo();
  printf("\nDecimal: %d", canvas);
  printf("\nBinario: %b", canvas);
  printf("\nHexadecimal: ");

  imprimirhex(canvas);
  printf("\n");
  printf("\n");

#endif

#ifdef EJ2
  printf("\n ==== EJERCICIO 2 ==== \n");
  qnode_t *qfirst = CATEDRA_CrearGrilla();

  imprimirGrilla(qfirst);
  imprimirGrilla2(qfirst);
  freeMem(qfirst);

#endif

#ifdef EJ3
  printf("\n ==== EJERCICIO 3 ==== \n");
  dnode_t *medio = CATEDRA_CrearDList();
  dnode_t *primero = NULL;
  dnode_t *ultimo = NULL;

  printf("El valor dado es %d", medio->dato);
  imprimirLista(&medio, &primero, &ultimo);

  printf("...\n");

  imprimirlistasolo(primero);

  toggleCirc(&primero);
  imprimirlistasolo(primero);

  toggleCirc(&(primero->prev));
  imprimirlistasolo((primero->prev));

  freeLista((primero->prev));

#endif
  /* Libere la memoria dinamica utilizada*/

  return 0;
}