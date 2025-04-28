#include <stdio.h>

void llenarmatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
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

void llenarvector(char *nombre, int tamaño, int vector[tamaño])
{
    printf("Nombre del vector: %s\n", nombre);
    for (int i = 0; i < tamaño; i++)
    {
        printf("Ingrese el valor para la posicion [%d]: ", i);
        scanf("%d", &vector[i]);
    }
}

void imprimirmatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
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

void imprimirvector(char *nombre, int tamaño, int vector[tamaño])
{
    printf("Nombre del vector: %s\n", nombre);
    printf("Vector ingresado:\n");
    for (int i = 0; i < tamaño; i++)
    {
        printf("%4d\n", vector[i]);
    }
    printf("\n");
}

void multiplicarmatrizvector(int filas, int columnas, int matriz[filas][columnas], int vector[columnas], int resultado[filas])
{
    for (int i = 0; i < filas; i++)
    {
        resultado[i] = 0;
        for (int j = 0; j < columnas; j++)
        {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}



int main()
{
    int filas, columnas;
    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &columnas);

    int matriz_a[filas][columnas];
    int vector[columnas];
    int resultado[filas];

    llenarmatriz("Matriz A", filas, columnas, matriz_a);
    llenarvector("Vector", columnas, vector);

    imprimirmatriz("Matriz A", filas, columnas, matriz_a);
    imprimirvector("Vector", columnas, vector);

    multiplicarmatrizvector(filas, columnas, matriz_a, vector, resultado);

    printf("Resultado de la multiplicacion de la matriz A por el vector:\n");
    for (int i = 0; i < filas; i++)
    {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}