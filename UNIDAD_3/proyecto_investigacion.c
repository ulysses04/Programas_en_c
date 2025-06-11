#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h> 

#define CONSOLE_WIDTH 80 

typedef struct {
    int id_programa;
    char nombre[71]; 
} Programa;

typedef struct {
    char dni[16]; 
    char nombre[71];
    char apellido[71];
    char titulacion[71];
    int anios_experiencia;
} Profesor;

typedef struct {
    int id_departamento;
    char nombre[71];
    char campus[71];
    char telefono[16]; 
    char dni_director[16]; 
} Departamento;

typedef struct {
    int id_grupo;
    char nombre[71];
    int id_departamento; 
    char dni_lider[16]; 
} Grupo;

typedef struct {
    int id_proyecto;
    char nombre[71];
    char fecha_inicio[11]; 
    char fecha_fin[11];    
    float presupuesto;     
    int id_grupo;          
} Proyecto;

typedef struct {
    float cantidad_aportada; 
    int id_proyecto;         
    int id_programa;         
} Financiamiento;

typedef struct {
    char dni_profesor[16];   
    int id_proyecto;         
    char fecha_incorporacion[11]; 
    char fecha_salida[11];        
} Participa;

MYSQL *con;

void finish_with_error() {
    fprintf(stderr, "Error de MySQL: %s\n", mysql_error(con));
    if (con != NULL) {
        mysql_close(con);
    }
    exit(1);
}

void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() falló\n");
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "12345", "proyecto_investigacion", 3306, NULL, 0) == NULL) {
        finish_with_error();
    }
    printf("Conexión a la base de datos establecida correctamente.\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_string_input(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
}

void gotoxy(int x, int y){
    printf("\033[%d;%dH", y, x);
}

void limpiar_pantalla() {
    printf("\033[2J");   
    printf("\033[1;1H"); 
}

void display_main_menu() {
    limpiar_pantalla(); 
    int start_y = 5; 

    char *title = "----- GESTION DE PROYECTOS DE INVESTIGACION -----";
    char *option1 = "1. Gestionar Programas";
    char *option2 = "2. Gestionar Profesores";
    char *option3 = "3. Gestionar Departamentos";
    char *option4 = "4. Gestionar Grupos";
    char *option5 = "5. Gestionar Proyectos";
    char *option6 = "6. Gestionar Financiamientos";
    char *option7 = "7. Gestionar Participaciones";
    char *option8 = "8. Salir";
    char *prompt = "Opcion: ";

    gotoxy((CONSOLE_WIDTH - strlen(title)) / 2, start_y++);
    printf("%s\n", title);
    start_y++; 

    gotoxy((CONSOLE_WIDTH - strlen(option1)) / 2, start_y++);
    printf("%s\n", option1);
    gotoxy((CONSOLE_WIDTH - strlen(option2)) / 2, start_y++);
    printf("%s\n", option2);
    gotoxy((CONSOLE_WIDTH - strlen(option3)) / 2, start_y++);
    printf("%s\n", option3);
    gotoxy((CONSOLE_WIDTH - strlen(option4)) / 2, start_y++);
    printf("%s\n", option4);
    gotoxy((CONSOLE_WIDTH - strlen(option5)) / 2, start_y++);
    printf("%s\n", option5);
    gotoxy((CONSOLE_WIDTH - strlen(option6)) / 2, start_y++);
    printf("%s\n", option6);
    gotoxy((CONSOLE_WIDTH - strlen(option7)) / 2, start_y++);
    printf("%s\n", option7);
    gotoxy((CONSOLE_WIDTH - strlen(option8)) / 2, start_y++);
    printf("%s\n", option8);
    start_y++; 

    gotoxy((CONSOLE_WIDTH - strlen(prompt)) / 2, start_y++);
    printf("%s", prompt);
}

