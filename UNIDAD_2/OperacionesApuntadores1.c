#include <stdio.h>//declaracion de libreria

 int main() { //metodo principal o programa principal
    int fno, sno, sum,res,mult,div; //declaro mis variables que almacenaran los valores y resultados de las operaciones
    int *ptr,*qtr,*resultsumptr,*resultresptr,*resultmultptr,*resultdivptr; //apuntadores de los valores y de los resultados
    printf("\n\npointer: operaciones con dos numeros: \n"); //titulo del programa
    printf("------------------------------------\n");
    printf("introduce primer numero: ");//pide el primer valor 
    scanf(" %d",&fno);//lee primer valor
    printf("introduce segundo numero: ");//pide el segundo valor
    scanf(" %d",&sno);//lee segundo valor 

    ptr = &fno;//asigna la direccion del primer valor con el apuntador
    qtr = &sno; //asigna la direccion de sno al apuntador
    printf("\n\n pointer1: %p",&ptr);//imprime la direccion del apuntador 1
    printf("\n\n pointer2: %p",qtr);//imprime la direccion del apuntador 2

    sum= *ptr + *qtr; //realiza la suma de los valores a los que apuntagf
    res=*ptr - *qtr;//resta de los valores a los que apunta
    mult=*ptr * *qtr;//multiplica los valores a los que apunta
    div= *ptr / *qtr;//divide los valores a los que apunta

    printf("\n\nla suma de los numeros dados: %d\n\n",sum);//imprime el resultado
    printf("direccion de resultado de suma: %p",(void*)resultsumptr);//imprime la direccion del resultado
    printf("\n\nla resta de los numeros dados: %d\n\n",res);//imprime resultado de la resta
    printf("direccion de resultado de resta: %p",(void*)resultresptr);//direccion del resultado de la resta
    printf("\n\nla multiplicacion de los numeros dados: %d\n\n",mult);//imprime resultado de multiplicacion
    printf("direccion de resultado de multiplicacion: %p",(void*)resultmultptr);//imprime la direccion del resultado de la multiplicacion
    printf("\n\nla division de los numeros dados: %d\n\n",div);//imprime el resultado de la division
    printf("direccion de resultado de division: %p",(void*)resultdivptr);//imprime la direccion del resultado




 return 0;//fin del programa
 }