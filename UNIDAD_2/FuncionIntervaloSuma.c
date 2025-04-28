#include <stdio.h>
void intervalo(int inicio, int fin){
    int suma=0;
    for(int i=inicio; i<=fin;i++){
        suma +=i;
    }
    printf("la suma de los numeros en el intervalo:%d",suma);
}
int main(){
    int start,finish;
    printf("ingresa el primer numero del intervalo:\n");
    scanf("%d",&start);
    printf("ingrese el ultimo numero del intervalo:\n");
    scanf("%d",&finish);
    intervalo(start,finish);
    return 0;
}