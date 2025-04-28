#include <stdio.h>

void setColor(int color) {
    printf("\033[7;%dm", color); 
}
int main() {
    printf("\033[2J"); 
    int tam;
    printf("Ingrese el tamano del cuadrado: ");
    scanf("%d", &tam);

    int colores[] = {31, 32, 33, 34, 35, 36, 37}; 
    int numColores = 7;

    for (int i = 0; i < tam; i++) {      
        for (int j = 0; j < tam; j++) { 
            int color = colores[(i + j) % numColores]; 
            setColor(color);
            printf("* "); 
            printf("\033[0m"); 
        }
        printf("\n");
    }

    return 0;
}