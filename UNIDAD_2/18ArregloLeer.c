//programa que se encarga de crear un arreglo apartir de un tamaño indicado
#include <stdio.h>
int main(){
    int size;
    printf("ingrese el tamano del arreglo:\n");
    scanf("%d",&size);

    int arregloNumeros[size];
    for(int i=0; i<size;i++){
        printf("ingrese valor en posicion [%d]:\n",i);
        int swap;
        scanf("%d",&swap);
        arregloNumeros[i]=swap;
    }
    //imprimiendo los valores del arreglo
    for(int i=0;i<size;i++){
        printf("arreglo[%d]=%d\n",i, arregloNumeros[i]);
    }


    return 0;
}