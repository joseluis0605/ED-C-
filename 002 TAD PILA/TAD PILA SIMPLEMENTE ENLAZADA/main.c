#include <stdio.h>
#include "pila.h"

int main() {
    Pila mipila;
    TElemento aux;

    crearPilaVacia(&mipila);
    apilar (&mipila, '5');
    apilar (&mipila, '3');
    apilar (&mipila, '1');
    apilar (&mipila, '7');

    cima (mipila, &aux);
    imprimir (aux);
    printf("\n");

    mostrar(mipila);
    desapilar(&mipila);
    desapilar(&mipila);
    desapilar(&mipila);
    desapilar(&mipila);

    mostrar(mipila);
    printf ("Adios\n");
    return 0;
}
