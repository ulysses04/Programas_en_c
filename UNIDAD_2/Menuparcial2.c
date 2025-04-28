#include <stdio.h> //Incluimos librería stdio
#include <math.h> //Incluimos libreria math para que se pueda hacer la raiz cuadrada
#include <string.h> //Incluimos string para los decimales
#include <stdbool.h>

#define FILAS 2
#define COLUMNAS 2
#define dolar 20.33  
#define euro 21.96  
#define libreest 26.27
#define PI 3.141516 
#define FILAS1 3
#define COLUMNAS1 3
#define FILASp48 3
#define COLUMNASp48 2


void llenarMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void saveMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    FILE *archivo = fopen("matriz.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fprintf(archivo, "%d ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
    printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
}

void imprimirMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatriz(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int matrizr[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void escalarMatrizA(int filas, int columnas, int matriz1[filas][columnas], int matriz_escA[filas][columnas])
{
    int numero;
    printf("Ingrese el número por el que desea multiplicar la matriz A:\n");
    scanf("%d", &numero);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_escA[i][j] = matriz1[i][j] * numero;
        }
    }
}

void escalarMatrizB(int filas, int columnas, int matriz2[filas][columnas], int matriz_escB[filas][columnas])
{
    int numero2;
    printf("Ingrese el número por el que desea multiplicar la matriz B:\n");
    scanf("%d", &numero2);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_escB[i][j] = matriz2[i][j] * numero2;
        }
    }
}

int calculardeterminante(int MatrizA[3][3])
{
    int MatrizExp[3][5], determinante = 0;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            MatrizExp[i][j] = MatrizA[i][j];
        }
        for (j = 3; j < 5; j++)
        {
            MatrizExp[i][j] = MatrizA[i][j - 3];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        determinante += MatrizExp[0][i] * MatrizExp[1][i + 1] * MatrizExp[2][i + 2];
    }

    for (int i = 0; i < 3; i++)
    {
        determinante -= MatrizExp[0][i + 2] * MatrizExp[1][i + 1] * MatrizExp[2][i];
    }

    return determinante;
}
void programa1 (){
    
    int filas, columnas;
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_r[filas][columnas];
    int matriz_escA[filas][columnas];
    int matriz_escB[filas][columnas];

    llenarMatriz("Matriz A", filas, columnas, matriz_a);
    llenarMatriz("Matriz B", filas, columnas, matriz_b);

    imprimirMatriz("Matriz A", filas, columnas, matriz_a);
    imprimirMatriz("Matriz B", filas, columnas, matriz_b);

    sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirMatriz("Suma A+B", filas, columnas, matriz_r);

    escalarMatrizA(filas, columnas, matriz_a, matriz_escA);
    imprimirMatriz("Matriz A multiplicada por el número ingresado:", filas, columnas, matriz_escA);

    escalarMatrizB(filas, columnas, matriz_b, matriz_escB);
    imprimirMatriz("Matriz B multiplicada por el número ingresado:", filas, columnas, matriz_escB);

    saveMatriz(filas, columnas, matriz_r);

    if (filas == 3 && columnas == 3)
    {
        int determinante = calculardeterminante(matriz_a);
        printf("El det de la matriz es: %d\n", determinante);
    }
    else
    {
        printf("No se puede calcular el determinante ");
    }

}

void programa2(){
    int size; 
    printf("Ingrese el tamaño del arreglo: \n");
    scanf ("%d", &size);
    
    int arregloNumeros[size]; 
    for(int i=0; i<size; i++){
        printf("Ingrese valor en posicion [%d]:\n",  i);
        int swap; 
        scanf("%d", &swap);
        arregloNumeros[i]=swap; 
    }
    
    for (int i=0; i<size; i++){
        printf("arreglo en[%d]=%d\n", i, arregloNumeros[i]);
    }
}

void programa3(){
    int num1, num2;
    int *ptr1, *ptr2; 

    ptr1 = &num1;
    ptr2 = &num2;

printf("%p\n",ptr1 );
printf("%p\n", ptr2);

    num1 = 10;
    num2 = 20;

    ptr1 = ptr2;
    ptr2 = NULL;  

printf("%p\n",ptr1 );
printf("%p\n",ptr2);

}

struct carro{
    char marca[50];
    char modelo[50];
    char color[50];
    char transmision[50];
    int ano, cilindros,nserie;
    char placas[50];  

};
void programa4(){
    int size;
    printf("ingrese tamano de arreglo:\n");
    scanf("%d",&size);
    struct carro usuarios[size];
    for(int i=0;i<size;i++){
        printf("ingrese marca del carro:\n");
        scanf("%s",usuarios[size].marca);
        printf("ingrese modelo:\n");
        scanf("%s",usuarios[size].modelo);
        printf("ingrese ano:\n");
        scanf("%d",&usuarios[size].ano);
        printf("ingrese color:\n");
        scanf("%s",usuarios[size].color);
        printf("ingrese tipo de transmision:\n");
        scanf("%s",usuarios[size].transmision);
        printf("ingresa numero de cilindros:\n");
        scanf("%d",&usuarios[size].cilindros);
        printf("ingrese numero de serie:\n");
        scanf("%d",&usuarios[size].nserie);
        printf("ingrese numero de placas:\n");
        scanf("%s",usuarios[size].placas);

        
    }
    for(int i=0;i<size;i++){
        printf("\ndatos del carro:\n");
        printf("marca:%s\n",usuarios[size].marca);
        printf("modelo:%s\n",usuarios[size].modelo);
        printf("ano:%d\n",usuarios[size].ano);
        printf("color:%s\n",usuarios[size].color);
        printf("transmision:%s\n",usuarios[size].transmision);
        printf("numero de cilindros:%d\n",usuarios[size].cilindros);
        printf("numero de serie:%d\n",usuarios[size].nserie);
        printf("numero de placas:%s\n",usuarios[size].placas);


    }



}


void programa5(){
    int numero =42; 
int *apuntador= &numero;

printf ("Valor del numero:%d", numero); 
printf("Direccion de numero: %p", &numero);
printf("Valor del apuntador:%p", apuntador);
printf("Valor al que paunta: %d", *apuntador);

}

void programa6 (){
    int a, b, c, d, e;
    printf("Ingrese valor A\n");
    scanf("%d", &a);
    printf ("Ingrese valor B\n");
    scanf("%d", &b);
    printf ("Ingrese valor C\n");
    scanf("%d", &c);
    printf ("Ingrese valor D\n");
    scanf("%d", &d);
    printf ("Ingrese valor E\n");
    scanf("%d", &e);

    int *const pa=&a;
    int *const pb=&b;
    int *const pc=&c;
    int *const pd=&d;
    int *const pe=&e;
   
   printf("Valores ingresados: A=%p\n",&pa);
   printf("Valores ingresados:  B=%p\n",&pb);
   printf("Valores ingresados: C=%p\n",&pc);   
   printf("Valores ingresados: D=%p\n",&pd);   
   printf("Valores ingresados: E=%p\n",&pe);

   int suma=*pa+*pa;
   printf("Resultado de la suma: %d", suma);

   *pa=suma; 
   printf("Valor nuevo A=%d\n", *pa);

   int resta=*pb-*pb;
   printf("Resultado de la resta:\n %d", resta);

   *pb=resta; 
   printf("Valor nuevo B=%d\n", *pb);

   int multiplicacion=*pc * *pc;
   printf("Resultado de la multiplicación: \n%d", multiplicacion);

   *pc=multiplicacion; 
   printf("Valor nuevo C=%d\n", *pc);


   int division=*pd / *pd;
   printf("Resultado de la división:\n %d", division);

   *pd=division; 
   printf("Valor nuevo D=%d\n", *pd);

}


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setColor(const char* color) {
    printf("%s", color);
}

void programa7 (){
    printf("\033[2J");
    int filas = 13;
    int columnas = 40;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
           
            if (i < 7 && j < 12) {
                setColor("\033[7;34m"); 
                printf("  "); 
                setColor("\033[0m"); 
                continue;
            }

            
            if (i % 2 == 0) {
                setColor("\033[7;31m"); 
            } else {
                setColor("\033[7;37m"); 
            }

            printf("  "); 
            setColor("\033[0m"); 
        }
        printf("\n"); 
    }
}
    
       

    
    void resetColor() {
        printf("\033[0m");
    }

    void programa8 (){
            int i, j;
        
            for (i = 0; i < 7; i++) {
            setColor("\033[7;32m");
                for (j = 0; j < 8; j++) {
                    printf(" ");
                }
        
                setColor("\033[7;37m");  
                for (j = 0; j < 8; j++) {
                    printf(" ");
                }
        
                setColor("\033[7;31m");  
                for (j = 0; j < 8; j++) {
                    printf(" ");
                }
        
                resetColor();
                printf("\n");
            }
        
        }

       
void programa9 (){
    struct KeyValue{
        char clave[50];
        char valor [100];};

    struct KeyValue tabla[3]={
        {"usurio", "admin"},
        {"contrasena", "1234"},
        {"servidor", "localhost"},

    };

    printf("Tabla Clave-valor:\n ");
    for (int i=0; i<3; i++){
        printf("%s; %s\n", tabla [i].clave, tabla[i]. valor);
    }
}
void limpiarpantalla (){
    printf("\033[2]");
}


void programa10 (){
        limpiarpantalla();
        gotoxy (5, 3);
        printf("Hellou from(5, 3)");
        }


        struct Puntos {  //Establecimos neuestra estructura
            float x;     //Las variables que va a incluir nuestro programa x en los puntos 
            float y;     //Varibale y en cada punto
        };               //Se cierra la especificación de variables

void programa11 (){
        
    
        struct Puntos p1, p2, p3, p4;    //Establecemos el arreglo que sera puntos, en el cuál habran 4 por cada cuadrante
        float d12, d23, d34, d41, d13; //Establecemos las distancias entre los puntos con d12, d23 etc
        float perimetro, area; //Establecemos el perimetro y el area para cada caso (posteriormente se verá)
        
        
        printf("Ingrese valor de x para el punto en el cuadrante 1 : "); //Pedimos el valor de x en el cuadrante 1 al usuario
        scanf("%f", &p1.x);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
        printf("Ingrese valor de y para el punto en el cuadrante 1: "); //Pedimos el valor de y en el cuadrante 1 al usuario
        scanf("%f", &p1.y);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
    
    
        printf("Ingrese valor de x para el punto  en el cuadrante 2: "); //Pedimos el valor de x en el cuadrante 2 al usuario
        scanf("%f", &p2.x);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
        printf("Ingrese valor de y para el punto en el cuadrante 2: "); //Pedimos el valor de y en el cuadrante 2 al usuario
        scanf("%f", &p2.y);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
    
    
        printf("Ingrese valor de x para el punto en el cuadrante 3: "); //Pedimos el valor de x en el cuadrante 3 al usuario
        scanf("%f", &p3.x);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
        printf("Ingrese valor de y para el punto en el cuadrante 3 : "); //Pedimos el valor de y en el cuadrante 3 al usuario
        scanf("%f", &p3.y);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
    
        printf("Ingrese valor de x para el punto en el cuadrante 4 : "); //Pedimos el valor de x en el cuadrante 4 al usuario
        scanf("%f", &p4.x);                                               //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
        printf("Ingrese valor de y para el punto en el cuadrante 4 : ");//Pedimos el valor de y en el cuadrante 4 al usuario
        scanf("%f", &p4.y);                                             //Escaneamos el valor, en este caso le puse flotante por si el usuario llega a poner flotantes
    
    
        d12= sqrt(((p2.x-p1.x)* (p2.x-p1.x))+ ((p2.y-p1.y)*(p2.y-p1.y))); //Con base en una formula ivnestigada se calcula la distancia entre el punto 1 y el 2
        d23=sqrt(((p3.x-p2.x)* (p3.x-p2.x))+ ((p3.y-p2.y)*(p3.y-p2.y))); //Con base en una formula ivnestigada se calcula la distancia entre el punto 2 y el 3
        d34=sqrt(((p4.x-p3.x)* (p4.x-p3.x))+ ((p4.y-p3.y)*(p4.y-p3.y)));//Con base en una formula ivnestigada se calcula la distancia entre el punto 3 y el 4
        d41=sqrt(((p1.x-p4.x)* (p1.x-p4.x))+ ((p1.y-p4.y)*(p1.y-p4.y))); //Con base en una formula ivnestigada se calcula la distancia entre el punto 4 y el 1
        d13=sqrt(((p3.x-p1.x)* (p3.x-p1.x))+ ((p3.y-p1.y)*(p3.y-p1.y))); //Es la distancaia de la línea para formar el triángulo 
    
    int opc;             //Comenzamos con el menú para calcular el area y el perimetro de un triángulo o de un cuadrado
        printf("%s\n", "Seleccione una opción:\n"); //Pedimos al usuario que nos de una opción
        printf("%s\n", "1.-Cuadrado\n"); //Damos la opción de hacer un cuadrado
        printf("%s\n", "2.-Triángulo\n"); //Damos la opción de hacer un triángulo
        scanf("%d", &opc); //Leemos la opción que el usuario brindó
        switch(opc){  //Comenzamos estableciendo qué se hace en cada caso
        
        case 1: //En el caso uno se hará
        printf("Ha seleccionado cuadrado\n"); //Decimos que se ha seleccionado el cuadrado
        perimetro = d12+d23+d34+d41; //Hacemos la operación para calcular el perímetro del cuadrado
        area = d12 * d23; //Hacemos la operación para calcular el área del cuadrado, suponiendo como se dijo en clase que el usuario da los valores correctos
        printf("\nTu perímetro es: %.2f", perimetro); //Imprimimos el valor del perimetro
        printf("\nTu área es: %.2f", area); //Imprimimos el valor del area
        break;     //cerramos el caso para que no existan errores
    
        case 2:    //comenzamos ocn el segundo caso
        printf("Ha seleccionado triángulo\n"); //Decimos que se ha seleccionado el triangulo
        perimetro = d12+d23+d13;     //Calculamos el perimetro del triángulo sumando sus lados
        area = ((sqrt(3))/4) * (d12*d12);         //Calculamos el área suponiendo que se trata de un triángulo equilátero con la formula investigada
        printf("\nTu perímetro es: %.2f", perimetro); //Imprimimos el valor del perimetro
        printf("\nTu área es: %.2f", area);  //Imprimirmos el valor del área
    
    
        break;    //Cerramos el caso 2
           default: //Ponemos una opción default
                printf("%s\n", "\nOpción inválida\n"); //Y en caso de que no se seleccione ninguna opción se imprimira opción inválida
            break; //se cierra el default
    }
    }

    void setcol(int col) {
        printf("\033[7;%dm", col); 
    }