void display_crud_menu(const char* table_name, int* opcion) {
    limpiar_pantalla(); 
    int start_y = 5; 

    char title_buffer[100];
    snprintf(title_buffer, sizeof(title_buffer), "----- GESTION DE %sS -----", table_name);

    char *option1 = "1. Insertar";
    char *option2 = "2. Consultar";
    char *option3 = "3. Modificar";
    char *option4 = "4. Eliminar";
    char *option0 = "0. Volver al menu principal";
    char *prompt = "Opcion: ";

    gotoxy((CONSOLE_WIDTH - strlen(title_buffer)) / 2, start_y++);
    printf("%s\n", title_buffer);
    start_y++;

    gotoxy((CONSOLE_WIDTH - strlen(option1)) / 2, start_y++);
    printf("%s\n", option1);
    gotoxy((CONSOLE_WIDTH - strlen(option2)) / 2, start_y++);
    printf("%s\n", option2);
    gotoxy((CONSOLE_WIDTH - strlen(option3)) / 2, start_y++);
    printf("%s\n", option3);
    gotoxy((CONSOLE_WIDTH - strlen(option4)) / 2, start_y++);
    printf("%s\n", option4);
    gotoxy((CONSOLE_WIDTH - strlen(option0)) / 2, start_y++);
    printf("%s\n", option0);
    start_y++;

    gotoxy((CONSOLE_WIDTH - strlen(prompt)) / 2, start_y++);
    printf("%s", prompt);
    
    if (scanf("%d", opcion) != 1) { 
        clear_input_buffer(); 
        *opcion = -1; 
    }
    clear_input_buffer(); 
}

