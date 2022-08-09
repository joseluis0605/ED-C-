#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"



typedef struct NodoSet{
    TElemento info;
    struct NodoSet* sig;
  }TnodoSet;



typedef TnodoSet* set;


void crearConjuntoVacio (set* a);
void mostrarConjunto (set* a);
void poner (TElemento* e, set* a);
int quitar (TElemento* e, set* a);
int elegir (TElemento* e, set* a);
void interseccion (set* a1, set* a2, set* u);
void diferencia (set* a1, set* a2, set* u);
void unir(set* a1, set* a2, set* u);
int esSubconjunto (set* a1, set* a2);
int pertenece (TElemento* e, set* a);
int esConjuntoVacio (set* a);
int cardinal (set* a);
int igualConjunto (set* l1, set* l2);
void asignarConjunto(set* original, set* copia);
void destruirConjunto(set* a);