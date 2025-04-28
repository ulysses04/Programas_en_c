#include <stdio.h>
#include <math.h>
//realizar un codigo que solicite un numero que tenga raiz cuadrada exacta, obtener la matriz a partir de la raiz, solicite caracterers y a vacia en un arreglo.



void llenarMatriz(char *nombre, int filas, int columnas, char matriz[filas][columnas])
{

    printf("Nombre de la matriz: %s\n", nombre);

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            printf("Ingrese el caracter para la posicion [%d][%d]: ", i, j);

            scanf(" %c", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(char *nombre, int filas, int columnas, char matriz[filas][columnas])
{

    printf("Nombre de la matriz: %s\n", nombre);

    printf("Matriz ingresada:\n");

    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {

            printf("%c ", matriz[i][j]);
        }

        printf("\n");
    }
}

int raizCuadrada(int numero){
    double resultado=sqrt(numero);
    if(resultado == (int)resultado){
        printf("numero tiene raiz cuadrada exacta: %.2f\n",resultado);
        return (int)resultado;
    }else{
        printf("numero no tiene raiz exacta\n");
        return -1;
    }

    
}

void almacenar_en_arreglo(int tam, char matriz[tam][tam], char arreglo[]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            arreglo[i * tam + j] = matriz[i][j]; 
        }
    }
}

void mostrar_arreglo(int tam, char arreglo[]) {
    printf("\nArreglo con los caracteres:\n");
    for (int i = 0; i < tam * tam; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

int main(){
    int num;
    printf("ingresa numero\n");
    scanf("%d",&num);
   
    int raiz=raizCuadrada(num);
    if(raiz==-1){
        return 1;
    }
    printf("matriz de %d x %d\n",raiz,raiz);

    char matriz[raiz][raiz];
    char arreglo[raiz * raiz]; 
    
    llenarMatriz("Matriz A",raiz,raiz, matriz);
    imprimirMatriz("Matriz A",raiz,raiz, matriz);
    
    almacenar_en_arreglo(raiz, matriz, arreglo);
    mostrar_arreglo(raiz, arreglo);
    return 0;
}