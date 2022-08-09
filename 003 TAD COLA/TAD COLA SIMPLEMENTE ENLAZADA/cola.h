#ifndef pila_h
#define pila_h
#include <stdlib.h>
#include "elemento.h"

// LA COLA SE INSERTA POR UN LADO Y SE MUESTRA Y ELIMINA POR EL OTRO
// MOSTRAMOS POR LA IZQUIERDA Y ELMININAMOS POR IZQUIERDA
// INSERTAMOS POR LA DERECHA

struct Nodo {
    TElemento info;
    struct Nodo *sig;
};

typedef struct Nodo Nodo;

typedef Nodo* Cola;

void crearVacia (Cola* cola);
void encolar (TElemento e, Cola* cola); //insertar al final
void primero (Cola cola, TElemento* e); //Devuelve el primero
void eliminar (Cola* cola); //Elimina el primero
int esVacia (Cola cola);
void mostrar (Cola cola);


#endif 
