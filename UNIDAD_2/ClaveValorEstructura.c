#include <stdio.h>
#include <string.h>

struct Keyvalue{
    char clave[50];
    char valor[100];
};
int main(){
    struct Keyvalue tabla[3]={
        {"usuario","admin"},
        {"contrasena","1234"},
        {"servidor","localhost"},
    };
    printf("tabla clave valor:\n");
    for(int i=0;i<3;i++){
        printf("%s:%s\n",tabla[i].clave,tabla[i].valor);
    }
    return 0;
}