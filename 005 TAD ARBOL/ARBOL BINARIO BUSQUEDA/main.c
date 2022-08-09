#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
//#include "simplelinkedlist.h"


int main(){
    TElemento e1,e2,e3,e4,e5,e6,e7,elemento;
    TBinarySearchTree a1, copia;
    TLinkedList preO;
    crear("Alfonso","4684411Z",7.9,&e1);
    crear("Cesar","9084411Z",3.9,&e2);
    crear("Laura","44342434P",6.2,&e3);
    crear("Pedro","94487006Y",1.9,&e4);
    crear("Vanessa","V566653Z",8.0,&e5);
    crear("Reyes","76000021H",4.0,&e6);
    crear("Teresa","6112033T",5.0,&e7);
    CrearArbolBusquedaVacio(&a1);
    CrearArbolBusquedaVacio(&copia);

    insertarArbolBusqueda(&a1,e1);
    insertarArbolBusqueda(&a1,e2);
    insertarArbolBusqueda(&a1,e3);
    insertarArbolBusqueda(&a1,e4);
    insertarArbolBusqueda(&a1,e5);
    insertarArbolBusqueda(&a1,e6);
    //insertarArbolBusqueda(&a1,e7);

    eliminarArbolBusqueda(&a1, e6);

    //eliminarArbolBusqueda(&a1,e1);
    printf("\nNumero de hojas %d\n",numeroHojas(a1));
    printf("\nNumero de nodos %d\n",numeroNodos(a1));
    printf("\nAltura %d\n",altura(a1));
    printf("Contiene Teresa: %d",contieneArbolBinarioBusqueda(a1,e7));
   /* //mayorNodo(&elemento, a1);
    //menorNodo(&elemento, a1);*/

    //contieneArbolBinarioBusqueda(a1, e6);

    copiarArbolBusqueda(a1, &copia);

    printf("EXAMEN!!!!!!!!!!\n");
    ascendientes(&a1, &e1, &preO);
    mostrar(preO);

    //destruirArbolBusqueda(&a1);
/*    printf("LISTADO:\n");
    preorden(a1, &preO);
    printf("LISTADO:\n");
    preorden(copia, &preO);
    crearVacia(&preO);
    postorden(a1,&preO);
    mostrar(preO);*/

    return 0;
}