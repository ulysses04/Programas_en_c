#include <stdio.h>
void hanoi(char torre1, char torre2, char torre3, int disco){
    if(disco ==1){
        printf("mover disco '%d'  desde torre  '%c'  a torre  '%c'\n",disco,torre1,torre3);
    }else{
    hanoi(torre1, torre3, torre2, disco-1);
    printf("mover disco '%d'  desde torre  '%c' a torre  '%c'\n",disco,torre1,torre3);
    hanoi(torre2, torre1, torre3, disco-1);
    }

    
}
int main(){
    int disco;
    char torre1,torre2,torre3;
    printf("nombre de la torre 1:\n");
    scanf(" %c", &torre1);
    printf("nombre de la torre 2:\n");
    scanf(" %c", &torre2);
    printf("nombre de la torre 3:\n");
    scanf(" %c", &torre3);
    printf("numero de discos:\n");
    scanf("%d",&disco);
    printf("hanoi:\n");
    hanoi(torre1,torre2,torre3,disco);
    return 0;

}