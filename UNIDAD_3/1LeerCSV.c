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
    char ruta[MAX] = "../"; 
    char archive[MAX];


    printf("  archivo: ");
    scanf("%s", archive);
    strcat(archive, ".csv"); 
    strcat(ruta, archive);



    file = fopen(ruta, "w");   
    if (file == NULL) {
        perror("Error al crear el archivo");
        return 1;
    }

    // Escribir encabezado
    fprintf(file, "nombre,edad,pais\n");

    limpiarpantalla();
    gotoxy(5, 5);
    printf("personas: ");
    scanf("%d", &cantidad);
    getchar(); 

    for (i = 0; i < cantidad; i++) {
        limpiarpantalla();
        gotoxy(10, 10);

        printf("\nPersona %d\n", i + 1);

        printf("Nombre: ");
        fgets(nombre, MAX, stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        printf("Edad: ");
        scanf("%d", &edad);
        getchar();

        printf("Pais: ");
        fgets(pais, MAX, stdin);
        pais[strcspn(pais, "\n")] = 0;

    
        setColor("\033[7;32m");
        printf("%s,%d,%s\n", nombre, edad, pais);
        setColor("\033[0m");

       
        fprintf(file, "%s,%d,%s\n", nombre, edad, pais);
    }

  
    fclose(file);
    

   
    file = fopen(ruta, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo para leer");
        return 1;
    }

    setColor("\033[1;36m");
    printf("\n%-50s %-10s %-15s\n", "nombre", "edad", "pais");
    printf("------------------------------------------------------------------------------------------------\n");
    setColor("\033[0m");

    int encabezado = 1;
    while (fgets(linea, MAX, file) != NULL) {
        linea[strcspn(linea, "\n")] = 0;

        if (encabezado) {
            encabezado = 0;
            continue; 
        }

        char *nombre = strtok(linea, ",");
        char *edad_str = strtok(NULL, ",");
        char *pais = strtok(NULL, ",");

        
        int edad = 0;
        char *endptr;
        if (edad_str != NULL) {
            edad = (int)strtol(edad_str, &endptr, 10);
           
        }

        if (nombre && pais) {
            printf("%-50s %-10d %-15s\n", nombre, edad, pais);
            printf("-------------------------------------------------------------------------------\n");
        }
    }

    fclose(file);
    
    return 0;
}
