#include <stdio.h>
#include "cola.h"
int main() {
    Cola mipila;
    TElemento aux;

    crearColaVacia(&mipila);
    insertar(&mipila, 1);
    insertar(&mipila, 2);
    insertar(&mipila, 3);
    insertar(&mipila, 4);
    insertar(&mipila, 5);
    insertar(&mipila, 6);
    insertar(&mipila, 7);
    insertar(&mipila, 8);
    insertar(&mipila, 9);

    eliminar(&mipila);
    eliminar(&mipila);
    eliminar(&mipila);
    eliminar(&mipila);
    eliminar(&mipila);

    insertar(&mipila, 10);
    insertar(&mipila, 11);
    insertar(&mipila, 12);
    insertar(&mipila, 13);
    insertar(&mipila, 14);
    insertar(&mipila, 15);




    primero(mipila, &aux);
    print(aux);
    printf("\n");

    mostrar(mipila);



    //mostrar(mipila);
    printf ("Adios\n");    return 0;
}
