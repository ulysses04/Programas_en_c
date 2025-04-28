#include <stdio.h>
void setcolor(const char* color){//n cantidad de caracteres 
    printf("%s",color);
}
int main(){
    printf("033[2j");//limpia pantalla

    setcolor("\033[4;36m");
    printf("\n bienvenido al programa con marco y colores\n");

    //restaura colores
    setcolor("\033[0m");

    setcolor("\033[7;34m");
    printf("\n bienvenido al programa con marco y colores:\n");

    setcolor("\033[0m");//restaurar color

    setcolor("\033[4;34m");
    printf("\n bienvenido al programa con marco y colores 2:\n");

    return 0;



}