#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Se quiere conocer el tamano maximo para n (
en cantidad de elementos y en mb)
, que  se puede asignar dinamicamente a
__uint32_t lista[n] antes de obtener un error*/

int main(void)
{
    uint64_t h;
    __uint32_t *lista;

    lista = (__uint32_t *)calloc(1, sizeof(__uint32_t));

    if (lista == NULL)
    {
        perror("No se pudo guardar el espacio");
        return 1;
    }

    for (h = 1; lista != NULL; h *= 2)
    {
        lista = (__uint32_t *)realloc(lista, sizeof(__uint32_t) * h);
        printf("h : %ld \n", h);
    }

    h /= 2;
    printf("Tamaño final: %ld Bytes\n", (sizeof(__uint32_t) * h));
    printf("Tamaño final: %ld KB\n", (sizeof(__uint32_t) * h) / (1024));
    printf("Tamaño final: %ld MB\n", (sizeof(__uint32_t) * h) / (1024 * 1024));
    printf("Tamaño final: %ld GB\n", (sizeof(__uint32_t) * h) / (1024 * 1024 * 1024));

    free(lista);
    return 0;
}