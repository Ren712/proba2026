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

    FILE *list = fopen("lista.bin", "rb");

    if (list == NULL)
    {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    while (fread(&temp, sizeof(int), 1, list))
    {
        cant++;
    }

    printf("cant: %d \n", cant);
    punt = (int *)calloc(cant, sizeof(int));

    rewind(list);

    while (fread(&temp, sizeof(int), 1, list))
    {
        printf("Temp: %d \n", temp);
        punt[i] = temp;
        i++;
    }

    printf("El Vector mide al final: %d", i);

    free(punt);
    return 0;
}