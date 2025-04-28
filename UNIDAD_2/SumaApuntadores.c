#include <stdio.h>

 int main() { 
    int fno, sno, sum; 
    int *ptr,*qtr,*resultsumptr; 
    printf("\n\npointer: operaciones con dos numeros: \n"); 
    printf("------------------------------------\n");
    printf("introduce primer numero: ");
    scanf(" %d",&fno);
    printf("introduce segundo numero: ");
    scanf(" %d",&sno);

    ptr = &fno;
    qtr = &sno; 
    printf("\n\n pointer1: %p",&ptr);
    printf("\n\n pointer2: %p",qtr);

    sum= *ptr + *qtr; 
    

    printf("\n\nla suma de los numeros dados: %d\n\n",sum);
    printf("direccion de resultado de suma: %p",(void*)resultsumptr);
    



 return 0;
 }