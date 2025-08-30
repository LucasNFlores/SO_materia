#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Cantidad de argumentos: %d\n", argc);

    printf("Path al programa: %s\n", argv[0]);
    
    for (int i = 0; i < argc; i++) {
        printf ("argumento %d: %s", i, argv[i]);
    }

    return 0;
}