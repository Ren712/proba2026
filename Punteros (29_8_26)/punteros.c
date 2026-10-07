#include <stdio.h>
#include <stdint.h>

// Ej 1

void cambio(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int var1 = 10;
    int var2 = 20;
    printf("Ingrese el valor de la primera variable: ");
    scanf("%d", &var1);
    printf("Ingrese el valor de la segunda variable: ");
    scanf("%d", &var2);
    printf("El valor de var 1 es: %d \n", var1);
    printf("El valor de var 2 es: %d \n", var2);
    printf("-----CAMBIO-----\n");
    cambio(&var1, &var2);
    printf("El valor de var 1 es: %d \n", var1);
    printf("El valor de var 2 es: %d \n", var2);
}