#include <stdio.h>
#include <stdint.h>
#define LARGOFILE 2000
/*
Preguntas Teoricas:

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

int main(void)
{

  int a = 0b1011;
  int b = 0b1100;

  int c = a ^ b;
  imprimirbin(c);
  return 0;
}*/

typedef struct
{
  int op;
  union direc
  {
    uint8_t up;
    uint8_t right;
    uint8_t down;
    uint8_t left;
  } direc;
} RC1_t;

int main(void)
{
  RC1_t arr[LARGOFILE];
  int cont[4];
  int changecount = 1;
  int i = 0;
  FILE *list = fopen("RecuC1.bin", "rb");

  if (list == NULL)
  {
    perror("No se pudo abrir el archivo");
    return 1;
  }

  while (fread(&arr[i], sizeof(RC1_t), 1, list))
  {
    printf("%d - ", arr[i].op);
    if (i > 0)
    {
      if (arr[i].op != arr[i - 1].op)
      {
        changecount++;
      }
    }
    cont[arr[i].op]++;
    i++;
  }

  int maximo = 0;
  int mascomun = 5;

  for (int j = 0; j < 4; j++)
  {
    printf("\ncontj %d : %d", j, cont[j]);
    if (cont[j] > maximo)
    {
      maximo = cont[j];
      mascomun = j;
    }
  }
  printf(" \nEl mas usado es: %d", mascomun);
  printf(" \ny la cantidad de cambios es: %d \n", changecount);
  printf("\n");

  /*calcu(&arr[0], SHORT_V, &menos, &nuevo[0]);
  printf("Maximo (ultimo minimo): %d \n", menos);*/

  fclose(list);
  return 0;
}