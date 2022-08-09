#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "arrayList.h"
#include "TElemento.h"

int main() {

    TElemento num1, num2, num3;
    TLista lista, listaAux;

    crearListaVacia(&lista);
    crearListaVacia(&listaAux);

    crearElemento(&num1, 1);
    crearElemento(&num2, 2);
    crearElemento(&num3, 3);

    insertarLista(&num1, &lista);
    insertarLista(&num2, &lista);
    //insertarLista(&num3, &lista);
    insertarLista(&num3, &listaAux);
    insertarLista(&num3, &listaAux);
    insertarLista(&num3, &listaAux);

    TElemento final;
    crearElemento(&final, 1);

    //insertarFinalLista(&final, &lista);

    //concatenarLista(&lista, &listaAux);

    //eliminarLista(&num3, &lista);
    //mostrarLista(&lista);

    printf("%d", igualLista(&lista, &lista));



}