void insert_programa() {
    limpiar_pantalla(); 
    Programa p;
    printf("--- Insertar Programa ---\n");
    printf("Nombre del programa: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO programa (nombre) VALUES('%s')", p.nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa insertado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_programas() {
    limpiar_pantalla(); 
    printf("--- Listado de Programas ---\n");
    if (mysql_query(con, "SELECT id_programa, nombre FROM programa")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-5s %-40s\n", "ID", "Nombre");
    printf("-------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%-5s %-40s\n", row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void update_programa() {
    limpiar_pantalla(); 
    Programa p;
    printf("--- Actualizar Programa ---\n");
    read_programas(); 
    printf("ID del programa a actualizar: ");
    if (scanf("%d", &p.id_programa) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    printf("Nuevo nombre del programa: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));

    char query[256];
    snprintf(query, sizeof(query), "UPDATE programa SET nombre='%s' WHERE id_programa=%d", p.nombre, p.id_programa);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa actualizado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_programa() {
    limpiar_pantalla(); 
    int id;
    printf("--- Eliminar Programa ---\n");
    read_programas(); 
    printf("ID del programa a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM programa WHERE id_programa=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa eliminado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_profesor() {
    limpiar_pantalla(); 
    Profesor p;
    printf("--- Insertar Profesor ---\n");
    printf("DNI: ");
    clear_input_buffer(); 
    get_string_input(p.dni, sizeof(p.dni));

    printf("Nombre: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Apellido: ");
    clear_input_buffer(); 
    get_string_input(p.apellido, sizeof(p.apellido));
    printf("Titulacion: ");
    clear_input_buffer(); 
    get_string_input(p.titulacion, sizeof(p.titulacion));
    printf("Anios de experiencia: ");
    if (scanf("%d", &p.anios_experiencia) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO profesor (dni, nombre, apellido, titulacion, anios_experiencia) VALUES('%s', '%s', '%s', '%s', %d)",
             p.dni, p.nombre, p.apellido, p.titulacion, p.anios_experiencia);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Profesor insertado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_profesores() {
    limpiar_pantalla(); 
    printf("--- Listado de Profesores ---\n");
    if (mysql_query(con, "SELECT dni, nombre, apellido, titulacion, anios_experiencia FROM profesor")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-15s %-25s %-25s %-30s %-10s\n", "DNI", "Nombre", "Apellido", "Titulacion", "Experiencia");
    printf("-----------------------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("DNI: %s, Nombre: %s %s, Titulacion: %s, Experiencia: %s\n",
               row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL",
               row[3] ? row[3] : "NULL", row[4] ? row[4] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void update_profesor() {
    limpiar_pantalla(); 
    Profesor p;
    printf("--- Actualizar Profesor ---\n");
    read_profesores(); 
    printf("DNI del profesor a actualizar: ");
    clear_input_buffer(); 
    get_string_input(p.dni, sizeof(p.dni));

    printf("Nuevo nombre: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Nuevo apellido: ");
    clear_input_buffer(); 
    get_string_input(p.apellido, sizeof(p.apellido));
    printf("Nueva titulacion: ");
    clear_input_buffer(); 
    get_string_input(p.titulacion, sizeof(p.titulacion));
    printf("Nuevos anios de experiencia: ");
    if (scanf("%d", &p.anios_experiencia) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE profesor SET nombre='%s', apellido='%s', titulacion='%s', anios_experiencia=%d WHERE dni='%s'",
             p.nombre, p.apellido, p.titulacion, p.anios_experiencia, p.dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Profesor actualizado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_profesor() {
    limpiar_pantalla(); 
    char dni[16];
    printf("--- Eliminar Profesor ---\n");
    read_profesores(); 
    printf("DNI del profesor a eliminar: ");
    clear_input_buffer(); 
    get_string_input(dni, sizeof(dni));

    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM profesor WHERE dni='%s'", dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Profesor eliminado correctamente .\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_departamento() {
    limpiar_pantalla(); 
    Departamento d;
    printf("--- Insertar Departamento ---\n");
    printf("Nombre del departamento: ");
    clear_input_buffer(); 
    get_string_input(d.nombre, sizeof(d.nombre));
    printf("Campus: ");
    clear_input_buffer(); 
    get_string_input(d.campus, sizeof(d.campus));
    printf("Telefono: ");
    clear_input_buffer(); 
    get_string_input(d.telefono, sizeof(d.telefono));
    read_profesores(); 
    printf("DNI del Director : ");
    clear_input_buffer(); 
    get_string_input(d.dni_director, sizeof(d.dni_director));

    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO departamento (nombre, campus, telefono, dni) VALUES('%s', '%s', '%s', '%s')",
             d.nombre, d.campus, d.telefono, d.dni_director);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Departamento insertado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_departamentos() {
    limpiar_pantalla(); 
    printf("--- Listado de Departamentos ---\n");
    if (mysql_query(con, "SELECT d.id_departamento, d.nombre, d.campus, d.telefono, p.nombre, p.apellido FROM departamento d LEFT JOIN profesor p ON d.dni = p.dni")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-5s %-25s %-20s %-15s %-30s\n", "ID", "Nombre", "Campus", "Telefono", "Director");
    printf("---------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%-5s %-25s %-20s %-15s %s %s\n",
               row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL",
               row[3] ? row[3] : "NULL", row[4] ? row[4] : "NULL", row[5] ? row[5] : "");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void update_departamento() {
    limpiar_pantalla(); 
    Departamento d;
    printf("--- Actualizar Departamento ---\n");
    read_departamentos(); 
    printf("ID del departamento a actualizar: ");
    if (scanf("%d", &d.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    printf("Nuevo nombre: ");
    clear_input_buffer(); 
    get_string_input(d.nombre, sizeof(d.nombre));
    printf("Nuevo campus: ");
    clear_input_buffer(); 
    get_string_input(d.campus, sizeof(d.campus));
    printf("Nuevo telefono: ");
    clear_input_buffer(); 
    get_string_input(d.telefono, sizeof(d.telefono));
    read_profesores(); 
    printf("Nuevo DNI del Director : ");
    clear_input_buffer(); 
    get_string_input(d.dni_director, sizeof(d.dni_director));

    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE departamento SET nombre='%s', campus='%s', telefono='%s', dni='%s' WHERE id_departamento=%d",
             d.nombre, d.campus, d.telefono, d.dni_director, d.id_departamento);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Departamento actualizado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_departamento() {
    limpiar_pantalla(); 
    int id;
    printf("--- Eliminar Departamento ---\n");
    read_departamentos(); 
    printf("ID del departamento a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM departamento WHERE id_departamento=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Departamento eliminado correctamente .\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_grupo() {
    limpiar_pantalla(); 
    Grupo g;
    printf("--- Insertar Grupo ---\n");
    printf("Nombre del grupo: ");
    clear_input_buffer(); 
    get_string_input(g.nombre, sizeof(g.nombre));
    read_departamentos(); 
    printf("ID del Departamento : ");
    if (scanf("%d", &g.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    read_profesores(); 
    printf("DNI del Lider : ");
    clear_input_buffer(); 
    get_string_input(g.dni_lider, sizeof(g.dni_lider));

    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO grupo (nombre, id_departamento, dni) VALUES('%s', %d, '%s')",
             g.nombre, g.id_departamento, g.dni_lider);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Grupo insertado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_grupos() {
    limpiar_pantalla(); 
    printf("--- Listado de Grupos ---\n");
    if (mysql_query(con, "SELECT g.id_grupo, g.nombre, d.nombre AS departamento, p.nombre AS lider_nombre, p.apellido AS lider_apellido FROM grupo g JOIN departamento d ON g.id_departamento = d.id_departamento LEFT JOIN profesor p ON g.dni = p.dni")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-5s %-25s %-25s %-30s\n", "ID", "Nombre Grupo", "Departamento", "Lider");
    printf("----------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Nombre: %s, Departamento: %s, Lider: %s %s\n",
               row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL",
               row[3] ? row[3] : "NULL", row[4] ? row[4] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void update_grupo() {
    limpiar_pantalla(); 
    Grupo g;
    printf("--- Actualizar Grupo ---\n");
    read_grupos(); 
    printf("ID del grupo a actualizar: ");
    if (scanf("%d", &g.id_grupo) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    printf("Nuevo nombre del grupo: ");
    clear_input_buffer(); 
    get_string_input(g.nombre, sizeof(g.nombre));
    read_departamentos();
    printf("Nuevo ID del Departamento : ");
    if (scanf("%d", &g.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    read_profesores();
    printf("Nuevo DNI del Lider : ");
    clear_input_buffer(); 
    get_string_input(g.dni_lider, sizeof(g.dni_lider));

    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE grupo SET nombre='%s', id_departamento=%d, dni='%s' WHERE id_grupo=%d",
             g.nombre, g.id_departamento, g.dni_lider, g.id_grupo);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Grupo actualizado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_grupo() {
    limpiar_pantalla(); 
    int id;
    printf("--- Eliminar Grupo ---\n");
    read_grupos(); 
    printf("ID del grupo a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM grupo WHERE id_grupo=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Grupo eliminado correctamente .\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_proyecto() {
    limpiar_pantalla(); 
    Proyecto p;
    printf("--- Insertar Proyecto ---\n");
    printf("Nombre del proyecto: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Fecha de inicio (YYYY-MM-DD): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_inicio, sizeof(p.fecha_inicio));
    printf("Fecha de fin (YYYY-MM-DD): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_fin, sizeof(p.fecha_fin));
    printf("Presupuesto: ");
    if (scanf("%f", &p.presupuesto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    read_grupos(); 
    printf("ID del Grupo : ");
    if (scanf("%d", &p.id_grupo) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO proyecto (nombre, fecha_inicio, fecha_fin, presupuesto, id_grupo) VALUES('%s', '%s', '%s', %.2f, %d)",
             p.nombre, p.fecha_inicio, p.fecha_fin, p.presupuesto, p.id_grupo);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto insertado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_proyectos() {
    limpiar_pantalla(); 
    printf("--- Listado de Proyectos ---\n");
    if (mysql_query(con, "SELECT p.id_proyecto, p.nombre, p.fecha_inicio, p.fecha_fin, p.presupuesto, g.nombre AS grupo FROM proyecto p JOIN grupo g ON p.id_grupo = g.id_grupo")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-5s %-25s %-12s %-12s %-12s %-25s\n", "ID", "Nombre Proyecto", "Inicio", "Fin", "Presupuesto", "Grupo");
    printf("----------------------------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Nombre: %s, Inicio: %s, Fin: %s, Presupuesto: %s, Grupo: %s\n",
               row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL",
               row[3] ? row[3] : "NULL", row[4] ? row[4] : "NULL", row[5] ? row[5] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void update_proyecto() {
    limpiar_pantalla(); 
    Proyecto p;
    printf("--- Actualizar Proyecto ---\n");
    read_proyectos(); 
    printf("ID del proyecto a actualizar: ");
    if (scanf("%d", &p.id_proyecto) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    printf("Nuevo nombre del proyecto: ");
    clear_input_buffer(); 
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Nueva fecha de inicio (YYYY-MM-DD): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_inicio, sizeof(p.fecha_inicio));
    printf("Nueva fecha de fin (YYYY-MM-DD): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_fin, sizeof(p.fecha_fin));
    printf("Nuevo presupuesto: ");
    if (scanf("%f", &p.presupuesto) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    read_grupos();
    printf("Nuevo ID del Grupo (debe existir): ");
    if (scanf("%d", &p.id_grupo) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE proyecto SET nombre='%s', fecha_inicio='%s', fecha_fin='%s', presupuesto=%.2f, id_grupo=%d WHERE id_proyecto=%d",
             p.nombre, p.fecha_inicio, p.fecha_fin, p.presupuesto, p.id_grupo, p.id_proyecto);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto actualizado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_proyecto() {
    limpiar_pantalla(); 
    int id;
    printf("--- Eliminar Proyecto ---\n");
    read_proyectos(); 
    printf("ID del proyecto a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM proyecto WHERE id_proyecto=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto eliminado correctamente (cuidado con financiamientos/participaciones).\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_financiamiento() {
    limpiar_pantalla(); 
    Financiamiento f;
    printf("--- Insertar Financiamiento ---\n");
    read_proyectos(); 
    printf("ID del Proyecto (debe existir): ");
    if (scanf("%d", &f.id_proyecto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    read_programas(); 
    printf("ID del Programa : ");
    if (scanf("%d", &f.id_programa) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    printf("Cantidad aportada: ");
    if (scanf("%f", &f.cantidad_aportada) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO financiamiento (cantidad_aportada, id_proyecto, id_programa) VALUES(%.2f, %d, %d)",
             f.cantidad_aportada, f.id_proyecto, f.id_programa);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Financiamiento registrado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_financiamientos() {
    limpiar_pantalla(); 
    printf("--- Listado de Financiamientos ---\n");
    if (mysql_query(con, "SELECT f.cantidad_aportada, p.nombre AS proyecto_nombre, pr.nombre AS programa_nombre FROM financiamiento f JOIN proyecto p ON f.id_proyecto = p.id_proyecto JOIN programa pr ON f.id_programa = pr.id_programa")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-15s %-30s %-30s\n", "Cantidad", "Proyecto", "Programa");
    printf("--------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("Proyecto: %s, Programa: %s, Cantidad Aportada: %s\n",
               row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL", row[0] ? row[0] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_financiamiento() {
    limpiar_pantalla(); 
    int id_proj, id_prog;
    printf("--- Eliminar Financiamiento ---\n");
    read_financiamientos(); 
    printf("ID del Proyecto del financiamiento a eliminar: ");
    if (scanf("%d", &id_proj) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    printf("ID del Programa del financiamiento a eliminar: ");
    if (scanf("%d", &id_prog) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM financiamiento WHERE id_proyecto=%d AND id_programa=%d", id_proj, id_prog);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Financiamiento eliminado correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void insert_participa() {
    limpiar_pantalla(); 
    Participa p;
    printf("--- Insertar Participacion ---\n");
    read_profesores(); 
    printf("DNI del Profesor (debe existir): ");
    clear_input_buffer(); 
    get_string_input(p.dni_profesor, sizeof(p.dni_profesor));
    read_proyectos(); 
    printf("ID del Proyecto (debe existir): ");
    if (scanf("%d", &p.id_proyecto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return; 
    }
    clear_input_buffer(); 
    printf("Fecha de incorporacion (YYYY-MM-DD): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_incorporacion, sizeof(p.fecha_incorporacion));
    printf("Fecha de salida (YYYY-MM-DD, o NULL si no ha salido): ");
    clear_input_buffer(); 
    get_string_input(p.fecha_salida, sizeof(p.fecha_salida));

    char query[512];
    if (strcmp(p.fecha_salida, "NULL") == 0 || strlen(p.fecha_salida) == 0) {
        snprintf(query, sizeof(query),
                 "INSERT INTO participa (dni, id_proyecto, fecha_incorporacion, fecha_salida) VALUES('%s', %d, '%s', NULL)",
                 p.dni_profesor, p.id_proyecto, p.fecha_incorporacion);
    } else {
        snprintf(query, sizeof(query),
                 "INSERT INTO participa (dni, id_proyecto, fecha_incorporacion, fecha_salida) VALUES('%s', %d, '%s', '%s')",
                 p.dni_profesor, p.id_proyecto, p.fecha_incorporacion, p.fecha_salida);
    }
    
    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Participacion registrada correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void read_participaciones() {
    limpiar_pantalla(); 
    printf("--- Listado de Participaciones ---\n");
    if (mysql_query(con, "SELECT pa.fecha_incorporacion, pa.fecha_salida, pr.nombre AS profesor_nombre, pr.apellido AS profesor_apellido, proy.nombre AS proyecto_nombre FROM participa pa JOIN profesor pr ON pa.dni = pr.dni JOIN proyecto proy ON pa.id_proyecto = proy.id_proyecto")) {
        finish_with_error();
    }
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("%-25s %-30s %-12s %-12s\n", "Profesor", "Proyecto", "Incorporacion", "Salida");
    printf("----------------------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("Profesor: %s %s, Proyecto: %s, Incorporacion: %s, Salida: %s\n",
               row[2] ? row[2] : "NULL", row[4] ? row[4] : "NULL", row[0] ? row[0] : "NULL", row[1] ? row[1] : "NULL");
    }
    mysql_free_result(result);
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void delete_participa() {
    limpiar_pantalla(); 
    char dni[16];
    int id_proj;
    printf("--- Eliminar Participacion ---\n");
    read_participaciones(); 
    printf("DNI del Profesor de la participacion a eliminar: ");
    clear_input_buffer(); 
    get_string_input(dni, sizeof(dni));
    printf("ID del Proyecto de la participacion a eliminar: ");
    if (scanf("%d", &id_proj) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        printf("\nPresiona ENTER para continuar...");
        get_string_input((char[2]){0}, 2); 
        limpiar_pantalla(); 
        return;
    }
    clear_input_buffer(); 
    
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM participa WHERE dni='%s' AND id_proyecto=%d", dni, id_proj);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Participacion eliminada correctamente.\n");
    }
    printf("\nPresiona ENTER para continuar...");
    get_string_input((char[2]){0}, 2); 
    limpiar_pantalla(); 
}

void menu_programa() {
    int opcion;
    do {
        display_crud_menu("PROGRAMA", &opcion); 
        switch (opcion) {
            case 1: insert_programa();
             break;
            case 2: read_programas(); 
            break;
            case 3: update_programa();
             break;
            case 4: delete_programa();
             break;
            case 0:
             break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_profesor() {
    int opcion;
    do {
        display_crud_menu("PROFESOR", &opcion); 
        switch (opcion) {
            case 1: insert_profesor(); 
            break;
            case 2: read_profesores();
             break;
            case 3: update_profesor();
             break;
            case 4: delete_profesor();
             break;
            case 0: 
            break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_departamento() {
    int opcion;
    do {
        display_crud_menu("DEPARTAMENTO", &opcion); 
        switch (opcion) {
            case 1: insert_departamento(); 
            break;
            case 2: read_departamentos(); 
            break;
            case 3: update_departamento(); 
            break;
            case 4: delete_departamento(); 
            break;
            case 0: 
            break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_grupo() {
    int opcion;
    do {
        display_crud_menu("GRUPO", &opcion); 
        switch (opcion) {
            case 1: insert_grupo(); 
            break;
            case 2: read_grupos(); 
            break;
            case 3: update_grupo(); 
            break;
            case 4: delete_grupo(); 
            break;
            case 0: 
            break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_proyecto() {
    int opcion;
    do {
        display_crud_menu("PROYECTO", &opcion); 
        switch (opcion) {
            case 1: insert_proyecto(); 
            break;
            case 2: read_proyectos(); 
            break;
            case 3: update_proyecto();
             break;
            case 4: delete_proyecto(); 
            break;
            case 0: break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_financiamiento() {
    int opcion;
    do {
        display_crud_menu("FINANCIAMIENTO", &opcion); 
        switch (opcion) {
            case 1: insert_financiamiento();
             break;
            case 2: read_financiamientos();
             break;
            case 4: delete_financiamiento();
             break; 
            case 0: 
            break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

void menu_participa() {
    int opcion;
    do {
        display_crud_menu("PARTICIPACION", &opcion); 
        switch (opcion) {
            case 1: insert_participa(); 
            break;
            case 2: read_participaciones();
             break;
            case 4: delete_participa(); 
            break; 
            case 0:
             break; 
            default: 
                limpiar_pantalla(); 
                printf("Opcion no valida. Intente de nuevo.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (opcion != 0);
}

int main() {
    conectar(); 

    int main_opc;

    do {
        display_main_menu(); 
        if (scanf("%d", &main_opc) != 1) {
            printf("Entrada invalida. Por favor, ingresa un numero.\n");
            main_opc = -1; 
            clear_input_buffer(); 
            printf("\nPresiona ENTER para continuar...");
            get_string_input((char[2]){0}, 2); 
            limpiar_pantalla(); 
            continue;
        }
        clear_input_buffer(); 

        switch (main_opc) {
            case 1: menu_programa(); 
            break;
            case 2: menu_profesor(); 
            break;
            case 3: menu_departamento();
             break;
            case 4: menu_grupo(); 
            break;
            case 5: menu_proyecto();
             break;
            case 6: menu_financiamiento();
             break;
            case 7: menu_participa(); 
            break;
            case 8: 
                limpiar_pantalla();
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default: 
                limpiar_pantalla(); 
                printf("Opcion invalida. Por favor, selecciona un numero entre 1 y 8.\n"); 
                printf("\nPresiona ENTER para continuar...");
                get_string_input((char[2]){0}, 2); 
                limpiar_pantalla(); 
                break;
        }
    } while (main_opc != 8); 

    mysql_close(con); 
    return 0;
}
