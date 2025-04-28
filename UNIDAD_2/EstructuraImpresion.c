#include <stdio.h>
struct direccion{
    char calle[50];
    int numero;

};
struct persona{
    char nombre[50];
    struct direccion domicilio;

};
int main(){
    int n;
    printf("ingrese el numero de personas:");
    scanf("%d",&n);
    getchar();
    struct persona personas[n];
    for(int i=0; i<n;i++){
        printf("\ningrese los datos de la persona %d:\n",i+1);
        printf("nombre: ");
        scanf(" %[^\n]",personas[i].nombre);
        printf("calle: ");
        scanf(" %[^\n]",personas[i].domicilio.calle);
        printf("numero: ");
        scanf("%d",&personas[i].domicilio.numero);
        getchar();
    }
    printf("\n%-20s | %-20s | %-10s\n","nombre","direccion","numero");
    printf("-----------------------------------------------------------\n");

    for(int i=0; i<n; i++){
        printf("%-20s | %-20s | %-10d\n",
        personas[i].nombre,
    personas[i].domicilio.calle,
personas[i].domicilio.numero);
    }
    return 0;
}