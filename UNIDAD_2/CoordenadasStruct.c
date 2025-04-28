#include <stdio.h>//declaracion de libreria
#include <math.h>//declaracion de libreria

struct cuadrado { //estructura cuadrado que tendra 4 coordenadas
    float x1,y1,x2,y2,x3,y3,x4,y4;//declaramos las variables
    float dis1,dis2,dis3,dis4,area,perimetro;// variables donde se guardaran las distancias entre puntos, area y perimetro
};
struct triangulo{//estructura de triangulo
    float x1,y1,x2,y2,x3,y3;//declaramos variables de las coordenadas
    float dis1,dis2,dis3,area,perimetro;// distancias entre puntos, area y perimetro
};
int main(){ //metodo principal
    int opcion; //declaramos variable para el menu
    printf("%s\n""menu\n");
    printf("%s\n","elija una figura:");//imprime menu entre cuadrado o triangulo
    printf("%s\n","1.- cuadrado");
    printf("%s\n","2.- triangulo");
    scanf("%d",&opcion);//lee el dato ingresado por el usuario
    switch(opcion){//inicio del switch y se elige opcion
        case 1:{
            struct cuadrado square; //llamamos arreglo
            printf("ingresa coordenadas para el cuadrado:\n");//pedimos y leemos las coordenadas dadas por le usuario 
            printf("ingresa x1:\n");
            scanf("%f",&square.x1);
            printf("ingresa y1:\n");
            scanf("%f",&square.y1);
            printf("ingresa x2:\n");
            scanf("%f",&square.x2);
            printf("ingresa y2:\n");
            scanf("%f",&square.y2);
            printf("ingresa x3:\n");
            scanf("%f",&square.x3);
            printf("ingresa y3:\n");
            scanf("%f",&square.y3);
            printf("ingresa x4:\n");
            scanf("%f",&square.x4);
            printf("ingresa y4:\n");
            scanf("%f",&square.y4);
            square.dis1 = sqrt(pow(square.x2 - square.x1, 2) + pow(square.y2 - square.y1,2));//realiza el calculo de la distancia entre los puntos dados
            square.dis2 = sqrt(pow(square.x3 - square.x2, 2) + pow(square.y3 - square.y2,2));
            square.dis3 = sqrt(pow(square.x4 - square.x3, 2) + pow(square.y4 - square.y3,2));
            square.dis4 = sqrt(pow(square.x1 - square.x4, 2) + pow(square.y1 - square.y4,2));
            square.perimetro = square.dis1+square.dis2+square.dis3+square.dis4; //con las distancias calculadas, se suma para obtener el perimetro
            square.area=square.dis1*square.dis2;//se calcula area
            printf("perimetro:%.2f\n",square.perimetro);//imprime el resultado, osea perimetro
            printf("area:%.2f\n",square.area);// imprime area
            break;//cierre de primer caso
            case 2:{//caso 2
            struct triangulo triangle;//iniciamos con arreglo
            printf("ingresa coordenadas para el triangulo:\n");
            printf("ingresa x1:\n");//pedimos y leemos datos ingresados de las coordenadas
            scanf("%f",&triangle.x1);
            printf("ingresa y1:\n");
            scanf("%f",&triangle.y1);
            printf("ingresa x2:\n");
            scanf("%f",&triangle.x2);
            printf("ingresa y2:\n");
            scanf("%f",&triangle.y2);
            printf("ingresa x3:\n");
            scanf("%f",&triangle.x3);
            printf("ingresa y3:\n");
            scanf("%f",&triangle.y3);
            //operacion de calcular la distancia entre las coordenadas
            triangle.dis1 = sqrt(pow(triangle.x2 - triangle.x1, 2) + pow(triangle.y2 - triangle.y1,2));
            triangle.dis2 = sqrt(pow(triangle.x3 - triangle.x2, 2) + pow(triangle.y3 - triangle.y2,2));
            triangle.dis3 = sqrt(pow(triangle.x1 - triangle.x3, 2) + pow(triangle.y1 - triangle.y3,2));
            triangle.perimetro= triangle.dis1+triangle.dis2+triangle.dis3;//perimetro es la suma de las distancias obtenidas
            float s=triangle.perimetro/2;//calculo de s para ocupar la formula de heron 
            triangle.area= sqrt(s*(s-triangle.dis1)*(s-triangle.dis2)*(s-triangle.dis3));//formula para area de triangulos irregulares
            printf("perimetro:%.2f\n",triangle.perimetro);//imprime el resultado, osea perimetro
            printf("area:%.2f\n",triangle.area);// imprime area
            break;//fin de caso 2
            }
            default://dado caso no se cumple algun caso
            printf("elige una opcion valida\n");//imprime que eliga una opcion disponible


            


            
        }
    }
return 0;
}