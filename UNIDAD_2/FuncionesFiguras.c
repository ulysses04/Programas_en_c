#include <stdio.h>
#define PI 3.1416

float acuadrado(int a)
{
    return a * a;
}
float atriangulo(int b, int h)
{
    return (h * b) / 2;
}
float acirculo(int r, double pi)
{
    return (r * r) * pi;
}

float arectangulo(int b, int h)
{
    return b * h;
}
float arombo(int d, int c)
{
    return (d * c) / 2;
}
float vcubo(int l)
{
    return l * l * l;
}
float vparalelepipedo(int a, int b, int c)
{
    return a * b * c;
}
float vpiramide(int b, int h)
{
    return (b * h) / 3;
}
float vcilindro(int r, int h, float pi)
{
    return (r * r) * h * pi;
}
float vesfera(int r, float pi)
{
    return (4 * pi * (r * r * r)) / 3;
}

    union Dato{
        float entero;
        float flotante;
    };


int main()
{
    union Dato resultado;
    int opc;
    printf("menu de figuras\n");
    printf("selecciona una opcion:\n");
    printf("1.-area de un cuadrado\n");
    printf("2.-area de un triangulo\n");
    printf("3.-area de un circulo\n");
    printf("4.-area de un rectangulo\n");
    printf("5.-area de un rombo\n");
    printf("6.-volumen de cubo\n");
    printf("7.-volumen de paralelepipedo\n");
    printf("8.-volumen de piramide\n");
    printf("9.-volumen de cilindro\n");
    printf("10.-volumen de una esfera\n");
    scanf("%d", &opc);
   

    switch (opc)
    {
    case 1:
        printf("ingresa lado del cuadrado:");
        int lado;
        scanf("%d", &lado);
        resultado.entero = acuadrado(lado);
            printf("el Area es : %.2f\n", resultado.entero);
            break;
        break;
    case 2:
        printf("ingresa base:");
        int base, altura;
        scanf("%d", &base);
        printf("ingresa altura:");
        scanf("%d", &altura);
        resultado.entero = arectangulo(base, altura);
            printf("Area: %.2f\n", resultado.entero);
        break;
    case 3:
        printf("ingresa radio:");
        int radio;
        scanf("%d", &radio);
        resultado.entero=acirculo(radio,PI);
        printf("area: %.2f\n",resultado.entero);
        
        break;
    case 4:
        printf("ingresa base:");
        int b, h;
        scanf("%d", &b);
        printf("ingresa altura:");
        scanf("%d", &h);
        resultado.entero=arectangulo(b,h);
        printf("area es de:%.2f",resultado.entero);
        break;
    case 5:
        
        printf("ingresa diagonal a:");
        int da, db;
        scanf("%d", &da);
        printf("ingresa diagonal b:");
        scanf("%d", &db);
        resultado.entero=arombo(da,db);
        printf("area es: %.2f",resultado.entero);
        break;
    case 6:
        
        printf("ingresa lado:");
        int l;
        scanf("%d", &l);
       resultado.flotante=vcubo(l);
        printf("volumen es: %.2f",resultado.flotante);
    case 7:
       
        printf("ingresa base:");
        int base2,altura2, ancho;
        scanf("%d", &base2);
        printf("ingresa altura:");
        scanf("%d", &altura2);
        printf("ingresa ancho:");
        scanf("%d", &ancho);
      resultado.flotante=vparalelepipedo(base2,altura2,ancho);
        printf("volumen es: %.2f",resultado.flotante);
        break;

    case 8:
       
        printf("ingresa altura:");
        int altura3, areabase;
        scanf("%d", &altura3);
        printf("ingresa area de base: ");
        scanf("%d", &areabase);
        resultado.flotante=vpiramide(altura3,areabase);
        printf("volumen es:%.2f",resultado.flotante);
        break;
    case 9:
      
        printf("ingresa radio:");
        int radio2,h2;
        scanf("%d", &radio2);
        printf("ingresa altura:");
        scanf("%d", &h2);
        resultado.flotante=vcilindro(radio2, h2, PI);
        printf("volumen es: %.2f",resultado.flotante);
        break;
    case 10:
     
        printf("ingresa radio: ");
        int r;
        scanf("%d", &r);
        resultado.flotante=vesfera(r, PI);
               printf("volumen es: %.2f",vesfera(r,PI));
        break;

    default:
        printf("elige una opcion valida");
        break;
    }
}