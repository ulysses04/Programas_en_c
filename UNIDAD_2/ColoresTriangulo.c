#include <stdio.h>
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
int main(){
    int asteriscos=1;
    setColor("\033[7;32m");
    for(int i=6;i>=0;i--){
        for(int j=1;j<=asteriscos;j++){
            printf("%s","*");
        }
        asteriscos++;
        printf("\n");
    }
    setColor("\033[0m");
    return 0;
}