#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void saltoLinea() {
    printf(" \n");
}


int imprimirInfoProceso(int tiempo_espera, int proceso_n) {
    printf(
        "Soy el hijo %d\n"
        "mi PID es %d \n"
        "mi PPID padre es %d \n"
        "Desperte en %d segundos \n", 
        proceso_n, getpid(), getppid(), tiempo_espera
    );
    saltoLinea();

    return 0;
}

int main() {
    pid_t proceso, proceso_padre;
    int cant_hijos = 3;
    int tiempo_espera = 2;
    
    proceso_padre = getpid(); // Guaramos el dato de cual es el proceso padre

    // Confirmamos cual es el proceso padre (Simple referencia para mi)
    saltoLinea();
    printf("Este es el proceso padre (PID-%d) \n", proceso_padre);
    imprimirInfoProceso(0, 0);
    printf("------------------ de aca para abajo son los procesos hijos ------------------ \n");
    saltoLinea();

    for(int i = 0; i < cant_hijos; i++) {

        if (getpid() == proceso_padre) {
            wait(NULL);
            pid_t pid = fork();
            
            if (pid < 0) {
                printf("Error al crear el proceso hijo \n");
                }
            else if(pid == 0) {
                sleep(tiempo_espera);
                imprimirInfoProceso(tiempo_espera, i + 1);
            }
        }

        tiempo_espera = tiempo_espera + 2;
    };

    if (getpid() == proceso_padre) {
        wait(NULL);
    }

    if (getpid() == proceso_padre) {
        printf("----------- Separado ----------- \n");
        saltoLinea();
        printf("Este es el fin del proceso padre (PID-%d", proceso_padre);
        saltoLinea();
    }

    return 0;
}

