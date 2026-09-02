#include <stdio.h>
#include <stdint.h>
#define SHORT_V 17

// EJ2

void calcu(int *arr, int lth, int *maximo, int *minimo, float *avg)
{
    *maximo = *arr;
    *minimo = *arr;
    float sum = 0;
    for (int i = 0; i < lth; i++)
    {
        if (*maximo < arr[i])
        {
            *maximo = arr[i];
        }
        if (*minimo > arr[i])
        {
            *minimo = arr[i];
        }
        sum += arr[i];
    }
    *avg = sum / lth;
}

int main()
{
    int arr[SHORT_V];
    int mas = 0;
    int menos = 0;
    float prom = 0;
    int i = 0;
    FILE *list = fopen("short_lista.bin", "rb");

    if (list == NULL)
    {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    while (fread(&arr[i], sizeof(int), 1, list))
    {
        printf("%d - ", arr[i]);
        i++;
    }
    printf("\n");

    calcu(&arr[0], SHORT_V, &mas, &menos, &prom);
    printf("Maximo: %d \n", mas);
    printf("minimo: %d \n", menos);
    printf("promedio: %.2f \n", prom);
    fclose(list);
    return 0;
}