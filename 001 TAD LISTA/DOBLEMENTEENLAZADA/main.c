#include <stdio.h>
#include "Telemento.h"
#include "DoblePointedSimpleLinkedList.h"
int main() {

    TLista lista;
    crearListaVacia(&lista);

    TElemento a1,a2,a3,a4, a5;
    crearElemento(&a1, 1);
    crearElemento(&a2, 1);
    crearElemento(&a3, 3);
    crearElemento(&a4, 4);
    crearElemento(&a5, 5);


   // insertarLista(&a4, &lista);
    //insertarLista(&a3, &lista);
    insertarLista(&a2, &lista);
    insertarLista(&a1, &lista);

    //mostrarListaInvertida(&lista);

    //unique(&lista);

    //borrarUltimo(&lista);

    //borrarNprimeros(&lista, 1);

    //borrarCadaX(&lista, 4);

    //insertarOrdenado(&lista, 0);

    //vecesXelemento(&lista, 3);

    //posfija(&lista, 3);

    //sumarLista(&lista);

    //sumaAnteriores(&lista, 5);

    //criba(&lista, 2);

    duplicarValores(&lista);

   return 0;
}
