#include <stdio.h>
typedef struct{
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;
int main(){
    Estudiante estudiante1= {"maria lopez",22,9.3};
    printf("nombre:%s\n",estudiante1.nombre);
    return 0;
}