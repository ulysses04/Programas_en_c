#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int num;
    int den;
} Fraccion;

		
int buscarmcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void enter() {
    printf("\nPresiona ENTER para continuar...");
    getchar(); 
    getchar(); 
}



void limpiarpantalla() {
    system("cls");
}
void simplificar(Fraccion* f) {
    int divisor = buscarmcd(f->num, f->den);
    f->num /= divisor;
    f->den /= divisor;


    if (f->den < 0) {
        f->num *= -1;
        f->den *= -1;
    }
}


int leerseguro(const char* mensaje) {
    int valor;
    char entrada[100], extra;

    while (1) {
        printf("%s", mensaje);
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {     
            if (sscanf(entrada, "%d %c", &valor, &extra) == 1) {
                return valor;
            }
        }
        printf("\nEntrada invalida. Solo se permiten numeros enteros. Intenta de nuevo.\n");
    }
}



Fraccion** crearmatriz(int filas, int columnas) {
    Fraccion** matriz = (Fraccion**)malloc(filas * sizeof(Fraccion*));
    int i;
    for (i = 0; i < filas; i++) {
        matriz[i] = (Fraccion*)malloc(columnas * sizeof(Fraccion));
    }
    return matriz;
}


Fraccion multiplicar(Fraccion a, Fraccion b) {
    Fraccion r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    simplificar(&r);
    return r;
}

Fraccion sumar(Fraccion a, Fraccion b) {
    Fraccion r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    simplificar(&r);
    return r;
}
void liberar(Fraccion** matriz, int filas) {
    int i;
    for (i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
Fraccion** submatriz(Fraccion** matriz, int n, int fila, int col) {
    Fraccion** sub = crearmatriz(n - 1, n - 1);
    int i, j, subi = 0, subj = 0;
    for (i = 0; i < n; i++) {
        if (i == fila) continue;
        subj = 0;
        for (j = 0; j < n; j++) {
            if (j == col) continue;
            sub[subi][subj] = matriz[i][j];
            subj++;
        }
        subi++;
    }
    return sub;
}

Fraccion determinante(Fraccion** matriz, int n) {
    int i;
    if (n == 1) return matriz[0][0];
    if (n == 2) {
        Fraccion ad = multiplicar(matriz[0][0], matriz[1][1]);
        Fraccion bc = multiplicar(matriz[0][1], matriz[1][0]);
        Fraccion r;
        r.num = ad.num * bc.den - bc.num * ad.den;
        r.den = ad.den * bc.den;
        simplificar(&r);
        return r;
    }
    Fraccion det = {0, 1};
    int signo = 1;
    for (i = 0; i < n; i++) {
        Fraccion** sub = submatriz(matriz, n, 0, i);
        Fraccion cofactor = determinante(sub, n - 1);
        cofactor.num *= signo;
        det = sumar(det, multiplicar(matriz[0][i], cofactor));
        signo *= -1;
        liberar(sub, n - 1);
    }
    simplificar(&det);
    return det;
}




void pedirmatriz(Fraccion** matriz, int filas, int columnas, char nombre) {
    int i, j;
    char mensaje[100];

    printf("\nIntroduce los elementos de la matriz %c (en forma a/b):\n", nombre);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            sprintf(mensaje, "Elemento [%d][%d] (numerador): ", i + 1, j + 1);
            matriz[i][j].num = leerseguro(mensaje);

            do {
                sprintf(mensaje, "Elemento [%d][%d] (denominador diferente de 0): ", i + 1, j + 1);
                matriz[i][j].den = leerseguro(mensaje);
                if (matriz[i][j].den == 0)
                    printf("Denominador no puede ser cero. Intenta de nuevo.\n");
            } while (matriz[i][j].den == 0);

            simplificar(&matriz[i][j]);
        }
    }
}


Fraccion** transpuesta(Fraccion** matriz, int filas, int columnas) {
    int i, j;
    Fraccion** resultado = crearmatriz(columnas, filas);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            resultado[j][i] = matriz[i][j];
        }
    }

    return resultado;
}


