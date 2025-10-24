#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Cantidad de argumentos: %d\n", argc);

    
    if (argc > 1){
        for (int i = 0; i < argc; i++) {
            printf ("Argumento N°%d: %s\n", i+1, argv[i]);
        }
    } else {
        printf("No hay argumentos además de la propia ruta del programa.");
    }

    return 0;
}