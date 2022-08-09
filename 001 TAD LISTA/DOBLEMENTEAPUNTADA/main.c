#include <stdio.h>
#include "stdlib.h"
#include "Telemento.h"
#include "DoblePointed.h"

void borrarUltimoMain (TLista *lista){
    if (!esListaVacia(lista)){
        TLista aux;
        crearListaVacia(&aux);
        int longitud= longitudLista(lista);
        longitud--;
        for (int i = 0; i < longitud; ++i) {
            TElemento auxiliar;
            primeroLista(lista, &auxiliar);
            restoLista(lista);
            insertarFinalLista(&auxiliar, &aux);
        }
        destruirLista(lista);
        asignarLista(&aux, lista);
    }
}

int main() {

    TLista lista;
    crearListaVacia(&lista);

    TLista lista2;
    crearListaVacia(&lista2);

    TLista listaNueva;
    crearListaVacia(&listaNueva);

    TElemento a1,a2,a3,a4, a5;
    crearElemento(&a1, 5);
    crearElemento(&a2, 4);
    crearElemento(&a3, 3);
    crearElemento(&a4, 2);
    crearElemento(&a5, 1);


    insertarLista(&a1, &lista);
    insertarLista(&a2, &lista);
    insertarLista(&a3, &lista);
    insertarLista(&a4, &lista);
    insertarLista(&a5, &lista);

    //listaOrdenada(&lista, &lista2);

    //mostrarLista(&lista);

    //borrarUltimoMain(&lista);
    //mostrarLista(&lista);

    //unique(&lista);
    //mostrarLista(&lista);

    //borrarUltimo(&lista);

    //borrarNprimeros(&lista, 1);

    //borrarCadaX(&lista, 2);

    //insertarDespuesDe(&lista, 2, 3);

    insertarOrdenado(&lista, 6);

    //vecesXelemento(&lista, 5);

    //sumarLista(&lista);

    //posfija(&lista, 2);

    //sumaAnteriores(&lista, 4);

    //criba(&lista, 2);


    mostrarLista(&lista);




    return 0;
}
