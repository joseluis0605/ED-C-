//
// Created by Jesús Vergara Igual on 6/4/21.
//

#include "cola.h"

void crearColaVacia (Cola* cola){
    cola->fin=-1;
    cola->inicio= -1;
    cola->longitud=0;
}
void insertar (Cola* cola, TElemento e){
    if (cola->longitud < N){
        //hay hueco
        if (esColaVacia(*cola)){
            cola->longitud++;
            cola->inicio++;
            cola->fin++;
            asignar(&cola->almacen[0], e);
        } else{
            cola->fin++;
            cola->longitud++;
            if (cola->fin==N){
                cola->fin=0;
            }
            asignar(&cola->almacen[cola->fin], e);
        }
    }
}
int esColaVacia (Cola cola){
    return cola.longitud==0;
}

//PRE: Cola debe ser no vacia
void primero (Cola cola, TElemento *e){
    if (!esColaVacia(cola)){
        asignar(e, cola.almacen[cola.inicio]);
    }
}
void eliminar (Cola* cola){
    if (!esColaVacia(*cola)){
        cola->inicio++;
        if (cola->inicio==N){
            cola->inicio=0;
        }
        cola->longitud--;
    }
}
void mostrar (Cola cola){
    if (!esColaVacia(cola)){
        int index= cola.inicio;
        if(cola.fin < cola.inicio){
            while (index<N){
                print(cola.almacen[index]);
                index++;
            }
            index=0;
            while (index <= cola.fin){
                print(cola.almacen[index]);
                index++;
            }
        } else{
            for (int i = index; i <= cola.fin; ++i) {
                print(cola.almacen[i]);
            }
        }
    }
}
