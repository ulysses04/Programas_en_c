#include <stdio.h>

#include <stdlib.h>

#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

typedef struct {
    int id_balon;
    char nombre[50];
    char marca[50];
    float precio;

}balon;

MYSQL *con;

void finish_with_error(){
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

    if (mysql_real_connect(con, "localhost", "root", "12345", "balon", 3306, NULL, 0) == NULL){
        finish_with_error();
    }
}

void crear_balon(const balon *balon){

    char query[256];

    snprintf(query, sizeof(query),

             "INSERT INTO balon (nombre,marca,precio) VALUES('%s','%s','%.2f')", balon->nombre, balon->marca, balon->precio);

    if (mysql_query(con, query))
    {

        finish_with_error();
    }
    else
    {

        printf("balon creada.\n");
    }
}

void leer_balon()
{

    if (mysql_query(con, "SELECT id_balon, nombre, marca, precio FROM balon"))
    {

        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {

        finish_with_error();
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        balon balon;
        balon.id_balon = atoi(row[0]);
        snprintf(balon.nombre, sizeof(balon.nombre), "%s", row[1]);
        snprintf(balon.marca, sizeof(balon.marca), "%s", row[2]);
        balon.precio = atof(row[3]);

        printf("ID: %d, Nombre: %s, marca: %s, precio:%.2f \n", balon.id_balon, balon.nombre, balon.marca, balon.precio);

        
    }

    mysql_free_result(result);
}

void actualizar_balon(const balon *balon)
{

    char query[256];

    snprintf(query, sizeof(query),

             "UPDATE balon SET nombre='%s', precio=%.2f WHERE id_balon=%d",

             balon->nombre,balon->precio, balon->id_balon);

    if (mysql_query(con, query))
    {

        finish_with_error();
    }
    else
    {

        printf("balon actualizada.\n");
    }
}

void eliminar_balon(int id_balon)
{

    char query[128];

    snprintf(query, sizeof(query), "DELETE FROM balon WHERE id_balon=%d", id_balon);

    if (mysql_query(con, query))
    {

        finish_with_error();
    }
    else
    {

        printf("balon eliminada.\n");
    }
}


   
int main(){

   conectar();
   balon brazzuka = {0, "brazzuka","adidas",250};
    crear_balon(&brazzuka);
    leer_balon();

    brazzuka.id_balon= 1;
    snprintf(brazzuka.nombre, sizeof(brazzuka.nombre), "brazzuka 2");
    brazzuka.precio = 220;
    actualizar_balon(&brazzuka);

    eliminar_balon(brazzuka.id_balon);


    
    mysql_close(con);

    return 0;
}