#include <stdio.h>

int factorial (int numero){
    //caso base
    if (numero==1){
        return 1;
    } else{
        return numero* factorial(numero-1);
    }
}

int factorial2 (int numero, int *resultado){
    if (numero==1){
        *resultado= *resultado*1;
        printf("%d", *resultado);
        return *resultado;
    } else{
        *resultado= *resultado*numero;
        factorial2(numero-1, resultado);
    }
}

int main() {

    int numero;
    scanf("%d", &numero);

    int resultado= factorial (numero);

    printf("%d ", resultado);

    int pos2= 1;
    factorial2(numero, &pos2);
    return 0;
}
