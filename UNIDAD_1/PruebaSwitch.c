#include<stdio.h>
int main(){
    int opc;
    printf("%s\n","selecciona una opcion");
    printf("%s\n","1.-sumar");
    printf("%s\n","2.-restar");
    scanf("%d",&opc);
    switch(opc){
        case 1:
        printf("%s\n","ha seleccionado suma");
        break;
        case 2:
        printf("%s\n","ha seleccionnado resta");
        break;
        default:
        printf("%s\n","no has seleccionado una opcion valida");
        break;

    }
    return 0;

}