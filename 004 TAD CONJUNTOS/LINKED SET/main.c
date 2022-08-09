#include <stdio.h>
#include <stdlib.h>
#include "linkedset.h"

#define dim 20

void insertarEnConjunto(int* store, set* s);

int main(){
    TElemento e;
    set conjunto1,conjunto2, conjunto3;

    crearConjuntoVacio(&conjunto1);
    crearConjuntoVacio(&conjunto2);
    crearConjuntoVacio(&conjunto3);

    TElemento e1,e2,e3,e4,e5;
    crearElemento(1, &e1);
    crearElemento(2, &e2);
    crearElemento(3, &e3);
    crearElemento(4, &e4);
    crearElemento(5, &e5);


    poner(&e1, &conjunto1);
    poner(&e2, &conjunto1);
    poner(&e3, &conjunto1);
    poner(&e1, &conjunto2);
    poner(&e1, &conjunto1);

    mostrarConjunto(&conjunto1);

    printf("\n");

    elegir(&e, &conjunto1);

    printf("\n");

    unir(&conjunto1, &conjunto2, &conjunto3);

    printf("\n");

    interseccion(&conjunto1, &conjunto2, &conjunto3);

    printf("\n");

    diferencia(&conjunto1, &conjunto2, &conjunto3);

    printf("\n");

    esSubconjunto(&conjunto2, &conjunto3);

    printf("\n");

    quitar(&e1, &conjunto1);

    printf("\n");

    igualConjunto(&conjunto2, &conjunto1);

    printf("\n");

    asignarConjunto(&conjunto1, &conjunto3);

    printf("\n");

    destruirConjunto(&conjunto1);





    return 0;
}

void insertarEnConjunto(int* store, set* s){
    TElemento e;
    for(int i=0;i<dim;i++){
        crearElemento(store[i],&e);
        poner(&e,s);
    }
}