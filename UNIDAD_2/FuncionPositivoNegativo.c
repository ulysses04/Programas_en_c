#include <stdio.h>
char valor(int a){
    if(a>0){
        return 'p';
    }else{
        return 'n';
    }
}
int main(){
    int num;
    char signo;
    printf("ingrese un numero:\n");
    scanf("%d",&num);
    signo=valor(num);
    if(signo=='p'){
        printf("el numero ingresado es positivo");
    }else{
        printf("el numero ingresado es negativo");
    }
   
    return 0;

}