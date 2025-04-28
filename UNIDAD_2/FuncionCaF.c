#include <stdio.h>
float convCF(float celsius){
    return (1.8*celsius)+32;
}
int main(){
    float gradoscel,resultado;
    printf("ingresa los grados celsius:\n");
    scanf("%f",&gradoscel);
    resultado=convCF(gradoscel);
    printf("grados celsius:%.2f\ngrados fahrenheit:%.2f",gradoscel,resultado);
    return 0;
}