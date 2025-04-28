#include <stdio.h>
int exponencial(int base, int exponente){
    int resultado=base;
    for(int i=1; i<exponente; i++){
        resultado*=base;
       

    }
    return resultado;
    }
int main(){
    int num,exp,result;
    printf("ingresa numero:\n");
    scanf("%d",&num);
    printf("ingresa exponente:\n");
    scanf("%d",&exp);
    result=exponencial(num,exp);
   
    printf("resultado de %d^%d es: %d",num,exp,result);




    return 0; 
}
