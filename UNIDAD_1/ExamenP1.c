#include<stdio.h>
int main(){
    int espacio=4;
    int asterisco=2;

    for(int i=1;i>=0;i--){
        for(int j=1;j<=espacio;j++){
            printf("%3s","/");
        }
        espacio--;
        for(int k=1;k<=asterisco;k++){
            printf("%3s","*");
        }
        asterisco+=2;
        printf("\n");
    }
    for(int k=1;k<=10;k++){
        printf("%3s","*");
        }

    
    
    
    
    
 return 0;

}