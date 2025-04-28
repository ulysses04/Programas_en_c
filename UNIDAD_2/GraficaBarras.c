#include <stdio.h>

void setColor(const char* color) {
    printf("%s", color);
}

const char* colores[7] = {
    "\033[41m", 
    "\033[42m", 
    "\033[43m", 
    "\033[44m", 
    "\033[45m", 
    "\033[46m", 
    "\033[47m"  
};

const char* RESET = "\033[0m";

int main() {
    int num_barras;
    int barras[7] = {0}; 
    int i, nivel;

   
    printf("numero de barras que quiere graficar: ");
    scanf("%d", &num_barras);

    
    if (num_barras > 7) {
        printf("El numero de barras maximo es 7.\n");
        return 0; 
    }

    printf("Ingresa las alturas de las %d barras:\n", num_barras);
    for (i = 0; i < num_barras; i++) {
        printf("Barra %d: ", i + 1);
        scanf("%d", &barras[i]);
    }
    
    printf("\033[2J");
   
    for (i = 0; i < num_barras * 2 + 2; i++) printf("*");
    printf("\n");

  
    for (nivel = 7; nivel >= 1; nivel--) {
        printf("*"); 
        for (i = 0; i < num_barras; i++) {
            if (barras[i] >= nivel) {
                setColor(colores[i]); 
                printf("**");         
                setColor(RESET);      
            } else {
                printf("  ");         
            }
        }
        printf("*\n"); 
    }

  
    for (i = 0; i < num_barras * 2 + 2; i++) printf("*");
    printf("\n");

    return 0;
}
