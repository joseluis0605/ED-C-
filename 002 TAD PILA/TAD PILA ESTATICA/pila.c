#include "pila.h"


void crearPilaVacia (Pila* pila){
    pila->n= 0;
    pila->almacen= malloc(sizeof (TElemento)*pila->tam);
}
void apilar (Pila* pila, TElemento e){
    if (pila->n < pila->tam){
        asignar(&pila->almacen[pila->n], e);
        pila->n++;
    }
}
int esPilaVacia (Pila* pila){
    return pila->n== 0;
}

//PRE: Pila debe ser no vacia
TElemento cima (Pila* pila){
    if (!esPilaVacia(pila)){
        return pila->almacen[pila->n-1];
    }
    return 0;
}
void desapilar (Pila* pila){
    if (!esPilaVacia(pila)){
        pila->n--;
    }
}
void mostrar (Pila* pila){
    if (!esPilaVacia(pila)){
        for (int i = pila->n-1; i >=0 ; i--) {
            imprimir(pila->almacen[i]);
        }
    }
}