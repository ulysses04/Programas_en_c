#include <math.h>
#include <stdio.h>
struct coordenada{
    int x;
    int y;
};
int main(){
    int opc;
    int i;

    struct coordenada arreglo[4];

    printf("%s\n", "Seleccione una opcion:");
    printf("%s\n", "1. Cuadrado");
    printf("%s\n", "2. Triángulo");
    scanf("%d", &opc);

    switch (opc) {
        case 1: // Cuadrado
            for (i = 0; i < 4; i++) {
                printf("Ingrese coordenada x%d: ", i + 1);
                scanf("%d", &arreglo[i].x);

                printf("Ingrese coordenada y%d: ", i + 1);
                scanf("%d", &arreglo[i].y);
            }

            // Distancias entre puntos consecutivos
            float ab = sqrt(
                pow(arreglo[1].x - arreglo[0].x, 2) +
                pow(arreglo[1].y - arreglo[0].y, 2));

            float bc = sqrt(
                pow(arreglo[2].x - arreglo[1].x, 2) +
                pow(arreglo[2].y - arreglo[1].y, 2));

            float cd = sqrt(
                pow(arreglo[3].x - arreglo[2].x, 2) +
                pow(arreglo[3].y - arreglo[2].y, 2));

            float da = sqrt(
                pow(arreglo[0].x - arreglo[3].x, 2) +
                pow(arreglo[0].y - arreglo[3].y, 2));

            float perimetro = ab + bc + cd + da;
            float area = ab * bc; // Solo válido si es cuadrado o rectángulo

            printf("Perimetro total: %f\n", perimetro);
            printf("area: %f\n", area);
            break;

        default:
            printf("Opcion no valida\n");
            break;

}

}