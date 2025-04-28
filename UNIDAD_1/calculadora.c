#include <stdio.h>
int main(){
    float num1,num2;
    int opc;
    float suma,resta,division,multiplicacion;
    printf("calculadora\n");
    printf("Elige una operacion\n");
    printf("1.-suma\n");
    printf("2.-resta\n");
    printf("3.-multiplicacion\n");
    printf("4.-division\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
        
        printf("suma de dos numeros\n");
        printf("introduce numero 1:");
        scanf("%f",&num1);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        suma=num1+num2;
        printf("resultado es: ");
        printf("%.2f",suma);
        break;
        case 2:
        printf("resta de dos numeros\n");
        printf("introduce numero 1:");
        scanf("%f",&num1);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        resta=num1-num2;
        printf("resultado es:");
        printf("%.2f",resta);
        break;
        case 3:
        printf("multiplicacion de dos numeros\n ");
        printf("introduce numero 1:");
        scanf("%f",&num1);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        multiplicacion=num1*num2;
        printf("resultado es:");
        printf("%.2f",multiplicacion);
        break;
        case 4:
        printf("division de dos numeros\n");
        printf("introduce numero 1:");
        scanf("%f",&num1);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        division=num1/num2;
        printf("resultado es:");
        printf("%.2f",division);
        break;
        default:
        printf("\n no has seleccionado una opcion valida");
        break;


    }


    return 0;
}