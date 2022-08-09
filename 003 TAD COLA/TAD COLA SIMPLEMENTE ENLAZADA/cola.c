//
// Created by Jesús Vergara Igual on 29/3/21.
//

#include "cola.h"


void crearVacia (Cola* cola){
    *cola= NULL;
}
void encolar (TElemento e, Cola* cola){
    Nodo *nuevo= malloc(sizeof (Nodo));
    nuevo->sig= NULL;
    asignar(&nuevo->info, e);
    if (esVacia(*cola)){
        (*cola)= nuevo;
    } else{
        Cola paux= *cola;
        while (paux->sig!=NULL){
            paux=paux->sig;
        }
        paux->sig=nuevo;
    }

}
void primero (Cola cola, TElemento* e){
    if (!esVacia(cola)){
        Cola paux= cola;
        while (paux->sig !=NULL){
            paux= paux->sig;
        }
        asignar(e, paux->info);
    }
}
void eliminar (Cola* cola){
    if (!esVacia(*cola)){
        Cola paux= *cola;
        *cola= paux->sig;
        free(paux);
    }
}
int esVacia (Cola cola){
    return cola==NULL;
}
void mostrar (Cola cola){
    if (!esVacia(cola)){
        Cola paux= cola;
        while (paux!=NULL){
            imprimir(paux->info);
            paux= paux->sig;
        }
    }
    printf("\n");
}