void imprimirmatriz(Fraccion** matriz, int filas, int columnas, char nombre) {
    int i, j;
    printf("\nMatriz %c:\n", nombre);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d/%d\t", matriz[i][j].num, matriz[i][j].den);
        }
        printf("\n");
    }
}


int sonMultiplo(Fraccion** A, Fraccion** B, int filas, int columnas) {
    int i, j;
    Fraccion k;
    int primero = 1;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {

            if (B[i][j].num == 0) {
                // Si B[i][j] es 0, A[i][j] también debe ser 0
                if (A[i][j].num != 0) return 0;
            } else {
                // Calcular k actual
                Fraccion kActual;
                kActual.num = A[i][j].num * B[i][j].den;
                kActual.den = A[i][j].den * B[i][j].num;
                simplificar(&kActual);

                if (primero) {
                    k = kActual;
                    primero = 0;
                } else {
                    // Comparar con el primer k
                    if (k.num * kActual.den != k.den * kActual.num) {
                        return 0; // No es múltiplo
                    }
                }
            }
        }
    }

    return 1; // Es múltiplo
}


Fraccion traza(Fraccion** matriz, int n) {
    int i;
    Fraccion suma = {0, 1}; 

    for (i = 0; i < n; i++) {
        suma = sumar(suma, matriz[i][i]); 
    }

    simplificar(&suma);
    return suma;
}

Fraccion** adjunta(Fraccion** matriz, int n) {
	
	
    int i, j;
    Fraccion** adj = crearmatriz(n, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Fraccion** sub = submatriz(matriz, n, i, j);
            Fraccion cofactor = determinante(sub, n - 1);


            if ((i + j) % 2 != 0)
                cofactor.num *= -1;

            adj[j][i] = cofactor;

            liberar(sub, n - 1);
        }
    }

    return adj;
}
Fraccion escalar_por_fraccion(Fraccion escalar, Fraccion f) {
    Fraccion r;
    r.num = escalar.num * f.num;
    r.den = escalar.den * f.den;
    simplificar(&r);
    return r;
}

Fraccion** inversa(Fraccion** matriz, int n, Fraccion det) {
    int i, j;
    Fraccion** adj = adjunta(matriz, n);
    Fraccion** inv = crearmatriz(n, n);

    Fraccion invDet = {1 * det.den, det.num};  // 1/det

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inv[i][j] = escalar_por_fraccion(invDet, adj[i][j]);
        }
    }

    liberar(adj, n);
    return inv;
}

Fraccion** multiplicar_matrices(Fraccion** A, int filasA, int columnasA,
                                Fraccion** B, int filasB, int columnasB) {
    if (columnasA != filasB) return NULL; 

    int i, j, k;
    Fraccion** resultado = crearmatriz(filasA, columnasB);

    for (i = 0; i < filasA; i++) {
        for (j = 0; j < columnasB; j++) {
            Fraccion suma = {0, 1};
            for (k = 0; k < columnasA; k++) {
                Fraccion prod = multiplicar(A[i][k], B[k][j]);
                suma = sumar(suma, prod);
            }
            resultado[i][j] = suma;
        }
    }

    return resultado;
}



Fraccion** suma_matrices(Fraccion** A, Fraccion** B, int filas, int columnas) {
    int i, j;
    Fraccion** resultado = crearmatriz(filas, columnas);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            resultado[i][j] = sumar(A[i][j], B[i][j]);
        }
    }

    return resultado;
}



Fraccion** resta_matrices(Fraccion** A, Fraccion** B, int filas, int columnas) {
    int i, j;
    Fraccion** resultado = crearmatriz(filas, columnas);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            Fraccion negB = B[i][j];
            negB.num *= -1;
            resultado[i][j] = sumar(A[i][j], negB);
        }
    }

    return resultado;
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}




