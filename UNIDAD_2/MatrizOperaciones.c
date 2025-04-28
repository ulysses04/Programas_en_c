#include <stdio.h>
#define FILAS 3
#define COLUMNAS 6
int main()
{

    float matriz[FILAS][COLUMNAS];
    printf("matriz:\n");
    for(int i=0;i<FILAS;i++){
        printf("ingresa valor 1:",i+1);
        scanf("%f",&matriz[i][0]);
        printf("ingresa valor 2:",i+1);
        scanf("%f",&matriz[i][1]);

        matriz[i][2]= matriz[i][0]+matriz[i][1];
        matriz[i][3]= matriz[i][0]-matriz[i][1];
        matriz[i][4]= matriz[i][0]*matriz[i][1];
        matriz[i][5]= matriz[i][0]/matriz[i][1];
    }
    printf("matriz con resultados:");
    printf("valor1 | valor 2 | suma | resta | multiplicacion | division |\n");
    for(int i=0;i<FILAS;i++){
        printf("%.2f | %.2f | %.2f | %.2f | %.2f | %.2f\n",
        matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5]);

    }
return 0;
}