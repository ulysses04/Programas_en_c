#include <stdio.h>
void limpiarpantalla(){
    printf("\033[2J]");

}
void gotoxy(int x, int y){
    printf("\033[%d;%dH",x,y);
}
int main(){
    limpiarpantalla();
    gotoxy(5,3);
    printf("hello from (5,3)");
}