void programa12(){
    printf("\033[2J"); 
    int tam;
    printf("Ingrese el tamano del cuadrado: ");
    scanf("%d", &tam);

    int colores[] = {31, 32, 33, 34, 35, 36, 37}; 
    int numColores = 7;

    for (int i = 0; i < tam; i++) {      
        for (int j = 0; j < tam; j++) { 
            int color = colores[(i + j) % numColores]; 
            setColor(color);
            printf("* "); 
            printf("\033[0m"); 
        }
        printf("\n");
    }

}
struct Coordenada {
    int x;
    int y;
};

void programa13 (){
        int opc;
        int i;
    
        struct Coordenada arreglo[4];
    
        printf("%s\n", "Seleccione una opcion:");
        printf("%s\n", "1. Cuadrado");
        printf("%s\n", "2. Triángulo");
        scanf("%d", &opc);
    
        switch (opc) {
            case 1: // Cuadrado
                for (i = 0; i < 4; i++) {
                    printf("Ingrese coordenada x%d: ", i + 1);
                    scanf("%d", &arreglo[i].x);
    
                    printf("Ingrese coordenada y%d: ", i + 1);
                    scanf("%d", &arreglo[i].y);
                }
    
                // Distancias entre puntos consecutivos
                float ab = sqrt(
                    pow(arreglo[1].x - arreglo[0].x, 2) +
                    pow(arreglo[1].y - arreglo[0].y, 2));
    
                float bc = sqrt(
                    pow(arreglo[2].x - arreglo[1].x, 2) +
                    pow(arreglo[2].y - arreglo[1].y, 2));
    
                float cd = sqrt(
                    pow(arreglo[3].x - arreglo[2].x, 2) +
                    pow(arreglo[3].y - arreglo[2].y, 2));
    
                float da = sqrt(
                    pow(arreglo[0].x - arreglo[3].x, 2) +
                    pow(arreglo[0].y - arreglo[3].y, 2));
    
                float perimetro = ab + bc + cd + da;
                float area = ab * bc; // Solo válido si es cuadrado o rectángulo
    
                printf("Perimetro total: %f\n", perimetro);
                printf("area: %f\n", area);
                break;
    
            default:
                printf("Opcion no valida\n");
                break;
    
    }

}

void programa14 (){
    int numeros[]={12, 20, 30, 20};
    int size=sizeof(numeros)/sizeof(numeros[0]); //Para saber el tamaño del arreglo 

    printf("Tamaño: %d\n", size);
    for(int i=0; i<size; i++){
        printf("numeros [%d]=%d\n", i, numeros[i]);
    }

}






void llenarMatrizp2(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
printf("Nombre de la matriz: %s\n", nombre);
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
scanf("%d", &matriz[i][j]);
}
}
}



void imprimirMatrizp2(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
printf("Nombre de la matriz: %s\n", nombre);
printf("Matriz ingresada:\n");
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
printf("%4d ", matriz[i][j]);
}
printf("\n");
}
}


void multiplicarMatrizp2(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int matrizr[filas][columnas])
{
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
matrizr[i][j] = matriz1[i][j] * matriz2[i][j];
}
}
}


void programa15 (){

int filas, columnas;
printf("Ingrese el número de filas: ");
scanf("%d", &filas);
printf("Ingrese el número de columnas: ");
scanf("%d", &columnas);

int matriz_a[filas][columnas];
int matriz_b[filas][columnas];
int matriz_r[filas][columnas];


llenarMatrizp2("Matriz A", filas, columnas, matriz_a);
llenarMatrizp2("Matriz B", filas, columnas, matriz_b);

imprimirMatrizp2("Matriz A", filas, columnas, matriz_a);
imprimirMatrizp2("Matriz B", filas, columnas, matriz_b);

multiplicarMatrizp2(filas, columnas, matriz_a, matriz_b, matriz_r);
imprimirMatrizp2("Multiplicacion AxB", filas, columnas, matriz_r);


}




struct Direccion{
    char calle [50];
    int numero;
};
struct Persona {
    char nombre[50];
    struct Direccion domicilio; 
};
void programa16 (){
   
    struct Persona personal={"Carlos Ramírez", {"Av.Reforma", 123}};
    printf("Nombre: %s\n", personal.nombre);
    printf("Domicilio: %s #%d\n", personal.domicilio.calle, personal.domicilio.numero);

}
typedef struct {
    char nombre[50];
    int edad; 
    float promedio;
}Estudiante;
void programa17 (){
    
        Estudiante estudiante1={"Maria López", 22, 9.3};
        printf ("Nombre: %s\n", estudiante1.nombre);
        
    }

    struct Coordenadas{
        int latitud; 
        int longitud;
    };
    struct Direccionp18{
        char colonia [50];
    struct Coordenadas coorde; 
    };
    struct Personas{
        char nombre [50];
        struct Direccionp18 direccion;
    };

void programa18 (){
   
        struct Personas persona;
        
    printf ("Ingrese el nombre de la persona:");
    scanf ("%s", persona.nombre);
    
    printf ("Ingrese la colonia:");
    scanf ("%s", persona.direccion.colonia);
    
    printf ("Ingrese latitud:");
    scanf ("%d", &persona.direccion.coorde.latitud);
    
    printf("Ingrese longitud:");
    scanf ("%d",&persona.direccion.coorde.longitud);
    
    //Para imprimir valores registrados
    printf("\nInformación de la persona:\n");
    printf("Nombre: %s\n ", persona.nombre);
    printf("Colonia: %s\n ", persona.direccion.colonia);
    printf("Latitud: %d\n", persona.direccion.coorde.latitud);
    printf("Longitud:%d\n", persona.direccion.coorde.longitud);
    
    }


    struct tenis{
        float talla;
        char color[50];
        char modelo[50];
        char material[50];
        char resistealagua[50];
        char forma[50];
        char suela[50];
        char categoria[50];
        char ajuste[50];
        char edicion[50];
        char altura[50];
    };
    struct brand{
        char marca[50];
        struct tenis especificaciones;
    };



    void programa19 (){
        int n;
        printf("ingrese el numero de tenis:");
        scanf("%d",&n);
        getchar();
        struct brand brands[n];
        for(int i=0; i<n;i++){
            printf("\ningrese los datos de los tenis %d:\n",i+1);
            printf("marca : ");
            scanf(" %[^\n]",brands[i].marca);
            printf("talla: ");
            scanf("%f",&brands[i].especificaciones.talla);
            printf("color: ");
            scanf(" %[^\n]",brands[i].especificaciones.color);
            printf("modelo : ");
            scanf(" %[^\n]",brands[i].especificaciones.modelo);
            printf("material : ");
            scanf(" %[^\n]",brands[i].especificaciones.material);
            printf("resistente al agua : ");
            scanf(" %[^\n]",brands[i].especificaciones.resistealagua);
            printf("forma  : ");
            scanf(" %[^\n]",brands[i].especificaciones.forma);
            printf("suela  : ");
            scanf(" %[^\n]",brands[i].especificaciones.suela);
            printf("categoria : ");
            scanf(" %[^\n]",&brands[i].especificaciones.categoria);
            printf("ajuste : ");
            scanf(" %[^\n]",brands[i].especificaciones.ajuste);
            printf("edicion  : ");
            scanf(" %[^\n]",brands[i].especificaciones.edicion);
            printf("altura : ");
            scanf(" %[^\n]",brands[i].especificaciones.altura);
             getchar();
        }
        printf("\n%-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n","marca","","talla","color","modelo","material","resistente al agua","forma","suela","categoria","ajuste","edicion","altura");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
        for(int i=0; i<n; i++){
            printf("%-10s | %.2f | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n",
            brands[i].marca,
        brands[i].especificaciones.talla,
    brands[i].especificaciones.color,
    brands[i].especificaciones.modelo,
    brands[i].especificaciones.material,
    brands[i].especificaciones.resistealagua,
    brands[i].especificaciones.forma,
    brands[i].especificaciones.suela,
    brands[i].especificaciones.categoria,
    brands[i].especificaciones.ajuste,
    brands[i].especificaciones.edicion,
    brands[i].especificaciones.altura);
        }
           }
    
        struct Usuariop20 {
            char nombre [50];
            int edad; 
            char correo [50];
        };
void programa20 (){
    
    struct Usuariop20 usuario1;
    printf("Ingrese su nombre;");
    scanf("%s", usuario1.nombre);

    printf ("Ingrese su edad:");
    scanf("%d", &usuario1.edad);

    printf("Ingrese su correo:"); 
    scanf("%s", usuario1.correo);

    printf("\nDatos del Usuario: \n");
    printf("Nombre %s\n", usuario1.nombre);
    printf("Edad: %d\n", usuario1.edad);
    printf("Correo: %s\n", usuario1.correo);

    
}

