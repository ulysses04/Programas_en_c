#include <stdio.h>
int main(){
    //tipos de datos primitivos
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

return 0;
}