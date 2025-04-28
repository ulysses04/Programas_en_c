#include <stdio.h>
#include <math.h>
int main(){
    int opc;
    printf("%s\n","Menu de programas de parcial 1");
    printf("%s\n","1.-escapes");
    printf("%s\n","2.-tipos de datos");
    printf("%s\n","3.-promedio de calificaciones");
    printf("%s\n","4.-temperatura con numeros enteros");
    printf("%s\n","5.-temperatura con numeros con numero decimal");
    printf("%s\n","6.-diagonales con asterisco");
    printf("%s\n","7.-tablas de multiplicar");
    printf("%s\n","8.-cuadrado con asteriscos");
    printf("%s\n","9.-triangulo Rectangulo");
    printf("%s\n","10.-triangulo rectangulo2");
    printf("%s\n","11.-triangulo equilatero");
    printf("%s\n","12.-trapecio");
    printf("%s\n","13.-promedio con scanf");
    printf("%s\n","14.-volumen y area de una esfera");
    printf("%s\n","15.-volumen y area de un cono");
    printf("%s\n","16.-volumen y area de un cilindro");
    printf("%s\n","17.-prueba de switch con numeros");
    printf("%s\n","18.-prueba de switch con letras");
    printf("%s\n","19.-calculadora con switch");
    printf("%s\n","20.- hola mundo");
    printf("%s\n","elige un programa:");
    scanf("%d",&opc);
    switch(opc){
        case 1:
        printf("%s","caracteres de salida o escape\n");
        printf("%s","salto de linea:\n" );
        printf("%s\t%s\n","tabulacion","tabulacion");
        printf("%s\n","\rretorno de carro");
        printf("%s\n","\besta salida hace un retroceso");
        printf("%s\n","\fsalto de pagina");
        printf("%s\v%s\n","tabulacion","vertical");
        printf("%s\\\n","imprimir diagonal invertida");
        printf("%s\?\n","imprime signo de interrogacion");
        printf("%s\"\n","imprime comillas dobles");
        int numerodecimal=64;
        printf("%s%o\n","imprime numero en octal:",numerodecimal);
        printf("%s%x\n","imprime numero en hexadecimal:",numerodecimal);
        char cadena[]="hola ,mundo";
        printf("%s\n",cadena);
        cadena[5]='\0';
        printf("%s%s","cadena despues de fin de cadena:",cadena);
        break;
        case 2:{
        char letra='a';
        int entero=100;
        unsigned int enteropositivo=250;
        short int enterocorto=50;
        long int enterolargo=123456789;
        long long int enteromuylargo=42227788999;
        float decimalcorto=3.14;
        double decimallargo=3.14159265;
        char nombre[20]="alejandro12345678910";
    
        printf("%c\n",letra);
        printf("%d\n",entero);
        printf("%u\n",enteropositivo);
        printf("%hd\n",enterocorto);
        printf("%ld\n",enterolargo);
        printf("%lld\n",enteromuylargo);
        printf("%f\n",decimalcorto);
        printf("%lf\n",decimallargo);
        printf("%s\n",nombre);
        break;
        }
        case 3:{
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
    break;
    }
    case 4:{
    int tempfahr, tempcelsius;
    int lower1, upper1, step1; //declara nuestras variables y su tipo de dato
    lower1=0; //limite inferior de la tabla de temperatura 
    upper1=300;//limite supeior 
    step1=20;//tamaño de incremento 
    tempfahr=lower1;//declara el valor inicial de nuestro contador 
    while (tempfahr<=upper1){ //condicion de nuestro contador 
        tempcelsius= 5 * (tempfahr-32)/9; //operacion de la conversion de grados fahr a celsius 
        printf("%d\t%d\n",tempfahr,tempcelsius); // imprime la conversion de temperatura 
        tempfahr= tempfahr + step1; //contador avanzara de 20 en 20 
        
        
    
    }
    break;
    }
    case 5:{
    float fahr, celsius;
    int lower, upper, step; 
    lower=0; 
    upper=300; 
    step=20; 
    fahr=lower; 
    while (fahr<=upper){ 
        celsius= 5 * (fahr-32)/9;  
        printf("%3.0f%6.1f\n",fahr,celsius);  
        fahr= fahr + step;  


    }
    break;
    }
    case 6:{
    int n=5;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            printf(" ");
        }
        printf("*\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<(n-i-1);j++){
            printf("  ");
        }
        printf("*\n");
    }
    break;
    }
    case 7:{
    int tabla=0;
    while (tabla <=10){
        int numero=0;
        while(numero<=10){
            int multiplicacion;
            multiplicacion= numero*tabla;
            printf("%s%d%s%d%s%d\n","(",tabla,")(",numero,")=",multiplicacion);
            numero++;

        }
    tabla++;

    }
    break;
    }
    case 8:{
    int num=6;
    int a,b;
    for(a=0;a<num;a++){
        printf("*");


    }
    printf("\n");
    for(b=1;b<(num-1);b++){
        printf("*");
        for(a=1;a<(num-1);a++){
            printf(" ");

        }
        printf("*\n");

    }
    if(num>1){
        for(a=0;a<num;a++){
            printf("*");

        }
        printf("\n");

    }
    break;
    }
    case 9:{
    int asteriscos=1;
    for(int x=6;x>=0;x--){
        for(int y=1;y<=asteriscos;y++){
            printf("%s","*");
        }
        asteriscos++;
        printf("\n");
    }
    break;
    }
    case 10:{
    int espacio=6;
    int asterisco=1;
    for(int g=6;g>=0;g--){
    for(int h=1;h<=espacio;h++){
        printf("%4s","$");
    }
    espacio--;
    for(int k=1;k<=asterisco;k++){
        printf("%4s","*");
    }
    asterisco++;
    printf("\n");
}
    break;
    }
    case 11:{
    int espacios=6;
    int asterisco2=1;

    for(int e=6;e>=0;e--){
        for(int r=1;r<=espacios;r++){
            printf("%4s","/");
        }
        espacios--;
        for(int r=1;r<=asterisco2;r++){
            printf("%4s","*");
        }
        asterisco2+=2;
        printf("\n");
    }
    break;
    }
    case 12:{
    int asterisco3=3;
    int espacio2=6;
    for(int q=1;q<=3;q++){
    for(int w=1;w<=espacio2;w++){
        printf("%4s","/");
    }
    espacio2--;
    for (int t=1;t<=asterisco3;t++){
        printf("%4s","*");
    }
    asterisco3+=2;
    printf("\n");
}
    break;
    }
    case 13:{
    char nombre[50];
    int calificacion1,calificacion2,calificacion3;
    float prom;
    printf("%s","ingresa tu nombre:");
    scanf("%s",&nombre);
    printf("%s","ingresa calificacion 1:");
    scanf("%d",&calificacion1);
    printf("%s","ingresa calificacion 2:");
    scanf("%d",&calificacion2);
    printf("%s","ingresa calificacion 3:");
    scanf("%d",&calificacion3);
    prom=(calificacion1+calificacion2+calificacion3)/3;
    printf("%s%s","nombre:\n",nombre);
    printf("%s%.2f","\npromedio:\n",prom);
    if (prom>=6){
        printf("%s","\naprobado");
    }
    else{
        printf("%s","\nreprobado");
    }
    break;
    }
    case 14:{
    float radioe,areae,volumene;
    double pi=3.1416;
    printf("%s","calcular area y volumen de una esfera\n");
    printf("%s","ingresa valor de radio:\n");
    scanf("%f",&radioe);

    areae= (radioe*radioe)*(4*pi);
    volumene=((radioe*radioe*radioe)*pi*4)/3;
    printf("%s","volumen es:\n");
    printf("%.2f",volumene);
    printf("%s","\narea es:\n");
    printf("%.2f",areae);
    break;
    }
    case 15:{
    float radioc,alturac,generatriz,areac,volumenc,arealateral,areabase;
    double pi2=3.1416;
    printf("calculo de area y volumen de un cono\n");
    printf("ingrese radio:\n");
    scanf("%f",&radioc);
    printf("ingrese altura:\n");
    scanf("%f",&alturac);
    generatriz=sqrt((radioc*radioc)+(alturac*alturac));
    areabase=(radioc*radioc)*pi2;
    arealateral=pi2*radioc*generatriz;
    areac=areabase+arealateral;
    volumenc=((radioc*radioc)*pi2*alturac)/3;
    printf("area es:\n");
    printf("%.2f",areac);
    printf("\nvolumen es:\n");
    printf("%.2f",volumenc);
    break;
    }
    case 16:{
    float radioci,alturaci,areaci,volumenci;
    double pi3=3.1416;
    printf("calcular area y volumen de un cilindro\n");
    printf("ingrese altura:");
    scanf("%f",&alturaci);
    printf("ingrese radio:");
    scanf("%f",&radioci);
    areaci=2*pi3*radioci*(alturaci+radioci);
    volumenci=(radioci*radioci)*alturaci*pi3;
    printf("area es:\n");
    printf("%.2f",areaci);
    printf("\nvolumen es:\n");
    printf("%.2f",volumenci);
    break;
    }
    case 17:{
    int opcion;
    printf("%s\n","selecciona una opcion");
    printf("%s\n","1.-sumar");
    printf("%s\n","2.-restar");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
        printf("%s\n","ha seleccionado suma");
        break;
        case 2:
        printf("%s\n","ha seleccionnado resta");
        break;
        default:
        printf("%s\n","no has seleccionado una opcion valida");
        

    }
    break;
    }
    case 18:{
    char option;
    printf("%s\n","selecciona una opcion:");
    printf("%s\n","a)selecciona opcion 1");
    printf("%s\n","b)selecciona opcion 2");
    scanf(" %c",&option);
    switch(option){
        case 'a':
        printf("%s\n","selecciono opcion 1");
        break;
        case 'b':
        printf("%s\n","selecciono opcion 2");
        break;
        default:
        printf("%s\n","opcion invalido");
    }
    break;
    }
    case 19:{
    float num1,num2;
    int op;
    float suma,resta,division,multiplicacion;
    printf("calculadora\n");
    printf("Elige una operacion\n");
    printf("1.-suma\n");
    printf("2.-resta\n");
    printf("3.-multiplicacion\n");
    printf("4.-division\n");
    scanf("%d",&op);
    switch(op){
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
        printf("%s\n","no has seleccionado una opcion valida");
        break;


    }
    break;
    }
    case 20:
    printf("hola mundo\n");
    break;
    default: 
    printf("%s\n","no has seleccionado una opcion valida");
    break;
}
return 0;
}