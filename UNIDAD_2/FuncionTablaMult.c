#include <stdio.h>
void tabla(int numero){
    for(int i=0;i<=10;i++){
        int resultado=i*numero;
        printf("%d x %d = %d\n",numero,i,resultado);
    }

}
   
    
      
int main(){
    int num;
    printf("ingresa numero para realizar su tabla de multiplicar: \n");
    scanf("%d",&num);
    tabla(num);
        return 0;
 }   
