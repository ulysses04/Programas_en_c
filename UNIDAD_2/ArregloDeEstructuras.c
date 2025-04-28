#include <stdio.h>

struct carro{
    char marca[50];
    char modelo[50];
    char color[50];
    char transmision[50];
    int ano, cilindros,nserie;
    char placas[50];  

};
int main(){
    int size;
    printf("ingrese tamano de arreglo:\n");
    scanf("%d",&size);
    struct carro usuarios[size];
    for(int i=0;i<size;i++){
        printf("ingrese marca del carro:\n");
        scanf("%s",usuarios[size].marca);
        printf("ingrese modelo:\n");
        scanf("%s",usuarios[size].modelo);
        printf("ingrese ano:\n");
        scanf("%d",&usuarios[size].ano);
        printf("ingrese color:\n");
        scanf("%s",usuarios[size].color);
        printf("ingrese tipo de transmision:\n");
        scanf("%s",usuarios[size].transmision);
        printf("ingresa numero de cilindros:\n");
        scanf("%d",&usuarios[size].cilindros);
        printf("ingrese numero de serie:\n");
        scanf("%d",&usuarios[size].nserie);
        printf("ingrese numero de placas:\n");
        scanf("%s",usuarios[size].placas);

        
    }
    for(int i=0;i<size;i++){
        printf("\ndatos del carro:\n");
        printf("marca:%s\n",usuarios[size].marca);
        printf("modelo:%s\n",usuarios[size].modelo);
        printf("ano:%d\n",usuarios[size].ano);
        printf("color:%s\n",usuarios[size].color);
        printf("transmision:%s\n",usuarios[size].transmision);
        printf("numero de cilindros:%d\n",usuarios[size].cilindros);
        printf("numero de serie:%d\n",usuarios[size].nserie);
        printf("numero de placas:%s\n",usuarios[size].placas);


    }



return 0;
}