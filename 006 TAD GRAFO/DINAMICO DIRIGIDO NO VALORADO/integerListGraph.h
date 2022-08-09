#include <stdio.h>
#include <stdlib.h>
#include "simplelinkedlist.h"
#include "arraylist.h"

//NO DIR. NO VAL.
struct NodoG{
    TElemento info;
    Tnodo *adyacentes;
    struct NodoG* sig; 
};
typedef struct NodoG TnodoG;
typedef TnodoG* TAdyacentGraph;

void crearGrafoVacio (TAdyacentGraph* a);
void insertarVertice (TElemento e, TAdyacentGraph* a);
void insertarArista (TElemento e1,TElemento e2, TAdyacentGraph* a); 
int eliminarVertice (TElemento e, TAdyacentGraph* a);
void eliminarArista (TElemento e1,TElemento e2, TAdyacentGraph* a); 
int esAdyacente(TElemento e1,TElemento e2,TAdyacentGraph a);
int contieneVertice (TElemento e, TAdyacentGraph a);
int esGrafoVacio (TAdyacentGraph a);
void listaVertices (TAdyacentGraph a, TLinkedList* l);
void listaAristas (TAdyacentGraph a, arrayList* l);
void copiarG(TAdyacentGraph original, TAdyacentGraph* copia);
void destruirG(TAdyacentGraph* a);

int gradoEntradaNodo (TAdyacentGraph a, TElemento nodo);
int gradoSalidaNodo (TAdyacentGraph a, TElemento nodo);
