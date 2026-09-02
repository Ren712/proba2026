#include <stdio.h>
#include <stdint.h>

typedef struct
{
  char nombre[20];
  uint32_t nroCuenta;
  union
  {
    int dni[10];
    char pas[12];
  } ident_t;
} cliente_t;

void imprimirbin(uint64_t dato)
{
  for (int i = 32; i > 0; i--)
  {
    if (i % 4 == 0)
    {
      printf(" ");
    }
    printf("%ld", (dato >> i - 1) & 1);
  }
  printf("\n");
}

int main()
{
  cliente_t p1;
  printf("Ingrese su Nombre:");
  scanf("%s", p1.nombre);
  printf("Nombre Ingresado: %s \n", p1.nombre);
  printf("Ingrese su Nro de Cuenta:");
  scanf("%u", &p1.nroCuenta);
  printf("Numero de cuenta Ingresado %u \n", p1.nroCuenta);
  printf("Es Usted Argentino? 1 = si ; 0 = no: ");
  int8_t arg;
  scanf("%hhd", &arg);
  printf("Valor Ingresado: %hhd \n", arg);
  imprimirbin(p1.nroCuenta);
  p1.nroCuenta = p1.nroCuenta | (arg << 31);
  imprimirbin(p1.nroCuenta);
  if ((p1.nroCuenta >> 31) == 0)
  {
    printf("Ingrese su Nro de DNI:");
  }
  else
  {
  }
  return 0;
}