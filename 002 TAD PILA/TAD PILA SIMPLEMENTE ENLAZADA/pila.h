#ifndef pila_h
#define pila_h
#include <stdlib.h>
#include "elemento.h"


struct Nodo {
    TElemento info;
    struct Nodo *sig;
};

typedef struct Nodo Nodo;

typedef Nodo* Pila;

void crearPilaVacia (Pila* pila);        //CrearListaVacia
void apilar (Pila* pila, TElemento e); //Insertar por el principio      insertar
int esPilaVacia (Pila pila);   //esListaVacia
//PRE: Pila debe ser no vacia
void cima (Pila pila, TElemento *e); //Consulta y devuelve el primero    primero
void desapilar (Pila* pila); //Elimina por el principio    resto
void mostrar (Pila pila);   // mostrar


#endif 
