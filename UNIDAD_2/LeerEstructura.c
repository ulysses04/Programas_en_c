#include <stdio.h>
struct usuario{
    char nombre[50];
    int edad;
    char correo[50];
};
int main(){
    struct usuario usuario1;
    printf("ingrese su nombre:");
    scanf("%s",&usuario1.nombre);
    printf("ingrese su edad:");
    scanf("%d", &usuario1.edad);
    printf("ingrese su correo:");
    scanf("%s",&usuario1.correo);
    printf("\ndatos del usuario:\n");
    printf("nombre:%s\n",usuario1.nombre);
    printf("edad:%d\n",usuario1.edad);
    printf("correo: %s\n",usuario1.correo);
    return 0;
}