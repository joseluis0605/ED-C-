#include <stdio.h>
#include "stdlib.h"
#include "TSimpleLinkedList.h"

int main() {

   tlista milista, lista2;

    inicializar(&milista);

    insertarElemento(&milista, 4);
    insertarElemento(&milista, 5);
    insertarElemento(&milista, 7);

    mostrar(&milista);

    contiene(6, milista);
    contiene(5, milista);

    //destruir(&milista);
    //mostrar(&milista);

    resto(&milista);
    mostrar(&milista);

    insertarFinal(3, &milista);

    eliminar(5, &milista);
    eliminar(3, &milista);
    eliminar(5, &milista);
    eliminar(5, &milista);

    mostrar(&milista);
    return 0;
}
/*
 mostrar(&milista);

    primero(&milista);
    ultimo(&milista);

    copiar(milista, &lista2);
 */