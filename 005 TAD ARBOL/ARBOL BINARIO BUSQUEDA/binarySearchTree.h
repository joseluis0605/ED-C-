#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "simplelinkedlist.h"

typedef struct NodeSearchTree{
        TElemento info;
        struct NodeSearchTree* left;
        struct NodeSearchTree* right;
    }TNodeSearchTree;

typedef TNodeSearchTree* TBinarySearchTree;


void CrearArbolBusquedaVacio(TBinarySearchTree* a);
void DevolverRaizBusqueda(TBinarySearchTree a, TElemento* r);
void DevolverHijoIzquierdoBusqueda(TBinarySearchTree a, TBinarySearchTree* r);
void DevolverHijoDerechoBusqueda(TBinarySearchTree e, TBinarySearchTree* r);
void destruirArbolBusqueda(TBinarySearchTree* a);
void copiarArbolBusqueda(TBinarySearchTree original, TBinarySearchTree* copia);
int  esArbolBusquedaVacio(TBinarySearchTree a);

//FUNCIONES ADICIONALES//
int numeroNodos(TBinarySearchTree a);
int numeroHojas(TBinarySearchTree a);
int altura(TBinarySearchTree a);
void preorden(TBinarySearchTree a, TLinkedList* r);
void inorden(TBinarySearchTree a, TLinkedList* r);
void postorden(TBinarySearchTree a, TLinkedList* r);
//FIN FUNCIONES ADICIONALES//


//PROPIAS DEL TAD ABB
int contieneArbolBinarioBusqueda(TBinarySearchTree a,TElemento e);
void insertarArbolBusqueda(TBinarySearchTree* a,TElemento e);
void eliminarArbolBusqueda(TBinarySearchTree* a,TElemento e);
void mayorNodo(TElemento * e, TBinarySearchTree a);
void menorNodo(TElemento * e, TBinarySearchTree a);

void ascendientes (TBinarySearchTree* a, TElemento* e, TLinkedList * r);
