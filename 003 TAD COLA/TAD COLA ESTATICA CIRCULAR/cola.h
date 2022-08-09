#ifndef cola_h
#define cola_h
#include <stdlib.h>
#include "TElemento.h"
#define N 10


struct Cola {
    TElemento almacen[N];
    int longitud;
    int inicio;
    int fin;
};

typedef struct Cola Cola;

void crearColaVacia (Cola* cola);
void insertar (Cola* cola, TElemento e);
int esColaVacia (Cola cola);

//PRE: Cola debe ser no vacia
void primero (Cola cola, TElemento *e);
void eliminar (Cola* cola);
void mostrar (Cola cola);

#endif 
