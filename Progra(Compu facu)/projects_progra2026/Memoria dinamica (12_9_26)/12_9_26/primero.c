#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/* Se quiere crear un vector dinamico para guardar numeros enteros.
El usuario debe  ingresar el tamano primero y luego completarlo con numeros.
Imprima el vector completo */

int main(void)
{

    int8_t type = 3;
    int cant = 0;

    printf("Ingrese la cantidad de numeros que quiere guardar: ");
    scanf("%d", &cant);

    printf("¿Quiere guardar Shorts o Ints? \t 0 = Short | 1 = int ");
    scanf("%hhd", &type);

    if (type == 0)
    {
        short *punt;
        punt = (short *)calloc(cant, sizeof(short));

        printf("------------------------------------------------\n");

        for (int i = 0; i < cant; i++)
        {
            printf("Ingrese el numero que corresponde al item %d: ", i + 1);
            scanf("%hd", (punt + i));
        }

        printf("------------------------------------------------\n");

        for (int i = 0; i < cant; i++)
        {
            printf("El numero que corresponde al item %d es %hd \n", i + 1, *(punt + i));
        }

        free(punt);
    }
    else if (type == 1)
    {
        int *punt;
        punt = (int *)calloc(cant, sizeof(int));

        printf("------------------------------------------------\n");

        for (int i = 0; i < cant; i++)
        {
            printf("Ingrese el numero que corresponde al item %d: ", i + 1);
            scanf("%d", (punt + i));
        }

        printf("------------------------------------------------\n");

        for (int i = 0; i < cant; i++)
        {
            printf("El numero que corresponde al item %d es %d \n", i + 1, *(punt + i));
        }

        free(punt);
    }

    return 0;
}