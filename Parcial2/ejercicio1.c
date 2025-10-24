#include <stdio.h>

// de aca sacamos las funciones getpid y getppid    
#include <unistd.h>

int main() {
    pid_t id_proceso_actual = getpid();
    pid_t id_proceso_padre = getppid();


    printf("ID del proceso actual: %d\n", id_proceso_actual);
    printf("ID del proceso padre: %d\n", id_proceso_padre);

    getchar();

    return 0;
}