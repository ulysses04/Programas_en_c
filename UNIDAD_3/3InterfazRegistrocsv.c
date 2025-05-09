#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void limpiarpantalla(){
    printf("\033[2J");
}
void setColor(const char* color) {
    printf("%s", color);
}

void gotoxy(int x, int y){
    printf("\033[%d;%dH", y, x);
}

int main(){
    FILE *file;
    char nombre[MAX];
    int edad;
    char pais[MAX];
    int cantidad, i;
    char linea[MAX];

    // abrir el archivo en modo lectura
    file = fopen("../2salida2.csv", "w");
    if (file == NULL){
        perror("error al abrir el archivo");
        return 1;
    }
    // escribir encabezados
    fprintf(file, "nombre,edad,pais\n");

    limpiarpantalla();
    gotoxy(5, 5);
    printf("cuantas personas quieres registrar: ");
    scanf("%d", &cantidad);
    getchar();
    
    for (i = 0; i < cantidad; i++) {
        limpiarpantalla();
        gotoxy(10,10);
        
        printf("\npersona %d\n", i + 1);
    
        printf("nombre: ");
        fgets(nombre, MAX, stdin);
        nombre[strcspn(nombre,"\n")] = 0;
    
        printf("edad: ");
        scanf("%d",&edad);
        getchar();
    
        printf("pais: ");
        fgets(pais,MAX, stdin);
        pais[strcspn(pais, "\n")] =0;
    
        
        setColor("\033[7;32m");
        printf("%s,%d,%s\n", nombre, edad, pais);
        setColor("\033[0m");
    
        
        fprintf(file, "%s,%d,%s\n", nombre, edad, pais);
    }
    

        // cerrar el archivo de escritura
        fclose(file);
        printf("\nArchivo 'salida.csv' creado exitosamente.\n");
    
        // Abrir el archivo en modo lectura
        file = fopen("../2salida2.csv", "r");
        if (file == NULL){
            perror("error al abrir el archivo para lectura");
            return 1;
        }
    
        
    
    
        setColor("\033[1;36m");
        printf("%-50s %-10s %-15s\n","nombre","edad","pais");
        printf("-------------------------------------------\n");
        while (fgets(linea, MAX, file) != NULL) {
            printf("%s", linea);  
        }
        setColor("\033[0m");
    
        fclose(file);
    
    return 0;
}
