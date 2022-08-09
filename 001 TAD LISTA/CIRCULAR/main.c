#include <stdio.h>
#include "stdlib.h"
#include "circularList.h"
#include "Telemento.h"

int main() {
    TLista lista;
    crearListaVacia(&lista);

    TElemento a1,a2,a3,a4, a5;
    crearElemento(&a1, 1);
    crearElemento(&a2, 2);
    crearElemento(&a3, 3);
    crearElemento(&a4, 4);
    crearElemento(&a5, 5);


    insertarLista(&a4, &lista);
    insertarLista(&a3, &lista);
    insertarLista(&a2, &lista);
    insertarLista(&a1, &lista);

    //mostrarListaInvertida(&lista);

    //unique(&lista);

    //borrarUltimo(&lista);
    mostrarLista(&lista);

    //borrarNprimeros(&lista, 3);

    //borrarCadaX(&lista, 3);

    //insertarOrdenado(&lista, 0);

    //insertarDespuesDe(&lista, 1,100);

    //vecesXelemento(&lista, 8);

    //posfija(&lista, 4);

    //sumarLista(&lista);

    //sumaAnteriores(&lista, 2);

    criba(&lista, 3);


    return 0;
}
