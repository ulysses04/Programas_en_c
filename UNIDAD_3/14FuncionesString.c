
#include <stdio.h>
#include <string.h> //declaracion de librerias a utilizar 


void ejemplo_strcat() {// funcion que concatena dos cadenas
    char destino[50] = "Hola "; //cadena destino, la que imprime primero 
    char fuente[] = "mundo"; //cadena fuente la que se imprimira despues de destino
    strcat(destino, fuente);
    printf("strcat: %s\n", destino);
}


void ejemplo_strchr() {// funcion que busca el caracter m en la cadena 
    char cadena[70] = "america odiame mas";
    char *ptr = strchr(cadena, 'o');//devuelve el puntero a esa posicion.
    printf("strchr: %s\n", ptr);//imprime posicion 
}


void ejemplo_strcmp() {//compara dos cadenas de caracteres, si son iguales devuelve 0, es sensible a mayusculas o minusculas
    char a[] = "chachau";//primer cadena
    char b[] = "Chachau";//segunda cadena a comparar
    printf("strcmp: %d\n", strcmp(a, b));
}


void ejemplo_strcmpi() {//funcion que compara dos cadenas de caracteres, si son iguales imprime 0, no es sensible a mayusculas o minusculas
    char a[] = "rubicon";
    char b[] = "RUBICON";
    printf("strcmpi: %d\n", strcasecmp(a, b)); 
}


void ejemplo_strcpy() {//funcion que copia la cadena fuente a destino, considerando que destino tenga suficiente eespacio
    char destino[20];
    strcpy(destino, "nueva vida");//cadena de texto a copiar 
    printf("strcpy: %s\n", destino);
}



void ejemplo_strlen() {//funcion que devuelve la longitud de una cadena
    char cadena[] = "eres arte";//cadena a contar longitud
    printf("strlen: %lu\n", strlen(cadena));//imprime longitud 
}


void ejemplo_strncat() {//funcion que concatena una cadena fuente a destino controlando el tamaño
    char a[20] = "bruce ";
    char b[] = "wayne";
    strncat(a, b, 3); //solo concatenera hasta way ya que es a 3 caracteres
    printf("strncat: %s\n", a);//imprime resultado
}


void ejemplo_strncmp() {//compara dos cadenas pero limitado a n caracteres
    char a[] = "justo";//primera cadena
    char b[] = "justicia";//segunda cadena
    printf("strncmp: %d\n", strncmp(a, b, 4));//solo comparara los primeros 4 caracteres
}


void ejemplo_strspn() {//funcion que devuelve la longitud de s1 que solo tiene caracteres de s2, lo opuesto de strcspn
    char s1[] = "abcde12345";//primera cadena
    char s2[] = "abcde";//segunda cadena
    printf("strspn: %lu\n", strspn(s1, s2));//imprimira 5 ya que coinciden 5
}

// strstr
void ejemplo_strstr() {//funcion que busca la subcadena s2 dentro de s1
    char s1[] = "eres arte";//cadena padre
    char s2[] = "ar";//buscara dentro de la cadena padre ar 
    printf("strstr: %s\n", strstr(s1, s2));//imprime palabra completa
}



int main() {//metodo principal
    
    ejemplo_strcat();//mando a llamar mis funciones
    ejemplo_strchr();
    ejemplo_strcmp();
    ejemplo_strcmpi();
    ejemplo_strcpy();
    ejemplo_strlen();
    ejemplo_strncat();
    ejemplo_strncmp();
    ejemplo_strspn();
    ejemplo_strstr();
    
    return 0;//fin de programa 
}
