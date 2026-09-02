#include <stdio.h>
#include <stdint.h>
#define SHORT_V 70

typedef struct
{
  int prioridad;
  int estado;
  char tipo[15];
} modulo_t;

int main(void)
{
  modulo_t arr[SHORT_V];
  int i = 0;
  float sum = 0;
  FILE *list = fopen("modulos.bin", "rb");

  if (list == NULL)
  {
    perror("No se pudo abrir el archivo");
    return 1;
  }

  while (fread(&arr[i], sizeof(modulo_t), 1, list))
  {
    printf("%d - ", arr[i].prioridad);
    printf("%.2f \n ", sum);
    sum += arr[i].prioridad;
    i++;
  }
  float avg = (sum / i);
  printf("El promedio de prioridad es: %.2f", avg);
  printf("\n");

  /*calcu(&arr[0], SHORT_V, &menos, &nuevo[0]);
  printf("Maximo (ultimo minimo): %d \n", menos);*/

  fclose(list);
  return 0;
}