#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} fraccion;

fraccion sumar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

fraccion restar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

fraccion multiplicar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

void multiplicarporescalar(int filas, int columnas, fraccion matriz[filas][columnas], fraccion escalar, fraccion resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = multiplicar(matriz[i][j], escalar);
        }
    }
}

void sumarmatrices(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizR[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizR[i][j] = sumar(matriz1[i][j], matriz2[i][j]);
        }
    }
}

void restarmatrices(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizR[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizR[i][j] = restar(matriz1[i][j], matriz2[i][j]);
        }
    }
}

void multiplicarmatrices(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizR[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizR[i][j].numerador = 0;
            matrizR[i][j].denominador = 1;
            for (int k = 0; k < columnas; k++) {
                matrizR[i][j] = sumar(matrizR[i][j], multiplicar(matriz1[i][k], matriz2[k][j]));
            }
        }
    }
}

void imprimirmatriz(char *nombre, int filas, int columnas, fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d/%-4d ", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void llenarmatriz(char *nombre, int filas, int columnas, fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posicion [%d][%d] (numerador y denominador): ", i, j);
            scanf("%d%d", &matriz[i][j].numerador, &matriz[i][j].denominador);
        }
    }
}

int main() {
    int filas, columnas;
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    fraccion matriz_a[filas][columnas];
    fraccion matriz_b[filas][columnas];  
    fraccion matriz_r[filas][columnas];

    llenarmatriz("Matriz A", filas, columnas, matriz_a);
    llenarmatriz("Matriz B", filas, columnas, matriz_b);

    imprimirmatriz("Matriz A", filas, columnas, matriz_a);
    imprimirmatriz("Matriz B", filas, columnas, matriz_b);

    sumarmatrices(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz("Resultado A + B", filas, columnas, matriz_r);

    restarmatrices(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz("Resultado A - B", filas, columnas, matriz_r);

    multiplicarmatrices(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz("Resultado A * B", filas, columnas, matriz_r);

    fraccion escalar = {2, 1};  
    multiplicarporescalar(filas, columnas, matriz_a, escalar, matriz_r);
    imprimirmatriz("Resultado A * Escalar", filas, columnas, matriz_r);

    return 0;
}