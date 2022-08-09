#include <stdio.h>
#include "cola.h"

int main() {
    Cola mipila;
    TElemento aux;

    crearVacia(&mipila);
    encolar(1, &mipila);
    encolar(2, &mipila);
    encolar(3, &mipila);
    encolar(4, &mipila);


    primero(mipila, &aux);
    imprimir (aux);
    printf("\n");

    mostrar(mipila);
    eliminar(&mipila);
    eliminar(&mipila);


    mostrar(mipila);
    printf ("Adios\n");
    return 0;
}
