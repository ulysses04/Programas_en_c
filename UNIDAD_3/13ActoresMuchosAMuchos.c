#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

typedef struct {
    int id;
    char nombre[100];
} Actor;

typedef struct {
    int id;
    char titulo[100];
} Pelicula;

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

    if (mysql_real_connect(con, "localhost", "root", "12345", "peliculas", 3306,NULL, 0) == NULL) {
        finish_with_error();
    }
}

int crear_actor(const char *nombre) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO actores(nombre) VALUES('%s')", nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con);
}

int crear_pelicula(const char *titulo) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO peliculas(titulo) VALUES('%s')", titulo);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con);
}

void asignar_actor_a_pelicula(int actor_id, int pelicula_id) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO actor_pelicula(actor_id, pelicula_id) VALUES(%d, %d)",
        actor_id, pelicula_id);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void leer_actores_y_peliculas() {
    const char *query =
        "SELECT a.id, a.nombre, p.titulo "
        "FROM actores a "
        "JOIN actor_pelicula ap ON a.id = ap.actor_id "
        "JOIN peliculas p ON p.id = ap.pelicula_id "
        "ORDER BY a.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_actor_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int actor_id = atoi(row[0]);
        const char *actor_nombre = row[1];
        const char *titulo = row[2];

        if (actor_id != last_actor_id) {
            printf("\nActor ID: %d, Nombre: %s\n", actor_id, actor_nombre);
            printf("Peliculas:\n");
            last_actor_id = actor_id;
        }

        printf(" - %s\n", titulo);
    }

    mysql_free_result(result);
}

void leer_peliculas_y_actores() {
    const char *query =
        "SELECT p.id, p.titulo, a.nombre "
        "FROM peliculas p "
        "JOIN actor_pelicula ap ON p.id = ap.pelicula_id "
        "JOIN actores a ON a.id = ap.actor_id "
        "ORDER BY p.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_pelicula_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int pelicula_id = atoi(row[0]);
        const char *titulo = row[1];
        const char *actor_nombre = row[2];

        if (pelicula_id != last_pelicula_id) {
            printf("\nPelicula ID: %d, Titulo: %s\n", pelicula_id, titulo);
            printf("Actores:\n");
            last_pelicula_id = pelicula_id;
        }

        printf(" - %s\n", actor_nombre);
    }

    mysql_free_result(result);
}

int main() {
    conectar();

    int brad = crear_actor("Brad Pitt");
    int pacino = crear_actor("Al Pacino");
    int deniro = crear_actor("Robert De Niro");
    int leo = crear_actor("Leonardo DiCaprio");

    
    int peli1 = crear_pelicula("Once Upon a Time in Hollywood");
    int peli2 = crear_pelicula("The Irishman");
    int peli3 = crear_pelicula("The Godfather Part II");

    asignar_actor_a_pelicula(leo, peli1);
    asignar_actor_a_pelicula(brad, peli1);
    asignar_actor_a_pelicula(deniro, peli2);
    asignar_actor_a_pelicula(pacino, peli2);
    asignar_actor_a_pelicula(pacino, peli3);
    asignar_actor_a_pelicula(deniro, peli3);

    printf("\n== Actores con sus peliculas ==\n");
    leer_actores_y_peliculas();

    printf("\n== Peliculas con sus actores ==\n");
    leer_peliculas_y_actores();

    mysql_close(con);
    return 0;
}
