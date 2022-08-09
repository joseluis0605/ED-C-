#define Dim 100
#include "TElemento.h"


typedef struct Tset{
    int indice;
    TElemento almacen[Dim];
} set;




void crearConjuntoVacio (set* a);
void mostrarConjunto (set* a);
void poner (TElemento* e, set* a);
int quitar (TElemento* e, set* a);
int elegir (TElemento* e, set* a);
void interseccion (set* a1, set* a2, set* i);
void diferencia (set* a1, set* a2, set* d);
void unir(set* a1, set* a2, set* u);
int esSubconjunto (set* a1, set* a2);
int pertenece (TElemento* e, set* a);
int esConjuntoVacio (set* a);
int cardinal (set* a);
void asignarConjunto(set* original, set* copia);
int igualConjuntos (set* l1, set* l2);
void destruirConjunto(set* a);




