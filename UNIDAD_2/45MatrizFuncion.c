#include <stdio.h>

void llenarMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{

    printf("Nombre de la matriz: %s\n", nombre);

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);

            scanf("%d", &matriz[i][j]);
        }
    }
}

void saveMatriz(int filas, int columnas, int matriz[filas][columnas])
{

    FILE *archivo = fopen("../matriz.txt", "w");

    if (archivo == NULL)
    {

        printf("Error al abrir el archivo.\n");

        return;
    }

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            fprintf(archivo, "%d ", matriz[i][j]);
        }

        fprintf(archivo, "\n");
    }

    fclose(archivo);

    printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
}

void imprimirMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{

    printf("Nombre de la matriz: %s\n", nombre);

    printf("Matriz ingresada:\n");

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            printf("%4d ", matriz[i][j]);
        }

        printf("\n");
    }
}

void sumarMatriz(int filas, int columnas,

                 int matriz1[filas][columnas], int matriz2[filas][columnas],

                 int matrizr[filas][columnas])
{

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Realizar el método para escalar
void escalarMatrizA(int filas, int columnas, int numero,

                    int matriz1[filas][columnas],

                    int matriz_escA[filas][columnas])
{

    printf("ingresa el numero por el que desea multiplicar la matriz A:\n");
    scanf("%d", &numero);

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            matriz_escA[i][j] = matriz1[i][j] * numero;
        }
    }
}
void escalarMatrizB(int filas, int columnas, int numero2,

                    int matriz2[filas][columnas],

                    int matriz_escB[filas][columnas])
{

    printf("ingresa el numero por el que desea multiplicar la matriz B:\n");
    scanf("%d", &numero2);

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            matriz_escB[i][j] = matriz2[i][j] * numero2;
        }
    }
}

int detA(int matriz[3][3])
{
    int det = 0;

    for (int i = 0; i < 3; i++)
    {
        det += matriz[0][i] * matriz[1][(i + 1) % 3] * matriz[2][(i + 2) % 3];
    }

    for (int i = 0; i < 3; i++)
    {
        det -= matriz[0][(i + 2) % 3] * matriz[1][(i + 1) % 3] * matriz[2][i];
    }
    return det;
}

// Realizar el método para determinante

int main()
{

    int filas, columnas, numero, numero2, det;

    printf("Ingrese el numero de filas: ");

    scanf("%d", &filas);

    printf("Ingrese el numero de columnas: ");

    scanf("%d", &columnas);

    int matriz_a[filas][columnas];

    int matriz_b[filas][columnas];

    int matriz_r[filas][columnas];

    int matriz_escA[filas][columnas];

    int matriz_escB[filas][columnas];

    llenarMatriz("Matriz A", filas, columnas, matriz_a);

    llenarMatriz("Matriz B", filas, columnas, matriz_b);

    imprimirMatriz("Matriz A", filas, columnas, matriz_a);

    imprimirMatriz("MAtriz B", filas, columnas, matriz_b);

    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);

    imprimirMatriz("SUMA A+B", filas, columnas, matriz_r);

    escalarMatrizA(filas, columnas, numero, matriz_a, matriz_escA);

    imprimirMatriz("Matriz A multplicada por el numero ingresado:", filas, columnas, matriz_escA);

    escalarMatrizB(filas, columnas, numero2, matriz_b, matriz_escB);

    imprimirMatriz("matriz B multiplicada por el numero ingresado:", filas, columnas, matriz_escB);

    det = detA(matriz_a);
    if (filas == 3 && columnas == 3)
    {
        det = detA(matriz_a);
        printf("El determinante es: %d\n", det);
    }
    else
    {
        printf("La matriz debe ser 3x3 .\n");
    }

    saveMatriz(filas, columnas, matriz_r);

    return 0;
}