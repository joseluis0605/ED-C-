#include <stdio.h>
#include <stdlib.h>
#include "booleanarrayset.h"

int main () {
    booleanbarraySet conjunto, conjunto2, conjunto3;

    crearConjuntoVacio (&conjunto);
    crearConjuntoVacio (&conjunto2);
    crearConjuntoVacio (&conjunto3);


    TElemento e1,e2,e3,e4,e5,e6,e7,e8,e;
    crear('j', &e1);
    crear('o', &e2);
    crear('s', &e3);
    crear('e', &e4);
    crear('l', &e5);
    crear('u', &e6);
    crear('i', &e7);
    crear('s', &e8);

    insertarConjunto(e1, &conjunto);
    insertarConjunto(e2, &conjunto);
    insertarConjunto(e3, &conjunto);
    insertarConjunto(e4, &conjunto);
    insertarConjunto(e5, &conjunto);
    insertarConjunto(e6, &conjunto);
    insertarConjunto(e7, &conjunto);
    insertarConjunto(e8, &conjunto2);
    insertarConjunto(e1, &conjunto2);

    mostrarConjunto(&conjunto);

    //eliminarConjunto(e1, &conjunto);


    //elegir(&e, &conjunto);

    //contiene(e2, &conjunto);

    //copiarConjunto(&conjunto, &conjunto2);

    mostrarConjunto(&conjunto2);

    //esSubconjunto(&conjunto2, &conjunto);

    diferencia(&conjunto, &conjunto2, &conjunto3);

    return 0;
}