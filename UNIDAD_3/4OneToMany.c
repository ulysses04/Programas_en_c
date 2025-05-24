/**
 * Instrucciones para ejecutar 

#######################
SQL 
CREATE TABLE personas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),
    edad INT
);

CREATE TABLE telefonos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    persona_id INT,
    numero VARCHAR(20),
    FOREIGN KEY (persona_id) REFERENCES personas(id) ON DELETE CASCADE
);

gcc -o 4OneToMany 4OneToMany.c \
-I/usr/local/opt/mysql-client/include \
-L/usr/local/opt/mysql-client/lib \
-lmysqlclient

./4OneToMany


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>


typedef struct {
    int id;
    char nombre[100];
    int edad;
} Persona;

typedef struct {
    int id;
    int persona_id;
    char numero[20];
} Telefono;

MYSQL *con;

void finish_with_error() {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void conectar(){
    con = mysql_init(NULL);
    if (con == NULL){
        fprintf(stderr, "mysql_init() falló\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "12345", "basedatos", 3306, NULL, 0) == NULL){
        finish_with_error();
    }
}

int crear_persona(const Persona *persona) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO personas(nombre, edad) VALUES('%s', %d)",
        persona->nombre, persona->edad);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con); 
}

void agregar_telefono(int persona_id, const char *numero) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO telefonos(persona_id, numero) VALUES(%d, '%s')",
        persona_id, numero);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void leer_personas_y_telefonos() {
    const char *query =
        "SELECT p.id, p.nombre, p.edad, t.numero "
        "FROM personas p LEFT JOIN telefonos t ON p.id = t.persona_id "
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
        const char *nombre = row[1];
        int edad = atoi(row[2]);
        const char *telefono = row[3];

        if (id != last_id) {
            printf("\nPersona ID: %d, Nombre: %s, Edad: %d\n", id, nombre, edad);
            printf("Teléfonos:\n");
            last_id = id;
        }

        if (telefono != NULL) {
            printf(" - %s\n", telefono);
        }
    }

    mysql_free_result(result);
}

int ultimo_registro() {
    const char *query =
        "SELECT p.id, p.nombre, p.edad, t.numero "
        "FROM personas p LEFT JOIN telefonos t ON p.id = t.persona_id "
        "ORDER BY p.id DESC";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_id = -1;
    bool flag = false; 
    int id = 0;
    while ((row = mysql_fetch_row(result))) {
        if (flag == false) {
            id = atoi(row[0]);
        }
        flag = true; 
    }

    mysql_free_result(result);
    return id; 
}

void eliminar_persona(int id) {
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM personas WHERE id=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Persona y sus teléfonos eliminados.\n");
    }
}

int main() {
    conectar();

    Persona persona = {0, "Carlos", 35};
    int persona_id = crear_persona(&persona);

    int ultimo_reg = ultimo_registro();
    printf("Valor = %d",ultimo_reg);

    agregar_telefono(persona_id, "555-1234");
    agregar_telefono(persona_id, "555-5678");

    leer_personas_y_telefonos();

    eliminar_persona(persona_id);

    mysql_close(con);
    return 0;
}
