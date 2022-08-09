#define Dim 100
#include "TElemento1.h"

typedef TElemento1 TAlmacen[Dim];

struct TarrayList
{
    int indice;
    TAlmacen almacen;
  //  TElemento1 almacen[Dim]; También se podría haber puesto así
} ;

typedef struct TarrayList arrayList;


void crearVaciaA (arrayList* a);
void mostrarA (arrayList a);
void insertarA (TElemento1 e, arrayList* a);
void insertarFinalA (TElemento1 e, arrayList* a);
int eliminarA (TElemento1 e, arrayList* a);
void primeroA (arrayList a, TElemento1* e);
void restoA (arrayList* a);
void ultimoA (arrayList a, TElemento1* e);
void concatenarA(arrayList* a1, arrayList a2);
int contieneA (TElemento1 e, arrayList a);
int esVaciaA (arrayList a);
int longitudA(arrayList a);

void destruirA(arrayList* a);

void copiarA(arrayList original, arrayList* copia);




