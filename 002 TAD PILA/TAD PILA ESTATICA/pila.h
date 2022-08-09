#ifndef pila_h
#define pila_h
#include <stdlib.h>
#include "elemento.h"



struct Pila {
    TElemento* almacen;
    int n; //numero de elementos que tiene dentro
    int tam; //tamaño máximo de la pila
};

typedef struct Pila Pila;

void crearPilaVacia (Pila* pila);
void apilar (Pila* pila, TElemento e);
int esPilaVacia (Pila* pila);

//PRE: Pila debe ser no vacia
TElemento cima (Pila* pila);
void desapilar (Pila* pila);
void mostrar (Pila* pila);

#endif 
