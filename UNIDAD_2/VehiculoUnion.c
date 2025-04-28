#include <stdio.h>
#include <string.h>
struct vehiculo{
    char color[20];
    int hp;
    int tanque;
    int cant_llantas;
    
};

union camion{
    int cant_asientos;
    int cant_puertas;
};
union motocicleta{
    int cc;
};
struct vehiculocamion{
    struct vehiculo comun;
    union camion especifico;
};
struct vehiculomoto{
    struct vehiculo comun;
    union motocicleta especifico;
};
int main(){
    struct vehiculocamion camion1;
    strcpy (camion1.comun.color,"blanco");
    camion1.comun.hp=200;
    camion1.comun.tanque=90;
    camion1.comun.cant_llantas=6;
    camion1.especifico.cant_asientos=10;
    camion1.especifico.cant_puertas=4;

    struct vehiculomoto moto1;
    strcpy(moto1.comun.color,"verde");
    moto1.comun.hp=250;
    moto1.comun.tanque=20;
    moto1.comun.cant_llantas=2;
    moto1.especifico.cc=2000;

    printf("datos del camion:\n");
    printf("color:%s\n",camion1.comun.color);
    printf("caballos de fuerza: %d\n",camion1.comun.hp);
    printf("capacidad de tanque en litros: %d\n",camion1.comun.tanque);
    printf("numero de llantas: %d\n",camion1.comun.cant_llantas);
    printf("numero de asientos: %d\n",camion1.especifico.cant_asientos);
    printf("numero de puertas: %d\n",camion1.especifico.cant_puertas);

    printf("datos de motocicleta:\n");
    printf("color: %s\n",moto1.comun.color);
    printf("caballos de fuerza: %d\n",moto1.comun.hp);
    printf("capacidad de tanque en litros: %d\n",moto1.comun.tanque);
    printf("numero de llantas: %d\n",moto1.comun.cant_llantas);
    printf("tamano del motor:%d\n",moto1.especifico.cc);

return 0;
}