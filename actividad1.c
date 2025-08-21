#include <stdio.h>

// --- Definición de nuestra función ---
// La definimos antes de main para que main sepa que existe.
int imprimirDatos(const char* nombre, int edad) {
    printf("Nombre: %s, Edad: %d años\n", nombre, edad);
    return 0;
}

void saludar(){
    printf("Hola mundo");
}

int mostrarNumero(int n){
    printf("El numero es %d", n);
}

void mayorDeTres(){
    int a;
    int b;
    int c;
    printf("Ingresa 3 numeros enteros");
    printf("No seas pete solo numeros");

    scanf("%d %d %d", &a, &b, &c);
    int mayor = a;
    if (b > mayor) {
        mayor = b;
    }
    if (c > mayor) {
        mayor = c;
    }
    printf("El mayor es %d", mayor);
}

float transformarCelsiusFarenheit(float celsius){
    return (celsius * 9/5) + 32;
}

int main() {
    char nombre1[] = "Carlos";
    int edad1 = 28;
    saludar();

    printf(nombre1);

    imprimirDatos(nombre1, edad1);
    imprimirDatos("Ana", 34);

    mayorDeTres(32, 12, 2);


    return 0; // Indica que el programa terminó correctamente
}

