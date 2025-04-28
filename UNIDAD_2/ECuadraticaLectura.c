#include <stdio.h> //declaracion de libreria
#include<math.h>  //declaracion de libreria
#include<string.h> //declaracion de libreria
struct eccuadratica{ //creacion de estructura
    int a,b,c; //coeficientes de la ecuacion
    int discriminante; //resultado dentro de la raiz cuadrada
    float x1; //solucion 1
    float x2; //solucion 2
    char solucion[30]; //guarda si tiene solucion o no

};
int main(){ //metodo principal
    int size; //variable que guardara valor ingresado por el usuario para la cantidad de arreglos
  
    printf("ingrese el tamano del arreglo:\n"); //pide al usuario ingresar numero de arreglos
    scanf("%d",&size); //lee y guarda el valor ingresado 
    
    struct eccuadratica arreglo[size];
    for(int i=0;i<size;i++){ //ciclo que se repetira dependiendo del numero ingresado
        printf("ingresa a:\n"); //pide valor de a
        scanf("%d",&arreglo[i].a); //guarda valor de a
        printf("ingresa b:\n"); //pide valor de b
        scanf("%d",&arreglo[i].b); //guarda valor de b
        printf("ingresa c:\n"); //pide valor de c
        scanf("%d",&arreglo[i].c); //guarda valor de c


    }
    
for(int i=0;i<size;i++){ //contador que hara las operaciones correspondientes dependiendo de size
    int discriminante=(arreglo[i].b*arreglo[i].b)-(4*arreglo[i].a*arreglo[i].c); //realiza la operacion dentro de la raiz
    if(discriminante<0){ //condicion si discriminante es menor a 0 no tiene solucion dentro de los reales
        strcpy(arreglo[i].solucion,"no tiene solucion");//imprime que no tiene solucion
    } else{ //si es mayor a 0, procede a realizar las demas operaciones
        int valx1=((-1)*arreglo[i].b + sqrt(discriminante))/2*arreglo[i].a;//operacion con el signo +
        int valx2=((-1)*arreglo[i].b-sqrt(discriminante))/2*arreglo[i].a;//operacion con el signo -
        strcpy(arreglo[i].solucion,"tiene solucion"); //imprime que tiene solucion
        arreglo[i].x1=valx1; //guarda solucion 1
        arreglo[i].x2=valx2; //guarda solucion 2

    }
}
printf("%s | %s | %s | %s | %s | %s\n","a","b","c","x1","x2","solucion");//imprime columnas para despues imprimir los resultados 
for(int i=0;i<size;i++){ //imprimira los datos segun el tamaño indicado
    printf(" %d | %d | %d | %.2f | %.2f | %s\n",
    arreglo[i].a,arreglo[i].b,arreglo[i].c,arreglo[i].x1,arreglo[i].x2,arreglo[i].solucion);//imprime los valores obtenidos
}
return 0; //fin de programa
}