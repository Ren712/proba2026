#include <stdio.h>
#define NOTA_APROBACION 4

typedef struct{
        char nombre[20];
        int nroCuenta[4];
        int arg;
        union ident_t{
            int dni[10];
            char pas[12];
        };
}cliente_t;

/*alumno_t imprimir(alumno_t prueba)
{
    printf("El alumno %s tiene una nota de %.2f", prueba.nombre, prueba.nota);
    if (prueba.nota < NOTA_APROBACION)
    {
        printf("\nIngrese la nota del recuperatorio");
        scanf("%f", &prueba.nota);
    }

    return prueba;
}*/

int main(){
    cliente_t a1;
    printf("Ingrese el nombre del cliente:\n");
    scanf("%s", a1.nombre);
    printf("Ingrese la nota del alumno:\n");
    scanf("%s", a1.nroCuenta);
    printf("\nEl alumno %s tiene una nota de %.2f", a1.nombre, a1.nroCuenta);
    return 0;
}