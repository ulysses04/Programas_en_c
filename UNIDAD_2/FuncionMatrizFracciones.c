#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void llenarMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese el valor para la posicion [%d][%d] (numerador y denominador): ", i, j);
            scanf("%d%d", &matriz[i][j].numerador, &matriz[i][j].denominador);
        }
    }
}

void imprimirMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d/%-4d ", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void multiplicarmatrices(int filas, int columnas, Fraccion matriz1[filas][columnas], Fraccion matriz2[filas][columnas], Fraccion matrizr[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizr[i][j].numerador = matriz1[i][j].numerador * matriz2[i][j].numerador;
            matrizr[i][j].denominador = matriz1[i][j].denominador * matriz2[i][j].denominador;
        }
    }
}

int main()
{
    int filas, columnas;
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    Fraccion matriz_a[filas][columnas];
    Fraccion matriz_b[filas][columnas];  
    Fraccion matriz_r[filas][columnas];

    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);

    imprimirMatriz("Matriz A", filas, columnas, matriz_a);
    imprimirMatriz("Matriz B", filas, columnas, matriz_b);

    multiplicarmatrices(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirMatriz("Resultado A * B", filas, columnas, matriz_r);

    return 0;
}