#include<stdio.h>
int main(){
    int calif1,calif2,calif3;
    float promedio;
    calif1=6;
    calif2=8;
    calif3=10;
    printf("%s\n","calificacion 1:");
    printf("%d\n",calif1);
    printf("%s\n","calificacion 2:");
    printf("%d\n",calif2);
    printf("%s\n","calificacion 3:");
    printf("%d\n",calif3);
    promedio=(calif1+calif2+calif3)/3;
    printf("%s","tu promedio es:");
    printf("%2.0f\n",promedio);
    return 0;
    }