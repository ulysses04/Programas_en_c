#include <stdio.h>

#include <stdlib.h>

#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

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

void crear_balon(const char *nombre, const char *marca, float precio, const char *color, const char *material, const char *deporte, const char *talla)
{

    char query[256];

    snprintf(query, sizeof(query),

             "INSERT INTO balon (nombre,marca,precio,color,material,deporte,talla) VALUES('%s','%s',%.2f,'%s','%s','%s',' %s')", nombre, marca, precio, color, material, deporte, talla);

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

    if (mysql_query(con, "SELECT id_balon, nombre, marca, precio,color,material,deporte,talla FROM balon"))
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

        for (int i = 0; i < num_fields; i++)
        {

            printf("%s\t", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
}

void actualizar_balon(int id_balon, const char *nuevo_nombre, float nueva_precio)
{

    char query[256];

    snprintf(query, sizeof(query),

             "UPDATE balon SET nombre='%s', precio=%.2f WHERE id_balon=%d",

             nuevo_nombre, nueva_precio, id_balon);

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

void leer_balon2()
{

    if (mysql_query(con, "SELECT id_balon, nombre, precio FROM balon"))
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

        for (int i = 0; i < num_fields; i++)
        {

            printf("%s\t", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
}
int main(){

    int opc;
    conectar();

    printf("-----menu-----\n");
    printf("1)insertar\n");
    printf("2)listar datos\n");
    printf("3)borrar dato\n");
    printf("4)actualizar\n");
    printf("selecciona una opcion:");
    scanf("%d",&opc);
    switch(opc){
        case 1:{
        char nombre[50];
        char marca[50];
        float precio;
        char color[50];
        char material[50];
        char deporte[50];
        char talla[50]; 
        printf("insertar datos de balon:\n");
        printf("nombre:");
        scanf("%s",nombre);
        printf("\nmarca:");
        scanf("%s",marca);
        printf("\nprecio:");
        scanf("%f",&precio);
        printf("\ncolor:");
        scanf("%s",color);
        printf("\nmaterial:");
        scanf("%s",material);
        printf("\ndeporte:");
        scanf("%s",deporte);
        printf("\ntalla:");
        scanf("%s",talla);
        crear_balon(nombre,marca,precio,color,material,deporte,talla);
        break;
        }
        case 2:{
        printf("listar datos:\n");
        leer_balon();
        break;
        }
        case 3:{
        int id_balon;
        leer_balon();
        printf("borrar dato:\n");
        printf("ingrese id del balon:\n");
        scanf("%d",&id_balon);
        eliminar_balon(id_balon);
        break;
        }
        case 4:{
        char nombrenuevo[50];
        float precionuevo;
        int id_balon2;
        leer_balon2();
        printf("actualizar datos:\n");
        printf("ingresa id a actualizar:\n");
        scanf("%d",&id_balon2);
        printf("ingresa nuevo nombre:");
        scanf("%s",nombrenuevo);
        printf("\ningresa nuevo precio:");
        scanf("%f",&precionuevo);
        actualizar_balon(id_balon2,nombrenuevo,precionuevo);
        break;
        }
        default:
        printf("elige una opcion valida");
        break;




    }

    

    
    mysql_close(con);

    return 0;
}