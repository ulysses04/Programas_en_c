#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h> // ¡¡¡Ajusta esta ruta a tu instalación de MySQL!!!

// --- Estructuras para cada tabla ---
typedef struct {
    int id_programa;
    char nombre[71]; // VARCHAR(70) + NUL
} Programa;

typedef struct {
    char dni[16]; // VARCHAR(15) + NUL
    char nombre[71];
    char apellido[71];
    char titulacion[71];
    int anios_experiencia;
} Profesor;

typedef struct {
    int id_departamento;
    char nombre[71];
    char campus[71];
    char telefono[16]; // VARCHAR(15) + NUL
    char dni_director[16]; // FOREIGN KEY (dni) REFERENCES profesor(dni)
} Departamento;

typedef struct {
    int id_grupo;
    char nombre[71];
    int id_departamento; // FOREIGN KEY
    char dni_lider[16]; // FOREIGN KEY
} Grupo;

typedef struct {
    int id_proyecto;
    char nombre[71];
    char fecha_inicio[11]; // DATE formatoYYYY-MM-DD + NUL
    char fecha_fin[11];    // DATE formatoYYYY-MM-DD + NUL
    float presupuesto;     // DECIMAL(10,2)
    int id_grupo;          // FOREIGN KEY
} Proyecto;

// Financiamiento es una tabla de unión (muchos a muchos)
typedef struct {
    float cantidad_aportada; // DECIMAL(10,2)
    int id_proyecto;         // FOREIGN KEY
    int id_programa;         // FOREIGN KEY
} Financiamiento;

// Participa es una tabla de unión (muchos a muchos)
typedef struct {
    char dni_profesor[16];   // FOREIGN KEY
    int id_proyecto;         // FOREIGN KEY
    char fecha_incorporacion[11]; // DATE
    char fecha_salida[11];        // DATE
} Participa;

// --- Variable global de conexión ---
MYSQL *con;

// --- Funciones de utilidad ---

// Maneja los errores de MySQL y cierra la conexión
void finish_with_error() {
    fprintf(stderr, "Error de MySQL: %s\n", mysql_error(con));
    if (con != NULL) {
        mysql_close(con);
    }
    exit(1);
}

// Establece la conexión a la base de datos
void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() falló\n");
        exit(1);
    }
    // Asegúrate de que la base de datos 'proyecto_investigacion' exista
    if (mysql_real_connect(con, "localhost", "root", "12345", "proyecto_investigacion", 3306, NULL, 0) == NULL) {
        finish_with_error();
    }
    printf("Conexión a la base de datos establecida correctamente.\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters until newline or EOF
    }
}
//     exit(1);
// }
// Placeholder for the MySQL connection (if applicable)
// MYSQL *con;
// Improved get_string_input function
void get_string_input(char *buffer, size_t buffer_size) {
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Remove trailing newline, if present
        size_t len = strcspn(buffer, "\n");
        buffer[len] = '\0';
        // Optional: Check for buffer overflow (if fgets reads the entire buffer without a newline)
        if (len == buffer_size - 1) {
            fprintf(stderr, "Warning: Input might be truncated.\n");
            // Consider additional error handling here, like clearing the rest of the input
        }
    } else {
        // Handle input error (e.g., EOF)
        fprintf(stderr, "Error reading input.\n");
        buffer[0] = '\0'; // Ensure the buffer is empty
    }
}

// --- Funciones CRUD para Programa ---
void insert_programa() {
    Programa p;
    printf("--- Insertar Programa ---\n");
    printf("Nombre del programa: ");
    clear_input_buffer(); // <-- ¡Añadido aquí! (Necesario si la función se llama después de un scanf)
    get_string_input(p.nombre, sizeof(p.nombre));

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO programa (nombre) VALUES('%s')", p.nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa insertado correctamente.\n");
    }
}

void read_programas() {
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
}

void update_programa() {
    Programa p;
    printf("--- Actualizar Programa ---\n");
    read_programas(); 
    printf("ID del programa a actualizar: ");
    if (scanf("%d", &p.id_programa) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return;
    }
    printf("Nuevo nombre del programa: ");
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    get_string_input(p.nombre, sizeof(p.nombre));

    char query[256];
    snprintf(query, sizeof(query), "UPDATE programa SET nombre='%s' WHERE id_programa=%d", p.nombre, p.id_programa);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa actualizado correctamente.\n");
    }
}

