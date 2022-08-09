#include <stdio.h>
#include <stdlib.h>
#include "simplelinkedlist.h"
#include "arraylist.h"
#define dim 100

//NO DIR. NO VAL.

typedef struct MGraph{
    int nodes[dim];
    int matrix[dim][dim];
}TMGraph;

void crearGrafoVacio (TMGraph* a);
void insertarVertice (int i, TMGraph* a);
void insertarArista (int lhs,int rhs, TMGraph* a);
int eliminarVertice (int nodo, TMGraph* a);
void eliminarArista (int lhs,int rhs, TMGraph* a);
int esAdyacente(int lhs,int rhs,TMGraph a);
int contieneVertice (int i, TMGraph a);
int esGrafoVacio (TMGraph a);



void listaVertices (TMGraph a, TLinkedList* l);
void listaAristas (TMGraph a,arrayList* l);
void copiarG(TMGraph original, TMGraph* copia);
void destruirG(TMGraph* a);

