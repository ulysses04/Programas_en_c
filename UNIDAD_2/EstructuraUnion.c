
#include <stdio.h>
#include <string.h>
#define FILAS 2
#define COLUMNAS 2

typedef struct
{
    char nombre[50];
    int edad;
} Persona;

typedef struct
{
    char producto[50];
    float precio;
} Producto;

typedef union
{
    Persona persona;
    Producto producto;
} Dato;

typedef struct
{
    Dato valor;
    int tipo;
} celda;

int main()
{
    celda matriz[FILAS][COLUMNAS];

    strcpy(matriz[0][0].valor.persona.nombre, "Roberto");
    matriz[0][0].valor.persona.edad = 25;
    matriz[0][0].tipo = 1;

    strcpy(matriz[0][1].valor.persona.nombre, "alejandro");
    matriz[0][1].valor.persona.edad = 30;
    matriz[0][1].tipo = 1;

    strcpy(matriz[1][0].valor.producto.producto, "conejo");
    matriz[1][0].valor.producto.precio = 88.99;
    matriz[1][0].tipo = 2;

    strcpy(matriz[1][1].valor.producto.producto, "golden");
    matriz[1][1].valor.producto.precio = 1377.99;
    matriz[1][1].tipo = 2;

    printf("recorriendo la amtriz de uniones con estructuras:\n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("celda [%d][%d]:", i, j);
            if (matriz[i][j].tipo == 1)
            {
                printf("persona - nombre: %s,edad:%d\n",
                       matriz[i][j].valor.persona.nombre,
                       matriz[i][j].valor.persona.edad);
            }
            else if (matriz[i][j].tipo == 2)
            {
                printf("producto - nombre:%s, precio: %.2f\n",
                       matriz[i][j].valor.producto.producto,
                       matriz[i][j].valor.producto.precio);
            }
        }
    }
    return 0;
}