struct Estudiante {
    char nombre [50];
    int edad; 
    float promedio;
};
void programa21 (){


    struct Estudiante estudiante1= {"Alejandro Díaz", 24, 8.5};
    printf("Nombre:%s\n",estudiante1.nombre);
    printf("Edad; %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);


}
void programa22 (){
    typedef struct{
        char nombre [50];
        int edad;
    }Persona; //Nombre de estructura
    
    typedef struct {
        char producto [50];
        float precio;
    } Producto;
    
    typedef union{
        Persona persona;
        Producto producto;
    } Dato;
    
    typedef struct{
        Dato valor;
        int tipo;
    } Celda;
    

        Celda matriz [FILAS][COLUMNAS];
        strcpy (matriz [0][0].valor.persona.nombre, "Roberto");
        matriz[0][0].valor.persona.edad=25;
        matriz[0][0]. tipo=1;
    
        strcpy(matriz [0][1].valor.persona.nombre, "Alejandro");
        matriz [0][1].valor.persona.edad=30;
        matriz[0][1].valor.persona.edad=30;
        matriz[0][1].tipo=1;
    
        strcpy(matriz [1][0].valor.producto.producto, "Conejo");
        matriz[1][0].valor.producto.precio=1377.99;
        matriz[1][1].tipo=2;
    
        printf("Recorriendo la matriz de uniones con estructuras:\n");
    
        for(int i=0; i<FILAS; i++){
            for (int j=0;j<COLUMNAS; j++){
                printf("Celda [%d][%d]:", i, j);
                if(matriz[i][j].tipo==1){
                    printf("Persona-Nombre;%s, Edad;%d\n", 
                    matriz[i][j].valor.persona.nombre,
                    matriz[i][j].valor.persona.edad);
                }else if(matriz[i][j].tipo==2){
                    printf("Producto-Nombre: %s, Precio: %.2f\n",
                    matriz[i][j].valor.producto.producto,
                    matriz[i][j].valor.producto.precio);
                }
                }
            }
         
        }
    
    
void programa23 (){
    struct EcCuadratica{
        int a; 
        int b; 
        int c;
        int discriminante;
        float x1;
        float x2;
        char solucion[30];
    };
    
        struct EcCuadratica arreglo[2]={
            {2,3,-5,0,0.0,0.0},
            {3,7,-6,0,0.0,0.0}
    
        };
    
    for (int i=0; i<2;i++){
    int d=(arreglo[i].b*arreglo[i].b)-(4*arreglo[i].a*arreglo[i].b);
    if(d<0){
        strcpy(arreglo[i].solucion,"No tiene solucion");
    } else{
        int valx1=((-1)*arreglo[i].b+sqrt(d))/2*arreglo[i].a;  //i por size 
        int valx2=((-1)*arreglo[i].b-sqrt(d))/2*arreglo[i].a;
        strcpy(arreglo[i].solucion,"Tiene solucion");
        arreglo[i].x1=valx1;
        arreglo[i].x2=valx2;
    }
    }
    printf("%s|%s|%s|%s|%s|%s", "a","b", "c", "x1","x2","Sol\n");
    for (int i=0; i<2;i++){
    printf("%d|%d|%d|%.2f|%2f|%s\n",
    arreglo[i].a,
    arreglo[i].b,
    arreglo[i].c,
    arreglo[i].x1,
    arreglo[i].x2,
    arreglo[i].solucion);
    }
 
    }

void programa24 (){
    struct eccuadratica{ //creacion de estructura
        int a,b,c; //coeficientes de la ecuacion
        int discriminante; //resultado dentro de la raiz cuadrada
        float x1; //solucion 1
        float x2; //solucion 2
        char solucion[30]; //guarda si tiene solucion o no 
        };  
        int size; //variable que guardara valor ingresado por el usuario para la cantidad de arreglos
  
    printf("ingrese el tamano del arreglo:\n"); //pide al usuario ingresar numero de arreglos
    scanf("%d",&size); //lee y guarda el valor ingresado 
    
    struct eccuadratica arreglo[size];
    for(int i=0;i<size;i++){ //ciclo que se repetira dependiendo del numero ingresado
        printf("ingresa a:\n"); //pide valor de a
        scanf("%d",&arreglo[i].a); //guarda valor de a
        printf("ingresa b:\n"); //pide valor de b
        scanf("%d",&arreglo[i].b); //guarda valor de b
        printf("ingresa c:\n"); //pide valor de c
        scanf("%d",&arreglo[i].c); //guarda valor de c


    }
    
for(int i=0;i<size;i++){ //contador que hara las operaciones correspondientes dependiendo de size
    int discriminante=(arreglo[i].b*arreglo[i].b)-(4*arreglo[i].a*arreglo[i].c); //realiza la operacion dentro de la raiz
    if(discriminante<0){ //condicion si discriminante es menor a 0 no tiene solucion dentro de los reales
        strcpy(arreglo[i].solucion,"no tiene solucion");//imprime que no tiene solucion
    } else{ //si es mayor a 0, procede a realizar las demas operaciones
        int valx1=((-1)*arreglo[i].b + sqrt(discriminante))/2*arreglo[i].a;//operacion con el signo +
        int valx2=((-1)*arreglo[i].b-sqrt(discriminante))/2*arreglo[i].a;//operacion con el signo -
        strcpy(arreglo[i].solucion,"tiene solucion"); //imprime que tiene solucion
        arreglo[i].x1=valx1; //guarda solucion 1
        arreglo[i].x2=valx2; //guarda solucion 2

    }
}
printf("%s | %s | %s | %s | %s | %s\n","a","b","c","x1","x2","solucion");//imprime columnas para despues imprimir los resultados 
for(int i=0;i<size;i++){ //imprimira los datos segun el tamaño indicado
    printf(" %d | %d | %d | %.2f | %.2f | %s\n",
    arreglo[i].a,arreglo[i].b,arreglo[i].c,arreglo[i].x1,arreglo[i].x2,arreglo[i].solucion);//imprime los valores obtenidos
}           
    
       
       
            } //Se cierra el programa 

            void datos(int a, int b) {
                if (a > b ) {
                    printf("a es el mayor\n");
                } else if (b > a) {
                    printf("b es el mayor\n");
            }
            }
        
    void programa25(){

    
            int a, b;
            printf("Dame el valor de a");
            scanf("%d", &a);
            printf("Dame el valor de b");
            scanf("%d", &b);
            datos (a, b);
          
        
        
        }

        void datosp26(int a, int b, int c) {
            if (a > b && a > c) {
                printf("a es el mayor\n");
            } else if (b > a && b > c) {
                printf("b es el mayor\n");
            } else if (c > a && c > b) {
                printf("c es el mayor\n");
            }
        }

    void programa26 (){


    int a, b, c;
    printf("Dame el valor de a");
    scanf("%d", &a);
    printf("Dame el valor de b");
    scanf("%d", &b);
    printf("Dame el valor de c");
    scanf("%d", &c);
    datosp26 (a, b,c);



}
float cf(float c) {  
    return (c * 1.8) + 32;
}

void programa27 (){
    
            float resultado, c;
            printf("Dame el valor de Celsius: ");
            scanf("%f", &c);
            resultado = cf(c);
            printf("Equivalencia en Fahrenheit = %.2f\n", resultado);
            
        }
        float ck(float c) {  
            return c + 273.15;
        }

void programa28 (){

        float resultadop28, c;
        printf("Dame el valor en Celsius: ");
        scanf("%f", &c);
        resultadop28 = ck(c);
        printf("Equivalencia en Kelvin = %.2f\n", resultadop28);
        
     
    }
void llenarMatrizp29(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
printf("Nombre de la matriz: %s\n", nombre);
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
scanf("%d", &matriz[i][j]);
}
}
}

void saveMatrizp29(int filas, int columnas, int matriz[filas][columnas])
{
FILE *archivo = fopen("matriz.txt", "w");
if (archivo == NULL)
{
printf("Error al abrir el archivo.\n");
return;
}
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
fprintf(archivo, "%d ", matriz[i][j]);
}
fprintf(archivo, "\n");
}
fclose(archivo);
printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
}

void imprimirMatrizp29(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
printf("Nombre de la matriz: %s\n", nombre);
printf("Matriz ingresada:\n");
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
printf("%4d ", matriz[i][j]);
}
printf("\n");
}
}

void sumarMatrizp29(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int matrizr[filas][columnas])
{
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
}
}
}

void escalarMatrizAp29(int filas, int columnas, int matriz1[filas][columnas], int matriz_escA[filas][columnas])
{
int numero;
printf("Ingrese el número por el que desea multiplicar la matriz A:\n");
scanf("%d", &numero);
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
matriz_escA[i][j] = matriz1[i][j] * numero;
}
}
}

void escalarMatrizBp29(int filas, int columnas, int matriz2[filas][columnas], int matriz_escB[filas][columnas])
{
int numero2;
printf("Ingrese el número por el que desea multiplicar la matriz B:\n");
scanf("%d", &numero2);
for (int i = 0; i < filas; i++)
{
for (int j = 0; j < columnas; j++)
{
matriz_escB[i][j] = matriz2[i][j] * numero2;
}
}
}

int calculardeterminantep29(int MatrizA[3][3])
{
int MatrizExp[3][5], determinante = 0;
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
MatrizExp[i][j] = MatrizA[i][j];
}
for (j = 3; j < 5; j++)
{
MatrizExp[i][j] = MatrizA[i][j - 3];
}
}
for (int i = 0; i < 3; i++)
{
determinante += MatrizExp[0][i] * MatrizExp[1][i + 1] * MatrizExp[2][i + 2];
}

for (int i = 0; i < 3; i++)
{
determinante -= MatrizExp[0][i + 2] * MatrizExp[1][i + 1] * MatrizExp[2][i];
}

return determinante;
}


void programa29 (){


int filas, columnas;
printf("Ingrese el número de filas: ");
scanf("%d", &filas);
printf("Ingrese el número de columnas: ");
scanf("%d", &columnas);

int matriz_a[filas][columnas];
int matriz_b[filas][columnas];
int matriz_r[filas][columnas];
int matriz_escA[filas][columnas];
int matriz_escB[filas][columnas];

llenarMatrizp29("Matriz A", filas, columnas, matriz_a);
llenarMatrizp29("Matriz B", filas, columnas, matriz_b);

imprimirMatrizp29("Matriz A", filas, columnas, matriz_a);
imprimirMatrizp29("Matriz B", filas, columnas, matriz_b);

sumarMatrizp29(filas, columnas, matriz_a, matriz_b, matriz_r);
imprimirMatrizp29("Suma A+B", filas, columnas, matriz_r);

escalarMatrizAp29(filas, columnas, matriz_a, matriz_escA);
imprimirMatrizp29("Matriz A multiplicada por el número ingresado:", filas, columnas, matriz_escA);

escalarMatrizBp29(filas, columnas, matriz_b, matriz_escB);
imprimirMatrizp29("Matriz B multiplicada por el número ingresado:", filas, columnas, matriz_escB);

saveMatrizp29(filas, columnas, matriz_r);

if (filas == 3 && columnas == 3)
{
int determinante = calculardeterminantep29(matriz_a);
printf("El det de la matriz es: %d\n", determinante);
}
else
{
printf("No se puede calcular el determinante ");
}


}
void llenarMatrizp30(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {

    printf("Nombre de la matriz: %s\n", nombre);
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
   
    scanf("%d", &matriz[i][j]);
   
    }
   
    }
   
   }
   
   
   
   void saveMatrizp30(int filas, int columnas, int matriz[filas][columnas]) {
   
    FILE *archivo = fopen("../matriz.txt", "w");
   
    if (archivo == NULL) {
   
    printf("Error al abrir el archivo.\n");
   
    return;
   
    }
   
    
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    fprintf(archivo, "%d ", matriz[i][j]);
   
    }
   
    fprintf(archivo, "\n");
   
    }
   
    
   
    fclose(archivo);
   
    printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
   
   }
   
   
   
   void imprimirMatrizp30(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
   
    printf("Nombre de la matriz: %s\n", nombre);
   
    printf("Matriz ingresada:\n");
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    printf("%4d ", matriz[i][j]);
   
    }
   
    printf("\n");
   
    }
   
   }
   
   
   
   void sumarMatrizp30(int filas, int columnas, 
   
    int matriz1[filas][columnas], int matriz2[filas][columnas], 
   
    int matrizr[filas][columnas]){
   
    for (int i = 0 ; i < filas; i++){
   
    for (int j = 0 ; j < columnas; j++){
   
    matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
   
    }
   
    }
   
   }
   
   
   void escalarMatrizAp30(int filas, int columnas, int num1,
   
       int matriz1[filas][columnas],
      
       int matriz_escA[filas][columnas]){
   
       printf("ingresa el numero por el que desea multiplicar la matriz A:\n");
       scanf("%d",&num1);
      
       for (int i = 0 ; i < filas; i++){
      
       for (int j = 0 ; j < columnas; j++){
      
       matriz_escA[i][j] = matriz1[i][j] *num1;
      
       }
      
       }
      
      }
      void escalarMatrizBp30(int filas, int columnas, int num2,
   
       int matriz2[filas][columnas],
      
       int matriz_escB[filas][columnas]){
   
       printf("ingresa el numero por el que desea multiplicar la matriz B:\n");
       scanf("%d",&num2);
   
       
      
       for (int i = 0 ; i < filas; i++){
      
       for (int j = 0 ; j < columnas; j++){
      
       matriz_escB[i][j] = matriz2[i][j] *num2;
      
       }
      
       }
      
      }


