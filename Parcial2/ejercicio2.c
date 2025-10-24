#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void pidPadreYPropio(){
    pid_t id_proceso_actual = getpid();
    pid_t id_proceso_padre = getppid();
    printf("Mi PID es: %d\n", id_proceso_actual);
    printf("Mi PPID es: %d\n", id_proceso_padre);
}

int main() {

    int id_proceso = fork();
    pid_t id_proceso_main = getpid();

    if (id_proceso == 0) {
        // aca el proceso hijo
        printf("\n================\n");
        printf("soy el proceso hijo\n");
        pidPadreYPropio();
        int id_proceso_nieto = fork();

        if (id_proceso_nieto == 0) {
            printf("\n================\n");
            printf("soy el proceso nieto\n");
            pidPadreYPropio();
        }
    }

    if (id_proceso > 0) {
        printf("\n================\n");
        printf("soy el proceso padre\n");
        pidPadreYPropio();
    }

    // Para que no termine instanteamente todo le agregue el sleep
    sleep(5);
    wait(NULL);

    return 0;
}