#include <stdio.h>
void palabras(int opcion){
    switch(opcion){
        case 1:
        printf("hola");
        break;
        case 2:
        printf("bonjour");
        break;
        case 3:
        printf("hello");
        break;
        case 4:
        printf("konichiwa");
        break;
        default:
        printf("elige una opcion correcta");
        break;
    }
}
int main(){
    int opcion;
    printf("selecciona un numero: 1, 2, 3, 4\n");
    scanf("%d",&opcion);
    palabras(opcion);
    return 0;
}