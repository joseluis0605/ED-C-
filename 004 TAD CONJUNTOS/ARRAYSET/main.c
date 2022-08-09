#include <stdio.h>
#include <stdlib.h>
#include "arrayset.h"

#define dim 20

void insertarEnConjunto(int* store, set* s);

int main(){

    TElemento e1,e2,e3,e4,e5,e6;
    crearElemento(1, &e1);
    crearElemento(2, &e2);
    crearElemento(3, &e3);
    crearElemento(4, &e4);
    crearElemento(5, &e5);
    crearElemento(1, &e1);

    set conjunto1, conjunto2, conjunto3;
    crearConjuntoVacio(&conjunto1);
    crearConjuntoVacio(&conjunto2);
    crearConjuntoVacio(&conjunto3);


    //poner(&e1, &conjunto1);
    //poner(&e2, &conjunto1);
    poner(&e3, &conjunto1);
    poner(&e4, &conjunto1);
    poner(&e5, &conjunto1);
    poner(&e1, &conjunto1);
    poner(&e1, &conjunto1);
    poner(&e1, &conjunto1);
    poner(&e1, &conjunto1);

    poner(&e1, &conjunto2);
    poner(&e2, &conjunto2);
    poner(&e3, &conjunto2);
    //poner(&e5, &conjunto2);

    mostrarConjunto(&conjunto1);
    mostrarConjunto(&conjunto2);


    //quitar(&e5, &conjunto1);

    //mostrarConjunto(&conjunto1);

    //elegir(&e6, &conjunto1);

    //asignarConjunto(&conjunto1, &conjunto2);

    //igualConjuntos(&conjunto1, &conjunto2);

    //esSubconjunto(&conjunto1, &conjunto2);

    diferencia(&conjunto1, &conjunto2, &conjunto3);




    return 0;
}

void insertarEnConjunto(int* store, set* s){
    TElemento e;
    for(int i=0;i<dim;i++){
        crearElemento(store[i],&e);
        poner(&e,s);
    }
}