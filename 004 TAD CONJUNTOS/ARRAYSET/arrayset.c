#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define Dim 100

#include "arrayset.h"


void crearConjuntoVacio (set* a){
    a->indice=-1;
}
void mostrarConjunto (set* a){
    if (!esConjuntoVacio(a)){
        for (int i = a->indice; i >=0; --i) {
            mostrarElemento(&a->almacen[i]);
        }
    }
    printf("\n");

}
void poner (TElemento* e, set* a){
    if (!pertenece(e,a)){
        if (a->indice< (Dim-1)){
            //entra un elemento
            a->indice++;
            asignarElemento(e, &a->almacen[a->indice]);
        }
    }
}
int quitar (TElemento* e, set* a){
    if (!esConjuntoVacio(a)){
        int encontrado=0;
        int index= 0;
        while (index<=a->indice && !encontrado){
            encontrado= igualElemento(&a->almacen[index], e);
            if (encontrado){
                for (int i = index; i < a->indice; ++i) {
                    asignarElemento(&a->almacen[i+1], &a->almacen[i]);
                }
                a->indice--;
            } else{
                index++;
            }
        }
        mostrarConjunto(a);
        return encontrado;
    }
    return 0;
}
int elegir (TElemento* e, set* a){
    if (!esConjuntoVacio(a)){
        srand(time(NULL));
        int numeroPosiciones= rand() % cardinal(a);
        mostrarElemento(&a->almacen[numeroPosiciones]);
        asignarElemento(&a->almacen[numeroPosiciones], e);
    }
}
void interseccion (set* a1, set* a2, set* i){
    if (!esConjuntoVacio(a1)){
        crearConjuntoVacio(i);
        int index= 0;
        while (index<=a1->indice){
            if(pertenece(&a1->almacen[index], a2)){
                poner(&a1->almacen[index], i);
            }
            index++;
        }
        mostrarConjunto(i);
    }
}
void diferencia (set* a1, set* a2, set* d){
    if (!esConjuntoVacio(a1)){
        for (int i = 0; i <= a1->indice ; ++i) {
            if (!pertenece(&a1->almacen[i], a2)){
                poner(&a1->almacen[i], d);
            }
        }
        mostrarConjunto(d);
    }
}
void unir(set* a1, set* a2, set* u){
    crearConjuntoVacio(u);
    if (esConjuntoVacio(a1)){
        for (int i = 0; i <= a2->indice; ++i) {
            asignarElemento(&a2->almacen[i], &u->almacen[i]);
            u->indice++;
        }
    }else if (esConjuntoVacio(a2)){
        for (int i = 0; i <= a1->indice; ++i) {
            asignarElemento(&a1->almacen[i], &u->almacen[i]);
            u->indice++;
        }
    } else{
        for (int i = 0; i <= a1->indice; ++i) {
            poner(&a1->almacen[i], u);
        }
        for (int i = 0; i <= a2->indice; ++i) {
            poner(&a2->almacen[i], u);
        }
    }
    mostrarConjunto(u);
}
int esSubconjunto (set* a1, set* a2){
    if (cardinal(a1) <= cardinal(a2)){
        int esta=1;
        int index= 0;

        while (index <=a1->indice && esta){
            esta= pertenece(&a1->almacen[index], a2);
            if (esta){
                index++;
            }
        }
        printf("%d", esta);
        return esta;

    }
    return 0;
}
int pertenece (TElemento* e, set* a){
    if (!esConjuntoVacio(a)){
        for (int i = 0; i <= a->indice; ++i) {
            if(igualElemento(&a->almacen[i], e)){
                return 1;
            }
        }
        return 0;
    }
    return 0;
}
int esConjuntoVacio (set* a){
    return a->indice==-1;
}
int cardinal (set* a){
    return a->indice+1;
}
void asignarConjunto(set* original, set* copia){
    if (!esConjuntoVacio(original)){
        crearConjuntoVacio(copia);
        for (int i = 0; i <= original->indice; ++i) {
            asignarElemento(&original->almacen[i], &copia->almacen[i]);
            copia->indice++;
        }
        mostrarConjunto(copia);
    }
}
int igualConjuntos (set* l1, set* l2){
    if (cardinal(l1) == cardinal(l2)){
        int iguales=1;
        int index= 0;
        while (index<= l1->indice && iguales){
            iguales= pertenece(&l1->almacen[index], l2);
            if (iguales){
                index++;
            }
        }
        printf("%d", iguales);
        return iguales;
    }
    return 0;
}
void destruirConjunto(set* a){
    a->indice=-1;
}