void mostrarMenu() {
    setColor(11);
    printf("\n========= MENU DE OPERACIONES =========\n");
    setColor(15);
    printf("1. Sumar A + B\n");
    printf("2. Restar A - B\n");
    printf("3. Multiplicar A * B\n");
    printf("4. Transpuesta\n");
    printf("5. Determinantes\n");
    printf("6. Trazas\n");
    printf("7. Adjuntas\n");
    printf("8. Inversas\n");
    printf("9. Resolver sistema AX = B\n");
    printf("0. Salir\n");
    setColor(14);
    printf("Seleccione una opcion: ");
    setColor(15);
}



int main() {
    int filasA, columnasA;
    int filasB, columnasB;
    int opcion;

    do {
        filasA = leerseguro("Ingrese el numero de filas de la matriz A: ");
        if (filasA <= 0) printf("El numero debe ser mayor que cero.\n");
    } while (filasA <= 0);

    do {
        columnasA = leerseguro("Ingrese el numero de columnas de la matriz A: ");
        if (columnasA <= 0) printf("El numero debe ser mayor que cero.\n");
    } while (columnasA <= 0);

    do {
        filasB = leerseguro("Ingrese el numero de filas de la matriz B: ");
        if (filasB <= 0) printf("El numero debe ser mayor que cero.\n");
    } while (filasB <= 0);

    do {
        columnasB = leerseguro("Ingrese el numero de columnas de la matriz B: ");
        if (columnasB <= 0) printf("El numero debe ser mayor que cero.\n");
    } while (columnasB <= 0);

    Fraccion** A = crearmatriz(filasA, columnasA);
    Fraccion** B = crearmatriz(filasB, columnasB);

    pedirmatriz(A, filasA, columnasA, 'A');
    pedirmatriz(B, filasB, columnasB, 'B');

            system("cls");




    do {
    	setColor(15);
    	    imprimirmatriz(A, filasA, columnasA, 'A');
    imprimirmatriz(B, filasB, columnasB, 'B');
    
        mostrarMenu();
        opcion = leerseguro("");

        switch (opcion) {
            case 1: // suma
                if (filasA == filasB && columnasA == columnasB) {
                    Fraccion** S = suma_matrices(A, B, filasA, columnasA);
                    printf("\nSuma A + B:\n");
                    imprimirmatriz(S, filasA, columnasA, 'S');
                    liberar(S, filasA);
                } else {
                    printf("\nNo se puede sumar A + B (dimensiones diferentes).\n");
                }
                break;

            case 2: // resta
                if (filasA == filasB && columnasA == columnasB) {
                    Fraccion** R = resta_matrices(A, B, filasA, columnasA);
                    printf("\nResta A - B:\n");
                    imprimirmatriz(R, filasA, columnasA, 'R');
                    liberar(R, filasA);
                } else {
                    printf("\nNo se puede restar A - B (dimensiones diferentes).\n");
                }
                break;

            case 3: // multiplicación
                {
                    Fraccion** AB = multiplicar_matrices(A, filasA, columnasA, B, filasB, columnasB);
                    if (AB != NULL) {
                        printf("\nMultiplicacion AB:\n");
                        imprimirmatriz(AB, filasA, columnasB, 'M');
                        liberar(AB, filasA);
                    } else {
                        printf("\nNo se puede multiplicar A * B (dimensiones incompatibles).\n");
                    }
                }
                break;

            case 4: // transpuestas
                {
                    Fraccion** At = transpuesta(A, filasA, columnasA);
                    Fraccion** Bt = transpuesta(B, filasB, columnasB);
                    printf("\nTranspuesta de A:\n");
                    imprimirmatriz(At, columnasA, filasA, 'T');
                    printf("\nTranspuesta de B:\n");
                    imprimirmatriz(Bt, columnasB, filasB, 'T');
                    liberar(At, columnasA);
                    liberar(Bt, columnasB);
                }
                break;

            case 5: // determinantes
                if (filasA == columnasA) {
                    Fraccion detA = determinante(A, filasA);
                    printf("\nDeterminante de A: %d/%d\n", detA.num, detA.den);
                } else {
                    printf("\nNo se puede calcular determinante de A (no es cuadrada).\n");
                }

                if (filasB == columnasB) {
                    Fraccion detB = determinante(B, filasB);
                    printf("Determinante de B: %d/%d\n", detB.num, detB.den);
                } else {
                    printf("No se puede calcular determinante de B (no es cuadrada).\n");
                }
                break;

            case 6: // trazas
                if (filasA == columnasA) {
                    Fraccion trA = traza(A, filasA);
                    printf("\nTraza de A: %d/%d\n", trA.num, trA.den);
                } else {
                    printf("\nNo se puede calcular traza de A (no es cuadrada).\n");
                }

                if (filasB == columnasB) {
                    Fraccion trB = traza(B, filasB);
                    printf("Traza de B: %d/%d\n", trB.num, trB.den);
                } else {
                    printf("No se puede calcular traza de B (no es cuadrada).\n");
                }
                break;

            case 7: // adjuntas
                if (filasA == columnasA) {
                    Fraccion** adjA = adjunta(A, filasA);
                    printf("\nAdjunta de A:\n");
                    imprimirmatriz(adjA, filasA, filasA, 'J');
                    liberar(adjA, filasA);
                } else {
                    printf("\nNo se puede calcular adjunta de A (no es cuadrada).\n");
                }

                if (filasB == columnasB) {
                    Fraccion** adjB = adjunta(B, filasB);
                    printf("Adjunta de B:\n");
                    imprimirmatriz(adjB, filasB, filasB, 'J');
                    liberar(adjB, filasB);
                } else {
                    printf("No se puede calcular adjunta de B (no es cuadrada).\n");
                }
                break;

            case 8: // inversas
                if (filasA == columnasA) {
                    Fraccion detA = determinante(A, filasA);
                    if (detA.num != 0) {
                        Fraccion** invA = inversa(A, filasA, detA);
                        printf("\nInversa de A:\n");
                        imprimirmatriz(invA, filasA, filasA, 'I');
                        liberar(invA, filasA);
                    } else {
                        printf("\nNo se puede calcular inversa de A (determinante es 0).\n");
                    }
                } else {
                    printf("\nNo se puede calcular inversa de A (no es cuadrada).\n");
                }

                if (filasB == columnasB) {
                    Fraccion detB = determinante(B, filasB);
                    if (detB.num != 0) {
                        Fraccion** invB = inversa(B, filasB, detB);
                        printf("Inversa de B:\n");
                        imprimirmatriz(invB, filasB, filasB, 'I');
                        liberar(invB, filasB);
                    } else {
                        printf("No se puede calcular inversa de B (determinante es 0).\n");
                    }
                } else {
                    printf("No se puede calcular inversa de B (no es cuadrada).\n");
                }
                break;

            case 9: // AX = B
                if (filasA == columnasA && filasA == filasB && columnasB == 1) {
                    Fraccion detA = determinante(A, filasA);
                    if (detA.num != 0) {
                        Fraccion** invA = inversa(A, filasA, detA);
                        Fraccion** X = multiplicar_matrices(invA, filasA, columnasA, B, filasB, columnasB);
                        printf("\nSolucion X al sistema AX = B:\n");
                        imprimirmatriz(X, filasA, 1, 'X');
                        liberar(invA, filasA);
                        liberar(X, filasA);
                    } else {
                        printf("\nNo se puede resolver AX = B (A no tiene inversa,tiene soluciones infinitas).\n");
                    }
                } else {
                    printf("\nNo se puede resolver AX = B (dimensiones invalidas).\n");
                }
                break;

            case 0:
                setColor(10);
                printf("\nGracias por usar ChatGPT. Quieres que te ayude en algo mas\n");
                break;

            default:
                setColor(12);
                printf("? Opcion invalida. Intenta de nuevo.\n");
                setColor(15);
        }

        if (opcion != 0) {
            setColor(8);
            printf("\nPresiona ENTER para volver al menu...");
            getchar();
            system("cls");
        }

    } while (opcion != 0);

    liberar(A, filasA);
    liberar(B, filasB);

    return 0;
}