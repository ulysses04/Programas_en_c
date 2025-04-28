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

void multiplicacionMatriz(int filasA, int columnasA, int matrizA[filasA][columnasA],
    int filasB, int columnasB, int matrizB[filasB][columnasB],
    int matrizr[filasA][columnasB]) {

if (columnasA != filasB) {
printf("Error: Las matrices no se pueden multiplicar.\n");
return;
}


for (int i = 0; i < filasA; i++) {
for (int j = 0; j < columnasB; j++) {
matrizr[i][j] = 0;
}
}


for (int i = 0; i < filasA; i++) {
for (int j = 0; j < columnasB; j++) {
for (int k = 0; k < columnasA; k++) { 
matrizr[i][j] += matrizA[i][k] * matrizB[k][j];
}
}
}
}


    

int main()
{

    int filasA, columnasA,filasB,columnasB;

    printf("Ingrese el numero de filas: ");

    scanf("%d", &filasA);

    printf("Ingrese el numero de columnas: ");

    scanf("%d", &columnasA);

    printf("Ingrese el numero de filas: ");

    scanf("%d", &filasB);

    printf("Ingrese el numero de columnas: ");

    scanf("%d", &columnasB);

    int matriz_a[filasA][columnasA];

    int matriz_b[filasB][columnasB];

    int matriz_r[filasA][columnasB];

    

    llenarMatriz("Matriz A", filasA, columnasA, matriz_a);

    llenarMatriz("Matriz B", filasB, columnasB, matriz_b);

    imprimirMatriz("Matriz A", filasA, columnasA, matriz_a);

    imprimirMatriz("MAtriz B", filasB, columnasB, matriz_b);

    multiplicacionMatriz(filasA, columnasA, matriz_a, filasB,columnasB,matriz_b, matriz_r);

    imprimirMatriz("multiplicacion A*B", filasA, columnasB, matriz_r);

    

   
    return 0;
}