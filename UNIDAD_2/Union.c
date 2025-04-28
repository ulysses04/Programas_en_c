#include <stdio.h>
union dato{
    int entero;
    float decimal;
    char texto[20];
};
int main(){
    union dato variable;
    variable.entero =42;
    printf("entero: %d\n",variable.entero);

    variable.decimal = 3.14;
    printf("decimal: %f\n",variable.decimal);

    sprintf(variable.texto,"hola c");
    printf("texto: %s\n",variable.texto);
    printf("\n despues de asignar un texto:\n");
    printf("entero: %d\n",variable.entero);
    printf("decimal: %.2f\n",variable.decimal);
    printf("texto: %s\n",variable.texto);

return 0;
}