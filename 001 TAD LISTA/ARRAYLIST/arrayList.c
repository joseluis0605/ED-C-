//
// Created by José Luis on 22/02/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "TElemento.h"
#include "arrayList.h"
void crearListaVacia(TLista * l){
    l->indice=-1;
}

int esListaVacia(TLista* l){
    return (*l).indice==-1;
}
int longitudLista(TLista* l){
    return l->indice+1;
}
void primeroLista(TLista * l, TElemento* e){
    if(!esListaVacia(l)){
        asignarElemento(&l->almacen[l->indice], e);
    }
}
void restoLista(TLista* l){
    if(!esListaVacia(l)){
        l->indice--;
    }
}
void ultimoLista(TLista* l, TElemento* e){
    if(!esListaVacia(l)){
        mostrarElemento(&l->almacen[l->indice]);
    }
}
void destruirLista(TLista* l){
    l->indice=-1;
}
void mostrarLista(TLista * l){
    if (!esListaVacia(l)){
        for (int i = l->indice; i >=0 ; i--) {
            mostrarElemento(&(l->almacen[i]));
            printf(" ");
        }
    }
}
void insertarLista(TElemento* e, TLista * l){
    if (l->indice<(DIM-1)){
        l->indice++;
        asignarElemento(e, &l->almacen[l->indice]);
    } else{
        printf("ESTA LLENA");
    }
}
void asignarLista(TLista* orig, TLista* dest){
    crearListaVacia(dest);
    for (int i = 0; i <= orig->indice; ++i) {
        asignarElemento(&orig->almacen[i], &dest->almacen[i]);
        dest->indice++;
    }
}
void insertarFinalLista(TElemento* e, TLista * l){
    if (l->indice<(DIM-1)){
        for (int i = l->indice; i >=0 ; i--) {
            l->almacen[i+1]=l->almacen[i];
        }
        l->indice++;
        asignarElemento(e, &l->almacen[0]);
    } else{
        printf("ESTA LLENA LA LISTA");
    }
}
int contieneLista(TElemento* e, TLista* l){
    if (!esListaVacia(l)){
        int encontrado= 0;
        int index= 0;
        while (index <= l->indice && !encontrado){
            if (igualesElemento(e, &l->almacen[index])){
                encontrado=1;
            } else{
                index++;
            }
        }
        return encontrado;
    } else{
        return 0;
    }
}
int igualLista(TLista* l1, TLista* l2){
    if (esListaVacia(l2)|| esListaVacia(l1)){
        return 0;
    } else{
        int encontrado= 1;
        TLista aux, aux2;
        crearListaVacia(&aux);
        crearListaVacia(&aux2);
        asignarLista(l1, &aux);
        asignarLista(l2, &aux2);
        while (!esListaVacia(&aux) && encontrado){
            TElemento a1, a2;
            primeroLista(&aux, &a1);
            primeroLista(&aux2, &a2);
            restoLista(&aux);
            restoLista(&aux2);
            encontrado= igualesElemento(&a1, &a2);
        }
    }
}
int eliminarLista(TElemento* e, TLista * l){
    if (!esListaVacia(l)){
        int encontrado=0;
        int index=0;
        while (!encontrado && index<=l->indice){
            encontrado= igualesElemento(e, &l->almacen[index]);
            if(!encontrado){
              index++;
            } else{
                if(index==l->indice){
                    l->indice--;
                } else{
                    for (int i = index; i < l->indice; ++i) {
                        asignarElemento(&l->almacen[i+1],& l->almacen[i]);
                    }
                    l->indice--;
                }
            }
        }
        return encontrado;
    } else{
        return 0;
    }
}
void concatenarLista(TLista* l1, TLista* l2){
    if(!esListaVacia(l1)){

        TLista aux ;
        crearListaVacia(&aux);
        asignarLista(l2, &aux);

        while (!esListaVacia(&aux)){
            TElemento nuevo;
            primeroLista(&aux, &nuevo);
            restoLista(&aux);
            insertarFinalLista(&nuevo, l1);
        }
    } else{
        asignarLista(l2, l1);
    }
}
