#include<stdio.h>
int main(){
    char opcion;
    printf("%s\n","selecciona una opcion:");
    printf("%s\n","a)selecciona opcion 1");
    printf("%s\n","selecciona opcion 2");
    scanf("%c",&opcion);
    switch(opcion){
        case 'a':
        printf("%s\n","selecciono opcion 1");
        break;
        case 'b':
        printf("%s\n","selecciono opcion 2");
        break;
        default:
        printf("%s\n","opcion invalido");
    }
    return 0;

}