void programa30 (){
    int filas, columnas,num1,num2;


 printf("Ingrese el numero de filas: ");

 scanf("%d", &filas);

 printf("Ingrese el numero de columnas: ");

 scanf("%d", &columnas);



 

 int matriz_a[filas][columnas];

 int matriz_b[filas][columnas];

 int matriz_r[filas][columnas];

 int matriz_escalarA[filas][columnas];

 int matriz_escalarB[filas][columnas];



 llenarMatrizp30("Matriz A", filas, columnas, matriz_a);

 llenarMatrizp30("Matriz B", filas, columnas, matriz_b);

 imprimirMatrizp30("Matriz A", filas, columnas, matriz_a);

 imprimirMatrizp30("MAtriz B", filas, columnas, matriz_b);

 sumarMatrizp30(filas, columnas, matriz_a, matriz_b, matriz_r);

 imprimirMatrizp30("SUMA A-B", filas, columnas, matriz_r);

 escalarMatrizAp30(filas,columnas,num1, matriz_a,matriz_escalarA);

 imprimirMatrizp30("Matriz A multplicada por el numero ingresado:",filas,columnas,matriz_escalarA);

 escalarMatrizBp30(filas,columnas,num2,matriz_b,matriz_escalarB);

 imprimirMatrizp30("matriz B multiplicada por el numero ingresado:",filas,columnas,matriz_escalarB);



 saveMatrizp30(filas, columnas, matriz_r); 


    
}
float pesoadolar(float pesos) {
    return pesos / dolar;
}

float dolarapeso(float dolares) {
    return dolares * dolar;
}

float pesoaeuro(float pesos) {
    return pesos / euro;
}
float euroapeso (float euros) {
    return euros*euro;
}
float pesoalibra(float pesos) {
    return pesos / libreest;
}
float libraapeso(float libras) {
    return libras* libreest;
}

void programa31 (){
    int opcion;
    float cantidad, resultado;
    printf("Seleccione una opción de conversion:\n");
    printf("1. Peso a Dolar\n");
    printf("2. Dolar a Peso\n");
    printf("3. Peso a Euro\n");
    printf("4. Euro a Peso\n");
    printf("5. Peso a Libra Esterlina\n");
    printf("6. Libra Esterlina a Peso\n");
    scanf("%d", &opcion);

    printf("Ingrese la cantidad: ");
    scanf("%f", &cantidad);

    switch(opcion) {
        case 1:
            resultado = pesoadolar(cantidad);
            printf("Los pesos a dolares son: %.2f\n", resultado);
            break;
        case 2:
            resultado = dolarapeso(cantidad);
            printf("Los dolares a pesos son: %.2f\n", resultado);
            break;
        case 3:
            resultado = pesoaeuro(cantidad);
            printf("Los pesos a euros: %.2f\n", resultado);
            break;
        case 4:
            resultado = euroapeso(cantidad);
            printf("Los euros a pesos son : %.2f\n", resultado);
            break;
        case 5:
            resultado = pesoalibra(cantidad);
            printf("Los pesos a libras son : %.2f\n", resultado);
            break;
        case 6:
            resultado = libraapeso(cantidad);
            printf("Las libras a pesos son: %.2f\n", resultado);
            break;
        default:
            printf("No ha seleccionado una opcion valida");
            break;
    }

    
}
struct Ecuadratica {
    int a;
    int b;
    int c;
    int discriminante;
    float x1;
    float x2;
    char solucion[30];
};

struct Ecuadratica leerCoeficientes() {
    struct Ecuadratica ec;
    printf("Dame valor de a:\n");
    scanf("%d", &ec.a);
    printf("Dame valor de b:\n");
    scanf("%d", &ec.b);
    printf("Dame valor de c:\n");
    scanf("%d", &ec.c);
    return ec;
}

struct Ecuadratica resolverEcuacion(struct Ecuadratica ec) {
    ec.discriminante = (ec.b * ec.b) - (4 * ec.a * ec.c);

    if (ec.discriminante < 0) {
        strcpy(ec.solucion, "No tiene solucion");
        ec.x1 = 0;
        ec.x2 = 0;
    } else {
        ec.x1 = ((-1.0 * ec.b) + sqrt(ec.discriminante)) / (2 * ec.a);
        ec.x2 = ((-1.0 * ec.b) - sqrt(ec.discriminante)) / (2 * ec.a);
        strcpy(ec.solucion, "Tiene solucion");
    }

    return ec;
}

void imprimirEncabezado() {
    printf("a|b|c|x1|x2|Sol\n");
}

void imprimirResultados(struct Ecuadratica ec) {
    printf("%d|%d|%d|%.2f|%.2f|%s\n", ec.a, ec.b, ec.c, ec.x1, ec.x2, ec.solucion);
}

void programa32 (){


    int size;
    printf("Ingrese el tamaño del arreglo:\n");
    scanf("%d", &size);

    struct Ecuadratica arreglo[size];

    for (int i = 0; i < size; i++) {
        arreglo[i] = leerCoeficientes();
        arreglo[i] = resolverEcuacion(arreglo[i]);
    }

    imprimirEncabezado();

    for (int i = 0; i < size; i++) {
        imprimirResultados(arreglo[i]);
    }

}
void numero(float a) {
    if (a > 0) {
        printf("Es un número positivo\n");
    } else if (a < 0) {
        printf("Es un número negativo\n");
    }
}

void programa33(){
    

    float a; 
    printf("Dame un numero");
    scanf ("%f", &a);
    numero(a);

}
void func1 (void){
    printf("segunda funcion");
    return;
}
void func2 (void){
    printf("tercera funcion");
    return;
}

void programa34 (){
    printf("primera funcion llamada main()");
    func1(); //segunda funcion llamada
    func2(); //tercera funcion llamada
    printf("main se termina");
   

}
int suma(int a, int b){
    return a+b;
}
int resta(int a, int b){
    int result=a -b;
    return result; 
}
int multiplicacion (int a){
    return a*a;
}
float dividir (int a, int b){
    return a/b; 
}
void imprimir(int a, int b, int c, float d){
printf("\nResultados:\n Suma:%d\n Resta:%d\n Multiplicación: %d\n División:%.2f\n ", a, b,c, d);
}
void programa35(){
    int opc1=suma (3, 2);
    int opc2=resta(5, 3);
    int opc3= multiplicacion(3);
    float opc4= dividir(5, 3);
    imprimir (opc1, opc2, opc3, opc4);
    
}


union dato {
    float entero;
    float flotante;
};

float areacuadrado(int l){
    return l *l;
}
float arearectangulo (int b, int h){
    return b*h;
}
float areatriangulo (int b, int h){
    return (b*h)/2;;
}
float areacirculo (int r){
    float result= PI * ( r * r );
    return result; 
}
float arearombo(int d, int D){
    return (D*d)/2;
}
float volumencubo(int a){
    return a*a*a;
}
float volumenprisma(int a, int b, int h){
    return a*b*h;
}
float volumencilindro(int r, int ladoaltura){
    float result= PI*(r*r)*ladoaltura;
    return result;
}
float volumenesfera( int r){
    float result= (4*PI*(r*r*r))/3; 
    return result;
}
float volumencono ( int r, int ladoh){
    float result= (PI*(r*r*r)*ladoh)/3; 
    return result; 
}
void programa36(){
    union dato resultado;
    int opcioncita, l, b, h, r, D, d, a, ladoaltura, ladoh; 
    printf("%s\n", "Seleccione una opción:");
    printf("%s\n", "1.-Area del cuadrado");
    printf("%s\n", "2.-Area del rectangulo");
    printf("%s\n", "3.-Area del triangulo");
    printf("%s\n", "4.-Area del circulo");
    printf("%s\n", "5.-Area del rombo");
    printf("%s\n", "6.-Volumen del cubo");
    printf("%s\n", "7.-Volumen del prisma");
    printf("%s\n", "8.-Volumen del cilindro ");
    printf("%s\n", "9.-Volumen del esfera");
    printf("%s\n", "10.-Volumen del cono");


    scanf("%d", &opcioncita);
    switch(opcioncita){
        case 1:
            printf ("%s\n", "Ha seleccionado Area del cuadrado");
            printf ("Dame el valor de l");
            scanf ("%d", &l);
            resultado.entero= areacuadrado(l); 
            printf("AREA=%.2f", resultado.entero);
            break; 


        case 2:
            printf ("%s\n", "Ha seleccionado Area del rectangulo");
             int b, h;
            printf ("Dame el valor de b");
            scanf ("%d", &b);
            printf ("Dame el valor de h");
            scanf ("%d", &h);
            resultado.entero= arearectangulo(b, h);
            printf("AREA=%.2f", resultado.entero);
            break; 


        case 3:
            printf ("%s\n", "Ha seleccionado Area del triangulo");
            printf ("Dame el valor de b");
            scanf ("%d", &b);
            printf ("Dame el valor de h");
            scanf ("%d", &h);
            resultado.entero = areatriangulo(b, h);
            printf("AREA=%.2f", resultado.entero);
            break; 

         case 4:
            printf ("%s\n", "Ha seleccionado Area del circulo");
            printf ("Dame el valor de r");
            scanf ("%d", &r);
            resultado.entero= areacirculo(r);
            printf("AREA=%.2f", resultado.entero);
            break; 


        case 5:
            printf ("%s\n", "Ha seleccionado Area del rombo");
            printf ("Dame el valor de diagonal mayor");
            scanf ("%d", &D);
            printf ("Dame el valor de diagonal menor");
            scanf ("%d", &d);
            resultado.entero = arearombo(D, d);
            printf("AREA=%.2f", resultado.entero);
            break; 

        case 6:
            printf ("%s\n", "Ha seleccionado Volumen del cubo");
            printf ("Dame el valor de a");
            scanf ("%d", &a);
            resultado.flotante = volumencubo(a);
            printf("AREA=%.2f", resultado.flotante);

            break; 


        case 7:
            printf ("%s\n", "Ha seleccionado Volumen del prisma");
            printf ("Dame el valor de a");
            scanf ("%d", &a);
            printf ("Dame el valor de b");
            scanf ("%d", &b);
            printf ("Dame el valor de h");
            scanf ("%d", &h);
            resultado.flotante = volumenprisma(a, b,h);
            printf("AREA=%.2f", resultado.flotante);
            break; 


        case 8:
            printf ("%s\n", "Ha seleccionado Volumen del cilindro");
            printf("Dame el valor de r");
            scanf ("%d", &r);
            printf("Dame valor de la altura de un lado");
            scanf ("%d", &ladoaltura);
            resultado.flotante= volumencilindro(r, ladoaltura);
            printf("AREA=%.2f", resultado.flotante);
            break; 


        case 9:
            printf ("%s\n", "Ha seleccionado Volumen de esfera");
            printf("Dame el valor de r");
            scanf ("%d", &r);
            resultado.flotante= volumenesfera(r);
            printf("AREA=%.2f", resultado.flotante);
            break; 
        

        case 10:
            printf ("%s\n", "Ha seleccionado Volumen de cono");
            printf("Dame el valor de r");
            scanf ("%d", &r);
            printf("Dame el valor de lado h");
            scanf ("%d", &ladoh);
            resultado.flotante= volumencono(r,ladoh);
            printf("AREA=%.2f", resultado.entero);
            break; 


        default:
        printf("%s\n", "No ha seleccionado una opción válida");
        break; 
    }

}

int exponencial(int base, int exponente){
    int resultado=base;
    for(int i=1; i<exponente; i++){
        resultado*=base;   
    }
    return resultado;
    }

void programa37 (){
    int num,exp,result;
    printf("ingresa numero:\n");
    scanf("%d",&num);
    printf("ingresa exponente:\n");
    scanf("%d",&exp);
    result=exponencial(num,exp);
   
    printf("resultado de %d^%d es: %d",num,exp,result);


}

float fc(float f) {  
    return (f - 32) / 1.8;
}

void programa38(){
    float resultado, f;
    printf("Dame el valor en Fahrenheit: ");
    scanf("%f", &f);
    resultado = fc(f);
    printf("Equivalencia en Celsius = %.2f\n", resultado);
    

}
void seriedenum(int inicio, int fin) {
    int suma = 0;  
    for (int i = inicio; i <= fin; i++) {
        suma += i;  
    }
    printf("La suma de los números en el  intervalo es: %d", suma);
}

void programa39(){
    int inicio, fin;
    printf("Ingrese el numero inicial del intervalo: ");
    scanf("%d", &inicio);
    printf("Ingrese el numero final del intervalo: ");
    scanf("%d", &fin);
    seriedenum(inicio, fin);

}
float kf(float k) {  
    return ((k - 273.15) * 1.8) + 32;
}

void programa40(){
    float resultado, k;
    printf("Dame el valor en Kelvin: ");
    scanf("%f", &k);
    resultado = kf(k);
    printf("Equivalencia en Fahrenheit = %.2f\n", resultado);

}

