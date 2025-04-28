#include <stdio.h>

void gotoxy(int x, int y){
    printf("\033[%d;%dH",y,x);//ANSI escape sequence
}
int main(){
    printf("\033[2J");//limpia pantalla
    gotoxy(10,5);
    printf("hola desde (10,5):");
    return 0;

}