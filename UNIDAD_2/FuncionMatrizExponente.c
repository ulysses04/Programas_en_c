#include <stdio.h>
#include <math.h>

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

void matrizexponente(int filas, int columnas,int exponente,

                 int matriz1[filas][columnas],

                 int matrizr[filas][columnas])
                  {
                    for (int i = 0; i < filas; i++) {
                        for (int j = 0; j < columnas; j++) {
                            matrizr[i][j] = (int)pow(matriz1[i][j], exponente); 
                        }
                    }
                }
                

    

int main()
{

    int filas, columnas,exp;

    printf("Ingrese el numero de filas: ");

    scanf("%d", &filas);

    printf("Ingrese el numero de columnas: ");

    scanf("%d", &columnas);

    int matriz_a[filas][columnas];


    int matriz_r[filas][columnas];

    

    llenarMatriz("Matriz A", filas, columnas, matriz_a);

    imprimirMatriz("Matriz A", filas, columnas, matriz_a);

    printf("Ingrese el exponente que desea elevar la matriz: ");
    scanf("%d", &exp);

    matrizexponente(filas, columnas, exp, matriz_a, matriz_r);
    imprimirMatriz("Matriz elevada al exponente:", filas, columnas, matriz_r);

    

   
    return 0;
}