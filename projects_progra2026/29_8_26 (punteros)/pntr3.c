#include <stdio.h>
#include <stdint.h>
#define SHORT_V 17

// EJ2

void calcu(int *arr, int lth, int *minimo, int *nuevo)
{
    *minimo = *arr;
    int yaContado = INT32_MIN;
    int CantDeVeces = 0;
    int repes = 1;

    for (int j = 0; j < lth; j++)
    {
        *minimo = INT32_MAX;

        for (int i = 0; i < lth; i++)
        {
            if (yaContado == arr[i])
            {
                CantDeVeces++;
            }
            if (*minimo > arr[i] && yaContado < arr[i])
            {
                *minimo = arr[i];
            }
            else if (*minimo > arr[i] && yaContado == arr[i] && CantDeVeces > repes)
            {
                *minimo = arr[i];
            }
        }
        nuevo[j] = *minimo;

        if (yaContado == *minimo)
        {
            repes++;
        }
        else
        {
            repes = 1;
        }

        CantDeVeces = 0;
        yaContado = *minimo;

        printf("%d - ", nuevo[j]);
    }
    printf("\n");
    return;
}

int main()
{
    int arr[SHORT_V];
    int nuevo[SHORT_V];
    int menos = 0;
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

    calcu(&arr[0], SHORT_V, &menos, &nuevo[0]);
    printf("Maximo (ultimo minimo): %d \n", menos);
    fclose(list);
    return 0;
}