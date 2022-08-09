//
// Created by Jesús Vergara Igual on 29/3/21.
//

#include "cola.h"

void crearVacia (Cola* cola){
    cola->principio=NULL;
    cola->final=NULL;
}
void encolar (TElemento e, Cola* cola){
    Nodo *nuevo= malloc(sizeof (Nodo));
    asignar(&nuevo->info, e);
    nuevo->sig=NULL;
    if (esVacia(*cola)){
        cola->final=nuevo;
        cola->principio=nuevo;
    } else{
        cola->final->sig=nuevo;
        cola->final=nuevo;
    }
}
void primero (Cola cola, TElemento* e){
    if (!esVacia(cola)){
        asignar(e, cola.principio->info);
    }
}
void eliminar (Cola* cola){
    if(!esVacia(*cola)){
        if(cola->principio->sig==NULL){
            //es el primero y unico
            Nodo *paux= cola->principio;
            cola->principio=NULL;
            cola->final=NULL;
            free(paux);
        } else{
            Nodo *paux= cola->principio;
            cola->principio=paux->sig;
            free(paux);
        }
    }
}
int esVacia (Cola cola){
    return cola.principio==NULL;
}
void mostrar (Cola cola){
    if (!esVacia(cola)){
        Nodo *paux= cola.principio;
        while (paux!=NULL){
            imprimir(paux->info);
            paux=paux->sig;
        }
    }
    printf("\n");
}