#include <stdio.h>

    struct Estudiante{
        char Nombre[50];
        int Edad;
        float Promedio;

    };
int main(){
    struct Estudiante estudiante1 = {"alejandro diaz",24, 8.5};
    printf("Nombre: %s\n", estudiante1.Nombre);
    printf("Edad: %d\n", estudiante1.Edad);
    printf("Promedio: %.2f\n", estudiante1.Promedio);
    return 0;
}
