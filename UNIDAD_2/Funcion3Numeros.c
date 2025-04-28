#include <stdio.h>
int numeromayor(int a, int b, int c){
    if(a>b && a>c){
        return a;
    }else if(b>a && b>c){
        return b;
    }else{
        return c;
    }


}
int main(){
    int num1,num2,num3,mayor;
    printf("ingresa numero 1:\n");
    scanf("%d",&num1);
    printf("ingresa numero 2:\n");
    scanf("%d",&num2);
    printf("ingresa numero 3:\n");
    scanf("%d",&num3);
    mayor=numeromayor(num1,num2,num3);
    printf("numeros ingresados: %d | %d | %d\n",num1,num2,num3);
    printf("numero mayor es:%d",mayor);
    return 0;
}