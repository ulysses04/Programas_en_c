#include <stdio.h>
int main(){
    int a,b,c,d,e;
    printf("ingresa valor a:\n");
    scanf("%d",&a);
    printf("ingresa valor b:\n");
    scanf("%d",&b);
    printf("ingresa valor c:\n");
    scanf("%d",&c);
    printf("ingresa valor d:\n");
    scanf("%d",&d);
    printf("ingresa valor e:\n");
    scanf("%d",&e);
    int *const pa=&a;
    int *const pb=&b;
    int *const pc=&c;
    int *const pd=&d;
    int *const pe=&e;
    
    printf("valores ingresados: a=%p\n",&pa);
    printf("valores ingresados: b=%p\n",&pb);
    printf("valores ingresados: c=%p\n",&pc);
    printf("valores ingresados: d=%p\n",&pd);
    printf("valores ingresados: e=%p\n",&pe);

    int suma= *pa + *pa;
    printf("resultado de la suma: %d\n",suma);

    *pa=suma;
    printf("valor nuevo: a=%d\n",*pa);

    int resta=*pb - *pb;
    printf("resultado de la resta: %d\n",resta);
    *pb=resta;
    printf("valor nuevo: b=%d\n",*pb);

    int mult= *pc * *pc;
    printf("resultado de la multiplicacion:%d\n",mult);
    *pc=mult;
    printf("valor nuevo: c=%d\n",*pc);

    int div= *pd / *pd;
    printf("resultado de la division:%d\n",div);
    *pd=div;
    printf("valor nuevo: d=%d\n ",*pd);
    

    return 0;
}