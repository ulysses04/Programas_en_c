#include <stdio.h>
int main(){
    int numeros[]={20,30,40,50,60};
    for(int i=0;i<5;i++){
        printf("valor en posicion i[$d]=%d",i,numeros[i]);
    }
    printf("valor:%d",numeros[0]);
    return 0;
}