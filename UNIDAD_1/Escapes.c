#include <stdio.h>
int main(){
    
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






    
    
    

    return 0;
}