void delete_programa() {
    int id;
    printf("--- Eliminar Programa ---\n");
    read_programas(); 
    printf("ID del programa a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return;
    }
    // No se necesita clear_input_buffer() después de este scanf porque no le sigue un get_string_input
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM programa WHERE id_programa=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Programa eliminado correctamente.\n");
    }
}


// --- Funciones CRUD para Profesor ---
void insert_profesor() {
    Profesor p;
    printf("--- Insertar Profesor ---\n");
    printf("DNI: ");
    clear_input_buffer(); // <-- ¡Añadido aquí! (Necesario si la función se llama después de un scanf)
    get_string_input(p.dni, sizeof(p.dni));
    printf("Nombre: ");
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Apellido: ");
    get_string_input(p.apellido, sizeof(p.apellido));
    printf("Titulacion: ");
    get_string_input(p.titulacion, sizeof(p.titulacion));
    printf("Anios de experiencia: ");
    if (scanf("%d", &p.anios_experiencia) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    // No se necesita clear_input_buffer() después de este scanf porque no le sigue un get_string_input
    
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO profesor (dni, nombre, apellido, titulacion, anios_experiencia) VALUES('%s', '%s', '%s', '%s', %d)",
             p.dni, p.nombre, p.apellido, p.titulacion, p.anios_experiencia);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Profesor insertado correctamente.\n");
    }
}

void read_profesores() {
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
}

void update_profesor() {
    Profesor p;
    printf("--- Actualizar Profesor ---\n");
    read_profesores();
    printf("DNI del profesor a actualizar: ");
    get_string_input(p.dni, sizeof(p.dni));
    printf("Nuevo nombre: ");
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Nuevo apellido: ");
    get_string_input(p.apellido, sizeof(p.apellido));
    printf("Nueva titulacion: ");
    get_string_input(p.titulacion, sizeof(p.titulacion));
    printf("Nuevos anios de experiencia: ");
    if (scanf("%d", &p.anios_experiencia) != 1) {
        clear_input_buffer(); // Limpiar si la entrada es inválida
        printf("Entrada invalida.\n");
        return;
    }
    clear_input_buffer(); // Consume the newline left by scanf
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE profesor SET nombre='%s', apellido='%s', titulacion='%s', anios_experiencia=%d WHERE dni='%s'",
             p.nombre, p.apellido, p.titulacion, p.anios_experiencia, p.dni);
             printf("Query: %s\n", query); // Print the query for debugging
    // if (mysql_query(con, query)) { // Uncomment if you are using MySQL directly
    //     finish_with_error();
    // } else {
    //     printf("Profesor actualizado correctamente.\n");
    // }
    printf("Profesor actualizado correctly (placeholder).\n"); // Placeholder
}

void delete_profesor() {
    char dni[16];
    printf("--- Eliminar Profesor ---\n");
    read_profesores();
    printf("DNI del profesor a eliminar: ");
    clear_input_buffer(); // <-- ¡Añadido aquí! (Necesario antes de get_string_input)
    get_string_input(dni, sizeof(dni));

    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM profesor WHERE dni='%s'", dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Profesor eliminado correctamente .\n");
    }
}


// --- Funciones CRUD para Departamento ---
void insert_departamento() {
    Departamento d;
    printf("--- Insertar Departamento ---\n");
    printf("Nombre del departamento: ");
    clear_input_buffer(); // <-- ¡Añadido aquí!
    get_string_input(d.nombre, sizeof(d.nombre));
    printf("Campus: ");
    get_string_input(d.campus, sizeof(d.campus));
    printf("Telefono: ");
    get_string_input(d.telefono, sizeof(d.telefono));
    read_profesores(); 
    printf("DNI del Director : ");
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
}

void read_departamentos() {
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
}

void update_departamento() {
    Departamento d;
    printf("--- Actualizar Departamento ---\n");
    read_departamentos(); 
    printf("ID del departamento a actualizar: ");
    if (scanf("%d", &d.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return;
    }
    printf("Nuevo nombre: ");
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    get_string_input(d.nombre, sizeof(d.nombre));
    printf("Nuevo campus: ");
    get_string_input(d.campus, sizeof(d.campus));
    printf("Nuevo telefono: ");
    get_string_input(d.telefono, sizeof(d.telefono));
    read_profesores(); 
    printf("Nuevo DNI del Director : ");
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
}

void delete_departamento() {
    int id;
    printf("--- Eliminar Departamento ---\n");
    read_departamentos(); 
    printf("ID del departamento a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM departamento WHERE id_departamento=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Departamento eliminado correctamente .\n");
    }
}

