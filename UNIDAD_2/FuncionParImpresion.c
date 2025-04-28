#include <stdio.h>
void pares(int numeros[], int n){
    for(int i=0;i<n;i++){
        printf("Introduzca un numero: \n");
        scanf("%d",&numeros[i]);
    }
    printf("Los numeros pares que ingreso son:\n");
    for(int i=0; i<n;i++){
        if (numeros[i]% 2 == 0)
        {
            printf("Numero %2d: %2d\n",i+1,numeros[i]);
        }
    }
    
}
int main(){
    int n;
    printf("Introduzca la cantidad de numeros que desea ingresar: \n");
    scanf("%d",&n);
    int numeros[n];
    pares(numeros,n);

    return 0;
}