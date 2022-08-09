#include <stdio.h>
#include "pila.h"
int main() {

    Pila mipila;
    crearPilaVacia(&mipila);

    apilar(&mipila, 1);
    apilar(&mipila, 2);
    apilar(&mipila, 3);
    apilar(&mipila, 4);

    desapilar(&mipila);
    desapilar(&mipila);
    desapilar(&mipila);
    //desapilar(&mipila);


    mostrar(&mipila);

    TElemento aux= cima(&mipila);
    imprimir(aux);


    return 0;
}
