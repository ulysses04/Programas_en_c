#include <stdio.h>

void setColor(int color) {
    printf("\033[7;%dm", color); 
}
void limpiarpantalla(){
    printf("\033[2J");

}
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}


int main(){
    int opc;
int num=15;
int i,j;
limpiarpantalla();

for(i=0;i<num;i++){
    printf("*  ");


}
printf("\n");
for(j=1;j<(num-1);j++){
    printf("*");
    for(i=1;i<(num-1);i++){
        printf("   ");

    }
    printf("  *\n");


}
if(num>1){
    for(i=0;i<num;i++){
        printf("*  ");

    }
    printf("\n");

}
gotoxy(9,1);
printf("menu\n");
gotoxy(10,4);
printf("1)suma matriz\n");
gotoxy(10,5);
printf("2)resta matriz\n");
gotoxy(10,6);
printf("3)multiplicacion matriz\n");
gotoxy(10,7);
printf("4)determinante\n");


gotoxy(38, 15); 
printf("opc: ");
scanf("%d",&opc);
switch(opc){
    case 1:
    printf("suma matriz");
    break;
    case 2:
    printf("resta matriz");
    break;
    case 3:
    printf("multiplicacion matriz");
    break;
    case 4:
    printf("determinante");
    break;
    default:
    printf("seleccione una opcion valida");
    break;
}


return 0;
}
    
