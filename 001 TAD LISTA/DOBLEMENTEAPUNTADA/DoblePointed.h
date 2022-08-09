//
// Created by José Luis on 18/03/2022.
//
#include "Telemento.h"
struct lista{
    struct nodo *principio;
    struct nodo *final;
};
typedef struct lista TLista;

struct nodo{
    TElemento info;
    struct nodo *sig;
};

typedef struct nodo* nodo;

void crearListaVacia(TLista  *l);
int esListaVacia(TLista* l);
int longitudLista(TLista* l);
void primeroLista(TLista * l, TElemento* e);
void restoLista(TLista* l);
void ultimoLista(TLista* l, TElemento* e);
void destruirLista(TLista* l);
void mostrarLista(TLista * l);
void insertarLista(TElemento* e, TLista * l);
void asignarLista(TLista* orig, TLista* dest);
void insertarFinalLista(TElemento* e, TLista * l);
int contieneLista(TElemento* e, TLista* l);
int eliminarLista(TElemento* e, TLista * l);
void concatenarLista(TLista* l1, TLista* l2);

//EJERCICIOS EXTRAS
void unique (TLista *lista);
void borrarUltimo (TLista *lista);
void borrarNprimeros (TLista *lista, int n);
void borrarCadaX (TLista *lista, int n);
void insertarDespuesDe (TLista *lista, TElemento insertardespues, TElemento elemento);
void insertarOrdenado (TLista *lista, TElemento elemento);
void vecesXelemento (TLista *lista, TElemento elemento);
void sumarLista (TLista *lista);
void posfija (TLista *lista, TElemento elemento);
void listaOrdenada (TLista *lista1, TLista *lista2);
void sumaAnteriores(TLista *lista, TElemento elemento);
void criba (TLista *lista, int salto);
