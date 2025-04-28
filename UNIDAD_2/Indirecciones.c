#include <stdio.h>
 
int main() {
    int numero = 42;                // Variable entera
    int *ptr = &numero;             // Puntero apuntando a 'numero'
    int **ptr_doble = &ptr;         // Puntero doble apuntando a 'ptr'
 
    printf("Valor de 'numero': %d\n", numero);
    printf("Direccion de 'numero': %p\n", (void*)&numero);
 
    printf("\nUsando puntero simple:\n");
    printf("Valor de 'ptr': %p\n", (void*)ptr);
    printf("Valor al que apunta 'ptr': %d\n", *ptr);
    printf("Direccion de 'ptr': %p\n", (void*)&ptr);
 
    printf("\nUsando puntero doble:\n");
    printf("Valor de 'ptr_doble': %p\n", (void*)ptr_doble);
    printf("Valor al que apunta 'ptr_doble' (direccion de 'ptr'): %p\n", (void*)*ptr_doble);
    printf("Valor final al que apunta 'ptr_doble': %d\n", **ptr_doble);
    printf("Direccion de 'ptr_doble': %p\n", (void*)&ptr_doble);
 
    return 0;
}