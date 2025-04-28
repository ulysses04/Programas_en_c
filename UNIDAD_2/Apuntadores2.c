#include <stdio.h>
int main(){
    int numero=42;
    int *apuntador =&numero;
    printf("valor de numero: %d\n",numero);
    printf("direccion de numero: %p\n",&numero);
    printf("valor del apuntador: %p\n",apuntador);
    printf("valor al que apunta: %d\n",*apuntador);
    return 0;
}