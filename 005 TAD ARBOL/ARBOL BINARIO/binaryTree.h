#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "simplelinkedlist.h"

typedef struct NodeTree{
        TElemento info;
        struct NodeTree* left;
        struct NodeTree* right;

    }TNodeTree;

typedef TNodeTree* TBinaryTree;

void CrearArbolVacio(TBinaryTree* a);
void CrearArbol(TBinaryTree* a,TBinaryTree izq,TBinaryTree der,TElemento e);

void DevolverRaiz(TBinaryTree a, TElemento* r);
void DevolverHijoIzquierdo(TBinaryTree a, TBinaryTree* hIzq);
void DevolverHijoDerecho(TBinaryTree a, TBinaryTree* hDer);

void destruirArbol(TBinaryTree* a);
void copiarArbol(TBinaryTree original, TBinaryTree* copia);
int  esArbolVacio(TBinaryTree a);

//Las demás funciones son adicionales, no son las del TAD BinaryTree por defecto
int contieneArbolBinario(TBinaryTree a,TElemento e);

int numeroNodos(TBinaryTree a);
int numeroHojas(TBinaryTree a);
int altura(TBinaryTree a);
void imprimirPreorden (TBinaryTree a);
void imprimirInorden (TBinaryTree a);
void imprimirPostorden (TBinaryTree a);

void preorden(TBinaryTree a, TLinkedList* r);
void inorden(TBinaryTree a, TLinkedList* r);
void postorden(TBinaryTree a, TLinkedList* r);

void imprimirNivel (TBinaryTree a, int nivel);
void dameListaNivelAux (TBinaryTree a, int nivel, TLinkedList* lista);
void dameListaNivel (TBinaryTree a, int nivel, TLinkedList* lista);
void imprimirNivelesImparesAux (TBinaryTree a, int nivel);
void imprimirNivelesParesAux (TBinaryTree a, int nivel);

void imprimirNivelesImpares (TBinaryTree a);

//EJERCICIOS EXTRAS

void imprimirHojas (TBinaryTree a);
int esArbolPar (TBinaryTree a);
int numeroNodosSoloDerechoVacio (TBinaryTree a);
int numeroNodosSoloIzquierdoVacio (TBinaryTree a);
void borrarHojas (TBinaryTree *a);
void espejo (TBinaryTree a, TBinaryTree *esp);
int sonEspejo (TBinaryTree a, TBinaryTree b);
int sonIguales (TBinaryTree a, TBinaryTree b);
int esDegenerado (TBinaryTree a);
void minimo (TBinaryTree a, TElemento *min);
void mayor (TBinaryTree a, TElemento *max);
int esABB (TBinaryTree a);