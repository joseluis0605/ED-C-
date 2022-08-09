#define Dim 10
#include "TElemento.h"
#include "TClave.h"
#include "TConjuntoDinamico.h"
#include "TConjuntoDinamico1.h"
#include "TConjuntoDinamico2.h"
#define Vacio 0
#define Borrado 1
#define Ocupado 2

struct NodoMapa{
    int estado; //0 vacio, 1 borrado, 2 ocupado
    TElemento elemen;
};
typedef struct NodoMapa Tnodo;
typedef struct NodoMapa Mapa[Dim];

void crearMapaVacio (Mapa* a);
int esMapaVacio (Mapa* a);
void mostrarMapa (Mapa* a);
int sizeMapa (Mapa* a);
void ponerMapa (TClave* c, TValor* e, Mapa* a);
int quitarMapa (TClave* c, Mapa* a);
void devolver (TClave* c, TValor* v, Mapa* a);
void destruirMapa(Mapa* a);
/////////////////////////////////////////////////////////////
void conjuntoEntradas (set* e, Mapa* h);
void conjuntoClaves (set1* e, Mapa* h);
void conjuntoValores (set2* e, Mapa* h);
void asignarMapa(Mapa* original, Mapa* copia);
int SonIgualesMapa (Mapa *a1, Mapa *a2);
int SonIgualesMapaV2 (Mapa *a1, Mapa *a2);





