#include <stdio.h>  

#define MAX 25 // Definir constante para el tamaño máximo

int MatrizA[MAX][MAX];   // Matriz de tamaño máximo (25x25)
int MatrizExp[MAX][MAX+2]; // Matriz expandida (25x27)
int i, j, determinante, k;

int main() {
    // Pedir datos para rellenar una MatrizA 3 x 3
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Dame valor para MatrizA[%d][%d]: ", i, j);
            scanf("%d", &MatrizA[i][j]);
        }
    }

    // Mostrar datos de una MatrizA 3 x 3
    printf("MatrizA 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", MatrizA[i][j]);
        }
        printf("\n");
    }

    // Crear Matriz Expandida
    k = 3;
    for (i = 0; i < k; i++) {
        for (j = 0; j < k + 2; j++) {
            if (j < 3)
                MatrizExp[i][j] = MatrizA[i][j];
            else
                MatrizExp[i][j] = MatrizA[i][j - 3]; // Agregar la 4ta y 5ta columna
        }
    }

    // Mostrar datos de la Matriz Expandida
    printf("Matriz Expandida 3x5:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < k + 2; j++) {
            printf("%d ", MatrizExp[i][j]);
        }
        printf("\n");
    }

    // Calcular la determinante de la submatriz 3x3 usando el método de Sarrus
    determinante = 0;
    for (i = 0; i < 3; i++) {
        // Producto de las diagonales descendentes
        determinante += MatrizExp[i][i] * MatrizExp[(i+1)%3][(i+1)%3] * MatrizExp[(i+2)%3][(i+2)%3];
        // Producto de las diagonales ascendentes
        determinante -= MatrizExp[i][(i+2)%3] * MatrizExp[(i+1)%3][(i)%3] * MatrizExp[(i+2)%3][(i+1)%3];
    }

    // Mostrar el determinante calculado
    printf("La determinante de la submatriz 3x3 es: %d\n", determinante);

    return 0;
}
