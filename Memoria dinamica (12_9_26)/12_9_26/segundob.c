#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Se quiere crear un vector dinamico para guardar numeros enteros.
El usuario debe  ingresar el tamano primero y luego completarlo con numeros.
Imprima el vector completo */

int main(void)
{
    int *punt;
    int temp = 0;
    int cant = 0;
    int i = 0;

    punt = (int *)calloc(1, sizeof(int));
    if (punt == NULL)
    {
        perror("No se pudo guardar el espacio");
        return 1;
    }

    FILE *list = fopen("lista.bin", "rb");

    if (list == NULL)
    {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    while (fread(&temp, sizeof(int), 1, list))
    {
        punt[cant] = temp;
        cant++;
        punt = (int *)realloc(punt, sizeof(int) * (cant + 1));
    }

    printf("cant: %d \n", cant);

    rewind(list);

    while (i < cant)
    {
        printf("Temp %d : %d \n", i, punt[i]);
        i++;
    }

    printf("El Vector mide al final: %d", i);

    free(punt);
    return 0;
}