#include <stdio.h>
float convFC(float fahrenheit){
    return (fahrenheit-32)/1.8;
}
int main(){
    float fahr,resultado;
    printf("ingresa los grados fahrenheit:\n");
    scanf("%f",&fahr);
    resultado=convFC(fahr);
    printf("grados fahrenheit ingresados:%.2f\n grados celsius:%.2f\n",fahr,resultado);
    return 0;
}
