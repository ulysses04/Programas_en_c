#include <stdio.h>
#define dolar 20.33  
#define euro 21.96  
#define libreest 26.27
float pesoadolar(float pesos) {
    return pesos / dolar;
}

float dolarapeso(float dolares) {
    return dolares * dolar;
}

float pesoaeuro(float pesos) {
    return pesos / euro;
}
float euroapeso (float euros) {
    return euros*euro;
}
float pesoalibra(float pesos) {
    return pesos / libreest;
}
float libraapeso(float libras) {
    return libras* libreest;
}

int main(){
    int opcion;
    float cantidad, resultado;
    printf("Seleccione una opcion de conversion:\n");
    printf("1. Peso a Dolar\n");
    printf("2. Dolar a Peso\n");
    printf("3. Peso a Euro\n");
    printf("4. Euro a Peso\n");
    printf("5. Peso a Libra Esterlina\n");
    printf("6. Libra Esterlina a Peso\n");
    scanf("%d", &opcion);

    printf("Ingrese la cantidad: ");
    scanf("%f", &cantidad);

    switch(opcion) {
        case 1:
            resultado = pesoadolar(cantidad);
            printf("Los pesos a dolares son: %.2f\n", resultado);
            break;
        case 2:
            resultado = dolarapeso(cantidad);
            printf("Los dolares a pesos son: %.2f\n", resultado);
            break;
        case 3:
            resultado = pesoaeuro(cantidad);
            printf("Los pesos a euros: %.2f\n", resultado);
            break;
        case 4:
            resultado = euroapeso(cantidad);
            printf("Los euros a pesos son : %.2f\n", resultado);
            break;
        case 5:
            resultado = pesoalibra(cantidad);
            printf("Los pesos a libras son : %.2f\n", resultado);
            break;
        case 6:
            resultado = libraapeso(cantidad);
            printf("Las libras a pesos son: %.2f\n", resultado);
            break;
        default:
            printf("No ha seleccionado una opción valida");
            break;
    }

    return 0;
    
}