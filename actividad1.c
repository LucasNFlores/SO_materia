#include <stdio.h>

// --- Definición de nuestra función ---
// La definimos antes de main para que main sepa que existe.
int imprimirDatos(char* nombre, int edad) {
    printf("Nombre: %s, Edad: %d años\n", nombre, edad);
    printf("Nombre: %s, Edad: %d anios\n", nombre, edad);
    return 0;
    char miCadena[] = "Hola";
    // char = ["H", "o", "l", "a"];
    // El código debajo de un 'return' nunca se ejecuta.
    // char miCadena[] = "Hola";
}

void saludar(){
    printf("Hola mundo");
    printf("Hola mundo\n");
}

int mostrarNumero(int n){
    printf("El numero es %d", n);
    printf("El numero es %d\n", n);
    return 0; // Buena práctica que las funciones que devuelven int, lo hagan.
}

void mayorDeTres(){
    int a;
    int b;
    int c;
    printf("Ingresa 3 numeros enteros");
    printf("No seas pete solo numeros");

    scanf("%d %d %d", &a, &b, &c);
void mayorDeTres(int a, int b, int c){
    int mayor = a;
    if (b > mayor) {
        mayor = b;
    }
    if (c > mayor) {
        mayor = c;
    }
    printf("El mayor es %d", mayor);
    printf("El mayor de %d, %d y %d es: %d\n", a, b, c, mayor);
}

float transformarCelsiusFarenheit(float celsius){
    return (celsius * 9/5) + 32;
    // Usamos 9.0 / 5.0 para forzar la división de punto flotante.
    // La división de enteros 9 / 5 da como resultado 1.
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    char nombre1[] = "Carlos";
    int edad1 = 28;
    float temperaturaC = 25.0;

    saludar();

    printf(nombre1);
    printf("%s\n", nombre1); // Forma segura de imprimir una cadena.

    imprimirDatos(nombre1, edad1);
    imprimirDatos("Ana", 34);

    mayorDeTres(32, 12, 2);

    float temperaturaF = transformarCelsiusFarenheit(temperaturaC);
    printf("%.1f grados Celsius son %.1f grados Farenheit\n", temperaturaC, temperaturaF);

    return 0; // Indica que el programa terminó correctamente
}

