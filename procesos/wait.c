#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int imprimirInfoProceso(int tiempo_espera) {
    printf(
        "mi PID es %d \n"
        "Desperte en %d segundos \n"
        "------- Separador ------- \n", 
        getpid(), tiempo_espera
    );

    return 0;
}

int main() {
    pid_t proceso;
    pid_t proceso_padre;
    int loops = 3;
    int tiempo_espera = 2;
    int tiempo_espera_ant = tiempo_espera;

    proceso_padre = getpid(); // Guaramos el dato de cual es el proceso padre
    printf("Este es el proceso padre (PID-%d) \n", proceso_padre);
    imprimirInfoProceso(1);
    
    // revisar la actividad de SO para esto con el WAIT y el sleeo
    for (int i = 0; i < loops; i++) {
        
        proceso = fork();
        sleep(tiempo_espera);

        tiempo_espera_ant = tiempo_espera; // guardo el tiempo para una impresion nueva
        tiempo_espera = tiempo_espera + 2;
        if (proceso == 0) {
            break;
        }
        
    }

    imprimirInfoProceso(tiempo_espera_ant);

    waitpid(proceso, NULL, 0);
    
    if (getpid() == proceso_padre) {
        printf("Este es el fin del proceso padre (PID-%d) \n", proceso_padre);

    };
    

    return 0;
}

