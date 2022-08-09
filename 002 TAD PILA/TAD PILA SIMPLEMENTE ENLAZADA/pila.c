//
// Created by Jesús Vergara Igual on 29/3/21.
//

#include "pila.h"

//CON LA PILA TENEMOS QUE HACER TODAS LAS OPERACIONES POR EL MISMO LADO

void crearPilaVacia (Pila* pila){
    *pila =NULL;
}
void apilar (Pila* pila, TElemento e){
    //vamos a insertar por el principio y hacer todo por el principio
    Nodo *nuevo= malloc(sizeof (Nodo));
    asignar(&nuevo->info, e);
    nuevo->sig=*pila;
    *pila= nuevo;
}
int esPilaVacia (Pila pila){
    return pila==NULL;
}
void cima (Pila pila, TElemento *e){
    if (!esPilaVacia(pila)){
        asignar(e, pila->info);
    }
    printf("\n");

}
void desapilar (Pila* pila){
    if (!esPilaVacia(*pila)){
        Pila paux= *pila;
        *pila= paux->sig;
        free(paux);
    }
    printf("\n");

}
void mostrar (Pila pila){
    if (!esPilaVacia(pila)){
        Pila paux= pila;
        while (paux!=NULL){
            imprimir(paux->info);
            paux= paux->sig;
        }
    }
    printf("\n");
}
