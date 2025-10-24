#include <stdio.h> // funciones estandar de entrada y salida [ej printf() o perror()]
#include <string.h>
#include <unistd.h> // pipe(), fork(), read(), write() y close()
#include <sys/wait.h> // para la espera de mas adelante 
#include <stdlib.h> // Para exit()


void fatherToChild(char *mensaje) {
    // Calculamos el tamaño REAL del mensaje + 1 para el carácter nulo '\0'
    int tamano_mensaje = strlen(mensaje) + 1; // <-- CAMBIO

    // creamos el pipe
    int pipeFD[2];
    if (pipe(pipeFD) == -1) {
        perror("Error pipe");
        return;
        exit(EXIT_FAILURE); // Si el pipe falla, no podemos continuar.
    }

    int id_proceso = fork();

    if (id_proceso == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE); // Si fork falla, no podemos continuar.
    }
    else if (id_proceso > 0) { // Proceso Padre
        // El padre no lee, cerramos el extremo de lectura
        close(pipeFD[0]);

        // Escribimos el mensaje completo en la pipe
        printf("PADRE: Enviando '%s'\n", mensaje);
        write(pipeFD[1], mensaje, tamano_mensaje); // <-- CAMBIO

        // Cerramos el extremo de escritura
        close(pipeFD[1]);

        // Esperamos al hijo
        wait(NULL);
    }
    else { // Proceso Hijo (id_proceso == 0)
        // El hijo no escribe, cerramos el extremo de escritura
        close(pipeFD[1]);

        // Creamos un buffer suficientemente grande para recibir el mensaje
        char mensRecibido[100]; // Usamos un buffer de tamaño fijo y seguro
        char mensRecibido[1024]; // Usamos un buffer de tamaño fijo y seguro

        // Leemos el mensaje de la pipe
        read(pipeFD[0], mensRecibido, sizeof(mensRecibido));
        ssize_t bytesLeidos = read(pipeFD[0], mensRecibido, sizeof(mensRecibido) - 1);

        printf("HIJO: Mensaje recibido: '%s'\n", mensRecibido);
        if (bytesLeidos > 0) {
            mensRecibido[bytesLeidos] = '\0'; // Aseguramos que la cadena termine en nulo
            printf("HIJO: Mensaje recibido: '%s'\n", mensRecibido);
        } else if (bytesLeidos == 0) {
            printf("HIJO: El padre cerró la pipe sin enviar datos.\n");
        } else {
            perror("HIJO: Error al leer de la pipe");
        }

        // Cerramos el extremo de lectura
        close(pipeFD[0]);
    }
}

int main() {
    char mensaje[] = "hola padre, este es un mensaje más largo";
    fatherToChild(mensaje);
    return 0;
}
