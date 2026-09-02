/*Hagan una funcion que me dgia el estado (lea) cualquier bit
uint8_t leeBit(uint64_t dato, uint8_t bitALeer)

Prenda cualquier bit, apague cualquier bit, invierta el estado de cualquier bit */

#include <stdio.h>
#include <stdint.h>
#define QBYTES 64

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

uint8_t leeBit(uint64_t dato, uint8_t bitALeer)
{
  printf("Numero a leer (en Bin):");
  imprimirbin(dato);
  dato = dato >> bitALeer - 1;
  uint8_t bitLeido = dato & 0b1;
  printf("%d \n", bitLeido);
  printf("\n");
  return bitLeido;
}

uint64_t prendeBit(uint64_t dato, uint8_t bitALeer)
{
  printf("Numero a editar (en Bin):");
  imprimirbin(dato);
  uint64_t Editar = 1 << bitALeer - 1;
  uint64_t bitLeido = dato | Editar;
  printf("Numero editado (en Bin):");
  imprimirbin(bitLeido);
  printf("\n");
  return bitLeido;
}

uint64_t apagueBit(uint64_t dato, uint8_t bitALeer)
{
  printf("Numero a editar (en Bin):");
  imprimirbin(dato);
  uint64_t Editar = 1 << bitALeer - 1;
  uint64_t bitLeido = dato & ~Editar;
  printf("Numero editado (en Bin):");
  imprimirbin(bitLeido);
  printf("\n");
  return bitLeido;
}

uint64_t cambioBit(uint64_t dato, uint8_t bitALeer)
{
  printf("Numero a editar (en Bin):");
  imprimirbin(dato);
  uint8_t bitLeido = dato ^ (1 << bitALeer - 1);
  printf("Numero editado (en Bin):");
  imprimirbin(bitLeido);
  printf("\n");
  return bitLeido;
}

int main(void)
{
  uint8_t z = leeBit(7, 3);

  uint64_t bitactivado = prendeBit(4, 2);

  uint64_t bitdesactivado = apagueBit(7, 3);

  uint64_t bitcambiado = cambioBit(3, 3);

  return 0;
}