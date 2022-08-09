#include <stdio.h>
#include <stdlib.h>
#include "pila.h"




int main () {
    Pila pila1;

    crearPilaVacia (&pila1);
    apilar (&pila1,1);
    apilar (&pila1,2);
    apilar (&pila1,3);
    apilar (&pila1,4);
    mostrar (&pila1);

    mostrar (&pila1);

    return 0;
}