// --- Funciones CRUD para Grupo ---
void insert_grupo() {
    Grupo g;
    printf("--- Insertar Grupo ---\n");
    printf("Nombre del grupo: ");
    clear_input_buffer(); // <-- ¡Añadido aquí!
    get_string_input(g.nombre, sizeof(g.nombre));
    read_departamentos(); 
    printf("ID del Departamento : ");
    if (scanf("%d", &g.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    read_profesores(); 
    printf("DNI del Lider : ");
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
}

void read_grupos() {
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
}

void update_grupo() {
    Grupo g;
    printf("--- Actualizar Grupo ---\n");
    read_grupos(); 
    printf("ID del grupo a actualizar: ");
    if (scanf("%d", &g.id_grupo) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return;
    }
    printf("Nuevo nombre del grupo: ");
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    get_string_input(g.nombre, sizeof(g.nombre));
    read_departamentos();
    printf("Nuevo ID del Departamento (debe existir): ");
    if (scanf("%d", &g.id_departamento) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return;
    }
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    read_profesores();
    printf("Nuevo DNI del Lider (debe existir): ");
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
}

void delete_grupo() {
    int id;
    printf("--- Eliminar Grupo ---\n");
    read_grupos(); 
    printf("ID del grupo a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM grupo WHERE id_grupo=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Grupo eliminado correctamente (asegurese de que no tenga proyectos asociados).\n");
    }
}


// --- Funciones CRUD para Proyecto ---
void insert_proyecto() {
    Proyecto p;
    printf("--- Insertar Proyecto ---\n");
    printf("Nombre del proyecto: ");
    clear_input_buffer(); // <-- ¡Añadido aquí!
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Fecha de inicio (YYYY-MM-DD): ");
    get_string_input(p.fecha_inicio, sizeof(p.fecha_inicio));
    printf("Fecha de fin (YYYY-MM-DD): ");
    get_string_input(p.fecha_fin, sizeof(p.fecha_fin));
    printf("Presupuesto: ");
    if (scanf("%f", &p.presupuesto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    read_grupos(); 
    printf("ID del Grupo (debe existir en Grupos): ");
    if (scanf("%d", &p.id_grupo) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO proyecto (nombre, fecha_inicio, fecha_fin, presupuesto, id_grupo) VALUES('%s', '%s', '%s', %.2f, %d)",
             p.nombre, p.fecha_inicio, p.fecha_fin, p.presupuesto, p.id_grupo);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto insertado correctamente.\n");
    }
}

void read_proyectos() {
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
}

void update_proyecto() {
    Proyecto p;
    printf("--- Actualizar Proyecto ---\n");
    read_proyectos(); 
    printf("ID del proyecto a actualizar: ");
    if (scanf("%d", &p.id_proyecto) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return; 
    }
    printf("Nuevo nombre del proyecto: ");
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    get_string_input(p.nombre, sizeof(p.nombre));
    printf("Nueva fecha de inicio (YYYY-MM-DD): ");
    get_string_input(p.fecha_inicio, sizeof(p.fecha_inicio));
    printf("Nueva fecha de fin (YYYY-MM-DD): ");
    get_string_input(p.fecha_fin, sizeof(p.fecha_fin));
    printf("Nuevo presupuesto: ");
    if (scanf("%f", &p.presupuesto) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return;
    }
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    read_grupos();
    printf("Nuevo ID del Grupo (debe existir): ");
    if (scanf("%d", &p.id_grupo) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE proyecto SET nombre='%s', fecha_inicio='%s', fecha_fin='%s', presupuesto=%.2f, id_grupo=%d WHERE id_proyecto=%d",
             p.nombre, p.fecha_inicio, p.fecha_fin, p.presupuesto, p.id_grupo, p.id_proyecto);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto actualizado correctamente.\n");
    }
}

void delete_proyecto() {
    int id;
    printf("--- Eliminar Proyecto ---\n");
    read_proyectos(); 
    printf("ID del proyecto a eliminar: ");
    if (scanf("%d", &id) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return; 
    }
    
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM proyecto WHERE id_proyecto=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Proyecto eliminado correctamente (cuidado con financiamientos/participaciones).\n");
    }
}