void palabras(int opcion41){
    switch(opcion41){
        case 1:
        printf("hola");
        break;
        case 2:
        printf("bonjour");
        break;
        case 3:
        printf("hello");
        break;
        case 4:
        printf("konichiwa");
        break;
        default:
        printf("elige una opcion correcta");
        break;
    }
}
void programa41(){
    int opcion41;
    printf("selecciona un numero: 1, 2, 3, 4\n");
    scanf("%d",&opcion41);
    palabras(opcion41);
}
void tablamulti(int a) {
    for (int i = 1; i <= 10; i++) {
            int resultado = a * i;
            printf("%d x %d = %d\n", a, i, resultado);
        }
    }
    
void programa42 (){
    int a;
    printf("Introduce un número para ver su tabla de multiplicar: ");
    scanf("%d", &a);
    tablamulti(a);

}

void programa43(){
    int opcc;
    float resultado, c, f, k;

    printf("Seleccione una opción:\n");
    printf("1.- De Celsius a Fahrenheit\n");
    printf("2.- De Fahrenheit a Celsius\n");
    printf("3.- De Kelvin a Fahrenheit\n");
    printf("4.- De Celsius a Kelvin\n");
    
    scanf("%d", &opcc);

    switch(opcc) {
        case 1:
            printf("Dame el valor de Celsius: ");
            scanf("%f", &c);
            resultado = cf(c); 
            printf("Fahrenheit = %.2f\n", resultado);
            break;

        case 2:
            printf("Dame el valor de Fahrenheit: ");
            scanf("%f", &f);
            resultado = fc(f); 
            printf("Celsius = %.2f\n", resultado);
            break;

        case 3:
            printf("Dame el valor de Kelvin: ");
            scanf("%f", &k);
            resultado = kf(k); 
            printf("Fahrenheit = %.2f\n", resultado);
            break;

        case 4:
            printf("Dame el valor de Celsius: ");
            scanf("%f", &c);
            resultado = ck(c); 
            printf("Kelvin = %.2f\n", resultado);
            break;

    default:
    printf("%s\n", "No ha seleccionado una opción válida");
    break; 
    }
}

void programa44(){
    printf("\033[2j"); //Limpia pantalla
    gotoxy(10,5);
    printf("Hola desde(10, 5)!");
}

 
// Función para cambiar el color
void setColores(const char* color) {
    printf("%s", color);
}

void programa45 (){char nombre[50];
    int edad;
 
    printf("\033[2J"); // Limpia la pantalla
    setColores("\033[7;34m");
 
    gotoxy(10, 5);
    printf("Ingrese su nombre: ");
    gotoxy(30, 5);
    setColores("\033[7;35m");
    scanf("%s", nombre);
 
    setColores("\033[7;34m");
    gotoxy(10, 7);
    printf("Ingrese su edad: ");
    gotoxy(30, 7);
    setColores("\033[7;35m");
    scanf("%d", &edad);
 
    gotoxy(10, 9);
    printf("Hola %s, tienes %d años.\n", nombre, edad);
 

}
void programa46 (){
    int matriz [FILAS1][COLUMNAS1]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    
    };
    printf("Recorriendo la matriz:\n");
    for (int i=0; i<FILAS1; i++){
        for(int j=0;j<COLUMNAS1; j++){
            printf("%d", matriz [i][j]);
        
        }
        printf ("\n");
    }

}
void programa47(){
    char matriz[FILAS1][COLUMNAS1][50];
for (int i=0; i<FILAS1; i++){
    for(int j=0;j<COLUMNAS1; j++){
        printf("%s", "Dame una palabra: ");
        scanf("%s", matriz[i][j]);
    
    }
}
printf ("\n");
for (int i=0; i<FILAS1; i++){
    for(int j=0; j<COLUMNAS1; j++){
    printf("%20s\t|", matriz[i][j]);
    }
 printf ("\n");
}

}
void programa48 (){

struct operaciones{
    int suma;
    int resta;
    int multiplicacion;
    float division; 
};

int matriz [FILASp48][COLUMNASp48];
struct operaciones resultado[FILASp48];
for (int i=0; i<FILASp48; i++){
    for(int j=0;j<COLUMNASp48; j++){
         printf("Dame los numeros para hacer la operacion");
         scanf("%d", &matriz[i][j]);
    }
}
for (int i=0; i<FILASp48; i++){
    int num1=matriz[i][0];
    int num2=matriz[i][1];

    resultado[i].suma=num1+num2;
    resultado[i].resta=num1-num2;
    resultado [i].multiplicacion=num1*num2;
    resultado[i].division=(float)num1/num2;
    
}
printf("%-15s|%-15s|%-15s|%-15s|%-15s|%-15s", "Val1","Val2","Suma","Resta", "Multiplicacion", "Division\n");
printf("---------------------------------------------------------------------------------\n");


for (int i=0; i<FILASp48; i++){
    printf ("%-15d|%-15d|%-15d|%-15d|%-15d|%-15.2f\n",
    matriz[i][0],
    matriz[i][1],
    resultado[i].suma,
    resultado[i].resta,
    resultado[i].multiplicacion,
    resultado[i].division);
}
}




void llenarMatriz49(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {

    printf("Nombre de la matriz: %s\n", nombre);
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
   
    scanf("%d", &matriz[i][j]);
   
    }
   
    }
   
   }
   
   
   
   void saveMatriz49(int filas, int columnas, int matriz[filas][columnas]) {
   
    FILE *archivo = fopen("../matriz.txt", "w");
   
    if (archivo == NULL) {
   
    printf("Error al abrir el archivo.\n");
   
    return;
   
    }
   
    
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    fprintf(archivo, "%d ", matriz[i][j]);
   
    }
   
    fprintf(archivo, "\n");
   
    }
   
    
   
    fclose(archivo);
   
    printf("Matriz guardada en 'matriz.txt' exitosamente.\n");
   
   }
   
   
   
   void imprimirMatriz49(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
   
    printf("Nombre de la matriz: %s\n", nombre);
   
    printf("Matriz ingresada:\n");
   
    for (int i = 0; i < filas; i++) {
   
    for (int j = 0; j < columnas; j++) {
   
    printf("%4d ", matriz[i][j]);
   
    }
   
    printf("\n");
   
    }
   
   }
   
   
   
   void sumarMatriz49(int filas, int columnas, 
   
    int matriz1[filas][columnas], int matriz2[filas][columnas], 
   
    int matrizr[filas][columnas]){
   
    for (int i = 0 ; i < filas; i++){
   
    for (int j = 0 ; j < columnas; j++){
   
    matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
   
    }
   
    }
   
   }
   

void programa49 (){
    int filas, columnas;

 

 printf("Ingrese el número de filas: ");

 scanf("%d", &filas);

 printf("Ingrese el número de columnas: ");

 scanf("%d", &columnas);

 

 int matriz_a[filas][columnas];

 int matriz_b[filas][columnas];

 int matriz_r[filas][columnas];



 llenarMatriz49("Matriz A", filas, columnas, matriz_a);

 llenarMatriz49("Matriz B", filas, columnas, matriz_b);

 imprimirMatriz49("Matriz A", filas, columnas, matriz_a);

 imprimirMatriz49("MAtriz B", filas, columnas, matriz_b);

 sumarMatriz49(filas, columnas, matriz_a, matriz_b, matriz_r);

 imprimirMatriz49("SUMA A-B", filas, columnas, matriz_b);

 saveMatriz49(filas, columnas, matriz_r); 



}
#define FILAS50 6
#define COLUMNAS50 6

void programa50(){
    int matriz [FILAS50][COLUMNAS50]={
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
        {31,32,33,34,35,36},
    
    };
    printf("Matriz con numeros, en donde en las posiciones impares se imprime:\n");
    for (int i=0; i<FILAS50; i++){
        for(int j=0;j<COLUMNAS50; j++){
            if(j%2==1){
            printf("%-15s","#");
        } else{
            printf("|%-15d|", matriz [i][j]);
        }
         
    }
    
      printf ("\n");
    }

}



#define FILAS51 3
#define COLUMNAS51 2  


void programa51(){
    struct Carro {
        char marca[50];
        char modelo[50];
        int anio;
        char color[50];
        float precio;
    };
    char matriz[FILAS51][COLUMNAS51][50];  
    struct Carro datos[FILAS51];

    for (int i = 0; i < FILAS51; i++) {
        printf("Ingrese los datos del carro %d\n", i + 1);

        printf("Marca: ");
        scanf("%s", matriz[i][0]);  

        printf("Modelo: ");
        scanf("%s", matriz[i][1]); 

        printf("Anio: ");
        scanf("%d", &datos[i].anio);

        printf("Color: ");
        scanf("%s", datos[i].color);

        printf("Precio: ");
        scanf("%f", &datos[i].precio);
    }

    printf("\n%-15s| %-15s| %-15s| %-15s| %-15s\n", "Marca", "Modelo", "Anio", "Color", "Precio");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < FILAS51; i++) {
        printf("%-15s| %-15s| %-15d| %-15s| %-15.2f\n", 
               matriz[i][0], matriz[i][1], 
               datos[i].anio, 
               datos[i].color, 
               datos[i].precio);
    }
    

}
void programa52 (){
    int opcmenuconcolor, num1, num2;
        float result;
    printf("\033[2J"); // Limpia la pantalla
    
    setColor("\033[7;32m");
    gotoxy(10,5);
    printf("Calculadora Basica con gotoxy y swithc-case: ");

    setColor("\033[4;30m");
    gotoxy(10,6);
    printf("Menú de operaciones: ");


    setColor("\033[7;31m");
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
    printf("Multiplciación: ");


    setColor("\033[7;35m");
    gotoxy(30,10);
    printf("4.-: ");

    setColor("\033[0m");
    gotoxy(31,10);
    printf("División: ");

    setColor("\033[0m");
    gotoxy(30,11);
    printf("Seleccione una opcion: ");

    setColor("\033[7;33m");
    gotoxy(55,11);
    printf("(1-4)");

scanf("%d", &opcmenuconcolor);
switch(opcmenuconcolor){
        case 1: 
            printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado suma");
            printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1+num2; 
            setColor("\033[7;31m");
            gotoxy(30,7);
            printf("Tu resultado es: %.2f\n", result);
            
            break; 
        case 2:
            printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado resta");
            printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1-num2;
            setColor("\033[7;33m");
            gotoxy(30,8);
            printf("Tu resultado es:%.2f\n", result);


            break;
        case 3:
             printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado multiplicación");
             printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1*num2;
            setColor("\033[7;36m");
            gotoxy(30,9);
            printf("Tu resultado es:%.2f\n", result);
            break;  



        case 4:
        printf("\033[2J"); // Limpia la pantalla
        setColor("\033[0m");
        printf ("%s\n", "Ha seleccionado división");
        printf("Dame el primer número"); 
        scanf("%d", &num1);
        printf("Dame el segundo número"); 
        scanf("%d", &num2);
        if (num2==0){
        setColor("\033[7;35m");
        gotoxy(30,10);
            printf("No se puede hacer la operacion\n");
        
        }else {
        result=num1/num2;
        setColor("\033[7;35m");
        gotoxy(30,10);
        printf("Tu resultado es: %.2f\n", result);
        }

         break; 
        default:
        printf("%s\n", "No ha seleccionado una opción válida");
        break; 
    }

}

#define FILAS53 2
#define COLUMNAS53 2

void programa53 (){

typedef struct {
    char nombre[50];
    int edad;
} Persona;

typedef struct {
    char nomproducto[50];
    float precio;
} Producto;

typedef union {
    Persona persona;
    Producto producto;
} Dato;

typedef struct {
    Dato valor;
    int tipo;
} Celda;

Celda matriz[FILAS53][COLUMNAS53];

for (int i = 0; i < FILAS53; i++) {
    for (int j = 0; j < COLUMNAS53; j++) {
            printf("Selecciona opción (1 para persona, 2 para producto) [%d][%d]: ", i, j);
            int opc;
            scanf("%d", &opc);

switch (opc) {
case 1:
    printf("Ingrese el nombre de la persona: ");
    scanf("%s", matriz[i][j].valor.persona.nombre);

    printf("Ingrese la edad de la persona: ");
    scanf("%d", &matriz[i][j].valor.persona.edad);

    matriz[i][j].tipo = 1; 
    break;

case 2:
    printf("Ingrese el nombre del producto: ");
    scanf("%s", matriz[i][j].valor.producto.nomproducto);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &matriz[i][j].valor.producto.precio);

    matriz[i][j].tipo = 2; 
    break;

    default:
    printf("Opción inválida\n");
    break;
    }}
    }

    for (int i = 0; i < FILAS53; i++) {
     for (int j = 0; j < COLUMNAS53; j++) {
    printf("Celda [%d][%d]: ", i, j);
        
        if (matriz[i][j].tipo == 1) {
        printf("Persona - Nombre: %s, Edad: %d\n",
            matriz[i][j].valor.persona.nombre,
            matriz[i][j].valor.persona.edad);
            } else if (matriz[i][j].tipo == 2) {
             printf("Producto - Nombre: %s, Precio: %.2f\n",
            matriz[i][j].valor.producto.nomproducto,
            matriz[i][j].valor.producto.precio);
            }
        }
    }
}




