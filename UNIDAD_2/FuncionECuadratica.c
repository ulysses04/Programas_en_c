#include <stdio.h>
#include <math.h> 

int discriminante(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

float calneg(int a, int b, int c) { 
    return (-b - sqrt(discriminante(a, b, c))) / (2.0 * a); 
}

float calpos(int a, int b, int c) { 
    return (-b + sqrt(discriminante(a, b, c))) / (2.0 * a); 
}

int main() {
    int a, b, c;

    printf("introduzca a: \n");
    scanf("%d", &a);
    printf("introduzca b:\n ");
    scanf("%d", &b);
    printf("introduzca c:\n ");
    scanf("%d", &c);

    int disc = discriminante(a, b, c); 

    if (disc < 0) { 
        printf("el discriminante es negativo.\n");
    } else {
        printf("raices son: (%.2f, %.2f)\n", calneg(a, b, c), calpos(a, b, c));
    }

    return 0;
}
