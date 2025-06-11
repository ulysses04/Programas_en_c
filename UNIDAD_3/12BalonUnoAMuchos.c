#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

typedef struct {
    int id;
    char nombre[100];
} Persona;

typedef struct {
    int id;
    int persona_id;
    char nombre[50];
    char marca[50];
} Balon;

MYSQL *con;

void finish_with_error() {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() falló\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "12345", "balon2", 3306, NULL, 0) == NULL) {
        finish_with_error();
    }
}

int crear_persona(const Persona *persona) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO personas(nombre) VALUES('%s')",
        persona->nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con);
}

void agregar_balon(int persona_id, const Balon *balon) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO balon(persona_id, nombre, marca) VALUES(%d, '%s', '%s')",
        persona_id, balon->nombre, balon->marca);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void leer_personas_y_balones() {
    const char *query =
        "SELECT p.id, p.nombre, b.nombre, b.marca "
        "FROM personas p LEFT JOIN balon b ON p.id = b.persona_id "
        "ORDER BY p.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int id = atoi(row[0]);
        const char *nombre_persona = row[1];
        const char *nombre_balon = row[2];
        const char *marca = row[3];

        if (id != last_id) {
            printf("\nPersona ID: %d, Nombre: %s\n", id, nombre_persona);
            printf("Balones:\n");
            last_id = id;
        }

        if (nombre_balon != NULL) {
            printf(" - Nombre: %s, Marca: %s\n", nombre_balon, marca);
        }
    }

    mysql_free_result(result);
}

void eliminar_persona(int id) {
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM personas WHERE id=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Persona y sus balones eliminados.\n");
    }
}

int main() {
    conectar();

    Persona juan = {0, "Juan"};
    int juan_id = crear_persona(&juan);

    Persona ulysses = {0, "Ulysses"};
    int ulysses_id = crear_persona(&ulysses);

   
    Balon balon_juan = {0, juan_id, "Jabulani", "Adidas"};
    agregar_balon(juan_id, &balon_juan);

    Balon balon_ulysses = {0, ulysses_id, "Nike Strike", "Nike"};
    agregar_balon(ulysses_id, &balon_ulysses);

  
    leer_personas_y_balones();

    
   

    mysql_close(con);
    return 0;
}
