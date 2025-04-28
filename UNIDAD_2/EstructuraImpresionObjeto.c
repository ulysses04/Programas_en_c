#include <stdio.h>
struct tenis{
    float talla;
    char color[50];
    char modelo[50];
    char material[50];
    char resistealagua[50];
    char forma[50];
    char suela[50];
    char categoria[50];
    char ajuste[50];
    char edicion[50];
    char altura[50];
};
struct brand{
    char marca[50];
    struct tenis especificaciones;
};
int main(){
    int n;
    printf("ingrese el numero de tenis:");
    scanf("%d",&n);
    getchar();
    struct brand brands[n];
    for(int i=0; i<n;i++){
        printf("\ningrese los datos de los tenis %d:\n",i+1);
        printf("marca : ");
        scanf(" %[^\n]",brands[i].marca);
        printf("talla: ");
        scanf("%f",&brands[i].especificaciones.talla);
        printf("color: ");
        scanf(" %[^\n]",brands[i].especificaciones.color);
        printf("modelo : ");
        scanf(" %[^\n]",brands[i].especificaciones.modelo);
        printf("material : ");
        scanf(" %[^\n]",brands[i].especificaciones.material);
        printf("resistente al agua : ");
        scanf(" %[^\n]",brands[i].especificaciones.resistealagua);
        printf("forma  : ");
        scanf(" %[^\n]",brands[i].especificaciones.forma);
        printf("suela  : ");
        scanf(" %[^\n]",brands[i].especificaciones.suela);
        printf("categoria : ");
        scanf(" %[^\n]",&brands[i].especificaciones.categoria);
        printf("ajuste : ");
        scanf(" %[^\n]",brands[i].especificaciones.ajuste);
        printf("edicion  : ");
        scanf(" %[^\n]",brands[i].especificaciones.edicion);
        printf("altura : ");
        scanf(" %[^\n]",brands[i].especificaciones.altura);
         getchar();
    }
    printf("\n%-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n","marca","","talla","color","modelo","material","resistente al agua","forma","suela","categoria","ajuste","edicion","altura");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i<n; i++){
        printf("%-10s | %.2f | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n",
        brands[i].marca,
    brands[i].especificaciones.talla,
brands[i].especificaciones.color,
brands[i].especificaciones.modelo,
brands[i].especificaciones.material,
brands[i].especificaciones.resistealagua,
brands[i].especificaciones.forma,
brands[i].especificaciones.suela,
brands[i].especificaciones.categoria,
brands[i].especificaciones.ajuste,
brands[i].especificaciones.edicion,
brands[i].especificaciones.altura);
    }
    return 0;
}