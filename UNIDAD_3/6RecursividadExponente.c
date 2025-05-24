#include <stdio.h>

int power(int base, int exponent){
    if(exponent==0){
    return 1;
    }else 
    return base*power(base,exponent-1);

}
int main(){
    int base,exponent;
    printf("ingrese base:\n");
    scanf("%d",&base);
    printf("ingrese exponente:\n");
    scanf("%d",&exponent);
    printf("resultado es:%d",power(base,exponent));

    return 0;
    

}