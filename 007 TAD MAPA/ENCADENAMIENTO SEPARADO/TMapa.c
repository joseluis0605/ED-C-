#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#include "TMapa.h"

int hashP(TClave* c){
    return (hash(c))%Dim;
}

void crearMapaVacio (Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        crearListaVacia(&(*a)[i]);
    }
}
void mostrarMapa (Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        mostrarLista(&(*a)[i]);
    }
}
void ponerMapa (TClave* c, TValor* e, Mapa* a){
    int poscion= hashP(c);
    TElemento nuevo;
    crearElemento(c,e, &nuevo);
    eliminarLista(&nuevo, &(*a)[poscion]);
    insertarLista(&nuevo, &(*a)[poscion]);
}
void devolver (TClave* c, TValor* v, Mapa* a){
    //Nos devuelve dada la clave el valor
    int poscion= hashP(c), encontrado= 0;

    TLista nueva;
    crearListaVacia(&nueva);
    asignarLista(&(*a)[poscion], &nueva);

    while (!esListaVacia(&nueva) && !encontrado){
        TElemento primeros;
        primeroLista(&primeros, &nueva);
        restoLista(&nueva);
        TClave aux;
        getClave(&primeros, &aux);
        if (igualClave(&aux, c)){
            encontrado=1;
            asignarValor(&primeros.valor, v);
            mostrarValor(&primeros.valor);
        }
    }
    if (encontrado==0){
        printf("NO ESTA LA CLAVE:\n");
    }
}
int esMapaVacio (Mapa* a){
    int esVacio=1;
    int index=0;
    while (index< Dim &&  esVacio){
        esVacio= esListaVacia(a[index]);
        index++;
    }
    return esVacio;
}
int sizeMapa (Mapa* a){
    int contador=0;
    for (int i = 0; i < Dim; ++i) {
        contador= contador + longitudLista(*a);
    }
    return contador;
}
int quitarMapa (TClave* c, Mapa* a){
    int posicion= hashP(c);
    int encontrado= 0;
    TLista lista;
    crearListaVacia(&lista);
    asignarLista(&(*a)[posicion], &lista);
    while (!esListaVacia(&lista) && !encontrado){
        TElemento primero;
        primeroLista(&primero, &lista);
        restoLista(&lista);
        TClave posible;
        getClave(&primero, &posible);
        if (igualClave(&posible, c)){
            encontrado=1;
            mostrarElemento(&primero);
            eliminarLista(&primero, &(*a)[posicion]);
        }
    }
    destruirLista(&lista);
    return encontrado;
}
void conjuntoEntradas (set* e, Mapa* h){
    crearConjuntoVacio(e);
    for (int i = 0; i < Dim; ++i) {
        TElemento primero;
        TLista lista;
        crearListaVacia(&lista);
        asignarLista(&(*h)[i], &lista);
        while (!esListaVacia(&lista)){
            primeroLista(&primero, &lista);
            restoLista(&lista);
            poner(&primero, e);
        }
    }
}
void conjuntoClaves (set1* e, Mapa* h){
    crearConjuntoVacio1(e);
    for (int i = 0; i < Dim; ++i) {
        TElemento primero;
        TLista lista;
        crearListaVacia(&lista);
        asignarLista(&(*h)[i], &lista);
        while (!esListaVacia(&lista)){
            primeroLista(&primero, &lista);
            restoLista(&lista);
            TClave miclave;
            getClave(&primero, &miclave);
            poner1(&miclave, e);
        }
    }
}
void conjuntoValores (set2* e, Mapa* h){
    crearConjuntoVacio2(e);
    for (int i = 0; i < Dim; ++i) {
        TElemento primero;
        TLista lista;
        crearListaVacia(&lista);
        asignarLista(&(*h)[i], &lista);
        while (!esListaVacia(&lista)){
            primeroLista(&primero, &lista);
            restoLista(&lista);
            TValor miclave;
            getValor(&primero, &miclave);
            poner2(&miclave, e);
        }
    }
}
void asignarMapa(Mapa* original, Mapa* copia){
    crearMapaVacio(copia);
    for (int i = 0; i < Dim; ++i) {
        TLista nueva;
        crearListaVacia(&nueva);
        asignarLista(&(*original)[i], &nueva);
        (*copia)[i]=nueva;
    }
}
void destruirMapa(Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        destruirLista(&(*a)[i]);
    }
}













