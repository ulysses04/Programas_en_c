#include <stdio.h>
struct coordenadas{
    int longitud;
    int latitud;
};
struct domicilio{
    char calle[50];
    int numero;
    struct coordenadas ubicacion;

};
struct alumno{
    char nombre[50];
    int matricula;
    struct domicilio direccion;

};
int main(){
    struct alumno estudiante1={"ulysses santiago",12345,{"benito jaurez",123,{54321,98765}}};
    printf("nombre:%s\n",estudiante1.nombre);
    printf("direccion:%s #%d\n",estudiante1.direccion.calle, estudiante1.direccion.numero);
    printf("coordenadas:%d,%d",estudiante1.direccion.ubicacion.latitud,estudiante1.direccion.ubicacion.longitud);
return 0;
}