#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3
int main()
{

    char matriz[FILAS][COLUMNAS][50];

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("ingrese palabra:\n");
            scanf("%s", matriz[i][j]);
        }
    }

    printf("matriz ingresada:\n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%-10s", matriz[i][j]);
            printf("|");
        }
        printf("\n");
    }

    return 0;
}