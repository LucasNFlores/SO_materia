#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t id_proceso_actual = getpid();
    pid_t id_proceso_padre = getppid();


    printf("ID del proceso actual: %d\n", id_proceso_actual);
    printf("ID del proceso padre: %d\n", id_proceso_padre);

    sleep(5);
     
    return 0;
}