// --- Funciones CRUD para Financiamiento (muchos a muchos) ---
void insert_financiamiento() {
    Financiamiento f;
    printf("--- Insertar Financiamiento ---\n");
    read_proyectos(); 
    printf("ID del Proyecto (debe existir): ");
    if (scanf("%d", &f.id_proyecto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return;
    }
    read_programas(); 
    printf("ID del Programa (debe existir): ");
    if (scanf("%d", &f.id_programa) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    printf("Cantidad aportada: ");
    if (scanf("%f", &f.cantidad_aportada) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return; 
    }
    
    char query[256];
    snprintf(query, sizeof(query),
             "INSERT INTO financiamiento (cantidad_aportada, id_proyecto, id_programa) VALUES(%.2f, %d, %d)",
             f.cantidad_aportada, f.id_proyecto, f.id_programa);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Financiamiento registrado correctamente.\n");
    }
}

void read_financiamientos() {
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
}

// Nota: Actualizar financiamiento es complejo por la clave compuesta, se omite para simplicidad del CRUD basico.
// Se enfoca en insertar y eliminar.

void delete_financiamiento() {
    int id_proj, id_prog;
    printf("--- Eliminar Financiamiento ---\n");
    read_financiamientos(); 
    printf("ID del Proyecto del financiamiento a eliminar: ");
    if (scanf("%d", &id_proj) != 1) {
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return;
    }
    printf("ID del Programa del financiamiento a eliminar: ");
    if (scanf("%d", &id_prog) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n"); 
        return; 
    }
    
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM financiamiento WHERE id_proyecto=%d AND id_programa=%d", id_proj, id_prog);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Financiamiento eliminado correctamente.\n");
    }
}


// --- Funciones CRUD para Participa (muchos a muchos) ---
void insert_participa() {
    Participa p;
    printf("--- Insertar Participacion ---\n");
    read_profesores(); 
    printf("DNI del Profesor (debe existir): ");
    clear_input_buffer(); // <-- ¡Añadido aquí!
    get_string_input(p.dni_profesor, sizeof(p.dni_profesor));
    read_proyectos(); 
    printf("ID del Proyecto (debe existir): ");
    if (scanf("%d", &p.id_proyecto) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return; 
    }
    clear_input_buffer(); // MANTENIDO aquí (después de scanf y antes de get_string_input)
    printf("Fecha de incorporacion (YYYY-MM-DD): ");
    get_string_input(p.fecha_incorporacion, sizeof(p.fecha_incorporacion));
    printf("Fecha de salida (YYYY-MM-DD, o NULL si no ha salido): ");
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
}

void read_participaciones() {
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
}

void delete_participa() {
    char dni[16];
    int id_proj;
    printf("--- Eliminar Participacion ---\n");
    read_participaciones(); 
    printf("DNI del Profesor de la participacion a eliminar: ");
    clear_input_buffer(); // <-- ¡Añadido aquí!
    get_string_input(dni, sizeof(dni));
    printf("ID del Proyecto de la participacion a eliminar: ");
    if (scanf("%d", &id_proj) != 1) { 
        clear_input_buffer(); 
        printf("Entrada invalida.\n");
        return;
    }
    
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM participa WHERE dni='%s' AND id_proyecto=%d", dni, id_proj);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Participacion eliminada correctamente.\n");
    }
}


// --- Menús de Tablas ---

