#include <stdio.h>
int main(){
    int num=6;
    int i,j;
    for(i=0;i<num;i++){
        printf("*");


    }
    printf("\n");
    for(j=1;j<(num-1);j++){
        printf("*");
        for(i=1;i<(num-1);i++){
            printf(" ");

        }
        printf("*\n");

    }
    if(num>1){
        for(i=0;i<num;i++){
            printf("*");

        }
        printf("\n");

    }
    
 return 0;
}