void programa54(){
    struct Tabla {
        int valor1;
        int valor2;
        int resultado;
    };
    struct Tabla arreglo54[3] = {
        {1, 3, 0},
        {2, 3, 0},
        {3, 3, 0},
    };

    for (int i = 0; i < 3; i++) {
    arreglo54[i].resultado = arreglo54[i].valor1 * arreglo54[i].valor2;
    }

    for (int i = 0; i < 3; i++) {
    printf("%d x %d = %d\n", arreglo54[i].valor1, arreglo54[i].valor2, arreglo54[i].resultado);
    }


}
void programa55(){
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
}




void llenarmatriz56(int val, char matriz[val][val]) {
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < val; j++) {
            printf("Ingrese el caracter para [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]); 
        }
    }
}

void imprimirmatriz56(int val, char matriz[val][val]) {
    printf("\nMatriz de caracteres %dx%d:\n", val, val);
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < val; j++) {
            printf("%c\t", matriz[i][j]);
        }
        printf("\n");
    }
}



void almacenarenarreglo56(int val, char matriz[val][val], char arreglo[]) {
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < val; j++) {
            arreglo[i * val + j] = matriz[i][j]; 
        }
    }
}



void imprimirarreglo56(int val, char arreglo[]) {
    printf("\nArreglo con los caracteres:\n");
    for (int i = 0; i < val * val; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}



void programa56 (){
    int numere;
    printf("Ingrese un numero para verificar su raiz cuadrada: ");
    scanf("%d", &numere);
    
    bool flag = false;
    int raiz = 0;
    
    for(int i = 0; i <= numere; i++) {
        if(i * i == numere) {
            flag = true;
            raiz = i;
            break;
        }
    }
    

    char matriz[raiz][raiz];
    char arreglo[raiz * raiz]; 
    
    llenarmatriz56(raiz, matriz);
    imprimirmatriz56(raiz, matriz);
    
    almacenarenarreglo56(raiz, matriz, arreglo);
    imprimirarreglo56(raiz, arreglo);
 
}

void llenarmatriz57( int filas, int columnas, int matriz[filas][columnas]) {

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirmatriz57(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz dada:\n");

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}


void transpuesta57(int filas, int columnas, int matriz[filas][columnas], int matriztrans[columnas][filas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriztrans[j][i] = matriz[i][j]; 
        }
    }
}


void programa57 (){
    int filas, columnas;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];
    int matriztrans[columnas][filas];  

    llenarmatriz57( filas, columnas, matriz);

    imprimirmatriz57("Matriz", filas, columnas, matriz);

    transpuesta57(filas, columnas, matriz, matriztrans);

    imprimirmatriz57("Matriz transpuesta", columnas, filas, matriztrans);

}


void llenarmatriz58(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void llenarvector58(char *nombre, int tamaño, int vector[tamaño])
{
    printf("Nombre del vector: %s\n", nombre);
    for (int i = 0; i < tamaño; i++)
    {
        printf("Ingrese el valor para la posición [%d]: ", i);
        scanf("%d", &vector[i]);
    }
}

void imprimirmatriz58(char *nombre, int filas, int columnas, int matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirvector58(char *nombre, int tamaño, int vector[tamaño])
{
    printf("Nombre del vector: %s\n", nombre);
    printf("Vector ingresado:\n");
    for (int i = 0; i < tamaño; i++)
    {
        printf("%4d", vector[i]);
    }
    printf("\n");
}

void multiplicarmatrizporvector58(int filas, int columnas, int matriz[filas][columnas], int vector[columnas], int resultado[filas])
{
    for (int i = 0; i < filas; i++)
    {
        resultado[i] = 0;
        for (int j = 0; j < columnas; j++)
        {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}



void programa58 (){
    int filas, columnas;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    int matriz_a[filas][columnas];
    int vector[columnas];
    int resultado[filas];

    llenarmatriz58("Matriz A", filas, columnas, matriz_a);
    llenarvector58("Vector", columnas, vector);

    imprimirmatriz58("Matriz A", filas, columnas, matriz_a);
    imprimirvector58("Vector", columnas, vector);

    multiplicarmatrizporvector58(filas, columnas, matriz_a, vector, resultado);

    printf("Resultado de la multiplicación de la matriz A por el vector:\n");
    for (int i = 0; i < filas; i++)
    {
        printf("%d ", resultado[i]);
    }
    printf("\n");


}

void llenarmatriz59(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void imprimirmatriz59(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarmatriz59(int filasa, int columnasa, int columnasb, int matriza[filasa][columnasa], int matrizb[columnasb][columnasb], int matrizR[filasa][columnasb]) {

    for (int i = 0; i < filasa; i++) {
        for (int j = 0; j < columnasb; j++) {
            matrizR[i][j] = 0; 
            for (int k = 0; k < columnasa; k++) { 
                matrizR[i][j] += matriza[i][k] * matrizb[k][j];
            }
        }
    }
}

void programa59 (){
    int filasa, columnasa, filasb, columnasb;

    printf("Ingrese el número de filas de la matriz A: ");
    scanf("%d", &filasa);
    printf("Ingrese el número de columnas de la matriz A: ");
    scanf("%d", &columnasa);


    printf("Ingrese el número de filas de la matriz B: ");
    scanf("%d", &filasb);
    printf("Ingrese el número de columnas de la matriz B: ");
    scanf("%d", &columnasb);

    int matriza[filasa][columnasa];
    int matrizb[filasb][columnasb];
    int matrizresult[filasa][columnasb]; 

    llenarmatriz59("Matriz A", filasa, columnasa, matriza);
    llenarmatriz59("Matriz B", filasb, columnasb, matrizb);



    imprimirmatriz59("Matriz A", filasa, columnasa, matriza);
    imprimirmatriz59("Matriz B", filasb, columnasb, matrizb);



    multiplicarmatriz59(filasa, columnasa, columnasb, matriza, matrizb, matrizresult);
    imprimirmatriz59("Resultado de A * B", filasa, columnasb, matrizresult);

}

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void llenarmatriz60(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese el valor para la posición [%d][%d] (numerador y denominador): ", i, j);
            scanf("%d%d", &matriz[i][j].numerador, &matriz[i][j].denominador);
        }
    }
}

void imprimirmatriz60(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas])
{
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d/%-4d ", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void multiplicarmatrices60(int filas, int columnas, Fraccion matriz1[filas][columnas], Fraccion matriz2[filas][columnas], Fraccion matrizr[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizr[i][j].numerador = matriz1[i][j].numerador * matriz2[i][j].numerador;
            matrizr[i][j].denominador = matriz1[i][j].denominador * matriz2[i][j].denominador;
        }
    }
}


void programa60 (){
    int filas, columnas;
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    Fraccion matriz_a[filas][columnas];
    Fraccion matriz_b[filas][columnas];  
    Fraccion matriz_r[filas][columnas];

    llenarmatriz60("Matriz A", filas, columnas, matriz_a);
    llenarmatriz60("Matriz B", filas, columnas, matriz_b);

    imprimirmatriz60("Matriz A", filas, columnas, matriz_a);
    imprimirmatriz60("Matriz B", filas, columnas, matriz_b);

    multiplicarmatrices60(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz60("Resultado A * B", filas, columnas, matriz_r);

}


typedef struct {
    int numerador;
    int denominador;
} fraccion;

fraccion sumar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

fraccion restar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

fraccion multiplicar(fraccion a, fraccion b) {
    fraccion resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

void multiplicarporescalar61(int filas, int columnas, fraccion matriz[filas][columnas], fraccion escalar, fraccion resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = multiplicar(matriz[i][j], escalar);
        }
    }
}

void sumarmatrices61(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizR[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizR[i][j] = sumar(matriz1[i][j], matriz2[i][j]);
        }
    }
}

void restarmatrices61(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizresult[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizresult[i][j] = restar(matriz1[i][j], matriz2[i][j]);
        }
    }
}

void multiplicarmatrices61(int filas, int columnas, fraccion matriz1[filas][columnas], fraccion matriz2[filas][columnas], fraccion matrizR[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizR[i][j].numerador = 0;
            matrizR[i][j].denominador = 1;
            for (int k = 0; k < columnas; k++) {
                matrizR[i][j] = sumar(matrizR[i][j], multiplicar(matriz1[i][k], matriz2[k][j]));
            }
        }
    }
}

void imprimirmatriz61(char *nombre, int filas, int columnas, fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d/%-4d ", matriz[i][j].numerador, matriz[i][j].denominador);
        }
        printf("\n");
    }
}

void llenarmatriz61(char *nombre, int filas, int columnas, fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d] (numerador y denominador): ", i, j);
            scanf("%d%d", &matriz[i][j].numerador, &matriz[i][j].denominador);
        }
    }
}

