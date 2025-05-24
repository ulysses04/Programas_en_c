#include <stdio.h>
long sumaNenteros(int number){
    if(number==1){
        return 1;

    }else
    return number + sumaNenteros(number - 1);

}
int main(){
    int number;
    printf("ingrese numero:");
    scanf("%d",&number);
    printf("resultado es:%ld",sumaNenteros(number));
    return 0;
}