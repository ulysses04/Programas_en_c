#include <stdio.h>
#include<math.h>
#include<string.h>

struct eccuadratica{
    int a,b,c;
    int discriminante;
    float x1;
    float x2;
    char solucion[30];

};
int main(){

    struct eccuadratica arreglo[2]={
        {2,3,-5,0,0.0,0.0},
        {3,7,-6,0,0.0,0.0},
    };
for(int i=0;i<2;i++){
    int discriminante=(arreglo[i].b*arreglo[i].b)-(4*arreglo[i].a*arreglo[i].c);
    if(discriminante<0){
        strcpy(arreglo[i].solucion,"no tiene solucion");
    } else{
        int valx1=((-1)*arreglo[i].b + sqrt(discriminante))/2*arreglo[i].a;
        int valx2=((-1)*arreglo[i].b-sqrt(discriminante))/2*arreglo[i].a;
        strcpy(arreglo[i].solucion,"tiene solucion");
        arreglo[i].x1=valx1;
        arreglo[i].x2=valx2;

    }
}
printf("%s|%s|%s|%s|%s|%s\n","a","b","c","x1","x2","solucion");
for(int i=0;i<2;i++){
    printf("%d|%d|%d|%.2f|%.2f|%s\n",
    arreglo[i].a,arreglo[i].b,arreglo[i].c,arreglo[i].x1,arreglo[i].x2,arreglo[i].solucion);
}
return 0;
}