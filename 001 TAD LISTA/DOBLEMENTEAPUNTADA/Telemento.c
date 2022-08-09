//
// Created by José Luis on 18/03/2022.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Telemento.h"


void crearElemento(TElemento* e, int i){
    *e= i;
}
void mostrarElemento(TElemento* e){
    printf("%d", *e);
}
void asignarElemento(TElemento* orig, TElemento* dest){
    *dest= *orig;
}
int igualesElemento(TElemento* e1, TElemento* e2){
    return *e1 == *e2;
}
int esMenor (TElemento e1, TElemento e2){
    return e1 < e2;
}
void suma(TElemento e1, TElemento e2, TElemento *resultado){
    *resultado = e1 + e2;
}