void programa61(){
    int filas, columnas;
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    fraccion matriz_a[filas][columnas];
    fraccion matriz_b[filas][columnas];  
    fraccion matriz_r[filas][columnas];

    llenarmatriz61("Matriz A", filas, columnas, matriz_a);
    llenarmatriz61("Matriz B", filas, columnas, matriz_b);

    imprimirmatriz61("Matriz A", filas, columnas, matriz_a);
    imprimirmatriz61("Matriz B", filas, columnas, matriz_b);

    sumarmatrices61(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz61("Resultado A + B", filas, columnas, matriz_r);

    restarmatrices61(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz61("Resultado A - B", filas, columnas, matriz_r);

    multiplicarmatrices61(filas, columnas, matriz_a, matriz_b, matriz_r);
    imprimirmatriz61("Resultado A * B", filas, columnas, matriz_r);

    fraccion escalar = {2, 1};  
    multiplicarporescalar61(filas, columnas, matriz_a, escalar, matriz_r);
    imprimirmatriz61("Resultado A * Escalar", filas, columnas, matriz_r);


}


void llenarmatriz62(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirmatriz62(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz ingresada:\n");

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarmatrizpormatriz62(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int matrizr[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizr[i][j] = 0;  
            for (int k = 0; k < columnas; k++) {  
                matrizr[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}
void programa62 (){

    int filas, columnas, veces;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz_a[filas][columnas];
    int matriz_r[filas][columnas];

    llenarmatriz62("Matriz A", filas, columnas, matriz_a);
    imprimirmatriz62("Matriz A", filas, columnas, matriz_a);

    printf("Ingrese el expontente al que desea elevar la matriz: ");
    scanf("%d", &veces);

    for (int i = 1; i <= veces; i++) {
        multiplicarmatrizpormatriz62(filas, columnas, matriz_a, matriz_a, matriz_r);
        imprimirmatriz62("Resultado", filas, columnas, matriz_r);

        for (int x = 0; x < filas; x++) {
            for (int y = 0; y < columnas; y++) {
                matriz_a[x][y] = matriz_r[x][y];
            }
        }
    }

}

void programa63(){
    int numero = 42;                // Variable entera
    int *ptr = &numero;             // Puntero apuntando a 'numero'
    int **ptr_doble = &ptr;         // Puntero doble apuntando a 'ptr'
 
    printf("Valor de 'numero': %d\n", numero);
    printf("Direccion de 'numero': %p\n", (void*)&numero);
 
    printf("\nUsando puntero simple:\n");
    printf("Valor de 'ptr': %p\n", (void*)ptr);
    printf("Valor al que apunta 'ptr': %d\n", *ptr);
    printf("Direccion de 'ptr': %p\n", (void*)&ptr);
 
    printf("\nUsando puntero doble:\n");
    printf("Valor de 'ptr_doble': %p\n", (void*)ptr_doble);
    printf("Valor al que apunta 'ptr_doble' (direccion de 'ptr'): %p\n", (void*)*ptr_doble);
    printf("Valor final al que apunta 'ptr_doble': %d\n", **ptr_doble);
    printf("Direccion de 'ptr_doble': %p\n", (void*)&ptr_doble);

}

void programa64(){
    int a, b, c, d, e,f, l;
    printf("Ingrese valor A\n");
    scanf("%d", &a);
    printf ("Ingrese valor B\n");
    scanf("%d", &b);
    printf ("Ingrese valor C\n");
    scanf("%d", &c);
    printf ("Ingrese valor D\n");
    scanf("%d", &d);
    printf ("Ingrese valor E\n");
    scanf("%d", &e);
    printf ("Ingrese valor F\n");
    scanf("%d", &f);

    int *const pa=&a;
    int *const pb=&b;
    int *const pc=&c;
    int *const pd=&d;
    int *const pe=&e;
    int *const pf=&f;
    int *const DL=&l;
    
    printf("Valores ingresados: A=%p\n",&pa);
    printf("Valores ingresados: B=%p\n",&pb);
    printf("Valores ingresados: C=%p\n",&pc);   
    printf("Valores ingresados: D=%p\n",&pd);   
    printf("Valores ingresados: E=%p\n",&pe);
    printf("Valores ingresados: F=%p\n",&pf);

    printf("Valores ingresados: DL=%p\n",&DL);

   int sumaab=*pa+*pb;
   printf("Resultado de la suma de AB:\n %d", sumaab);

    *DL=sumaab; 
   printf("\nResultado posición=%d\n", *DL);

   int restaab=*pa-*pb;
   printf("Resultado de la resta AB:\n %d", restaab);

   *DL=restaab; 
   printf("\nResultado posición=%d\n", *DL);

   int multiplicacionab=*pa * *pb;
   printf("Resultado de la multiplicación  AB: \n%d", multiplicacionab);

   *DL=multiplicacionab; 
   printf("\nResultado posición=%d\n", *DL);


   int divisionab=*pa / *pb;
   printf("Resultado de la división   AB:\n %d", divisionab);

   *DL=divisionab; 
   printf("\nResultado posición=%d\n", *DL);




   int sumacd=*pc+*pd;
   printf("Resultado de la suma de CD: \n%d", sumacd);

   *DL=sumacd; 
   printf("\nResultado posición=%d\n", *DL);

   int restacd=*pc-*pd;
   printf("Resultado de la resta CD:\n %d", restacd);

   *DL=restacd; 
   printf("\nResultado posición=%d\n", *DL);

   int multiplicacioncd=*pc * *pd;
   printf("Resultado de la multiplicación CD: \n%d", multiplicacioncd);

   *DL=multiplicacioncd; 
   printf("\nResultado posición=%d\n", *DL);


   int divisioncd=*pc / *pd;
   printf("Resultado de la división  CD:\n %d", divisioncd);

   *DL=divisioncd; 
   printf("\nResultado posición=%d\n", *DL);
   


   int sumaef=*pe+*pf;
   printf("Resultado de la suma de EF:\n %d", sumaef);

   *DL=sumaef; 
   printf("\nResultado posición=%d\n", *DL);

   int restaef=*pe-*pf;
   printf("Resultado de la resta EF:\n %d", restaef);

   *DL=restaef; 
   printf("\nResultado posición=%p\n", &DL);

   int multiplicacionef=*pe * *pf;
   printf("Resultado de la multiplicación EF: \n%d", multiplicacionef);

   *DL=multiplicacionef; 
   printf("\nResultado posición=%p\n", &DL);


   int divisionef=*pe / *pf;
   printf("Resultado de la división  EF:\n %d", divisionef);

    *DL=divisionef; 
    printf("\nResultado posición=%p\n", &DL);


}

// Función para cambiar el color
void setcolor(const char* color) {
    printf("%s", color);
}

void programa65(){
    //Limpiar pantalla
    printf("033[2j"); 
    setcolor ("\033[4;36m"); 
    printf("\n Bienvenido al programa con marco y colores"); 

    //Restaurar color
    setcolor ("\033[0m");

    setcolor("\033[7;34m"); 
    printf("\nBienvenido al programa con marco y colores!\n");

    setcolor("\033[0m");

    setcolor("\033[4;34m");
    printf("Bienvenido al programa con marco y colores 2!\n");


}
void programa66 (){
    char buffer [100];
    float pi=3.14159;
    sprintf(buffer, "The value of pi es %.2f.", pi);
    printf("%s\n", buffer);
}

void programa67 (){
    struct Direccion{
        char calle[50];
        int numero;
    };
    struct Persona{
        char nombre [50];
        struct Direccion domicilio;
    
    };
    int n;

printf ("Ingrese el número de personas");
scanf ("%d", &n);
getchar ();

struct Persona personas[n];
for (int i=0; i<n; i++){
    printf ("\nIngrese los datos de la persona %d;\n", i+1);

    printf("Nombre:");
    scanf("%s", personas[i].nombre);


    printf("Calle:");
    scanf("%s", personas [i]. domicilio.calle);

    printf ("Numero");
    scanf("%d", &personas[i].domicilio.numero);
    getchar();}

    printf("\n%-20s|%20s|%-10s\n", "Nombre", "Direccion", "Número");
    printf("--------------------------------------------------\n");

    for(int i=0; i<n;i++){
        printf("%-20s|%-20s|%-10d\n",
        personas[i].nombre,
        personas[i].domicilio.calle,
        personas[i].domicilio.numero);
    
}

}
void programa68 (){
    int arr1[25], i, n;
    printf("\n\n Pointer : Store and retrieve elements from an array :\n");
    printf("------------------------------------------------------------\n");
    printf(" Input the number of elements to store in the array : ");
    scanf("%d", &n);
    printf(" Input %d number of elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf(" element - %d : ", i);
        scanf("%d", arr1 + i);
    }
    printf(" The elements you entered are : \n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : %d %p\n", i, *(arr1 + i), &arr1[i]);
    }
}        

void programa69(){
    printf("\033[2J"); // Limpia la pantalla
    int asteriscos=1;
    for (int i=6; i>=0; i--){
    for (int j=1; j<=asteriscos; j++){
setColor("\033[7;31m");
printf("%s", " ");
}
asteriscos ++; 
printf("\n");
}
setcolor("\033[0m");
}

void programa70 (){
    union Dato{
        int entero;
        float decimal;
        char texto [20];
    };
        union Dato variable;
        variable.entero=42;
        printf( "Entero: %d\n", variable.entero);
    
        variable.decimal=3.14;
        printf("Entero: %.2f\n", variable.entero);
        
        variable.texto, "Hola C";
         printf("Texto: %s\n", variable.texto);
}
void programa71(){
    struct Moto{
        char cc[20];
    };
    struct Camion{
        struct {
        char cantascientos [20];
        char cantpue [20]; 
        }datosdelcamion;
    };
    
    struct Vehiculo{
        char vim [20];
        char hp [20];
        char tanque [20];
        char cantllantas[20];
        char color[20];
        struct Moto moto;
        struct Camion camion;
    
    };
    union Tipovehiculo{
        char Motocicleta[20];
        char Camion [20];
    };
    
        struct Vehiculo motos;
        strcpy(motos.moto.cc, "444cc");
        printf("CC de la moto: %s\n", motos.moto.cc);
    
        struct Vehiculo camiones;
        strcpy(camiones.camion.datosdelcamion.cantascientos,"6");
        strcpy(camiones.camion.datosdelcamion.cantpue, "2");
        
        printf("La cantidad de puertas del camion son:%s\n", camiones.camion.datosdelcamion.cantascientos);
        printf("La cantidad de puertas es de:%s\n ", camiones.camion.datosdelcamion.cantpue);
    
   
}



const char* colores[7] = {
    "\033[41m", 
    "\033[42m", 
    "\033[43m", 
    "\033[44m", 
    "\033[45m", 
    "\033[46m", 
    "\033[47m"  
};

const char* RESET = "\033[0m";

void programa73(){
    int num_barras;
    int barras[7] = {0}; 
    int i, nivel;

   
    printf("numero de barras que quiere graficar: ");
    scanf("%d", &num_barras);

    
    if (num_barras > 7) {
        printf("El numero de barras maximo es 7.\n");
        return 0; 
    }

    printf("Ingresa las alturas de las %d barras:\n", num_barras);
    for (i = 0; i < num_barras; i++) {
        printf("Barra %d: ", i + 1);
        scanf("%d", &barras[i]);
    }
    
    printf("\033[2J");
   
    for (i = 0; i < num_barras * 2 + 2; i++) printf("*");
    printf("\n");

  
    for (nivel = 7; nivel >= 1; nivel--) {
        printf("*"); 
        for (i = 0; i < num_barras; i++) {
            if (barras[i] >= nivel) {
                setColor(colores[i]); 
                printf("**");         
                setColor(RESET);      
            } else {
                printf("  ");         
            }
        }
        printf("*\n"); 
    }

  
    for (i = 0; i < num_barras * 2 + 2; i++) printf("*");
    printf("\n");

}





    void gotoxyH(int x, int y) { 
    printf("\033[%d;%dH", y, x); 
    }

    void clearScreenH() { 
        printf("\033[2J");
     }
    
    void llenarMatrizH(char *nombre, int filas, int columnas, int matrizH[3][3]) {
        printf("Nombre de la matriz: %s\n", nombre);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
                scanf("%d", &matrizH[i][j]);
            }
        }
    }
    
    void imprimirMatrizH(char *nombre, int filas, int columnas, int matrizH[3][3], int x, int y) {
        gotoxyH(x + 5, y);
        printf(" %s\n", nombre);
        for (int i = 0; i < 3; i++) {
            gotoxyH(x, y + 1 + i);
            printf("*");
            for (int j = 0; j < 3; j++) {
                gotoxyH(x + 2 + j * 4, y + 1 + i);
                printf("%3d ", matrizH[i][j]);
            }
            gotoxyH(x + 14, y + 1 + i);
            printf("*");
        }
    }
    
    void restaMatrizH(int filas, int columnas, int matriz1H[filas][columnas], int matriz2H[filas][columnas], int matrizrH[filas][columnas]) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matrizrH[i][j] = matriz1H[i][j] - matriz2H[i][j];
            }
        }
    }
    
    void sumarMatrizH(int filas, int columnas, int matriz1H[filas][columnas], int matriz2H[filas][columnas], int matrizrH[filas][columnas]) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matrizrH[i][j] = matriz1H[i][j] + matriz2H[i][j];
            }
        }
    }
    
    void escalarMatrizAH(int filas, int columnas, int numeroH, int matriz1H[filas][columnas], int matriz_escAH[filas][columnas]) {
        printf("\nIngresa el numero por el que desea multiplicar la matriz A:\n");
        scanf("%d", &numeroH);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz_escAH[i][j] = matriz1H[i][j] * numeroH;
            }
        }
    }
    
    void escalarMatrizBH(int filas, int columnas, int numero2H, int matriz2H[filas][columnas], int matriz_escBH[filas][columnas]) {
        printf("\nIngresa el numero por el que desea multiplicar la matriz B:\n");
        scanf("%d", &numero2H);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz_escBH[i][j] = matriz2H[i][j] * numero2H;
            }
        }
    }
    
    int detAH(int matrizH[3][3]) {
        int detH = 0;
        for (int i = 0; i < 3; i++) {
            detH += matrizH[0][i] * matrizH[1][(i + 1) % 3] * matrizH[2][(i + 2) % 3];
        }
        for (int i = 0; i < 3; i++) {
            detH -= matrizH[0][(i + 2) % 3] * matrizH[1][(i + 1) % 3] * matrizH[2][i];
        }
        return detH;
    }
    
    void programa72() {
        int filas, columnas, numeroH, numero2H, detH;
    
        printf("Ingrese el numero de filas: ");
        scanf("%d", &filas);
    
        printf("Ingrese el numero de columnas: ");
        scanf("%d", &columnas);
    
        int matriz_aH[3][3];
        int matriz_bH[3][3];
        int matriz_rH[3][3];
        int matriz_escAH[3][3];
        int matriz_escBH[3][3];
    
        llenarMatrizH("Matriz A", filas, columnas, matriz_aH);
        llenarMatrizH("Matriz B", filas, columnas, matriz_bH);
    
        clearScreenH();
    
        imprimirMatrizH("Matriz A", filas, columnas, matriz_aH, 5, 2);
        imprimirMatrizH("Matriz B", filas, columnas, matriz_bH, 25, 2);
    
        sumarMatrizH(filas, columnas, matriz_aH, matriz_bH, matriz_rH);
        imprimirMatrizH("SUMA A+B", filas, columnas, matriz_rH, 45, 2);
    
        restaMatrizH(filas, columnas, matriz_aH, matriz_bH, matriz_rH);
        imprimirMatrizH("RESTA A-B", filas, columnas, matriz_rH, 65, 2);
    
        escalarMatrizAH(filas, columnas, numeroH, matriz_aH, matriz_escAH);
        imprimirMatrizH("Matriz A x esc:", filas, columnas, matriz_escAH, 85, 2);
    
        escalarMatrizBH(filas, columnas, numero2H, matriz_bH, matriz_escBH);
        imprimirMatrizH("Matriz B x esc:", filas, columnas, matriz_escBH, 105, 2);
    
        gotoxyH(5, 10);
    
        if (filas == 3 && columnas == 3) {
            detH = detAH(matriz_aH);
            printf("El determinante de la matriz A es: %d\n", detH);
        } else {
            printf("La matriz debe ser 3x3.\n");
        }
    
        gotoxyH(0, 15);
    }
    


