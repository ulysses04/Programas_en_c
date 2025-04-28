#include <stdio.h>
#include <string.h>
#define FILAS 2
#define COLUMNAS 2

typedef struct
{
    char nombre[50];
    int edad;
} Gato;

typedef struct
{
    char nombre[50];
    int edad;
} Perro;

typedef union
{
    Gato gato;
    Perro perro;
} Dato;

typedef struct
{
    Dato valor;
    int tipo;
} celda;

int main(){
    celda matriz[FILAS][COLUMNAS];
    int opc;
    for(int i=0; i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            printf("selecciona el tipo de dato: 1)perro 2)gato\n");
            scanf("%d",&opc);
            matriz[i][j].tipo=opc;
            

            if(opc==1){
            printf("ingresa el nombre del perro:\n");
            scanf("%s",matriz[i][j].valor.perro.nombre);
            printf("ingresa la edad del perro:\n");
            scanf("%d",&matriz[i][j].valor.perro.edad);
            }
            else if(opc==2){
            
            
            printf("ingresa el nombre del gato:\n");
            scanf("%s",matriz[i][j].valor.gato.nombre);
            printf("ingresa la edad del gato:\n");
            scanf("%d",&matriz[i][j].valor.gato.edad);
            }
            else{
            printf("opcion invalido");
            }
            
        

        }
    }
    printf("matriz ingresada:\n");
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){

            if(matriz[i][j].tipo==1){
                printf("perro - nombre:%s, edad: %d\n",
                matriz[i][j].valor.perro.nombre,
            matriz[i][j].valor.perro.edad);
            }else if(matriz[i][j].tipo ==2){
                printf("gato- nombre: %s, edad: %d\n",
                matriz[i][j].valor.gato.nombre,
            matriz[i][j].valor.gato.edad);
            }
        }
    }
    return 0;
}
