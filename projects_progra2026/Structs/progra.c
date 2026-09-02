#include <stdio.h>
#define NOTA_APROBACION 4

typedef struct{
        char nombre[20];
        float nota;
}alumno_t;

alumno_t imprimir(alumno_t prueba){
    printf("El alumno %s tiene una nota de %.2f", prueba.nombre, prueba.nota);
    if (prueba.nota<NOTA_APROBACION){
        printf("\nIngrese la nota del recuperatorio");
        scanf("%f", &prueba.nota);
    }

    return prueba;
}

int main(){
    alumno_t a1;
    printf("Ingrese el nombre del alumno:\n");
    scanf("%s", a1.nombre);
    printf("Ingrese la nota del alumno:\n");
    scanf("%f", &a1.nota);
    a1 = imprimir(a1);
    printf("\nEl alumno %s tiene una nota de %.2f", a1.nombre, a1.nota);
    return 0;
}