int main() {
    int opc;

    printf("%s\n", "Seleccione una opción:");
    printf("1.- Programa 1:matriz por escalar\n");
    printf("2.- Programa 2: arreglo con scanf\n");
    printf("3.- Programa 3: apuntadores ejemplo 1\n");
    printf("4.- Programa 4: estructura con arreglo\n");
    printf("5.- Programa 5: apuntadores ejemplo 2\n");
    printf("6.- Programa 6:apuntadores con operaciones basicas\n");
    printf("7.- Programa 7: bandera de usa\n");
    printf("8.- Programa 8:bandera de mexico\n");
    printf("9.- Programa 9:estructura \n");
    printf("10.- Programa 10:gotoxy\n");
    printf("11.- Programa 11:coordenadas triangulo o cuadrado\n");
    printf("12.- Programa 12:cuadrado con colores diferente por celda\n");
    printf("13.- Programa 13:coordenadas remasterizado\n");
    printf("14.- Programa 14:determinante de matrices\n");
    printf("15.- Programa 15:multiplicacion de dos matrices\n");
    printf("16.- Programa 16:estructura direccion-persona\n");
    printf("17.- Programa 17:estructura estudiante\n");
    printf("18.- Programa 18:estructura persona con datos ingresados\n");
    printf("19.- Programa 19:estructura tenis\n");
    printf("20.- Programa 20:estructura usuario\n");
    printf("21.- Programa 21:ejemplo estructura 1\n");
    printf("22.- Programa 22:matriz uniones con estructura\n");
    printf("23.- Programa 23:ecuacion cuadratica con arreglo\n");
    printf("24.- Programa 24:ecuacion cuadratica con scanf y arreglo\n");
    printf("25.- Programa 25:funcion dos numeros \n");
    printf("26.- Programa 26:funcion tres numeros\n");
    printf("27.- Programa 27:funcion celsius a fahrenheit\n");
    printf("28.- Programa 28:funcion celsius a kelvin\n");
    printf("29.- Programa 29:determinante de dos matrices\n");
    printf("30.- Programa 30:suma de matrices\n");
    printf("31.- Programa 31:funcion de divisas\n");
    printf("32.- Programa 32:ecuacion cuadratica discriminantes\n");
    printf("33.- Programa 33:funciones numero positivo o negativo\n");
    printf("34.- Programa 34:funciones ejemplo 1\n");
    printf("35.- Programa 35:funciones operaciones\n");
    printf("36.- Programa 36:funciones area y volumen de figuras\n");
    printf("37.- Programa 37:funcion de base y exponente\n");
    printf("38.- Programa 38:funcion fahrenheit a celsius\n");
    printf("39.- Programa 39:funcion suma de intervalo\n");
    printf("40.- Programa 40:funcion kelvin a fahrenheit\n");
    printf("41.- Programa 41:funcion palabras\n");
    printf("42.- Programa 42:funcion tabla de multiplicar\n");
    printf("43.- Programa 43:funcion menu de temperaturas\n");
    printf("44.- Programa 44:gotoxy ejemplo 2\n");
    printf("45.- Programa 45:funcion setcolor nombre y edad\n");
    printf("46.- Programa 46:matriz \n");
    printf("47.- Programa 47:matriz de palabras\n");
    printf("48.- Programa 48:matriz de operaciones\n");
    printf("49.- Programa 49:matrices guardado y funciones\n");
    printf("50.- Programa 50:matriz que imprime numeros impares\n");
    printf("51.- Programa 51:estructura carros\n");
    printf("52.- Programa 52:calculadora basica con colores y gotoxy\n");
    printf("53.- Programa 53:matriz con estructuras\n");
    printf("54.- Programa 54:arreglo y estructuras\n");
    printf("55.- Programa 55:apuntadores con operaciones\n");
    printf("56.- Programa 56:funcion raiz exacta \n");
    printf("57.- Programa 57:transpuesta de una matriz\n");
    printf("58.- Programa 58:matriz por vector\n");
    printf("59.- Programa 59:multiplicacion de matriz por otra matriz\n");
    printf("60.- Programa 60:multiplicacion de matrices con fracciones\n");
    printf("61.- Programa 61:operaciones con matrices de fracciones\n");
    printf("62.- Programa 62:multiplicacion convencional de matrices \n");
    printf("63.- Programa 63:indirecciones\n");
    printf("64.- Programa 64:apuntadores constante\n");
    printf("65.- Programa 65:funcion colores ejemplo 2\n");
    printf("66.- Programa 66:sprintf\n");
    printf("67.- Programa 67:estructura persona-domicilio\n");
    printf("68.- Programa 68:apuntadores\n");
    printf("69.- Programa 69:triangulo de color rojo\n");
    printf("70.- Programa 70: union \n");
    printf("71.- Programa 71: vehiculo union\n");
    printf("72.- Programa 72: impresion de matrices horizontal\n");
    printf("73.- Programa 73: grafica de barras\n");

    

    scanf("%d", &opc);

    switch(opc) {
        case 1:
            printf("Ha seleccionado el Programa 1\n");
            programa1();
            break;
        case 2:
            printf("Ha seleccionado el Programa 2\n");
            programa2();
            break;
        case 3:
            printf("Ha seleccionado el Programa 3\n");
            programa3();
            break;
        case 4:
            printf("Ha seleccionado el Programa 4\n");
            programa4();
            break;
        case 5:
            printf("Ha seleccionado el Programa 5\n");
            programa5 ();
            break;
        case 6:
            printf("Ha seleccionado el Programa 6\n");
            programa6 ();
            break;
        case 7:
            printf("Ha seleccionado el Programa 7\n");
            programa7 ();
            break;
        case 8:
            printf("Ha seleccionado el Programa 8\n");
            programa8();
            break;
        case 9:
            printf("Ha seleccionado el Programa 9\n");
            programa9();
            break;
        case 10:
            printf("Ha seleccionado el Programa 10\n");
            programa10();
            break;
        case 11:
            printf("Ha seleccionado el Programa 11\n");
            programa11();
            break;
        case 12:
            printf("Ha seleccionado el Programa 12\n");
            programa12();
            break;
        case 13:
            printf("Ha seleccionado el Programa 13\n");
            programa13();
            break;
        case 14:
            printf("Ha seleccionado el Programa 14\n");
            programa14();
            break;
        case 15:
            printf("Ha seleccionado el Programa 15\n");
            programa15();
            break;
        case 16:
            printf("Ha seleccionado el Programa 16\n");
            programa16();
            break;
        case 17:
            printf("Ha seleccionado el Programa 17\n");
            programa17();
            break;
        case 18:
            printf("Ha seleccionado el Programa 18\n");
            programa18();
            break;
        case 19:
            printf("Ha seleccionado el Programa 19\n");
            programa19();
            break;
        case 20:
            printf("Ha seleccionado el Programa 20\n");
            programa20();
            break;
        case 21:
            printf("Ha seleccionado el Programa 21\n");
            programa21();
            break;
        case 22:
            printf("Ha seleccionado el Programa 22\n");
            programa22 ();
            break;
        case 23:
            printf("Ha seleccionado el Programa 23\n");
            programa24();
            break;
        case 24:
            printf("Ha seleccionado el Programa 24\n");
            programa24 ();
            break;
        case 25:
            printf("Ha seleccionado el Programa 25\n");
            programa26();
            break;
        case 26:
            printf("Ha seleccionado el Programa 26\n");
            programa26();
            break;
        case 27:
            printf("Ha seleccionado el Programa 27\n");
            programa27();
            break;
        case 28:
            printf("Ha seleccionado el Programa 28\n");
            programa28();
            break;
        case 29:
            printf("Ha seleccionado el Programa 29\n");
            programa29();
            break;
        case 30:
            printf("Ha seleccionado el Programa 30\n");
            programa30();
            break;
        case 31:
            printf("Ha seleccionado el Programa 31\n");
            programa31();
            break;
        case 32:
            printf("Ha seleccionado el Programa 32\n");
            programa32();
            break;
        case 33:
            printf("Ha seleccionado el Programa 33\n");
            programa33();
            break;
        case 34:
            printf("Ha seleccionado el Programa 34\n");
            programa34();
            break;
        case 35:
            printf("Ha seleccionado el Programa 35\n");
            programa35();
            break;
        case 36:
            printf("Ha seleccionado el Programa 36\n");
            programa36();
            break;
        case 37:
            printf("Ha seleccionado el Programa 37\n");
            programa37();
            break;
        case 38:
            printf("Ha seleccionado el Programa 38\n");
            programa38();
            break;
        case 39:
            printf("Ha seleccionado el Programa 39\n");
            programa39();
            break;
        case 40:
            printf("Ha seleccionado el Programa 40\n");
            programa40();
            break;
        case 41:
            printf("Ha seleccionado el Programa 41\n");
            programa41();
            break;
        case 42:
            printf("Ha seleccionado el Programa 42\n");
            programa42();
            break;
        case 43:
            printf("Ha seleccionado el Programa 43\n");
            programa43();
            break;
        case 44:
            printf("Ha seleccionado el Programa 44\n");
            programa44();
            break;
        case 45:
            printf("Ha seleccionado el Programa 45\n");
            programa45();
            break;
        case 46:
            printf("Ha seleccionado el Programa 46\n");
            programa46();
            break;
        case 47:
            printf("Ha seleccionado el Programa 47\n");
            programa47();
            break;
        case 48:
            printf("Ha seleccionado el Programa 48\n");
            programa48();
            break;
        case 49:
            printf("Ha seleccionado el Programa 49\n");
            programa49();
            break;
        case 50:
            printf("Ha seleccionado el Programa 50\n");
            programa50();
            break;
        case 51:
            printf("Ha seleccionado el Programa 51\n");
            programa51();
            break;
        case 52:
            printf("Ha seleccionado el Programa 52\n");
            programa52();
            break;
        case 53:
            printf("Ha seleccionado el Programa 53\n");
            programa53();
            break;
        case 54:
            printf("Ha seleccionado el Programa 54\n");
            programa54();
            break;
        case 55:
            printf("Ha seleccionado el Programa 55\n");
            programa55();
            break;
        case 56:
            printf("Ha seleccionado el Programa 56\n");
            programa56();
            break;
        case 57:
            printf("Ha seleccionado el Programa 57\n");
            programa57();
            break;
        case 58:
            printf("Ha seleccionado el Programa 58\n");
            programa58();
            break;
        case 59:
            printf("Ha seleccionado el Programa 59\n");
            programa59();
            break;
        case 60:
            printf("Ha seleccionado el Programa 60\n");
            programa60();
            break;
        case 61:
            printf("Ha seleccionado el Programa 61\n");
            programa61();
            break;
        case 62:
            printf("Ha seleccionado el Programa 62\n");
            programa62();
            break;
        case 63:
            printf("Ha seleccionado el Programa 63\n");
            programa63();
            break;
        case 64:
            printf("Ha seleccionado el Programa 64\n");
            programa64();
            break;
        case 65:
            printf("Ha seleccionado el Programa 65\n");
            programa66();
            break;
        case 66:
            printf("Ha seleccionado el Programa 66\n");
            programa66();
            break;
        case 67:
            printf("Ha seleccionado el Programa 67\n");
            programa67();
            break;
        case 68:
            printf("Ha seleccionado el Programa 68\n");
            programa68();
            break;
        case 69:
            printf("Ha seleccionado el Programa 69\n");
            programa69();
            break;
        case 70:
            printf("Ha seleccionado el Programa 70\n");
            programa70();
            break;
        case 71:
            printf("Ha seleccionado el programa 71\n");
            programa71();
            break;
        case 72:
            printf("Ha seleccionado el programa 72\n");
            programa72();
            break;
        case 73:
            printf("Ha seleccionado el programa 73\n");
            programa73();
            break;

        default:
            printf("No ha seleccionado una opcion valida\n");
            break;
    }

    return 0;
}
