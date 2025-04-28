#include <stdio.h>

//30 negro,31 rojo,32 verde, 33 amarillo, 34 azul, 35 mayenta, 36 cyan, 37 blanco
//0 normal,1 negrita, 4 subrayado, 7 invertir colores

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
void limpiarpantalla(){
    printf("\033[2J]");
}


   

int main(){
    int opc;
    float num1,num2,suma,resta,multiplicacion,division;
    printf("\033[2J"); // Limpia la pantalla
    
    setColor("\033[7;32m");
    gotoxy(10,5);
    printf("Calculadora Basica con gotoxy y switch-case: ");

    setColor("\033[4;30m");
    gotoxy(10,6);
    printf("Menu de operaciones: ");


    setColor("\033[7;37m");
    gotoxy(30,7);
    printf("1.-: ");

    setColor("\033[0m");
    gotoxy(31,7);
    printf("Suma: ");

    setColor("\033[7;33m");
    gotoxy(30,8);
    printf("2.-: ");

    setColor("\033[0m");
    gotoxy(31,8);
    printf("Resta: ");

    setColor("\033[7;36m");
    gotoxy(30,9);
    printf("3.-: ");

    setColor("\033[0m");
    gotoxy(31,9);
    printf("Multiplciacion: ");


    setColor("\033[7;31m");
    gotoxy(30,10);
    printf("4.-: ");

    setColor("\033[0m");
    gotoxy(31,10);
    printf("Division: ");

    
    setColor("\033[0m");
    gotoxy(32,11);
    printf("seleccione una opcion");
    
    setColor("\033[7;33m");
    gotoxy(55,11);
    printf("1-4:");
    scanf("%d",&opc);
    setColor("\033[0m");

    limpiarpantalla();
    switch(opc){
        case 1:
       
        gotoxy(10,2);
        printf("introduce numero 1:");
        scanf("%f",&num1);
        gotoxy(10,4);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        suma=num1+num2;
        gotoxy(10,6);
        setColor("\033[7;37m");
        printf("resultado es: ");
        printf("%.2f",suma);
        setColor("\033[0m");
        break;
        case 2:
        
        gotoxy(10,2);
        printf("introduce numero 1:");
        scanf("%f",&num1);
        gotoxy(10,4);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        resta=num1-num2;
        setColor("\033[7;33m");
        printf("resultado es:");
        printf("%.2f",resta);
        setColor("\033[0m");

        break;
        case 3:
       
       gotoxy(10,2);
        printf("introduce numero 1:");
        scanf("%f",&num1);
        gotoxy(10,4);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        multiplicacion=num1*num2;
        setColor("\033[7;36m");
        printf("resultado es:");
        printf("%.2f",multiplicacion); 
        setColor("\033[0m");
        
        break;
        case 4:
   
        gotoxy(10,2);
        printf("introduce numero 1:");
        scanf("%f",&num1);
        gotoxy(10,4);
        printf("introduce numero 2:");
        scanf("%f",&num2);
        if(num2==0){
            setColor("\033[7;31m");
            printf("no se puede dividir entre 0");
        }else{
        division=num1/num2;
        setColor("\033[7;31m");

        printf("resultado es:");
        printf("%.2f",division);
    
        }
        setColor("\033[0m");
        break;
        default:
        printf("%s\n","no has seleccionado una opcion valida");
        break;

    }

return 0;
}