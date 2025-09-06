#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void saltoLinea() {
    printf(" \n");
}


int imprimirInfoProceso(int tiempo_espera) {
    printf(
        "mi PID es %d \n"
        "mi PID padre es %d \n"
        "Desperte en %d segundos \n", 
        getpid(), getppid(), tiempo_espera
    );
    saltoLinea();

    return 0;
}

int main() {
    pid_t proceso, proceso_padre;
    int loops = 3;
    int tiempo_espera = 2;
    
    proceso_padre = getpid(); // Guaramos el dato de cual es el proceso padre

    // Confirmamos cual es el proceso padre (Simple referencia para mi)
    saltoLinea();
    printf("Este es el proceso padre (PID-%d) \n", proceso_padre);
    imprimirInfoProceso(1);
    printf("------------------ de aca para abajo son los procesos hijos ------------------ \n");
    saltoLinea();

    // revisar la actividad de SO para esto con el WAIT y el sleeo
    for (int i = 0; i < loops; i++) {
        proceso = fork();
        
        if (proceso == 0) {
            sleep(tiempo_espera);

            int tiempo_despertar = tiempo_espera + 2; // guardo el tiempo para una impresion nueva
            // Muestro la info del proceso
            imprimirInfoProceso(tiempo_espera);
            break;
        }
        tiempo_espera = tiempo_espera + 2;
    }

    // el proceso en caso de tener un hijo siempre espera a que este termine para finalizarse
    // PROCESO 1 <- Epera al proceso 1.2
    // |--- PROCESO 1.2 <- espera al proceso 1.2.1
    // |---|--- PROCESO 1.2.1
    waitpid(
        proceso, // le facilitamos el PID del proceso a esperar
        NULL, // Se indica que no importa el como termino el proceso pero cuando lo haga se mate el proceso
        0
    );
    
    if (getpid() == proceso_padre) {
        sleep(2);
        printf("----------- Separado ----------- \n");
        saltoLinea();
        printf("Este es el fin del proceso padre (PID-%d) \n", proceso_padre);
        saltoLinea();
    };

    return 0;
}

