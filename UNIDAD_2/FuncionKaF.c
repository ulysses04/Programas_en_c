#include <stdio.h>
float convKF(float kelvin){
    return ((kelvin-273.15)*1.8)+32;
}
int main(){
    float gradoskel,resultado;
    printf("ingresa los grados kelvin:");
    scanf("%f",&gradoskel);
    resultado=convKF(gradoskel);
    printf("grados kelvin:%.2f\ngrados fahrenheit:%.2f\n",gradoskel,resultado);
    return 0;
}