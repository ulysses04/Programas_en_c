#include <stdio.h>
float convCK(float celsius){
    return celsius + 273.15;

}
int main(){
    float gradoscel,resultado;
    printf("ingresa los grados celsius:\n");
    scanf("%f",&gradoscel);
    resultado=convCK(gradoscel);
    printf("grados celsius ingresados: %.2f\n grados kelvin:%.2f\n",gradoscel,resultado);
    return 0;
}