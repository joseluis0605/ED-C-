//
// Created by José Luis on 22/02/2022.
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stdio.h>
#include "TElemento.h"

#define DIM 100

struct TLista{
    TElemento almacen[DIM];
    int indice;
};
typedef struct TLista TLista;

void crearListaVacia(TLista * l);
int esListaVacia(TLista* l);
int longitudLista(TLista* l);
void primeroLista(TLista * l, TElemento* e);
void restoLista(TLista* l);
void ultimoLista(TLista* l, TElemento* e);
void destruirLista(TLista* l);
void mostrarLista(TLista * l);
void insertarLista(TElemento* e, TLista * l);
void asignarLista(TLista* orig, TLista* dest);
void insertarFinalLista(TElemento* e, TLista * l);
int contieneLista(TElemento* e, TLista* l);
int igualLista(TLista* l1, TLista* l2);
int eliminarLista(TElemento* e, TLista * l);
void concatenarLista(TLista* l1, TLista* l2);


#endif //ARRAYLIST_ARRAYLIST_H
