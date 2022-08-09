#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#define Dim 100


struct booleanbarraySet{
    int numeroElementos;  //Los que estan a 1
    int almacen[Dim];
 };

typedef struct booleanbarraySet booleanbarraySet;



void crearConjuntoVacio (booleanbarraySet* a);
void mostrarConjunto (booleanbarraySet* a);
void insertarConjunto (TElemento e, booleanbarraySet* a);
int eliminarConjunto (TElemento e, booleanbarraySet* a);
void elegir (TElemento* e, booleanbarraySet* a);
void interseccion (booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* i); 
void diferencia (booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* d); 
void unir(booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* u);
int esSubconjunto (booleanbarraySet* a1, booleanbarraySet* a2);
int contiene (TElemento e, booleanbarraySet* a);
int esConjuntoVacio (booleanbarraySet* a);
int cardinal (booleanbarraySet* a);
void copiarConjunto(booleanbarraySet* original, booleanbarraySet* copia); 
void destruirConjunto(booleanbarraySet* a);