void menu_programa() {
    int opcion;
    Programa p;
    do {
        printf("\n----- GESTION DE PROGRAMAS -----\n");
        printf("1. Insertar Programa\n");
        printf("2. Consultar Programas\n");
        printf("3. Modificar Programa\n");
        printf("4. Eliminar Programa\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); } // Limpiar y poner opcion invalida
        switch (opcion) {
            case 1: insert_programa(); break;
            case 2: read_programas(); break;
            case 3: update_programa(); break;
            case 4: delete_programa(); break;
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_profesor() {
    int opcion;
    do {
        printf("\n----- GESTION DE PROFESORES -----\n");
        printf("1. Insertar Profesor\n");
        printf("2. Consultar Profesores\n");
        printf("3. Modificar Profesor\n");
        printf("4. Eliminar Profesor\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_profesor(); break;
            case 2: read_profesores(); break;
            case 3: update_profesor(); break;
            case 4: delete_profesor(); break;
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_departamento() {
    int opcion;
    do {
        printf("\n----- GESTION DE DEPARTAMENTOS -----\n");
        printf("1. Insertar Departamento\n");
        printf("2. Consultar Departamentos\n");
        printf("3. Modificar Departamento\n");
        printf("4. Eliminar Departamento\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_departamento(); break;
            case 2: read_departamentos(); break;
            case 3: update_departamento(); break;
            case 4: delete_departamento(); break;
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_grupo() {
    int opcion;
    do {
        printf("\n----- GESTION DE GRUPOS -----\n");
        printf("1. Insertar Grupo\n");
        printf("2. Consultar Grupos\n");
        printf("3. Modificar Grupo\n");
        printf("4. Eliminar Grupo\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_grupo(); break;
            case 2: read_grupos(); break;
            case 3: update_grupo(); break;
            case 4: delete_grupo(); break;
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_proyecto() {
    int opcion;
    do {
        printf("\n----- GESTION DE PROYECTOS -----\n");
        printf("1. Insertar Proyecto\n");
        printf("2. Consultar Proyectos\n");
        printf("3. Modificar Proyecto\n");
        printf("4. Eliminar Proyecto\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_proyecto(); break;
            case 2: read_proyectos(); break;
            case 3: update_proyecto(); break;
            case 4: delete_proyecto(); break;
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_financiamiento() {
    int opcion;
    do {
        printf("\n----- GESTION DE FINANCIAMIENTOS -----\n");
        printf("1. Insertar Financiamiento\n");
        printf("2. Consultar Financiamientos\n");
        // printf("3. Modificar Financiamiento (No implementado por clave compuesta)\n");
        printf("4. Eliminar Financiamiento\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_financiamiento(); break;
            case 2: read_financiamientos(); break;
            case 4: delete_financiamiento(); break; // Directamente la opcion 4
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}

void menu_participa() {
    int opcion;
    do {
        printf("\n----- GESTION DE PARTICIPACIONES -----\n");
        printf("1. Insertar Participacion\n");
        printf("2. Consultar Participaciones\n");
        // printf("3. Modificar Participacion (No implementado por clave compuesta)\n");
        printf("4. Eliminar Participacion\n");
        printf("0. Volver al menu principal\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { printf("Entrada invalida.\n"); opcion = -1; clear_input_buffer(); }
        switch (opcion) {
            case 1: insert_participa(); break;
            case 2: read_participaciones(); break;
            case 4: delete_participa(); break; // Directamente la opcion 4
            case 0: break;
            default: printf("Opcion no valida. Intente de nuevo.\n"); break;
        }
    } while (opcion != 0);
}


// --- Función Principal (main) ---

int main() {
    conectar(); // Establecer conexión a la base de datos al inicio

    int main_opc;
    int crud_opc;

    do {
        display_main_menu();
        if (scanf("%d", &main_opc) != 1) {
            clear_input_buffer();
            printf("Entrada invalida. Por favor, ingresa un numero.\n");
            continue;
        }
        clear_input_buffer(); // Limpiar el buffer después de leer el número de opción del menú principal

        if (main_opc >= 1 && main_opc <= 7) {
            const char* table_names[] = {"Programa", "Profesor", "Departamento", "Grupo", "Proyecto", "Financiamiento", "Participa"};
            do {
                display_crud_menu(table_names[main_opc - 1]);
                if (scanf("%d", &crud_opc) != 1) {
                    clear_input_buffer();
                    printf("Entrada invalida. Por favor, ingresa un numero.\n");
                    crud_opc = 0; // Para que se quede en el bucle CRUD
                    continue;
                }
                clear_input_buffer(); // Limpiar el buffer después de leer el número de opción del menú CRUD
                
                // Las funciones CRUD individuales ahora se encargan de clear_input_buffer()
                // cuando necesitan leer cadenas después de un scanf.
                if (crud_opc >=1 && crud_opc <=4){
                    handle_crud_choice(main_opc, crud_opc);
                } else if (crud_opc != 5) {
                    printf("Opcion invalida. Por favor, intenta de nuevo.\n");
                }

            } while (crud_opc != 5); // Bucle para el menú CRUD
        } else if (main_opc == 8) {
            printf("Saliendo del programa. \n");
        } else {
            printf("Opcion invalida. Por favor, selecciona un numero entre 1 y 8.\n");
        }
    } while (main_opc != 8); // Bucle para el menú principal

    mysql_close(con); // Cerrar la conexión al salir del programa
    return 0;
}
