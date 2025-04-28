#include <stdio.h>
int numeromayor(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int main(){
    int num1,num2,mayor;
    printf("ingresa numero 1:\n");
    scanf("%d",&num1);
    printf("ingresa numero 2:\n");
    scanf("%d",&num2);
    mayor= numeromayor(num1,num2);
    printf("numeros ingresados:%d, %d\n",num1,num2);
    printf("numero mayor es:%d",mayor);
    return 0;
}