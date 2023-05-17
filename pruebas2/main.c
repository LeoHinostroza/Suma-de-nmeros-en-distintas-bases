#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool validar_numero(char numero[], int base);
int convertir_a_decimal(char numero[], int base);
void convertir_a_nueva_base(int numero, int base_nueva);

int main() {
    char num1[20], num2[20];
    int base1, base2, decimal1, decimal2, suma, base_nueva;

    printf("Ingrese el primer numero: ");
    scanf("%s", num1);

    printf("Ingrese la base del primer numero (2-16): ");
    scanf("%d", &base1);

    // Validar el primer numero
    while(!validar_numero(num1, base1)) {
        printf("Error: el primer numero ingresado no corresponde a la base especificada.\n");
        printf("Ingrese la base del primer numero (2-16): ");
        scanf("%d", &base1);
    }

    printf("Ingrese el segundo numero: ");
    scanf("%s", num2);

    printf("Ingrese la base del segundo numero (2-16): ");
    scanf("%d", &base2);

    // Validar el segundo numero
    while(!validar_numero(num2, base2)) {
        printf("Error: el segundo numero ingresado no corresponde a la base especificada.\n");
        printf("Ingrese la base del segundo numero (2-16): ");
        scanf("%d", &base2);
    }

    decimal1 = convertir_a_decimal(num1, base1);
    decimal2 = convertir_a_decimal(num2, base2);
    suma = decimal1 + decimal2;

    printf("La suma en base 10 es: %d\n", suma);

    printf("Ingrese la base en la que desea ver la suma (2-16): ");
    scanf("%d", &base_nueva);

    printf("La suma en base %d es: ", base_nueva);
    convertir_a_nueva_base(suma, base_nueva);

    return 0;
}

bool validar_numero(char numero[], int base) {
    int longitud = strlen(numero);
    for(int i = 0; i < longitud; i++) {
        int digito;
        if(numero[i] >= 'A' && numero[i] <= 'F') {
            digito = numero[i] - 'A' + 10;
        } else {
            digito = numero[i] - '0';
        }
        if(digito >= base) {
            return false;
        }
    }
    return true;
}

int convertir_a_decimal(char numero[], int base) {
    int decimal = 0, longitud, digito, potencia;
    longitud = strlen(numero);
    potencia = longitud - 1;
    for(int i = 0; i < longitud; i++) {
        if(numero[i] >= 'A' && numero[i] <= 'F') {
            digito = numero[i] - 'A' + 10;
        } else {
            digito = numero[i] - '0';
        }
        decimal += digito * pow(base, potencia);
        potencia--;
    }
    return decimal;
}
void convertir_a_nueva_base(int numero, int base_nueva) {
    int cociente = numero;
    int resto;
    char resultado[20];
    int i = 0;
    while(cociente != 0) {
        resto = cociente % base_nueva;
        cociente = cociente / base_nueva;
        if(resto > 9) {
            resultado[i] = resto - 10 + 'A';
        } else {
            resultado[i] = resto + '0';
        }
        i++;
    }
    printf("%s", "La suma en base ");
    printf("%d", base_nueva);
    printf("%s", " es: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", resultado[j]);
    }
    printf("\n");
}
