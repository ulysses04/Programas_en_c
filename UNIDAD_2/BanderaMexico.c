#include <stdio.h>

 
void setColor(const char* color) {
    printf("%s", color);
}

void resetColor() {
    printf("\033[0m");
}

int main() {
    int i, j;

    for (i = 0; i < 7; i++) {
    setColor("\033[7;32m");
        for (j = 0; j < 8; j++) {
            printf(" ");
        }

        setColor("\033[7;37m");  
        for (j = 0; j < 8; j++) {
            printf(" ");
        }

        setColor("\033[7;31m");  
        for (j = 0; j < 8; j++) {
            printf(" ");
        }

        resetColor();
        printf("\n");
    }

    return 0;
}