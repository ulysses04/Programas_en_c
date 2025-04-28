#include <stdio.h>
#define FILAS 2
#define COLUMNAS 2
struct Direccion{
    char calle[50];
    int numero;
    
};
struct Persona{
    char nombre[50];
    char apellido[50];
    struct Direccion domicilio;
};
int main(){
    struct Persona matriz[FILAS][COLUMNAS] ={
        {{"juan", "sanchez", {"benito jaurez", 34}}, {"jose", "hernandez", {"pino suarez", 76}}},
        {{"miguel", "lopez", {"constitucion", 37}}, {"pablo", "martinez", {"libertad", 21}}}

    };
    printf("matriz de personas:\n");
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            printf("%s | %s | %s | %d\t",
            matriz[i][j].nombre, matriz[i][j].apellido, matriz[i][j].domicilio.calle, matriz[i][j].domicilio.numero);
        }
        printf("\n");
    }
    return 0;
}
