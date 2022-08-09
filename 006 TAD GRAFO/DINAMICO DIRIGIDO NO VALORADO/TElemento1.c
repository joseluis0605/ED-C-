#include <stdio.h>
#include <string.h>
#include "TElemento1.h"


void print1 (TElemento1 t){
    printf("[%d , %d] ",t.origen,t.destino);
}

void asignar1(TElemento1* copia, TElemento1 original){
    copia->destino=original.destino;
    copia->origen=original.origen;
}

int igual1(TElemento1* uno, TElemento1* dos){
    return ((uno->origen==dos->origen)&&(dos->destino==uno->destino));
}

void crear1(int o, int d, TElemento1* e){
    e->destino=d;
    e->origen=o;
} 
