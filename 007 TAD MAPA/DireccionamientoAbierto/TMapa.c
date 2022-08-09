#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#include "TMapa.h"

int hashP(TClave* c){
    return (hash(c))%Dim;
}

void crearMapaVacio (Mapa* a){
    for (int i = 0; i < Dim ; ++i) {
        (*a)[i].estado = Vacio;
    }
}
int esMapaVacio (Mapa* a){
    int esVacio = 1;
    for (int i = 0; i < Dim && esVacio; ++i) {
        esVacio = ((*a)[i].estado == Vacio);
    }
    return esVacio;
}
void mostrarMapa (Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        if ((*a)[i].estado == Ocupado){
            mostrarElemento(&((*a)[i].elemen));
        }
    }
}
int sizeMapa (Mapa* a){
    int contador = 0;
    for (int i = 0; i < Dim; ++i) {
        if ((*a)[i].estado == Ocupado){
            contador++;
        }
    }
    return contador;
}
void ponerMapa (TClave* c, TValor* e, Mapa* a){
    int posicion = hashP(c);
    TElemento elem;
    crearElemento(c,e,&elem);
    int iterador = 0;
    int igua = 0;
    while ((*a)[posicion].estado != Vacio && iterador<Dim && !igua){
        TClave aux;
        getClave(&(*a)[posicion].elemen,&aux);
        igua = igualClave(&aux,c);
        if (!igua){
            posicion = (posicion + 1) % Dim;
            iterador++;
        }
    }
    //o he encontrado el hueco  o esta lleno o tengo que renombrar
    if (iterador<Dim){
        asignarElemento(&elem,&(*a)[posicion].elemen);
        (*a)[posicion].estado = Ocupado;
    }else{
        printf("NO HAY HUECO\n");
    }
}
int quitarMapa (TClave* c, Mapa* a){
    int posicion = hashP(c);
    int contador = 0;
    TClave clave;
    getClave(&((*a))[posicion].elemen,&clave);
    while (contador<Dim && (*a)[posicion].estado != Vacio && (!igualClave(&clave,c) || (*a)[posicion].estado != Borrado)){
        contador ++;
        posicion = (posicion + 1) % Dim;
        getClave(&((*a))[posicion].elemen,&clave);
    }
    //puede que lo hayas encontrado o que no.
    if (igualClave(&clave,c) && (*a)[posicion].estado == Ocupado){
        //lo hemos encontrado
        (*a)[posicion].estado = Borrado;
        return 1;
    }else{
        return 0;
    }
}
void devolver (TClave* c, TValor* v, Mapa* a){
    //devuelve el valor buscado
    int posicion = hashP(c);
    int contador = 0;
    TClave clave;
    getClave(&((*a))[posicion].elemen,&clave);
    while (contador<Dim && !igualClave(&clave,c) && (*a)[posicion].estado == Ocupado){
        contador ++;
        posicion = (posicion + 1) % Dim;
        getClave(&((*a))[posicion].elemen,&clave);
    }
    //puede que lo haya encontrado o que no
    if (igualClave(&clave,c)){
        //lo hemos encontrado
        getValor(&((*a))[posicion].elemen,v);
    }
}
void destruirMapa(Mapa* a){
    crearMapaVacio(a);
}
void asignarMapa(Mapa* original, Mapa* copia){
    crearMapaVacio(copia);
    for (int i = 0; i < Dim; ++i) {
        (*copia)[i].estado = (*original)[i].estado;
        if ( (*original)[i].estado == Ocupado){
            asignarElemento(&(*original)[i].elemen, &(*copia)[i].elemen);
        }
    }
}
int SonIgualesMapa (Mapa *a1, Mapa *a2){
    if (sizeMapa(a1) != sizeMapa(a2)){
        return 0;
    }else{
        int iguales = 1;
        int iterador = 0;
        for (int i = 0; i < Dim; ++i) {
            if ((*a1)[i].estado == Ocupado){
                TClave c1;
                TValor v1,v2;
                getValor(&(*a1)[i].elemen,&v1);
                getClave(&(*a1)[i].elemen,&c1);
                devolver(&c1,&v2,a2);
                printf("COMPRUEBO SI SON IGULES EL VALOR: ");
                mostrarValor(&v1);
                printf(" y: ");
                mostrarValor(&v2);
                printf("\n");
                iguales = igualValor(&v1,&v2);
            }
            iterador++;
        }
        return iguales;
    }
}
void conjuntoClaves (set1* e, Mapa* h){
    crearConjuntoVacio1(e);
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i].estado == Ocupado){
            //inserto la clave
            TClave aux;
            getClave(&((*h)[i].elemen),&aux);
            poner1(&aux,e);
        }
    }
}
void conjuntoValores (set2* e, Mapa* h){
    crearConjuntoVacio2(e);
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i].estado == Ocupado){
            //inserto el valor
            TValor aux;
            getValor(&((*h)[i].elemen),&aux);
            poner2(&aux,e);
        }
    }
}
void conjuntoEntradas (set* e, Mapa* h){
    crearConjuntoVacio(e);
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i].estado == Ocupado){
            //inserto el elemento
            TElemento aux;
            asignarElemento(&((*h)[i].elemen),&aux);
            poner(&aux,e);
        }
    }
}
int SonIgualesMapaV2 (Mapa *a1, Mapa *a2){
    int iguales = 1;
    set1 conjunto;
    int iterador = 0;
    TClave aux;
    TValor e1,e2;

    if (sizeMapa(a1) != sizeMapa(a2)){
        return 0;
    }else{
        crearConjuntoVacio1(&conjunto);
        conjuntoClaves(&conjunto,a1);
        while (iterador<Dim && iguales && !esConjuntoVacio1(&conjunto)){
            elegir1(&aux,&conjunto);
            quitar1(&aux,&conjunto);
            devolver(&aux,&e1,a1);
            devolver(&aux,&e2,a2);
            iguales = igualValor(&e1,&e2);
            iterador++;
        }
    }
    return iguales;
}