#include <stdio.h>
#include <math.h>

void gotoxy(int x, int y){
    printf("\033[%d;%dH",y,x);
}

void clearScreen() {
    printf("\033[2J");
}

void llenarMatriz(char *nombre, int filas, int columnas, int matriz[3][3])
{

    printf("Nombre de la matriz: %s\n", nombre);

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);

            scanf("%d", &matriz[i][j]);
        }
    }
}


void imprimirMatriz(char *nombre, int filas, int columnas, int matriz[3][3],int x,int y)
{
    gotoxy(x + 5, y);
    printf(" %s\n", nombre);



    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + 1 + i);
        printf("*"); 
        for (int j = 0; j < 3; j++)
        {
            gotoxy(x + 2 + j*4, y + 1 + i);

            printf("%3d ", matriz[i][j]);
        }

        gotoxy(x + 14, y + 1 + i); 
        printf("*");
    }
}

void restaMatriz(int filas, int columnas,

                 int matriz1[filas][columnas], int matriz2[filas][columnas],

                 int matrizr[filas][columnas])
{

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            matrizr[i][j] = matriz1[i][j] - matriz2[i][j];
        }
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

    printf("\ningresa el numero por el que desea multiplicar la matriz A:\n");
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

    printf("\ningresa el numero por el que desea multiplicar la matriz B:\n");
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

    int matriz_a[3][3];

    int matriz_b[3][3];

    int matriz_r[3][3];

    int matriz_escA[3][3];

    int matriz_escB[3][3];

    llenarMatriz("Matriz A", filas, columnas, matriz_a);

    llenarMatriz("Matriz B", filas, columnas, matriz_b);

    clearScreen();

    imprimirMatriz("Matriz A", filas, columnas, matriz_a,5,2);

    imprimirMatriz("MAtriz B", filas, columnas, matriz_b,25,2);

    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);

    imprimirMatriz("SUMA A+B", filas, columnas, matriz_r,45,2);

    restaMatriz(filas,columnas,matriz_a,matriz_b,matriz_r);

    imprimirMatriz("resta A-B",filas,columnas,matriz_r,65,2);

    escalarMatrizA(filas, columnas, numero, matriz_a, matriz_escA);

    imprimirMatriz("Matriz A x esc:", filas, columnas, matriz_escA,80,2);

    escalarMatrizB(filas, columnas, numero2, matriz_b, matriz_escB);

    imprimirMatriz("matriz B x esc:", filas, columnas, matriz_escB,100,2);

    gotoxy(5, 10);



    det = detA(matriz_a);
    if (filas == 3 && columnas == 3)
    {
        det = detA(matriz_a);
        printf("El determinante es de la matriz A: %d\n", det);
    }
    else
    {
        printf("La matriz debe ser 3x3 .\n");
    }

  gotoxy(0, 15);

    return 0;
}