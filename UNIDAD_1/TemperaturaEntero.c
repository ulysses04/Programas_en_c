#include <stdio.h> // declara libreria a utilizar
//imprime la tabla fahrenheit celsius
//para fahr=0,20,...,300. 
int main() //metodo principal
{
    int fahr, celsius;
    int lower, upper, step; //declara nuestras variables y su tipo de dato
    lower=0; //limite inferior de la tabla de temperatura 
    upper=300;//limite supeior 
    step=20;//tamaño de incremento 
    fahr=lower;//declara el valor inicial de nuestro contador 
    while (fahr<=upper){ //condicion de nuestro contador 
        celsius= 5 * (fahr-32)/9; //operacion de la conversion de grados fahr a celsius 
        printf("%d\t%d\n",fahr,celsius); // imprime la conversion de temperatura 
        fahr= fahr + step; //contador avanzara de 20 en 20 


    }
    return 0; //fin de programa 
}