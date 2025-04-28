#include <stdio.h>
void func1 (void){
    printf("segunda funcion\n");
    return;
}
void func2 (void){
    printf("tercera funcion\n");
    return;
}
int main(){
    printf("primera funcion llamada main()\n");
    func1(); //segunda funcion llamada
    func2(); //tercera funcion llamada
    printf("main se termina\n");
    return 0; //devuelve control al sistema
}