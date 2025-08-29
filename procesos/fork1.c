#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t proceso;
    int id_proceso = fork();

    if (id_proceso == -1) {
        perror("Error al crear el proceso hijo");
        return 1;
    }
    else if (id_proceso == 0) {
        printf("Soy el proceso hijo\n");
        printf("PID Hijo: %d\n", getpid());
        printf("PID Padre: %d\n", getppid());
    }
    else if (id_proceso > 0) {
        printf("Soy el proceso padre\n");
        printf("PID Padre: %d\n", getpid());
        printf("PID de mi Hijo: %d\n", id_proceso);
    }


}