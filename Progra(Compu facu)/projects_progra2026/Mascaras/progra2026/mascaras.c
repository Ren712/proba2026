#include <stdio.h>
#include <stdint.h>
/* NO LLEGUE A TERMINAR ESTA PARTE
void printbin(uint16_t nro)
{
  printf("Ingrese un nro decimal: ");
  scanf("%hd", &nro);
  uint16_t masc = 0b10000;
  for (int i = 16; i > 0; i--)
  {

    printf("%d", nro&masc);
    nro = nro >> 1;
  }
}*/

int main()
{

  uint16_t dato = 13450;
  uint8_t temperatura = (dato & 0xff);
  uint8_t humedad = dato >> 8;

  printf("T : %d \n", temperatura);
  printf("H : %d \n", humedad);

  printbin(0);

  return 0;
}